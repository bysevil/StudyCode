#include"Date.h"

int Date::GetMonthDay(int year, int month) {
	int MonthDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		MonthDay[1] = 29;
	}
	return MonthDay[month-1];
}

Date::Date(int year, int month, int day){
	if (month > 0 && month <= 12 && day > 0 && day <= GetMonthDay(year, month)) {
		_year = year;
		_month = month;
		_day = day;
	}
	else {
		std::cout << "日期非法" << std::endl;
	}
}

Date::Date(const Date& d) 
	:_year(d._year)
	,_month(d._month)
	,_day(d._day){
}

Date& Date::operator=(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date::~Date() {
	_year = 0;
	_month = 0;
	_day = 0;
}

Date& Date::operator+=(int day) {
	if (day < 0) {
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {
		_day -= GetMonthDay(_year, _month);
		if (_month != 12) {
			_month++;
		}
		else {
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day) {
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date Date::operator-(int day) {
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator-=(int day) {
	if (day < 0) {
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0 ) {
		_day += GetMonthDay(_year, _month);
		if (_month != 1) {
			_month--;
		}
		else {
			_month = 12;
			_year--;
		}
	}
	return *this;
}

Date& Date::operator++() {
	*this += 1;
	return *this;
}

Date Date::operator++(int) {
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date Date::operator--(int) {
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

Date& Date::operator--() {
	*this -= 1;
	return *this;
}

bool Date::operator>(const Date& d) {
	return _year > d._year
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day);
}
bool Date::operator==(const Date& d) {
	return _year == d._year 
		&& _month == d._month 
		&& _day == d._day;
}

bool Date::operator>= (const Date & d) {
	return *this > d || *this == d;
}

bool Date::operator < (const Date& d) {
	return !(*this > d || *this == d);
}


bool Date::operator <= (const Date& d) {
	return *this < d || *this == d;
}

bool Date::operator != (const Date& d) {
	return !(*this == d);
}

int Date::operator-(const Date& d) {
	int day = 0;
	while (*this > d) {
		(*this)--;day++;
	}
	while (*this < d) {
		(*this)++; day--;
	}
	return day;
}
void Date::print() {
	std::cout << _year << '-' << _month << '-' << _day << std::endl;
}
