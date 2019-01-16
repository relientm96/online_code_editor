/*Manages registration page resources located in Registration Resources folder*/

#ifndef REGISTRATIONPAGE

#define REGISTRATIONPAGE

#include "RESTBASE.h"

class RegistrationPage : public restBaseClass{

public:
	virtual void doRead(HTTPServerRequest &req, HTTPServerResponse &resp);
	virtual void doCreate(HTTPServerRequest &req, HTTPServerResponse &resp);
	virtual void doDelete(HTTPServerRequest &req, HTTPServerResponse &resp);
	virtual void doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp);
};

#endif //REGISTRATIONPAGE

