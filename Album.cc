#include "Album.h"

Album::Album(const std::string &title, const std::string &description)
    : title(title), description(description) {
}

bool Album::equals(const std::string &title) const {
    return this->title == title;
}

void Album::addPhoto(Photo *photo) {
    photos.add(photo);
}

Photo *Album::getPhoto(int index) const {
    return photos[index];
}

int Album::size() const {
    return photos.size();
}

void Album::print(std::ostream &out) const {
    out << "Album: " << title << std::endl;
    out << "Description: " << description << std::endl;
    out << "Number of Photos: " << size() << std::endl;
}

void Album::display(std::ostream &out) const {
    // print(out);
    // for (int i = 0; i < size(); i++) {
    //     photos[i]->display();
    // }
        out << "Album Title: " << title << endl;
    out << "Album Description: " << description << endl;

    for (int i = 0; i < photos.size(); i++) {
        out << "Photo #" << i+1 << ":" << endl;
        photos[i]->display(out);
        out << endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Album &album) {
    album.print(out);
    return out;
}
