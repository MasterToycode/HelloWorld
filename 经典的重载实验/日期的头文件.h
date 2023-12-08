#include<iostream>
#include<iomanip>
using namespace std;
class CDate 
{
protected:
    int year;
    int month;
    int day;
public:
    CDate(int y, int m, int d) : year(y), month(m), day(d) {}

    void DisplayDate() const
    {
        cout << setw(4) << setfill('0') << year << "-"
            << setw(2) << setfill('0') << month << "-"
            << setw(2) << setfill('0') << day << endl;
    }

    // Helper function to calculate the number of days in a month
    int daysInMonth(int year, int month) {
        if (month == 2) {
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;  // February has 29 days in a leap year
            }
            else {
                return 28;  // February has 28 days in a non-leap year
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) 
        {
            return 30;  // April, June, September, and November have 30 days
        }
        else 
        {
            return 31;  // January, March, May, July, August, October, and December have 31 days
        }
    }

    // Other member functions for weekday calculation, format selection, etc.

    // Overloaded operators
    bool operator<(const CDate& other) const 
    {
        // Implementation of <
        if (year < other.year)
            return true;
        else if (year > other.year)
            return false;

        if (month < other.month)
            return true;
        else if (month > other.month)
            return false;

        return day < other.day;
    }

    CDate CDate::operator+(int days) const 
    {
        CDate result = *this;  // Create a copy of the current date

        // Add 'days' to the current date
        result.day += days;

        // Take care of month and year changes
        while (result.day > daysInMonth(result.year, result.month)) {
            result.day -= daysInMonth(result.year, result.month);
            result.month++;

            if (result.month > 12) 
            {
                result.month = 1;
                result.year++;
            }
        }
        return result;
    }

    CDate CDate::operator-(int days) const 
    {
        CDate result = *this;  // Create a copy of the current date

        // Subtract 'days' from the current date
        result.day -= days;

        // Take care of month and year changes
        while (result.day < 1) {
            result.month--;

            if (result.month < 1) {
                result.month = 12;
                result.year--;
            }

            result.day += daysInMonth(result.year, result.month);
        }

        return result;
    }

    CDate& CDate::operator++()
    {
        // Increment the current date by one day
        day++;

        // Take care of month and year changes
        while (day > daysInMonth(this->year, this->month)) 
        {
            day -= daysInMonth(this->year, this->month);
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }

        return *this;
    }

    CDate& CDate::operator--() 
    {
        // Decrement the current date by one day
        day--;

        // Take care of month and year changes
        while (day < 1) {
            month--;

            if (month < 1) {
                month = 12;
                year--;
            }

            day += daysInMonth(year, month);
        }

        return *this;
    }

};

class CTime 
{
protected:
    int hour;
    int minute;
    int second;

public:
    CTime(int h, int m, int s) : hour(h), minute(m), second(s) {}

    void DisplayTime() const {
        cout << setw(2) << setfill('0') << hour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second << endl;
    }
};

class CDateTime : public CDate, public CTime 
{
public:
    CDateTime(int y, int m, int d, int h, int min, int s)
        : CDate(y, m, d), CTime(h, min, s) {}

    // Display the date and time
    void DisplayDateTime()  
    {
        CDate::DisplayDate();
        CTime::DisplayTime();
    }

    // Overloaded operators
    bool operator==(const CDateTime& other) const 
    {
        return CDate::operator==(other) && CTime::operator==(other);
    }

    bool operator>(const CDateTime& other) const 
    {
        return !(*this <= other);
    }

    bool operator>=(const CDateTime& other) const 
    {
        return (*this > other) || (*this == other);
    }

    bool operator<=(const CDateTime& other) const 
    {
        return (*this < other) || (*this == other);
    }

    bool operator!=(const CDateTime& other) const 
    {
        return !(*this == other);
    }

    CDateTime operator+(int seconds) const 
    {
        CDateTime result = *this;  // Create a copy of the current date and time

        // Add 'seconds' to the current time
        result.second += seconds;

        // Take care of minute, hour, and day changes
        while (result.second >= 60) 
        {
            result.second -= 60;
            result.minute++;

            if (result.minute >= 60) 
            {
                result.minute = 0;
                result.hour++;

                if (result.hour >= 24) 
                {
                    result.hour = 0;
                    result.day++;

                    // Take care of month and year changes
                    while (result.day > daysInMonth(result.year, result.month)) 
                    {
                        result.day -= daysInMonth(result.year, result.month);
                        result.month++;

                        if (result.month > 12) 
                        {
                            result.month = 1;
                            result.year++;
                        }
                    }
                }
            }
        }

        return result;
    }

    CDateTime operator-(int seconds) const 
    {
        CDateTime result = *this;  // Create a copy of the current date and time

        // Subtract 'seconds' from the current time
        result.second -= seconds;

        // Take care of minute, hour, and day changes
        while (result.second < 0) {
            result.second += 60;
            result.minute--;

            if (result.minute < 0) {
                result.minute = 59;
                result.hour--;

                if (result.hour < 0) {
                    result.hour = 23;
                    result.day--;

                    // Take care of month and year changes
                    while (result.day < 1) {
                        result.month--;

                        if (result.month < 1) {
                            result.month = 12;
                            result.year--;
                        }

                        result.day += daysInMonth(result.year, result.month);
                    }
                }
            }
        }
        return result;
    }
};
