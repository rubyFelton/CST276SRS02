#pragma once
#include "DateI18N.h"

class DMYValidator :
	public DateI18N
{
public:
	DMYValidator();
	~DMYValidator();
	bool Validate(std::string date) override;
};

