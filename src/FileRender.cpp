#include "FileRender.h"

void FileRender::doCreate(HTTPServerRequest &req, HTTPServerResponse &resp) {
	//Stream in project name to be created 
	this->projName = streamRequestData(req, resp);

	Poco::Path newProjPath(Poco::Path("Projects", this->projName));
	Poco::File(newProjPath).createDirectories();

	resp.setStatus(HTTPResponse::HTTP_CREATED);
}

 void FileRender::doRead(HTTPServerRequest &req, HTTPServerResponse &resp) {

	 //Render code editor HTML file
	 resp.sendFile("codemirror/editor.html", "text/html");

 }

 void FileRender::doUpdate(HTTPServerRequest &req, HTTPServerResponse &resp) {

	 //Obtaining Project name parameter from URI
	 Poco::URI uri(req.getURI());
	 Poco::URI::QueryParameters queryParams (uri.getQueryParameters());

	 //Get the project filename from url query string
	 for (const std::pair <std::string, std::string> &param : queryParams) {
		 if (param.first == "name") {
			 this->projName = param.second;
		 }
	 }

	 //Stream in code from CodeMirror Editor
	 std::string code = streamRequestData(req, resp);
	 
	 //Return permission denied code if user makes system call
	 if (ifSystemCallFound(code)) {
		 //Stream out permission denied in output box 
		 resp.setStatus(HTTPResponse::HTTP_FORBIDDEN);
		 resp.setContentType("text/html");
		 std::ostream& out = resp.send();

		 //Warn user for making system calls
		 out << "Cannot make system calls!";
		 out.flush();
		 return;
	 }

	 //Stream Buffer into file
	 std::ofstream cFile;
	 cFile.open("Projects/" + this->projName + "/outputFile.c");
	 cFile << code;
	 cFile.close();

	 //Launch GCC for compilation
	 std::string gccPath("C:/MinGW/bin/gcc.exe");
	 
	 //Create argument list for compilation
	 std::vector<std::string> compileArgs;
	 compileArgs.push_back("-Wall");
	 compileArgs.push_back("-o");
	 compileArgs.push_back("Projects/" + this->projName + "/outputFile");
	 compileArgs.push_back("Projects/" + this->projName + "/outputFile.c");

	 //Pipe in error stream 
	 Poco::Pipe outError;

	 if (0 != Poco::Process::launch(gccPath, compileArgs, 0 , 0, &outError).wait()) {
		 //Stream out errors produced from gcc
		 std::ostream& errorResponse = resp.send();
		 Poco::PipeInputStream istr(outError);
		 Poco::StreamCopier::copyStream(istr, errorResponse);
		 return;
	 }
	 
	 //Succesful compilation, execute compiled file
	 else {
			
		 std::string outputFilePath("Projects/" + this->projName + "/outputFile");
		 std::vector<std::string> runArgs;
		
		 Poco::Pipe outPipe;

		 if (0 != Poco::Process::launch(outputFilePath, runArgs, 0, &outPipe, 0).wait())
			 throw std::runtime_error("Error Executing File!");

		 //Return compiled file response to response body
		 std::ostream& out = resp.send();
		 Poco::PipeInputStream istr(outPipe);
		 Poco::StreamCopier::copyStream(istr, out);

		 resp.setStatus(HTTPResponse::HTTP_OK);
	 }

 }

 void FileRender::doDelete(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 printMessage(req, resp);
 }

 void FileRender::printMessage(HTTPServerRequest &req, HTTPServerResponse &resp) {

	 resp.setStatus(HTTPResponse::HTTP_OK);
	 resp.setContentType("text/html");

	 std::ostream& out = resp.send();

	 out << "<title> Matthew Yong </title>";

	 out << "<h1>Hello world!</h1>"
		 << "<p>Host: " << req.getHost() << "</p>"
		 << "<p>Method: " << req.getMethod() << "</p>"
		 << "<p>URI: " << req.getURI() << "</p>";
	 out.flush();
 }
 
//Reading request payload
 std::string FileRender::streamRequestData(HTTPServerRequest &req, HTTPServerResponse &resp) {
	 std::istream &i = req.stream();
	 int len = req.getContentLength();
	 char* buffer = new char[len + 1];
	 i.read(buffer, req.getContentLength());
	 buffer[len] = '\0';
	 return buffer;
 }

 //Search for "system" calls
 bool FileRender::ifSystemCallFound(std::string inputCode ) {
	 if (inputCode.find("system") != std::string::npos) {
		 return true;
	 }
	 else return false;
 }
