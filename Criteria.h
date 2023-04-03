#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Photo.h"

using namespace std;

class Criteria {
public:
    virtual bool matches(const Photo& p) const = 0;
    virtual void print(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Criteria& c);
};

class Cat_Criteria : virtual public Criteria {
public:
    Cat_Criteria(const string& category);
    virtual bool matches(const Photo& p) const override;
    virtual void print(ostream& os) const override;

private:
    string category;
};

class Date_Criteria : virtual public Criteria {
public:
    Date_Criteria(const Date& start, const Date& end);
    virtual bool matches(const Photo& p) const override;
    virtual void print(ostream& os) const override;

private:
    Date start;
    Date end;
};

class CandD_Criteria : public Date_Criteria, public Cat_Criteria {
public:
    CandD_Criteria(const Date& start, const Date& end, const string& category);
    virtual bool matches(const Photo& p) const override;
    virtual void print(ostream& os) const override;
};

#endif
