#include "ResourceManager.h"

void ResourceManager::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Print code to test endpoint
	std::cout << "Resource Create" << std::endl;
}

void ResourceManager::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {

	//Load images located in resource directory

	if (req.getURI() == "/Resources/Registration/registration.html") {
		resp.sendFile("Resources/Registration/registration.html" , "text/html");
	}

	else if (req.getURI() == "/Resources/background.jpg") {
		resp.sendFile("Resources/background.jpg", "image/jpeg");
	}

	else if (req.getURI() == "/Resources/mainpage.jpg") {
		resp.sendFile("Resources/mainpage.jpg", "image/jpeg");
	}

}

void ResourceManager::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Print code to test endpoint
	std::cout << "Resource Update" << std::endl;
}

void ResourceManager::doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Print code to test endpoint
	std::cout << "Resource Delete" << std::endl;
}