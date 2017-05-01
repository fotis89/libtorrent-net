#pragma once

#include <libtorrent/aux_/proxy_settings.hpp>
#include "proxy_type.h"

namespace libtorrent
{
	class proxy_settings_;
}

namespace lt
{
	public ref class proxy_settings
	{
	internal:
		libtorrent::aux::proxy_settings* ptr();

	public:
		proxy_settings();
		proxy_settings(const libtorrent::settings_pack& s);
		proxy_settings(const libtorrent::aux::session_settings& s);

		property System::String^ hostname
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property System::String^ username
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property System::String^ password
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property int port
		{
			int get();
			void set(int value);
		}

		property bool proxy_hostnames
		{
			bool get();
			void set(bool value);
		}

		property bool proxy_peer_connections
		{
			bool get();
			void set(bool value);
		}

		property bool proxy_tracker_connections
		{
			bool get();
			void set(bool value);
		}

		property proxy_type type
		{
			proxy_type get();
			void set(proxy_type value);
		}

		~proxy_settings();
		!proxy_settings();

	private:
		libtorrent::aux::proxy_settings* proxy_settings_;
	};
};
