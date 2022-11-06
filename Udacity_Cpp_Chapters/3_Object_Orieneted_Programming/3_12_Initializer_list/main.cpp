#include <iostream>
#include <cassert>

using namespace std;

class Date
{
	public: 
		Date (int day, int month, int year) : day(day), month(month), year(year) {}
		int Day()   {return day;}
		int Month() {return month;}
		int Year()  {return year;}
		void Day   (int day);
		void Month (int month);
		void Year  (int year);


	private:
		int day{1};
		int month{1};
		int year{0};
};

void Date::Day(int day)
{
	Date::day = day;
}

void Date::Month(int month)
{
	Date::month = month;
}

void Date::Year(int year)
{
	Date::year = year;
}

int main ()
{
	Date date(16, 04, 2022);
	cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\r\n";

	date.Day(18);
	cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\r\n";
	return 0;
}
