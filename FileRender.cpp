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
	 
	 std::ofstream cFile;
	 cFile.open("Resources/outputFile.c");
	 cFile << buffer;
	 cFile.close();

	 std::cout << "gcc launched ..." << std::endl;
	 std::string gccPath("C:/MinGW/bin/gcc.exe");
	 
	 std::vector<std::string> compileArgs;
	 compileArgs.push_back("-Wall");
	 compileArgs.push_back("-o");
	 compileArgs.push_back("Resources/outputFile");
	 compileArgs.push_back("Resources/outputFile.c");

	 if (0 != Poco::Process::launch(gccPath, compileArgs).wait()) {
		 throw std::runtime_error("Error at GCC Compilation!");
		 resp.sendFile("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/error.txt", "text/plain");
	 }

	 std::cout << "Successful Compilation..." << std::endl;
	 
	 std::string outputFilePath("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/outputFile");
	 std::vector<std::string> runArgs;
	 runArgs.push_back(">");
	 runArgs.push_back("process.txt");

	 if (0 != Poco::Process::launch(outputFilePath, runArgs).wait())
		 throw std::runtime_error("Error Executing File!");

	 std::cout << "Successful Run..." << std::endl;

	 resp.sendFile("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/process.txt", "text/plain");
	 resp.setStatus(HTTPResponse::HTTP_OK);
	 
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
