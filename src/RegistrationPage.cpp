#include "RegistrationPage.h"

void RegistrationPage::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Print to test for this end point
	std::cout << "Registration Create" << std::endl;
}

void RegistrationPage::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Print to test for this end point
	resp.sendFile("Resources/Registration/registration.html", "text/html");
}

void RegistrationPage::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Print to test for this end point
	std::cout << "Registration Update" << std::endl;
}

void RegistrationPage::doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Print to test for this end point
	std::cout << "Registration Delete" << std::endl;
}