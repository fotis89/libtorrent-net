#include "proxy_settings.h"

#include "interop.h"

using namespace lt;

proxy_settings::proxy_settings()
{
	proxy_settings_ = new libtorrent::aux::proxy_settings();
}

proxy_settings::proxy_settings(const libtorrent::settings_pack& s)
{
	proxy_settings_ = new libtorrent::aux::proxy_settings(s);
}

proxy_settings::proxy_settings(const libtorrent::aux::session_settings& s)
{
	proxy_settings_ = new libtorrent::aux::proxy_settings(s);
}

System::String^ proxy_settings::hostname::get()
{
	return interop::from_std_string(proxy_settings_->hostname);
}

void proxy_settings::hostname::set(System::String^ s)
{
	proxy_settings_->hostname = interop::to_std_string(s);
}

System::String^ proxy_settings::username::get()
{
	return interop::from_std_string(proxy_settings_->username);
}

void proxy_settings::username::set(System::String^ s)
{
	proxy_settings_->username = interop::to_std_string(s);
}

System::String^ proxy_settings::password::get()
{
	return interop::from_std_string(proxy_settings_->password);
}

void proxy_settings::password::set(System::String^ s)
{
	proxy_settings_->password = interop::to_std_string(s);
}

int proxy_settings::port::get()
{
	return proxy_settings_->port;
}

void proxy_settings::port::set(int p)
{
	proxy_settings_->port = p;
}

proxy_type proxy_settings::type::get()
{
	switch (proxy_settings_->type)
	{
	case libtorrent::aux::proxy_settings::proxy_type::http:
		return proxy_type::http;
		break;
	case libtorrent::aux::proxy_settings::proxy_type::http_pw:
		return proxy_type::http_pw;
		break;
	case libtorrent::aux::proxy_settings::proxy_type::i2p_proxy:
		return proxy_type::i2p_proxy;
		break;
	case libtorrent::aux::proxy_settings::proxy_type::none:
		return proxy_type::none;
		break;
	case libtorrent::aux::proxy_settings::proxy_type::socks4:
		return proxy_type::socks4;
		break;
	case libtorrent::aux::proxy_settings::proxy_type::socks5:
		return proxy_type::socks5;
		break;
	case libtorrent::aux::proxy_settings::proxy_type::socks5_pw:
		return proxy_type::socks5_pw;
		break;
	default:break;
	}
}

void proxy_settings::type::set(proxy_type p)
{
	switch (p)
	{
	case proxy_type::http:
		proxy_settings_->type = libtorrent::aux::proxy_settings::proxy_type::http;
		break;
	case proxy_type::http_pw:
		proxy_settings_->type = libtorrent::aux::proxy_settings::proxy_type::http_pw;
		break;
	case proxy_type::i2p_proxy:
		proxy_settings_->type = libtorrent::aux::proxy_settings::proxy_type::i2p_proxy;
		break;
	case proxy_type::none:
		proxy_settings_->type = libtorrent::aux::proxy_settings::proxy_type::none;
		break;
	case proxy_type::socks4:
		proxy_settings_->type = libtorrent::aux::proxy_settings::proxy_type::socks4;
		break;
	case proxy_type::socks5:
		proxy_settings_->type = libtorrent::aux::proxy_settings::proxy_type::socks5;
		break;
	case proxy_type::socks5_pw:
		proxy_settings_->type = libtorrent::aux::proxy_settings::proxy_type::socks5_pw;
		break;
	default:break;
	}
}

bool proxy_settings::proxy_hostnames::get()
{
	return proxy_settings_->proxy_hostnames;
}

void proxy_settings::proxy_hostnames::set(bool p)
{
	proxy_settings_->proxy_hostnames = p;
}

bool proxy_settings::proxy_peer_connections::get()
{
	return proxy_settings_->proxy_peer_connections;
}

void proxy_settings::proxy_peer_connections::set(bool p)
{
	proxy_settings_->proxy_peer_connections = p;
}

bool proxy_settings::proxy_tracker_connections::get()
{
	return proxy_settings_->proxy_tracker_connections;
}

void proxy_settings::proxy_tracker_connections::set(bool p)
{
	proxy_settings_->proxy_tracker_connections = p;
}

proxy_settings::~proxy_settings()
{
	this->!proxy_settings();
}

proxy_settings::!proxy_settings()
{
	delete proxy_settings_;
}

libtorrent::aux::proxy_settings* proxy_settings::ptr()
{
	return proxy_settings_;
}
