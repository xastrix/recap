#pragma once

#include <string>

namespace utils
{
	int convertTimeStringToInt(const std::wstring& string);
	std::wstring getFileExtension(const std::wstring& filename);
}