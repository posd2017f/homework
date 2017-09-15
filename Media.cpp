#include "include/Media.h"
#include <iostream>

/**< ShapeMedia */
Shape * ShapeMedia::getShape(){
    return shape;
}

double ShapeMedia::area() const{
    return shape->area();
}

double ShapeMedia::perimeter() const{
    return shape->perimeter();
}


/**< ComboMedia */
ComboMedia::ComboMedia() {
    std::vector<Media *> instance;
    medias = instance;
}

void ComboMedia::add(Media * ma){
    medias.push_back(ma);
}

std::vector<Media *> ComboMedia::getMedias(){
    return medias;
}

double ComboMedia::area() const{
    double total = 0;

    for (Media * mp : medias)
        total += mp->area();

    return total;
}

double ComboMedia::perimeter() const{
    double total = 0;

    for (Media * mp : medias)
        total += mp->perimeter();

    return total;
}

