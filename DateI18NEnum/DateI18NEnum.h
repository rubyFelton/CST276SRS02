#pragma once
#include <string>
#include <sstream>
#include "vector"

class DateI18NEnum
{
public:
	enum class Format { YMD, DMY, MDY, YDM};
	std::vector<std::string> delimiterList{ "/", ".", "_", " " };

	DateI18NEnum();
	~DateI18NEnum();
	auto splitDate(std::string date);
	static auto toInt(std::string str);
	static auto max_day(const std::string year, const std::string month) noexcept;
	auto is_year(std::string str);
	auto is_month(std::string str);
	auto is_day(std::string month, std::string year, std::string str);
	bool ValidateEnum(Format format, std::string date);
};
