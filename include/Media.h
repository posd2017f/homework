#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED

#include "Shapes.h"

class MediaVisitor;

class Media {

public:

    virtual double area() const = 0;
    virtual double perimeter () const = 0;
    // virtual void accept(MediaVisitor * mv) = 0;

};

class ShapeMedia : public Media {

private:

    Shape * shape;

public:

    ShapeMedia(Shape * sh):shape(sh){}

    Shape * getShape();

    double area() const;

    double perimeter() const;

};

class ComboMedia : public Media {

private:

    std::vector<Media *> medias;

public:

    ComboMedia();

    ComboMedia(std::vector<Media *> & mds): medias(mds){}

    void add(Media * ma);

    void removeMedia(Media * ma);

    std::vector<Media *> getMedias();

    double area() const;

    double perimeter() const;

};

class TextMedia : public Media {
private:
    Rectangle boundingBox;

    std::string text;

public:

    TextMedia(Rectangle boundingBox, std::string text):boundingBox(boundingBox), text(text){}

    std::string getText();

    double area() const;

    double perimeter() const;

};


#endif // MEDIA_H_INCLUDED
