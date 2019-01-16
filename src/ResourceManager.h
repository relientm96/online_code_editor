/*Manage Resources loading from Resouces directory*/

#ifndef RESOURCEMANAGER

#define RESOURCEMANAGER

#include "RESTBASE.h"

class ResourceManager : public restBaseClass {

public:
	virtual void doRead(HTTPServerRequest &req, HTTPServerResponse &resp);
	virtual void doCreate(HTTPServerRequest &req, HTTPServerResponse &resp);
	virtual void doDelete(HTTPServerRequest &req, HTTPServerResponse &resp);
	virtual void doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp);
};

#endif //RESOURCEMANAGER

