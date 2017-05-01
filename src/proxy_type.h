#pragma once


namespace lt
{
	public enum class proxy_type
	{
		// This is the default, no proxy server is used, all other fields are
		// ignored.
		none,

		// The server is assumed to be a `SOCKS4 server`_ that requires a
		// username.
		//
		// .. _`SOCKS4 server`: http://www.ufasoft.com/doc/socks4_protocol.htm
		socks4,

		// The server is assumed to be a SOCKS5 server (`RFC 1928`_) that does
		// not require any authentication. The username and password are
		// ignored.
		//
		// .. _`RFC 1928`: http://www.faqs.org/rfcs/rfc1928.html
		socks5,

		// The server is assumed to be a SOCKS5 server that supports plain
		// text username and password authentication (`RFC 1929`_). The
		// username and password specified may be sent to the proxy if it
		// requires.
		//
		// .. _`RFC 1929`: http://www.faqs.org/rfcs/rfc1929.html
		socks5_pw,

		// The server is assumed to be an HTTP proxy. If the transport used
		// for the connection is non-HTTP, the server is assumed to support
		// the CONNECT_ method. i.e. for web seeds and HTTP trackers, a plain
		// proxy will suffice. The proxy is assumed to not require
		// authorization. The username and password will not be used.
		//
		// .. _CONNECT: http://tools.ietf.org/html/draft-luotonen-web-proxy-tunneling-01
		http,

		// The server is assumed to be an HTTP proxy that requires user
		// authorization. The username and password will be sent to the proxy.
		http_pw,

		// route through an i2p SAM proxy
		i2p_proxy
	};
}