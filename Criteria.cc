#include "Criteria.h"

ostream& operator<<(ostream& os, const Criteria& c) {
    c.print(os);
    return os;
}

Cat_Criteria::Cat_Criteria(const string& category) : category(category) {}

bool Cat_Criteria::matches(const Photo& p) const {
    return p.getCategory() == category;
}

void Cat_Criteria::print(ostream& os) const {
    os << "Category Criteria: " << category;
}

Date_Criteria::Date_Criteria(const Date& start, const Date& end) : start(start), end(end) {}

bool Date_Criteria::matches(const Photo& p) const {
    return p.getDate() >= start && p.getDate() <= end;
}

void Date_Criteria::print(ostream& os) const {
    os << "Date Criteria: " << start << " to " << end;
}

CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& category)
    : Date_Criteria(start, end), Cat_Criteria(category) {}

bool CandD_Criteria::matches(const Photo& p) const {
    return Date_Criteria::matches(p) && Cat_Criteria::matches(p);
}

void CandD_Criteria::print(ostream& os) const {
    os << "Combined Criteria: ";
    Date_Criteria::print(os);
    os << " and ";
    Cat_Criteria::print(os);
}
