#include "FileRender.h"

void FileRender::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	printMessage(req, resp);
}

 void FileRender::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printJson(req, resp);

 }

 void FileRender::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printMessage(req, resp);
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

 void FileRender::printJson(HTTPServerRequest &req, HTTPServerResponse &resp) {

	resp.setStatus(HTTPResponse::HTTP_OK);
	resp.setContentType("application/json");
	 
	std::ostream& ostr = resp.send();

	ostr << "Name" << ": I like pho";
	ostr.flush();

 }

