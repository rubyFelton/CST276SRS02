#pragma once
#include "chrono"
#include <string>
#include <sstream>
#include "vector"

class DateValidatorI18N
{
public:
	enum class Format { YMD, DMY, MDY };
	std::vector<std::string> delimiterList{ "/", ".", "_", " " };

	auto splitDate(std::string date)
	{
		std::istringstream iss{ date };
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

	static auto toInt(std::string str)
	{
		if (str.length() > 2)
		{
			const auto position = str.find_first_not_of('0');
			str.erase(0, position);
		}

		return std::stoi(str, nullptr, 10);
	}

	static auto max_day(const std::string year, const std::string month) noexcept
	{
		std::vector<int> days{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		auto result = days[toInt(month) - 1];
		if (toInt(month) == 2 && (toInt(year) % 4 == 0 && toInt(year) % 4 != 100 || toInt(year) % 400 == 0))
		{
			result = 29;
		}

		return result;
	}

	auto is_year(std::string str)
	{
		auto result = false;
		if (str.length() > 2 && toInt(str) >= 1901 && toInt(str) < 2100)
		{
			result = true;
		}
		return result;
	}

	auto is_month(std::string str)
	{
		auto result = false;
		if (toInt(str) >= 1 && toInt(str) <= 12)
		{
			result = true;
		}
		return result;
	}

	auto is_day(std::string month, std::string year, std::string str)
	{
		auto result = false;
		auto range_max = max_day(month, year);

		if (str.length() <= 2 && toInt(str) <= range_max)
		{
			result = true;
		}
		return result;
	}

	bool ValidateEnum(Format format, std::string date)
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
		}
		return result;
	}
};
