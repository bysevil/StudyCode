

#include<iostream>
using namespace std;

class Date{
privarter:
	int _day;
	int _month;
	int _year;
};

Date::GetMonthDay(int _year,int _month){
	switch(_month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
			return 29;
		}else{
			return 28;
		}
	}
}

void Date::print(){
	cout << d1._year << '\' << d1._month << '\' << d1._day << endl;
}

void Date::Date(int year, int month, int day){
	_year = year;
	_month = month;
	_day = day;
}

int main(){
	Date d1(2000,2,19);
	d1.print();
	return 0;
}
