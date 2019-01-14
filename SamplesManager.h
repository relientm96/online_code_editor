/* Manages CodeMirror Resource Loading */

#ifndef SAMPLESMANAGER

#define SAMPLESMANAGER

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <fstream>
#include <string>

using namespace Poco::Net;

class SamplesManager : public HTTPRequestHandler {

public:
	void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);

};

#endif //SAMPLESMANAGER
