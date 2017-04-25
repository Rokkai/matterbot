#pragma once
#include <array>
#include <unordered_map>

namespace lospi
{
	typedef std::array<unsigned char, 16> Md5Digest;
	Md5Digest compute_md5(const char *data, unsigned long size);	//	takes a c-style string and its size and creates an md5Digest	/
	Md5Digest get_md5_from_str(const std::wstring &md5_str);	//	takes a wstring and converts to Md5Digest
	std::wstring get_str_from_md5(const Md5Digest &md5_str);	//	takes MD5Digest and converts to string		/
	std::string wstring_to_string(const std::wstring &other);	//	take a wstring and converts to string		/
	std::wstring string_to_wstring(const std::string &s);		//	take a string and converts to wstring

  struct Combinator {
    Combinator(std::string alphabet, size_t length);
    bool has_next() const;
    std::vector<char> next();
  private:
    bool could_increment(int index = 0);
    const std::string alphabet;
    const size_t length;
    std::vector<uint8_t> combination_indices;
    std::vector<char> combination;
    bool has_next_flag;
  };
}
