#pragma once
#include "DateI18N.h"

class YMDValidator : public DateI18N
{
public:
	YMDValidator();
	~YMDValidator();
	bool Validate(std::string date) override;
};
