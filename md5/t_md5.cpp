#include "md5/md5.h"
#include "log/log.h"

#include <sstream>

static void test_md5(const std::string& source, const std::string& expected) {
	std::ostringstream out;
	md5::ostream stream { out };
	stream << source;
	std::string digest;
	stream.finish(digest);
	if (source != out.str()) {
		log_fatal(source.c_str(), out.str().c_str());
	}
	if (expected != digest) {
		log_fatal(expected.c_str(), digest.c_str());
	}
}

int main() {
	try {
		test_md5("", "d41d8cd9" "8f00b204" "e9800998" "ecf8427e");
		test_md5("a", "0cc175b9" "c0f1b6a8" "31c399e2" "69772661");
		test_md5("abc", "90015098" "3cd24fb0" "d6963f7d" "28e17f72");
		test_md5("message digest", "f96b697d" "7cb7938d" "525a2f31" "aaf161d0");
		test_md5(
			"abcdefghij" "klmnopqrst" "uvwxyz",
			"c3fcd3d7" "6192e400" "7dfb496c" "ca67e13b"
		);
		test_md5(
			"ABCDEFGHIJ" "KLMNOPQRST" "UVWXYZabcd" "efghijklmn" "opqrstuvwx"
			"yz01234567" "89",
			"d174ab98" "d277d9f5" "a5611c2c" "9f419d9f"
		);
		test_md5(
			"1234567890" "1234567890" "1234567890" "1234567890" "1234567890"
			"1234567890" "1234567890" "1234567890",
			"57edf4a2" "2be3c955" "ac49da2e" "2107b67a"
		);
	} catch (const terminate_exception& ex) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
