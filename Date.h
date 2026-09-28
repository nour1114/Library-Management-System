#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int year, int month, int day);

    bool isValid() const;

    bool isBefore(const Date& other) const;

    std::string toString() const;
};

#endif
