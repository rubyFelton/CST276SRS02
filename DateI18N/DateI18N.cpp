#include "stdafx.h"
#include "DateI18N.h"

DateI18N::DateI18N()
{
}

DateI18N::~DateI18N()
{
}

std::vector<std::string> DateI18N::splitDate(std::string date)
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

int DateI18N::toInt(std::string str)
{
	if (str.length() > 2)
	{
		const auto position = str.find_first_not_of('0');
		str.erase(0, position);
	}

	return std::stoi(str, nullptr, 10);
}

int DateI18N::max_day(const std::string year, const std::string month) noexcept
{
	std::vector<int> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	auto result = days[toInt(month) - 1];
	if (toInt(month) == 2 && (toInt(year) % 4 == 0 && toInt(year) % 4 != 100 || toInt(year) % 400 == 0))
	{
		result = 29;
	}

	return result;
}

bool DateI18N::is_year(std::string str)
{
	auto result = false;
	if (str.length() > 2 && toInt(str) > 1901 && toInt(str) < 2100)
	{
		result = true;
	}
	return result;
}

bool DateI18N::is_month(std::string str)
{
	auto result = false;
	if (toInt(str) > 1 && toInt(str) < 12)
	{
		result = true;
	}
	return result;
}

bool DateI18N::is_day(std::string month, std::string year, std::string str)
{
	auto result = false;
	auto range_max = max_day(month, year);

	if (str.length() <= 2 && toInt(str) < range_max)
	{
		result = true;
	}
	return result;
}

//work toward implementing templet pattern
// std::vector<std::string> DateI18N::getDelimiter()
// {
// 	return delimiterList;
// }
