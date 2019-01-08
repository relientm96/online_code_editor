#include "NotFound.h"

void NotFoundManager::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp) {

	resp.setStatus(HTTPResponse::HTTP_NOT_FOUND);
	print404Response(req, resp);
}

void NotFoundManager::print404Response(HTTPServerRequest &req, HTTPServerResponse &resp) {

	resp.setContentType("text/html");
	std::ostream& out = resp.send();
	out << "<h2>404 NOT FOUND</h2>";
	out.flush();

}
