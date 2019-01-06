#include "FileRender.h"

void FileRender::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	printMessage(req, resp);
}

 void FileRender::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 resp.sendFile("mainpage.html", "text/html");
 }

 void FileRender::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printMessage(req, resp);

	 std::cout << "Process Launched ..." << std::endl;

	 std::string pathToArduino("C:/Program Files (x86)/Arduino/arduino.exe");
	 
	 std::vector<std::string> args;
	 args.push_back("C:/Matthew Documents/MatthewHolidayProjects/PocoTest/PocoTest/testSketch/testSketch.ino");

	 Poco::Pipe outPipe;
	 Poco::ProcessHandle ph = Poco::Process::launch(pathToArduino, args, 0, &outPipe, 0);	 Poco::PipeInputStream istr(outPipe);	 std::ofstream ostr("processes.txt");
	 Poco::StreamCopier::copyStream(istr, ostr);
 }

 void FileRender::doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printMessage(req, resp);
 }

 void FileRender::doDownload(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 resp.sendFile("resume_2019.pdf", "application/pdf");
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

