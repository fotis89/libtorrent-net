#include "session.h"

#include <libtorrent/session.hpp>
#include <libtorrent/session_status.hpp>

#include "add_torrent_params.h"
#include "entry.h"
#include "interop.h"
#include "sha1_hash.h"
#include "torrent_handle.h"
#include "settings_pack.h"

using namespace lt;

session::session(settings_pack ^ settings)
{
    session_ = new libtorrent::session(settings->ptr());
}

session::~session()
{
	this->!session();
}

session::!session()
{
	delete session_;
}

entry^ session::save_state(unsigned int flags)
{
    libtorrent::entry e;
    session_->save_state(e, flags);

    return gcnew entry(e);
}

void session::post_torrent_updates()
{
    session_->post_torrent_updates();
}

torrent_handle^ session::find_torrent(sha1_hash^ hash)
{
    return gcnew torrent_handle(session_->find_torrent(hash->ptr()));
}

cli::array<torrent_handle^>^ session::get_torrents()
{
    std::vector<libtorrent::torrent_handle> torrents = session_->get_torrents();
    cli::array<torrent_handle^>^ result = gcnew cli::array<torrent_handle^>(torrents.size());

    for (size_t i = 0; i < torrents.size(); i++)
    {
        result[i] = gcnew torrent_handle(torrents[i]);
    }

    return result;
}

void session::async_add_torrent(add_torrent_params^ params)
{
    session_->async_add_torrent(*params->ptr());
}

torrent_handle^ session::add_torrent(add_torrent_params^ params)
{
    libtorrent::error_code ec;
    libtorrent::torrent_handle h = session_->add_torrent(*params->ptr(), ec);

    if (ec)
    {
        throw gcnew System::Exception(interop::from_std_string(ec.message()));
    }

    return gcnew torrent_handle(h);
}

void session::pause()
{
    session_->pause();
}

void session::resume()
{
    session_->resume();
}

bool session::is_paused()
{
    return session_->is_paused();
}

bool session::is_dht_running()
{
    return session_->is_dht_running();
}

void session::add_dht_node(System::String^ host, int port)
{
    session_->add_dht_node(std::make_pair(interop::to_std_string(host), port));
}

void session::set_key(int key)
{
    session_->set_key(key);
}

bool session::is_listening()
{
    return session_->is_listening();
}

int session::listen_port()
{
    return session_->listen_port();
}

int session::ssl_listen_port()
{
    return session_->ssl_listen_port();
}

void session::remove_torrent(torrent_handle^ handle, int options)
{
    session_->remove_torrent(*handle->ptr(), options);
}

void session::delete_port_mapping(int handle)
{
    session_->delete_port_mapping(handle);
}