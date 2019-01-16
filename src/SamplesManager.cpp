#include "SamplesManager.h"

void SamplesManager::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp) {

	if (req.getMethod() == "GET") {

		if (req.getURI() == "/Samples/time.c") {
			std::ifstream inputFile("Samples/time.c");
			std::string content((std::istreambuf_iterator<char>(inputFile)),
				(std::istreambuf_iterator<char>()));

			resp.setContentType("text/plain");

			std::ostream& out = resp.send();

			out << content;
			out.flush();

			resp.setStatus(HTTPResponse::HTTP_OK);
		}

		else if (req.getURI() == "/Samples/addTwoNumbers.c") {
			std::ifstream inputFile("Samples/addTwoNumbers.c");
			std::string content((std::istreambuf_iterator<char>(inputFile)),
				(std::istreambuf_iterator<char>()));

			resp.setContentType("text/plain");

			std::ostream& out = resp.send();

			out << content;
			out.flush();

			resp.setStatus(HTTPResponse::HTTP_OK);
		}

		else if (req.getURI() == "/Samples/drawTree.c") {
			std::ifstream inputFile("Samples/drawTree.c");
			std::string content((std::istreambuf_iterator<char>(inputFile)),
				(std::istreambuf_iterator<char>()));

			resp.setContentType("text/plain");

			std::ostream& out = resp.send();

			out << content;
			out.flush();

			resp.setStatus(HTTPResponse::HTTP_OK);
		}

		else if (req.getURI() == "/Samples/printName.c") {
			std::ifstream inputFile("Samples/printName.c");
			std::string content((std::istreambuf_iterator<char>(inputFile)),
				(std::istreambuf_iterator<char>()));

			resp.setContentType("text/plain");

			std::ostream& out = resp.send();

			out << content;
			out.flush();

			resp.setStatus(HTTPResponse::HTTP_OK);
		}


	}

}
