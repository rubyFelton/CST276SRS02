#include "stdafx.h"
#include "YMDValidator.h"
#include "DateI18N.h"

YMDValidator::YMDValidator()
{
}


YMDValidator::~YMDValidator()
{
}

bool YMDValidator::Validate(std::string date)
{
	std::vector<std::string> parts = splitDate(date);
	auto result = false;

	if (is_year(parts[1]) && is_month(parts[2]) && is_day(parts[1], parts[3], parts[2]))
	{
		result = true;
	}
	return result;
}
