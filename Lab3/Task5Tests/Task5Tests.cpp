#include "stdafx.h"
#include "../Task5/ParseURL.h"
#include <boost/test/unit_test.hpp>
#include <string>

using namespace std;

bool VerifyParseURL(string const& inputText, Protocol expectedProtocol, int expectedPort, std::string const & expectedHost,
	std::string const & expectedDocument)
{
	Protocol protocol;
	int port;
	string host;
	string document;

	if (ParseURL(inputText, protocol, port, host, document))
	{
		if (protocol != expectedProtocol)
		{
			return false;
		}
		if (port != expectedPort)
		{
			return false;
		}
		if (host != expectedHost)
		{
			return false;
		}
		if (document != expectedDocument)
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

BOOST_AUTO_TEST_SUITE(ParseURLTests)

BOOST_AUTO_TEST_CASE(ParseURL)
{
	BOOST_CHECK(VerifyParseURL("http://", HTTP, 80, "", ""));
	BOOST_CHECK(VerifyParseURL("https://", HTTPS, 443, "", ""));
	BOOST_CHECK(VerifyParseURL("ftp://", FTP, 21, "", ""));
	BOOST_CHECK(VerifyParseURL("http://www.host.com", HTTP, 80, "www.host.com", ""));
	BOOST_CHECK(VerifyParseURL("http://www.host.com:76", HTTP, 76, "www.host.com", ""));
	BOOST_CHECK(!VerifyParseURL("http://www.host.com:", HTTP, 80, "www.host.com", ""));
	BOOST_CHECK(VerifyParseURL("http://www.host.com/index.html", HTTP, 80, "www.host.com", "index.html"));
	BOOST_CHECK(VerifyParseURL("http://www.host.com:55/index.html", HTTP, 55, "www.host.com", "index.html"));
	BOOST_CHECK(VerifyParseURL("http://www.host.com/", HTTP, 80, "www.host.com", ""));
	BOOST_CHECK(VerifyParseURL("http://:78", HTTP, 78, "", ""));
}

BOOST_AUTO_TEST_SUITE_END()
