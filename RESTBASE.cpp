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

	else if (req.getURI() == "/codemirror/lib/codemirror.js") {
		resp.sendFile("codemirror/lib/codemirror.js", "application/javascript");
	}

	else if (req.getURI() == "/codemirror/lib/codemirror.css") {
		resp.sendFile("codemirror/lib/codemirror.css", "text/css");
	}

	else if (req.getURI() == "/codemirror/theme/dracula.css") {
		resp.sendFile("codemirror/theme/dracula.css", "text/css");
	}

	else if (req.getURI() == "/codemirror/mode/clike/clike.js") {
		resp.sendFile("codemirror/mode/clike/clike.js", "application/javascript");
	}

	else { //404 Response
		resp.setStatus(HTTPResponse::HTTP_NOT_FOUND);
		print404Response(req, resp);
	}

	//Loggint out status of response to console
	std::cout << resp.getStatus() << std::endl;

}

void restBaseClass::print404Response(HTTPServerRequest &req, HTTPServerResponse &resp) {

	resp.setContentType("text/html");

	std::ostream& out = resp.send();

	out << "<h2>404 NOT FOUND</h2>";
	out.flush();

}




