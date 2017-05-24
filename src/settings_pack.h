#pragma once

namespace libtorrent
{
    struct settings_pack;
}

namespace lt
{
    public ref class settings_pack
    {
    internal:
		settings_pack(libtorrent::settings_pack& settings);
        libtorrent::settings_pack& ptr();

    public:
        ~settings_pack();
		!settings_pack();

		void set_str(int name, System::String^ val);
		void set_int(int name, int val);
		void set_bool(int name, bool val);
		bool has_val(int name);

    private:
        libtorrent::settings_pack* settings_;
    };
}
