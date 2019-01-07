/*Handles File Compilations*/

#ifndef FILERENDER

#define FILERENDER

#include <Poco/Process.h>
#include <Poco/Path.h>
#include <Poco/File.h>
#include <Poco/FileStream.h>
#include <Poco/PipeStream.h>
#include <Poco/StreamCopier.h>
#include <fstream>

#include "RESTBASE.h"

class FileRender : public restBaseClass {

private:
	 virtual void doCreate(HTTPServerRequest &req, HTTPServerResponse &resp);
	 virtual void doRead(HTTPServerRequest &req, HTTPServerResponse &resp);
	 virtual void doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp);
	 virtual void doDelete(HTTPServerRequest &req, HTTPServerResponse &resp);

	 void printMessage(HTTPServerRequest &req, HTTPServerResponse &resp);

};

#endif //FILERENDER