#pragma once

namespace libtorrent
{
    class session;
}

namespace lt
{
    ref class alert;
    ref class add_torrent_params;
    ref class dht_settings;
    ref class entry;
    ref class session_settings;
    ref class session_status;
    ref class sha1_hash;
    ref class torrent_handle;
	ref class settings_pack;


    public ref class session
    {
    public:
		session(settings_pack ^ settings);
        ~session();
		!session();

        entry^ save_state(unsigned int flags);
        void post_torrent_updates();
        torrent_handle^ find_torrent(sha1_hash^ hash);
        cli::array<torrent_handle^>^ get_torrents();
        void async_add_torrent(add_torrent_params^ params);
        torrent_handle^ add_torrent(add_torrent_params^ params);
        void pause();
        void resume();
        bool is_paused();
        bool is_dht_running();

        /// <summary>
        /// adds the given endpoint to a list of DHT router nodes. If a search
        /// is ever made while the routing table is empty, those nodes will be
        /// used as backups. Nodes in the router node list will also never be
        /// added to the regular routing table, which effectively means they
        /// are only used for bootstrapping, to keep the load off them.
        /// </summary>
        void add_dht_node(System::String^ host, int port);
        void set_key(int key);
        bool is_listening();
        int listen_port();
        int ssl_listen_port();
        void remove_torrent(torrent_handle^ handle, int options);
        void delete_port_mapping(int handle);

    private:
        libtorrent::session* session_;
    };
}
