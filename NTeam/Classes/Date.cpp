//
// Created by Rui Pinto on 10/11/2019.
//

#include "Date.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Date::Date()
{

}

Date::Date(string date) {

    istringstream Dat(date);
    string dayS, monthS, yearS;
    getline(Dat, yearS, '/');
    getline(Dat, monthS, '/');
    getline(Dat, dayS, '/');

    if(Dat.fail())
        throw WrongDateFormat(date); // Throw exception on error
    else
    {
        try {
            day = (unsigned short)stoi(dayS);
            month = (unsigned short)stoi(monthS);
            year = (unsigned short)stoi(yearS);
        }
        catch(...) {
            throw WrongDateFormat(date);
        }
    }

}


Date::Date(unsigned short day, unsigned short month, unsigned year) {

    this->day = day;
    this->month = month;
    this->year = year;
}


unsigned short Date::getDay() const {

    return day;

}


unsigned short Date::getMonth() const {

    return month;

}

unsigned Date::getYear() const {

    return year;

}

string Date::getDate() const
{
    return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}


void Date::setDay(unsigned short &day) {

    this->day = day;

}
void Date::setMonth(unsigned short &month) {

    this->month = month;

}

void Date::setYear(unsigned &year) {

    this->year = year;

}


ostream& operator<<(ostream& out, const Date & date) {

    out << date.year << "/" << date.month << "/" << date.day;
    return out;
}
