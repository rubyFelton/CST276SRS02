#pragma once
#include "DateI18N.h"

class MDYValidator :
	public DateI18N
{
public:
	MDYValidator();
	~MDYValidator();
	bool Validate(std::string date) override;
};

