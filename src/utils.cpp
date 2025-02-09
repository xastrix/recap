#include "utils.h"

#include <cwctype>

int utils::convertTimeStringToInt(const std::wstring& string)
{
	if (string.empty())
		return 0;

	size_t pos = 0;
	while (pos < string.size() && std::iswdigit(string[pos]))
		pos++;

	if (pos == 0)
		return 0;

	int num = std::stoi(string.substr(0, pos), nullptr);
	std::wstring suffix = string.substr(pos);

	if (suffix == L"ms") {
		return num;
	}

	else if (suffix == L"s") {
		return num * 1000;
	}

	else if (suffix == L"hs") {
		return num * 3600000;
	}

	else {
		return num;
	}
}