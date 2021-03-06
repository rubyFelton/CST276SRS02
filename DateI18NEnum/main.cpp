// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include "DateI18NEnum.h"
#include <assert.h>
//without patterns
int main()
{
	//YMD, DMY, MDY, YDM
	enum class Format { YMD, DMY, MDY, YDM };

	std::string date1 = "2020/12/31"; //ymd
	std::string date2 = "2120-12-31"; //out of year bound
	std::string date3 = "20/12/31"; //no 4 digit year
	std::string date4 = "12.31.2020"; //mdy
	std::string date5 = "31/12/2020"; //dmy
	std::string date6 = "2020/31/12"; //ydm
	std::string date7 = "02-28-2020"; //mdy
	std::string date8 = "2/30/2020"; //out of day bound
	std::string date9 = "09/31/2020"; //out of day bound

	DateI18NEnum validator;

	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date1) == true);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date1) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date1) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date1) == false);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date2) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date2) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date2) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date2) == false);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date3) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date3) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date3) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date3) == false);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date4) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date4) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date4) == true);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date4) == false);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date5) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date5) == true);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date5) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date5) == false);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date6) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date6) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date6) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date6) == true);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date7) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date7) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date7) == true);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date7) == false);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date8) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date8) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date8) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date8) == false);	
	
	assert(validator.ValidateEnum(DateI18NEnum::Format::YMD, date9) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::DMY, date9) == false);	
	assert(validator.ValidateEnum(DateI18NEnum::Format::MDY, date9) == false);
	assert(validator.ValidateEnum(DateI18NEnum::Format::YDM, date9) == false);
	
    return 0;
}

