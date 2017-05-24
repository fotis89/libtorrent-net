#include "util.h"

#include <libtorrent/bencode.hpp>

#include "entry.h"
#include "interop.h"

using namespace lt;

cli::array<System::Byte>^ util::bencode(entry^ e)
{
    std::vector<char> buffer;
    libtorrent::bencode(std::back_inserter(buffer), *e->ptr());

    auto result = gcnew cli::array<System::Byte>(buffer.size());

    for (size_t i = 0; i < buffer.size(); i++)
    {
        result[i] = buffer[i];
    }

    return result;
}
