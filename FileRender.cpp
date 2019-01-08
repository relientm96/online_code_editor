#include "FileRender.h"

void FileRender::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	printMessage(req, resp);

	resp.setStatus(HTTPResponse::HTTP_CREATED);
}

 void FileRender::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 resp.sendFile("codemirror/editor.html", "text/html");
 }

 void FileRender::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 
	 //Stream in C Code into buffer 
	 std::istream &i = req.stream();
	 int len = req.getContentLength();
	 char* buffer = new char[len + 1];
	 i.read(buffer, req.getContentLength());
	 buffer[len] = '\0';
	 
	 //Stream Buffer into file
	 std::ofstream cFile;
	 cFile.open("Resources/outputFile.c");
	 cFile << buffer;
	 cFile.close();

	 //Launch GCC for compilation
	 std::cout << "gcc launched ..." << std::endl;
	 std::string gccPath("C:/MinGW/bin/gcc.exe");
	 
	 //Create argument list for compilation
	 std::vector<std::string> compileArgs;
	 compileArgs.push_back("-Wall");
	 compileArgs.push_back("-o");
	 compileArgs.push_back("Resources/outputFile");
	 compileArgs.push_back("Resources/outputFile.c");

	 //Pipe in error stream 
	 Poco::Pipe outError;

	 if (0 != Poco::Process::launch(gccPath, compileArgs, 0 , 0, &outError).wait()) {
		 //Stream out errors produced from gcc
		 std::cout << "ERROR" << std::endl;
		 std::ostream& errorResponse = resp.send();
		 Poco::PipeInputStream istr(outError);
		 Poco::StreamCopier::copyStream(istr, errorResponse);
		 return;
	 }
	 
	 //Succesful compilation, execute compiled file
	 else {
			
		 std::cout << "Successful Compilation..." << std::endl;

		 std::string outputFilePath("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/outputFile");
		 std::vector<std::string> runArgs;
		
		 Poco::Pipe outPipe;

		 if (0 != Poco::Process::launch(outputFilePath, runArgs, 0, &outPipe, 0).wait())
			 throw std::runtime_error("Error Executing File!");

		 std::cout << "Successful Run..." << std::endl;

		 //Return compiled file response to response body
		 std::ostream& out = resp.send();
		 Poco::PipeInputStream istr(outPipe);
		 Poco::StreamCopier::copyStream(istr, out);

		 resp.setStatus(HTTPResponse::HTTP_OK);
	 }

 }

 void FileRender::doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printMessage(req, resp);
 }

 void FileRender::printMessage(HTTPServerRequest &req, HTTPServerResponse &resp) {

	 resp.setStatus(HTTPResponse::HTTP_OK);
	 resp.setContentType("text/html");

	 std::ostream& out = resp.send();

	 out << "<title> Matthew Yong </title>";

	 out << "<h1>Hello world!</h1>"
		 << "<p>Host: " << req.getHost() << "</p>"
		 << "<p>Method: " << req.getMethod() << "</p>"
		 << "<p>URI: " << req.getURI() << "</p>";
	 out.flush();
 }
