#include "ResourceManager.h"

void ResourceManager::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	std::cout << "Resource Create" << std::endl;
}

void ResourceManager::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {

	if (req.getURI() == "/Resources/Registration/registration.html") {
		resp.sendFile("Resources/Registration/registration.html" , "text/html");
	}

}

void ResourceManager::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	std::cout << "Resource Update" << std::endl;
}

void ResourceManager::doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) {
	std::cout << "Resource Delete" << std::endl;
}