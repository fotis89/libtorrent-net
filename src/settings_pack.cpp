#include "settings_pack.h"

#include <libtorrent/settings_pack.hpp>

#include "interop.h"

using namespace lt;

settings_pack::settings_pack()
{
	settings_ = new libtorrent::settings_pack();
}

settings_pack::settings_pack(libtorrent::settings_pack& settings)
{
    settings_ = new libtorrent::settings_pack(settings);
}

settings_pack::~settings_pack()
{
	this->!settings_pack();
}

settings_pack::!settings_pack()
{
	delete settings_;
}

void settings_pack::set_str(int name, System::String^ val) {
	settings_->set_str(name, interop::to_std_string(val));
}

void settings_pack::set_int(int name, int val) {
	settings_->set_int(name, val);
}

void settings_pack::set_bool(int name, bool val) {
	settings_->set_bool(name, val);
}

bool settings_pack::has_val(int name) {
	return settings_->has_val(name);
}

libtorrent::settings_pack& settings_pack::ptr()
{
    return *settings_;
}