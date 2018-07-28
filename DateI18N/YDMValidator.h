#pragma once
#include "DateI18N.h"

class YDMValidator : public DateI18N
{
public:
	YDMValidator();
	~YDMValidator();
	bool Validate(std::string date) override;
};
