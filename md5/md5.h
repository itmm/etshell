#pragma once

#include <ostream>
#include <string>

namespace md5 {
	class ostream: private std::streambuf, public std::ostream {
			std::ostream& forward_;
			unsigned state_[4];
			unsigned count_[2];
			unsigned char buffer_[64];

			void init();
			void decode_buffer(unsigned x[16]);
			void encode(
				const unsigned* source, unsigned char* dest, unsigned byte_count
			);

			void process_block();
			void add_to_hash(unsigned char ch);

			int overflow(int ch) override {
				forward_.put(ch);
				add_to_hash(static_cast<unsigned char>(ch));
				return 0;
			}

		public:
			explicit ostream(std::ostream& forward):
				std::ostream { this }, forward_ { forward }
			{ init(); }

			void finish(unsigned char digest[16]);
			void finish(std::string& digest);
	};
}
