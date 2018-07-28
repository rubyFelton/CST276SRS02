#include "stdafx.h"
#include "YDMValidator.h"
#include "DateI18N.h"

YDMValidator::YDMValidator()
{
}


YDMValidator::~YDMValidator()
{
}

bool YDMValidator::Validate(std::string date)
{
	std::vector<std::string> parts = splitDate(date);
	auto result = false;

	if (is_year(parts[1]) && is_day(parts[1], parts[3], parts[2]) && is_month(parts[2]))
	{
		result = true;
	}
	return result;
}