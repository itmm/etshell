#line 28 "README.md"
#if !defined(lazy_h)
#define lazy_h

#line 197
	#include <cstdint>
#line 137
	#include <fstream>
#line 31
	#include <iostream>
	#include <string>

	class Lazy {
#line 111
			std::istream& in_;
			const std::string out_path_;
#line 142
			std::fstream out_;
#line 202
			int ch_ { ' ' };
			std::uintmax_t written_ { 0 };
#line 113

#line 53
			bool open_file_();
			void match_prefix_();
			int next_ch_();
			void overwrite_rest_();
			void truncate_file_();
#line 35
		public:
			Lazy(std::istream& in, const std::string& out_path);
			void operator()();
	};

#endif
