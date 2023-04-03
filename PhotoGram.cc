#include "PhotoGram.h"
#include "defs.h"

// Constructor
PhotoGram::PhotoGram()
{
}

// Destructor
PhotoGram::~PhotoGram()
{
    for (int i = 0; i < albums.size(); i++) {
        delete albums[i];
    }
    for (int i = 0; i < photos.size(); i++) {
        delete photos[i];
    }
}

// Add an album
bool PhotoGram::addAlbum(const string& title, const string& description)
{
    if (albums.size() == MAX_ARRAY){
        cout << "Album array is full. Cannot add new album." << endl;
        return false;
    }
    Album* album = mediaFactory.createAlbum(title, description);
    albums.add(album);
    return true;
}

// Add photos to an album
void PhotoGram::addToAlbum(int index, Array<Photo*>& photos)
{
    if (index < 0 || index >= albums.size()) {
        cout << "Invalid album index." << endl;
        return;
    }
    Album* album = albums[index];
    for (int i = 0; i < photos.size(); i++) {
        album->addPhoto(photos[i]);
    }
}

// Remove an album
bool PhotoGram::deleteAlbum(int index)
{
    if (index < 0 || index >= albums.size()) {
        cout << "Invalid album index." << endl;
        return false;
    }

    delete albums[index];
    albums.remove(albums[index]);
    return true;
}

// Upload a photo
bool PhotoGram::uploadPhoto(const string& title)
{
    if (photos.size() == MAX_ARRAY){
        cout << "Photo array is full. Cannot add new photo." << endl;
        return false;
    }
    Photo* photo = mediaFactory.uploadPhoto(title);
    photos.add(photo);
    return true;
}

// Get photos that match a criteria
void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo*>& photos)
{
    for (int i = 0; i < this->photos.size(); i++) {
        if (criteria.matches(*this->photos[i])) {
            photos.add(this->photos[i]);
        }
    }
}

// Display an album
void PhotoGram::displayAlbum(int index, View& view) const
{
    if (index < 0 || index >= albums.size()) {
        cout << "Invalid album index." << endl;
        return;
    }
    view.displayAlbum(*albums[index]);
}

// Print all albums using the given View
int PhotoGram::printAlbums(View& view) const {
    view.printAlbums(albums);
    return albums.size();
}

// Display the photo at the given index using the given View
void PhotoGram::displayPhoto(int index, View& view) const {
    if (index < 0 || index >= photos.size()) {
        cout << "Invalid photo index." << endl;
        return;
    }
    view.displayPhoto(*photos[index]);
}

// Print all photos using the given View
int PhotoGram::printPhotos(View& view) const {
    view.printPhotos(photos);
    return photos.size();
}
