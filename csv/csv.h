#pragma once

#include <iostream>

namespace csv {

	class istream: private std::streambuf, public std::istream {
			std::istream& source_;
			char ch_ = ' ';
			bool quoting_ { false };
			bool eof_ { false };

			void next_ch();

			int_type process_next_ch();
			int_type underflow() override;

		public:
			static const char SEPARATOR = ',';

			istream(std::istream& source):
				std::istream { this }, source_ { source }
			{
				setg(&ch_, &ch_ + 1, &ch_ + 1);
			}
			
			bool next_cell();
			bool next_line();
	};

}
