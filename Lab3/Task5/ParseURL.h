#pragma once

#include <string>

enum Protocol
{
	HTTP,
	HTTPS,
	FTP
};

bool ParseURL(std::string const& url, Protocol &  protocol, int & port, std::string & host,
	std::string & document);