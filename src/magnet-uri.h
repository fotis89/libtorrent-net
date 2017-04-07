#pragma once

#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/error_code.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/magnet_uri.hpp>
#include <libtorrent/storage_defs.hpp>

namespace libtorrent
{
	struct magnet_uri;
}

namespace lt
{
	public ref class magnet_uri
	{
	public:
		void parse_magnet_uri(System::String^ uri, libtorrent::add_torrent_params &p, libtorrent::error_code &ec);
	};
}