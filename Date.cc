#include "Date.h"

// Constructor
Date::Date() {
	day = 1;
	month = 1;
	year = 1900;
}

// Constructor
Date::Date(int year, int month, int day) {
	setDate(year, month, day);
}

// Copy Constructor
Date::Date(const Date& d) {
	setDate(d);
}

// Setter for day
void Date::setDay(int d) {
	day = d;
}

// Setter for month
void Date::setMonth(int m) {
	month = m;
}

// Setter for year
void Date::setYear(int y) {
	year = y;
}

// Setter for all three fields
void Date::setDate(int y, int m, int d) {
	setYear(y);
	setMonth(m);
	setDay(d);
}

// Setter for all three fields using another Date object
void Date::setDate(const Date& d) {
	setDate(d.getYear(), d.getMonth(), d.getDay());
}

// Getter for day
int Date::getDay() const {
	return day;
}

// Getter for month
int Date::getMonth() const {
	return month;
}

// Getter for year
int Date::getYear() const {
	return year;
}

// Function to get the name of the month
string Date::getMonthName() const {
	string monthNames[] = {"January", "February", "March", "April", "May", "June", 
	                       "July", "August", "September", "October", "November", "December"};
	return monthNames[month-1];
}

// Function to increment the date by one day
void Date::incDate() {
	day++;
	if(day > getMaxDay()) {
		day = 1;
		month++;
		if(month > 12) {
			month = 1;
			year++;
		}
	}
}

// Function to add days to the date
void Date::addDays(int numDays) {
	for(int i = 0; i < numDays; i++) {
		incDate();
	}
}

// Function to check if one date is less than another
bool Date::lessThan(const Date& d) const {
	if(year < d.getYear()) {
		return true;
	} else if(year > d.getYear()) {
		return false;
	} else {
		if(month < d.getMonth()) {
			return true;
		} else if(month > d.getMonth()) {
			return false;
		} else {
			if(day < d.getDay()) {
				return true;
			} else {
				return false;
			}
		}
	}
}

// Function to check if one date is equal to another
bool Date::equals(const Date& d) const {
	if(year == d.getYear() && month == d.getMonth() && day == d.getDay()) {
		return true;
	} else {
		return false;
	}
}

// Function to print the date
void Date::print() const {
	cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day;
}

// Overloaded operator <
bool Date::operator<(const Date& d) const {
	return lessThan(d);
}

// Overloaded operator <=
bool Date::operator<=(const Date& d) const {
	return lessThan(d) || equals(d);
}

// Overloaded operator ==
bool Date::operator==(const Date& d) const {
	return equals(d);
}

// Overloaded operator !=
bool Date::operator!=(const Date& d) const {
	return !equals(d);
}

// Overloaded operator >
bool Date::operator>(const Date& d) const {
    if (year > d.year) {
        return true;
    } else if (year == d.year && month > d.month) {
        return true;
    } else if (year == d.year && month == d.month && day > d.day) {
        return true;
    } else {
        return false;
    }
}

// Overloaded operator >=
bool Date::operator>=(const Date& d) const {
    if (year > d.year) {
        return true;
    }
    else if (year < d.year) {
        return false;
    }
    else {
        if (month > d.month) {
            return true;
        }
        else if (month < d.month) {
            return false;
        }
        else {
            if (day >= d.day) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d.getMonthName() << " " << d.getDay() << ", " << d.getYear();
    return os;
}

int Date::getMaxDay() const{
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
