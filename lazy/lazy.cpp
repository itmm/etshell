#line 68 "README.md"
#include "lazy.h"
#include "log/log.h"

#line 164
#include <filesystem>

#line 71
Lazy::Lazy(std::istream& in, const std::string& out_path)
#line 126
	: in_ { in }, out_path_ { out_path }
#line 72
{ }

bool Lazy::open_file_() {
#line 168
	bool exists { std::filesystem::exists(out_path_) };
	if (exists) {
		out_.open(out_path_.c_str(),
			std::ios_base::in | std::ios_base::out | std::ios_base::binary
		);
	} else {
		out_.open(out_path_.c_str(), std::ios_base::out | std::ios_base::binary);
	}
	out_.exceptions(std::ios_base::failbit | std::ios_base::badbit);
	return exists;
#line 76
}

int Lazy::next_ch_() {
#line 217
	if (ch_ >= 0) {
		ch_ = in_.get();
	}
	return ch_;
#line 80
}

void Lazy::match_prefix_() {
#line 237
	for (;;) {
		ch_ = next_ch_();
		if (ch_ < 0) { break; }
		int should = out_.get();
		if (should != ch_) { break; }
		++written_;
	}
#line 83
}

void Lazy::overwrite_rest_() {
#line 259
	out_.seekp(written_);
	for (;;) {
		if (ch_ < 0) { break; }
		out_.put(ch_);
		++written_;
		ch_ = next_ch_();
	}
#line 86
}

void Lazy::truncate_file_() {
#line 281
	out_.close();
	auto cur { std::filesystem::file_size(out_path_) };
	if (cur != written_) {
		std::filesystem::resize_file(out_path_, written_);
	}
#line 89
}

void Lazy::operator()() {
	try {
		if (open_file_()) {
			match_prefix_();
		} else {
			next_ch_();
		}
		overwrite_rest_();
		truncate_file_();
	} catch (const std::ios_base::failure& ex) {
		log_fatal("Lazy Fehler", ex.what());
	}
}
