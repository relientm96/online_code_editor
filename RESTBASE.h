#ifndef RESTBASE

#define RESTBASE

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

class restBaseClass : public HTTPRequestHandler {

protected:
	//Handles all requests
	void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);

	//Dedicated methods for each request
	virtual void doRead(HTTPServerRequest &req, HTTPServerResponse &resp) = 0;
	virtual void doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) = 0;
	virtual void doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) = 0;
	virtual void doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) = 0;

	//For Download Request
	virtual void doDownload(HTTPServerRequest &req, HTTPServerResponse &resp) = 0;

	//404 Response
	void print404Response(HTTPServerRequest &req, HTTPServerResponse &resp);

};

#endif //RESTBASE