#include <Poco/Net/ServerSocket.h>
#include <Poco/Util/ServerApplication.h>

#include "FileRender.h"
#include "CodeMirrorManager.h"
#include "NotFound.h"
#include "RegistrationPage.h"
#include "ResourceManager.h"

using namespace Poco::Util;

class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
	virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest & request)
	{
		//Handles CodeMirror Resource Requests
		if (request.getURI().find("codemirror") != std::string::npos) {
			return new CodeMirrorManager;
		}
		//Handles Resource Loading
		else if (request.getURI().find("Resources") != std::string::npos) {
			return new ResourceManager;
		}
		//Registration Page
		else if (request.getURI() == "/") {
			return new RegistrationPage;
		}
		//Main App
		else if (request.getURI() == "/app") {
			return new FileRender;
		}
		//Cannot find specified resource from URL
		else {
			return new NotFoundManager;
		}
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