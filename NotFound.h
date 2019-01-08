/*Handles 404 Responses*/

#ifndef NOTFOUND

#define NOTFOUND

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

class NotFoundManager : public HTTPRequestHandler {

public:
	void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);
	void print404Response(HTTPServerRequest &req, HTTPServerResponse &resp);
};

#endif //NOTFOUND
