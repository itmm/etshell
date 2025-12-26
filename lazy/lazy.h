#line 26 "README.md"
#if !defined(lazy_h)
#define lazy_h

	#include <cstdint>
	#include <fstream>
	#include <iostream>
	#include <string>

	class Lazy {
			std::istream& in_;
			const std::string out_path_;
			std::fstream out_;
			int ch_ { ' ' };
			std::uintmax_t offset_ { 0 };

			void match_prefix_();
			void overwrite_rest_();
			void truncate_file_();

		public:
			Lazy(std::istream& in, const std::string& out_path);
			void process();
	};

#endif
