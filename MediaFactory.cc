
#include "MediaFactory.h"
#include <fstream>
#include <sstream>
#include <limits>

Date MediaFactory::toDate(const string& d){
    stringstream ss;
    ss<<d;
    int year, month, day;
    ss>>year>>month>>day;
    return Date(year, month, day);
}

// 'upload' a photo 
Photo* MediaFactory::uploadPhoto(const string& wanted){
    ifstream file("media/photos.txt");
    string title, category, date, line;
    while (getline(file, title)) {
        if (!getline(file, category) || !getline(file, date)) return nullptr;
        stringstream content;
        bool complete = false;
        while (getline(file, line)) {
            if (line == "!!endrecord!!") { complete = true; break; }
            content << line << endl;
        }
        if (!complete) return nullptr;
        if (title == wanted) return new Photo(title, category, toDate(date), content.str());
    }
    return nullptr;
}

// create Criteria
Criteria* MediaFactory::dateCriteria(const Date& start, const Date& end){
    return new Date_Criteria(start, end);
}
Criteria* MediaFactory::categoryCriteria(const string& cat){
    return new Cat_Criteria(cat);
}
Criteria* MediaFactory::dateAndCatCriteria(const Date& start, const Date& end, const string& cat){
    return new CandD_Criteria(start, end, cat);
}

Album* MediaFactory::createAlbum(const string& title, const string& description){
    return new Album(title, description);
}