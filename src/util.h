#pragma once

namespace libtorrent
{
    struct lazy_entry;
}

namespace lt
{
    ref class entry;
    ref class lazy_entry;

    public ref class util
    {
    public:
        static cli::array<System::Byte>^ bencode(entry^ e);
    };
}
