#include "csv.h"

#include "log/log.h"

#include <iostream>

namespace csv {

	void istream::next_ch() {
		if (! eof_) {
			int got { source_.get() };
			if (got >= 0) {
				ch_ = static_cast<char>(got);
			} else {
				eof_ = true;
			}
		}
	}

	istream::int_type istream::process_next_ch() {
		next_ch();

		if (ch_ == '"' && ! quoting_) {
			quoting_ = true;
			next_ch();
		}
		if (ch_ == '"' /* && quoting_ */) {
			next_ch();
			if (eof_  || ch_ != '"') { quoting_ = false; }
		}
		if (eof_) {
			if (quoting_) { log_fatal("Offener CSV String", ""); }
			return traits_type::eof();
		} else if (! quoting_) {
			if (ch_ == '\r') {
				next_ch();
				if (ch_ != '\n') { log_fatal("Falsches Zeilenende", ""); }
			}
			if (eof_ || ch_ == '\n' || ch_ == SEPARATOR) {
				return traits_type::eof();
			}
		}
		setg(&ch_, &ch_, &ch_ + 1);
		return traits_type::to_int_type(ch_);
	}

	istream::int_type istream::underflow() {
		if (eof_) { return traits_type::eof(); }
		if (! quoting_ && (ch_ == '\n' || ch_ == SEPARATOR)) {
			return traits_type::eof();
		}
		return process_next_ch();
	}

	bool istream::next_cell() {
		while (this->get() >= 0) { }
		if (! eof_ && ch_ == SEPARATOR) {
			if (process_next_ch() >= 0) {
				clear();
				return true;
			}
		}
		return false;
	}

	bool istream::next_line() {
		while (next_cell()) { }
		if (! eof_ && ch_ == '\n') {
			if (process_next_ch() >= 0) {
				clear();
				return true;
			}
		}
		return false;
	}
}
