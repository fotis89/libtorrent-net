#pragma once

namespace libtorrent
{
    class file_storage;
}

namespace ltnet
{
    ref class file_entry;

    public ref class file_storage
    {
    internal:
        file_storage(const libtorrent::file_storage& storage);
        libtorrent::file_storage& ptr();

    public:
        file_storage();
        ~file_storage();
		!file_storage();

        bool is_valid();
        void reserve(int num_files);
        void add_file(System::String^ p, long long size);
        void rename_file(int index, System::String^ new_filename);
        int num_files();
		System::String^ at(int index);
        long long total_size();
        void set_num_pieces(int n);
        int num_pieces();
        void set_piece_length(int l);
        int piece_length();
        int piece_size(int index);
        void set_name(System::String^ name);
        System::String^ name();
        void optimize(int pad_file_limit, int alignment);
        long long file_size(int index);
        System::String^ file_name(int index);
        long long file_offset(int index);
        bool pad_file_at(int index);
        System::String^ symlink(int index);
        System::String^ file_path(int index, System::String^ save_path);
        int file_flags(int index);
        int file_index_at_offset(long long offset);

    private:
        libtorrent::file_storage* storage_;
    };
}
