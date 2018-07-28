#include "stdafx.h"
#include "DateI18N.h"
#include "YMDValidator.h"
#include "DMYValidator.h"
#include "MDYValidator.h"
#include "YDMValidator.h"
#include <cassert>

//using GOF strategy patterns
int main()
{
	//YMD, DMY, MDY, YDM

	std::string date1 = "2020/12/31"; //ymd
	std::string date2 = "2120-12-31"; //out of year bound
	std::string date3 = "20/12/31"; //no 4 digit year
	std::string date4 = "12.31.2020"; //mdy
	std::string date5 = "31/12/2020"; //dmy
	std::string date6 = "2020/31/12"; //ydm
	std::string date7 = "02-28-2020"; //mdy
	std::string date8 = "2/30/2020"; //out of day bound
	std::string date9 = "09/31/2020"; //out of day bound

	YMDValidator ymd_validator;
	DMYValidator dmy_validator;
	MDYValidator mdy_validator;
	YDMValidator ydm_validator;


	assert(ymd_validator.Validate(date1) == true);
	assert(mdy_validator.Validate(date1) == false);
	assert(ydm_validator.Validate(date1) == false);
	assert(dmy_validator.Validate(date1) == false);	
	
	assert(ymd_validator.Validate(date2) == false);
	assert(mdy_validator.Validate(date2) == false);
	assert(ydm_validator.Validate(date2) == false);
	assert(dmy_validator.Validate(date2) == false);	
	
	assert(ymd_validator.Validate(date3) == false);
	assert(mdy_validator.Validate(date3) == false);
	assert(ydm_validator.Validate(date3) == false);
	assert(dmy_validator.Validate(date3) == false);	
	
	assert(ymd_validator.Validate(date4) == false);
	assert(mdy_validator.Validate(date4) == true);
	assert(ydm_validator.Validate(date4) == false);
	assert(dmy_validator.Validate(date4) == false);	
	
	assert(ymd_validator.Validate(date5) == false);
	assert(mdy_validator.Validate(date5) == false);
	assert(ydm_validator.Validate(date5) == false);
	assert(dmy_validator.Validate(date5) == true);	
	
	assert(ymd_validator.Validate(date6) == false);
	assert(mdy_validator.Validate(date6) == false);
	assert(ydm_validator.Validate(date6) == true);
	assert(dmy_validator.Validate(date6) == false);	
	
	assert(ymd_validator.Validate(date7) == false);
	assert(mdy_validator.Validate(date7) == true);
	assert(ydm_validator.Validate(date7) == false);
	assert(dmy_validator.Validate(date7) == false);	
	
	assert(ymd_validator.Validate(date8) == false);
	assert(mdy_validator.Validate(date8) == false);
	assert(ydm_validator.Validate(date8) == false);
	assert(dmy_validator.Validate(date8) == false);	
	
	assert(ymd_validator.Validate(date9) == false);
	assert(mdy_validator.Validate(date9) == false);
	assert(ydm_validator.Validate(date9) == false);
	assert(dmy_validator.Validate(date9) == false);	
	
	return 0;
}