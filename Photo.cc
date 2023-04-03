#include "Photo.h"

// constructor
Photo::Photo(const string& title, const string& category, const Date& date, const string& content) {
    this->title = title;
    this->category = category;
    this->date = date;
    this->content = content;
}

// copy constructor
Photo::Photo(const Photo& p){
    this->title = p.title;
    this->category = p.category;
    this->date = p.date;
    this->content = p.content;
}

// check if title matches
bool Photo::equals(const string& title) const { 
    return this->title == title;
}

// get date
const Date& Photo::getDate() const {
    return date;
}

// get category
const string& Photo::getCategory() const {
    return category;
}

// print to output stream
void Photo::print(ostream& os) const {
    os << "Photo title: " << title << endl;
    os << "Category: " << category << endl;
    os << "Date: ";
    date.print();
}

// display to output stream
void Photo::display(ostream& os) const {
    print(os);
    os << endl << "Content: " << content << endl;
}

// stream insertion operator overload
ostream& operator<<(ostream& os, const Photo& p) {
    p.display(os);
    return os;
}
