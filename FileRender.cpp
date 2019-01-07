#include "FileRender.h"

void FileRender::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	printMessage(req, resp);
}

 void FileRender::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 resp.sendFile("codemirror/editor.html", "text/html");
 }

 void FileRender::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printMessage(req, resp);

	 std::cout << "gcc launched ..." << std::endl;

	 std::string gccPath("C:/MinGW/bin/gcc.exe");
	 
	 std::vector<std::string> args;
	 args.push_back("-Wall");
	 args.push_back("-o");
	 args.push_back("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/outputFile");
	 args.push_back("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/Resources/outputFile.c");

	 Poco::Pipe outPipe;
	 if (0 != Poco::Process::launch(gccPath, args, 0, &outPipe, 0).wait())
		 throw std::runtime_error("Error at GCC Compilation!");

	 std::cout << "Successful Compilation..." << std::endl;
	 
	// std::cout << "Succesful Run..." << std::endl;
	 
	// resp.sendFile(output);

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

