#include "stdafx.h"
#include "ParseURL.h"
#include <boost/algorithm/string.hpp>
using namespace boost;

using namespace std;

bool ParseURL(std::string const& url, Protocol &  protocol, int & port, std::string & host,
	std::string & document)
{
	
	size_t pos = url.find("://");
	if (pos == string::npos)
	{
		return false;
	}
	string protocolStr = to_lower_copy(url.substr(0, pos));
	if (protocolStr == "http") 
	{
		protocol = HTTP;
		port = 80;
	}
	else if (protocolStr == "https")
	{
		protocol = HTTPS;
		port = 443;
	}
	else if (protocolStr == "ftp")
	{
		protocol = FTP;
		port = 21;
	}
	else
		return false;

	pos += 3;
	size_t posPort = url.find(":", pos);
	size_t posDoc = url.find("/", pos);
	if ((posPort == string::npos) && (posDoc == string::npos))
	{
		host = url.substr(pos, url.length());
		return true;
	}
	if (posDoc == string::npos)
	{
		try
		{
			port = stoi(url.substr(posPort + 1, url.length()));
		}
		catch (...)
		{
			return false;
		}
		host = url.substr(pos, posPort - pos);
		return true;
	}
	if (posPort == string::npos)
	{
		document = url.substr(posDoc + 1, url.length());
		host = url.substr(pos, posDoc - pos);
		return true;
	}
	document = url.substr(posDoc + 1, url.length());
	try
	{
		port = stoi(url.substr(posPort + 1, posDoc - posPort - 1));
	}
	catch (...)
	{
		return false;
	}
	host = url.substr(pos, posPort - pos);
	return true;
}