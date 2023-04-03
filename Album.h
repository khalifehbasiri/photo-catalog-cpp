#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <iostream>
#include "Array.h"
#include "Photo.h"

class Album {
public:
    Album(const std::string &title, const std::string &description);

    bool equals(const std::string &title) const;
    void addPhoto(Photo *photo);
    Photo *getPhoto(int index) const;
    int size() const;
    void print(std::ostream &out) const;
    void display(std::ostream &out) const;

private:
    std::string title;
    std::string description;
    Array<Photo *> photos;
};

std::ostream &operator<<(std::ostream &out, const Album &album);

#endif
