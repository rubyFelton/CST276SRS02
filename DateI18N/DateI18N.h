#pragma once
#include "chrono"
#include <string>
#include <sstream>
#include "vector"

class DateI18N
{
private:
	std::vector<std::string> delimiterList{ "/", ".", "_", " " };

public:
	DateI18N();
	~DateI18N();
	std::vector<std::string> splitDate(std::string date);
	static int toInt(std::string str);
	static int max_day(const std::string year, const std::string month) noexcept;
	bool is_year(std::string str);
	bool is_month(std::string str);
	bool is_day(std::string month, std::string year, std::string str);
	virtual bool Validate(std::string date) = 0;
	virtual std::vector<std::string> getDelimiter() = 0;
};
