#include "FileRender.h"

void FileRender::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	printMessage(req, resp);
}

 void FileRender::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 resp.sendFile("codemirror/editor.html", "text/html");
 }

 void FileRender::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 
	 std::istream &i = req.stream();
	 int len = req.getContentLength();
	 char* buffer = new char[len + 1];
	 i.read(buffer, req.getContentLength());
	 buffer[len] = '\0';

	 std::cout << buffer << std::endl;

	 std::ofstream cFile;
	 cFile.open("Resources/outputFile.c");
	 cFile << buffer;

	 std::cout << "gcc launched ..." << std::endl;
	 std::string gccPath("C:/MinGW/bin/gcc.exe");
	 
	 std::vector<std::string> compileArgs;
	 compileArgs.push_back("-Wall");
	 compileArgs.push_back("-o");
	 compileArgs.push_back("Resources/outputFile.exe");
	 compileArgs.push_back("Resources/outputFile.c");

	 if (0 != Poco::Process::launch(gccPath, compileArgs).wait())
		 throw std::runtime_error("Error at GCC Compilation!");

	 std::cout << "Successful Compilation..." << std::endl;
	 
	 std::string outputFilePath("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/outputFile.exe");
	 std::vector<std::string> runArgs;
	 runArgs.push_back("<");
	 runArgs.push_back("process.txt");

	 if (0 != Poco::Process::launch(outputFilePath, runArgs).wait())
		 throw std::runtime_error("Error Executing File!");

	 std::cout << "Succesful Run..." << std::endl;

	 resp.sendFile("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/process.txt", "text/plain");
	 resp.setStatus(HTTPResponse::HTTP_OK);
	 
 }

 void FileRender::doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printMessage(req, resp);
 }

 void FileRender::doDownload(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 resp.sendFile("Resources/resume_2019.pdf", "application/pdf");
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

 void FileRender::printJson(HTTPServerRequest &req, HTTPServerResponse &resp) {

	resp.setStatus(HTTPResponse::HTTP_OK);
	resp.setContentType("application/json");
	 
	std::ostream& ostr = resp.send();

	ostr << "Name" << ": I like pho";
	ostr.flush();

 }

