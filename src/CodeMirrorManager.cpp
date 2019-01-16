#include "CodeMirrorManager.h"

void CodeMirrorManager::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp) {

	if (req.getURI() == "/codemirror/lib/codemirror.js") {
		resp.sendFile("codemirror/lib/codemirror.js", "application/javascript");
	}

	else if (req.getURI() == "/codemirror/lib/codemirror.css") {
		resp.sendFile("codemirror/lib/codemirror.css", "text/css");
	}

	else if (req.getURI() == "/codemirror/theme/dracula.css") {
		resp.sendFile("codemirror/theme/dracula.css", "text/css");
	}

	else if (req.getURI() == "/codemirror/mode/clike/clike.js") {
		resp.sendFile("codemirror/mode/clike/clike.js", "application/javascript");
	}

	else if (req.getURI() == "/codemirror/addon/edit/closebrackets.js") {
		resp.sendFile("codemirror/addon/edit/closebrackets.js", "application/javascript");
	}

	else if (req.getURI() == "/codemirror/editor.css") {
		resp.sendFile("codemirror/editor.css", "text/css");
	}

	else if (req.getURI() == "/codemirror/boostrap-4.2.1-dist/css/bootstrap.min.css") {
		resp.sendFile("codemirror/boostrap-4.2.1-dist/css/bootstrap.min.css", "text/css");
	}

	else if (req.getURI() == "/codemirror/boostrap-4.2.1-dist/js/bootstrap.min.js") {
		resp.sendFile("codemirror/boostrap-4.2.1-dist/js/bootstrap.min.js", "application/javascript");
	}

	else { //404 Response
		resp.setStatus(HTTPResponse::HTTP_NOT_FOUND);
	}

}

