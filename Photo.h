#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Photo {
		
	public:
		//constructor
        Photo(const string& title, const string& category, const Date& date, const string& content);
        Photo(const Photo&);
		
		bool equals(const string& title) const;
        const Date& getDate() const;
        const string& getCategory() const;
        void print(ostream& os) const;
        void display(ostream& os) const;
	
	private:
	
		//variables
		string title;
		string category;
		string content;
		Date date;
	
};

// stream insertion operator overload
ostream& operator<<(ostream& os, const Photo& p);

#endif
