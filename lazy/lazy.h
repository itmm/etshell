#line 30 "README.md"
#if !defined(lazy_h)
#define lazy_h

#line 199
	#include <cstdint>
#line 139
	#include <fstream>
#line 33
	#include <iostream>
	#include <string>

	class Lazy {
#line 113
			std::istream& in_;
			const std::string out_path_;
#line 144
			std::fstream out_;
#line 204
			int ch_ { ' ' };
			std::uintmax_t written_ { 0 };
#line 115

#line 55
			bool open_file_();
			void match_prefix_();
			int next_ch_();
			void overwrite_rest_();
			void truncate_file_();
#line 37
		public:
			Lazy(std::istream& in, const std::string& out_path);
			void operator()();
	};

#endif
