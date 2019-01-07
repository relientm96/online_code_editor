#include "RESTBASE.h"

void restBaseClass::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp){

	if (req.getURI() == "/") {

		if (req.getMethod() == "POST") {
			resp.setStatus(HTTPResponse::HTTP_OK);
			doCreate(req, resp);
		}
		else if (req.getMethod() == "GET") {
			resp.setStatus(HTTPResponse::HTTP_OK);
			doRead(req, resp);
		}
		else if (req.getMethod() == "PUT") {
			resp.setStatus(HTTPResponse::HTTP_OK);
			doUpdate(req, resp);
		}
		else if (req.getMethod() == "DELETE") {
			resp.setStatus(HTTPResponse::HTTP_OK);
			doDelete(req, resp);
		}
		else { //Bad request
			resp.setStatus(HTTPResponse::HTTP_BAD_REQUEST);
			std::ostream& out = resp.send();
			out << "Bad Request!";
			out.flush();
		}
	}

	else if (req.getURI() == "/download") {
		if (req.getMethod() == "GET") {
			resp.setStatus(HTTPResponse::HTTP_OK);
			doDownload(req, resp);
		}
	}

	else { //404 Response
		resp.setStatus(HTTPResponse::HTTP_NOT_FOUND);
		print404Response(req, resp);
	}

	//Logging out status of response to console
	std::cout << resp.getStatus() << std::endl;

}

void restBaseClass::print404Response(HTTPServerRequest &req, HTTPServerResponse &resp) {

	resp.setContentType("text/html");

	std::ostream& out = resp.send();

	out << "<h2>404 NOT FOUND</h2>";
	out.flush();

}




