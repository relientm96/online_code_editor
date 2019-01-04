#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>
#include <string>
#include <vector>

#include "FileRender.h"

using namespace Poco::Util;

class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
	virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &)
	{
		return new FileRender;
	}
};

class MyServerApp : public ServerApplication
{
protected:
	int main(const std::vector<std::string> &)
	{
		HTTPServer server(new MyRequestHandlerFactory, ServerSocket(7000), new HTTPServerParams);

		server.start();
		std::cout << std::endl << "Server started" << std::endl;

		waitForTerminationRequest(); 

		std::cout << std::endl << "Shutting down..." << std::endl;
		server.stop();

		return Application::EXIT_OK;
	}
};

int main(int argc, char** argv)
{
	MyServerApp app;
	return app.run(argc, argv);
}