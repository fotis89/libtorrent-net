#include "magnet-uri.h"
#include <msclr\marshal_cppstd.h>

using namespace lt;
using namespace System::Runtime::InteropServices;

void magnet_uri::parse_magnet_uri(System::String^ uri, libtorrent::add_torrent_params &p, libtorrent::error_code &ec)
{
	std::string unmanaged = msclr::interop::marshal_as<std::string>(uri);
	libtorrent::parse_magnet_uri(unmanaged, p, ec);
}