#include "stdafx.h"
#include "DateI18NEnum.h"

DateI18NEnum::DateI18NEnum()
{
}


DateI18NEnum::~DateI18NEnum()
{
}

auto DateI18NEnum::splitDate(std::string date)
{
	std::istringstream iss{date};
	std::vector<std::string> parts;

	for (std::string element : delimiterList)
	{
		if (date.find(element) != -1)
		{
			parts.push_back(element);
		}
	}

	while (iss.good())
	{
		std::string buffer;
		std::getline(iss, buffer, parts[0][0]);
		parts.push_back(buffer);
	}
	return parts;
}

auto DateI18NEnum::toInt(std::string str)
{
	if (str.length() > 2)
	{
		const auto position = str.find_first_not_of('0');
		str.erase(0, position);
	}

	return std::stoi(str, nullptr, 10);
}

auto DateI18NEnum::max_day(const std::string year, const std::string month) noexcept
{
	std::vector<int> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	auto result = days[toInt(month) - 1];
	if (toInt(month) == 2 && (toInt(year) % 4 == 0 && toInt(year) % 4 != 100 || toInt(year) % 400 == 0))
	{
		result = 29;
	}

	return result;
}

auto DateI18NEnum::is_year(std::string str)
{
	auto result = false;
	if (str.length() > 2 && toInt(str) >= 1901 && toInt(str) < 2100)
	{
		result = true;
	}
	return result;
}

auto DateI18NEnum::is_month(std::string str)
{
	auto result = false;
	if (toInt(str) >= 1 && toInt(str) <= 12)
	{
		result = true;
	}
	return result;
}

auto DateI18NEnum::is_day(std::string month, std::string year, std::string str)
{
	auto result = false;
	auto range_max = max_day(month, year);

	if (str.length() <= 2 && toInt(str) <= range_max)
	{
		result = true;
	}
	return result;
}

bool DateI18NEnum::ValidateEnum(Format format, std::string date)
{
	std::vector<std::string> parts = splitDate(date);
	auto result = false;
	switch (format)
	{
	case Format::YMD:

		if (is_year(parts[1]) && is_month(parts[2]) && is_day(parts[1], parts[3], parts[2]))
		{
			result = true;
		}
		break;

	case Format::DMY:

		if (is_day(parts[1], parts[3], parts[2]) && is_month(parts[2]) && is_year(parts[3]))
		{
			result = true;
		}
		break;

	case Format::MDY:

		if (is_month(parts[1]) && is_day(parts[1], parts[3], parts[2]) && is_year(parts[3]))
		{
			result = true;
		}
		break;
		
	case Format::YDM:

		if (is_year(parts[3]) && is_day(parts[1], parts[3], parts[2]) && is_month(parts[1]) )
		{
			result = true;
		}
		break;
	}
	return result;
}
