#include "stdafx.h"
#include "MDYValidator.h"


MDYValidator::MDYValidator()
{
}


MDYValidator::~MDYValidator()
{
}

bool MDYValidator::Validate(std::string date)
{
	std::vector<std::string> parts = splitDate(date);
	auto result = false;

	if (is_month(parts[2]) && is_day(parts[1], parts[3], parts[2]) && is_year(parts[1]))
	{
		result = true;
	}
	return result;
}