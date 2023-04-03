#ifndef PHOTOGRA_H
#define PHOTOGRA_H

#include <string>
#include "Array.h"
#include "Album.h"
#include "MediaFactory.h"
#include "Criteria.h"
#include "View.h"

using namespace std;

class PhotoGram {
    public:
        PhotoGram();
        ~PhotoGram();

        bool addAlbum(const string& title, const string& description);
        void addToAlbum(int index, Array<Photo*>& photos);
        bool deleteAlbum(int index);
        bool uploadPhoto(const string& title);
        void getPhotos(const Criteria& criteria, Array<Photo*>& photos);
        void displayAlbum(int index, View& view) const;
        int printAlbums(View& view) const;
        void displayPhoto(int index, View& view) const;
        int printPhotos(View& view) const;

    private:
        Array<Album*> albums;
        Array<Photo*> photos;
        MediaFactory mediaFactory;
};

#endif



