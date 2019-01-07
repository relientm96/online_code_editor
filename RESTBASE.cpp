#include "RESTBASE.h"

void restBaseClass::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp){

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

	//Logging out status of response to console
	std::cout << resp.getStatus() << std::endl;

}





