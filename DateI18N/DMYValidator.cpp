#include "stdafx.h"
#include "DMYValidator.h"


DMYValidator::DMYValidator()
{
}


DMYValidator::~DMYValidator()
{
}

bool DMYValidator::Validate(std::string date)
{
	std::vector<std::string> parts = DateI18N::splitDate(date);
	auto result = false;

	if (DateI18N::is_day(parts[1], parts[3], parts[2]) && DateI18N::is_month(parts[2]) && DateI18N::is_year(parts[1]))
	{
		result = true;
	}
	return result;
}
