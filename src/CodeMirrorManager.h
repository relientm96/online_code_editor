/* Manages CodeMirror Resource Loading from Resource folder*/

#ifndef CODEMIRRORMANAGER

#define CODEMIRRORMANAGER

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

class CodeMirrorManager : public HTTPRequestHandler {

public:
	void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);
};

#endif //CODEMIRRORMANAGER
