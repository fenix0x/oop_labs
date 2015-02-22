#include "stdafx.h"
#include "ParseURL.h"
#include <boost/algorithm/string.hpp>

using namespace boost;
using namespace std;

bool ParseProtocol(string const& protocolStr, Protocol &  protocol, int & port)
{
	if (protocolStr == "http")
	{
		protocol = HTTP;
		port = 80;
		return true;
	}
	else if (protocolStr == "https")
	{
		protocol = HTTPS;
		port = 443;
		return true;
	}
	else if (protocolStr == "ftp")
	{
		protocol = FTP;
		port = 21;
		return true;
	}
	else
		return false;
}

bool ParseHost(string const& urlStr, int start, int size, string & host)
{
	host = urlStr.substr(start, size);
	return (host.length() > 0);
}

bool ParsePort(string const& urlStr, int start, int size, int & port)
{
	try
	{
		port = stoi(urlStr.substr(start, size));
		return ((port >= 1) && (port <= 65535));
	}
	catch (...)
	{
		return false;
	}
}

bool ParseURL(std::string const& url, Protocol &  protocol, int & port, std::string & host,
	std::string & document)
{
	size_t pos = url.find("://");
	if (pos == string::npos)
	{
		return false;
	}

	if (!ParseProtocol(to_lower_copy(url.substr(0, pos)), protocol, port))
	{
		return false;
	}

	pos += 3;
	size_t posPort = url.find(":", pos);
	size_t posDoc = url.find("/", pos);
	document = "";

	if ((posPort == string::npos) && (posDoc == string::npos))
	{
		return ParseHost(url, pos, url.length(), host);
	}
	
	if (posDoc == string::npos)
	{
		if (!ParsePort(url, posPort + 1, url.length(), port))
		{
			return false;
		}
		return ParseHost(url, pos, posPort - pos, host);
	}
	
	if (posPort == string::npos)
	{
		document = url.substr(posDoc + 1, url.length());
		return ParseHost(url, pos, posDoc - pos, host);
	}
	
	document = url.substr(posDoc + 1, url.length());
	if (!ParsePort(url, posPort + 1, posDoc - posPort - 1, port))
	{
		return false;
	}
	return ParseHost(url, pos, posPort - pos, host);
}