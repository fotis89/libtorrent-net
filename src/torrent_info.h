#pragma once

namespace libtorrent
{
    class torrent_info;
}

namespace lt
{
    ref class announce_entry;
    ref class sha1_hash;
	ref class file_entry;
	ref class file_storage;

    public ref class torrent_info
    {
    public:
        torrent_info(cli::array<System::Byte>^ buffer);
        torrent_info(System::String^ fileName);

        ~torrent_info();
		!torrent_info();

        void rename_file(int index, System::String^ new_filename);
        cli::array<announce_entry^>^ trackers();
        void add_tracker(System::String^ url, int tier);
        int num_pieces();
        long long total_size();
        int piece_length();
        sha1_hash^ info_hash();
        int num_files();
		System::String^ torrent_info::file_at(int index);
        System::String^ ssl_cert();
        bool is_valid();
        bool priv();
        bool is_i2p();
        int piece_size(int index);
        System::Nullable<System::DateTime>^ creation_date();
        System::String^ name();
        System::String^ comment();
        System::String^ creator();
        int metadata_size();
        cli::array<System::Byte>^ metadata();
        bool is_merkle_torrent();

    internal:
        torrent_info(const libtorrent::torrent_info& info);

        libtorrent::torrent_info* ptr();

    private:
        libtorrent::torrent_info* info_;
    };
}
