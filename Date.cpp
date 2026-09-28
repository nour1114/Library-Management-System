#include "Date.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

Date::Date(int year, int month, int day)
    : year(year),
      month(month),
      day(day) {

    if (!isValid()) {
        throw std::invalid_argument("Invalid date");
    }
}

bool Date::isValid() const {

    if (year < 1) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth;

    if (month == 2) {

        if ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0)) {

            daysInMonth = 29;
        }
        else {
            daysInMonth = 28;
        }
    }
    else if (
        month == 4 ||
        month == 6 ||
        month == 9 ||
        month == 11
    ) {

        daysInMonth = 30;
    }
    else {
        daysInMonth = 31;
    }

    return day >= 1 && day <= daysInMonth;
}

bool Date::isBefore(const Date& other) const {

    if (year != other.year) {
        return year < other.year;
    }

    if (month != other.month) {
        return month < other.month;
    }

    return day < other.day;
}

std::string Date::toString() const {

    std::ostringstream output;

    output << year << "-"
           << std::setfill('0') << std::setw(2) << month << "-"
           << std::setfill('0') << std::setw(2) << day;

    return output.str();
}
