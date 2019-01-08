#include "RESTBASE.h"

void restBaseClass::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp){

	if (req.getMethod() == "POST") {
		doCreate(req, resp);
	}
	else if (req.getMethod() == "GET") {
		doRead(req, resp);
	}
	else if (req.getMethod() == "PUT") {
		doUpdate(req, resp);
	}
	else if (req.getMethod() == "DELETE") {
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





