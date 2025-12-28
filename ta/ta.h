#pragma once

#include <iostream>
#include <string>

namespace ta {
	
	class Reader {
			std::istream& in_;
			int cur_ = '\n';
			int next_ = '\n';
			int last_ = '\n';

			int get_ch_();
			std::string read_command();

		public:
			Reader(std::istream& in): in_ { in } { get_ch_(); get_ch_(); }
			bool open_next_file(std::string& name);
			int next_ch();
	};
		
	class ostream: private std::streambuf, public std::ostream {
			std::ostream& forward_;
			int last_ = '\n';

			int overflow(int ch) override;

		public:
			ostream(std::ostream& forward):
				std::ostream { this }, forward_ { forward }
			{ }

			void open_next_file(const std::string& name);
	};
};

