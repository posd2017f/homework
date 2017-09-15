#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#include <vector>
#include <string>
#include <sstream>
#include <math.h>

#include <iostream>

typedef struct Coordinate
{
    double x;
    double y;

}vertex;

double distanceOfVertexs(const vertex vertex_1, const vertex vertex_2);

class Shape {

public:

    std::string name = "Shape";

    Shape(std::string shapeName):name(shapeName){}

    std::string getShapeName(){
        return name;
    }

    void setShapeName(std::string shapeName){
        name = shapeName;
    }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string toString() const = 0;

};

class Rectangle : public Shape {

private:

    double x,y,l,w;

public:

    Rectangle(double ulcx, double ulcy, double length, double width, std::string name = "r"):
        Shape(name), x(ulcx), y(ulcy), l(length), w(width){}

    double area() const {return l*w;}

    double perimeter() const {return (2*l)+(2*w);}

    std::string toString() const {
        std::stringstream ss;
        ss << name << "(" << x << " " << y << " " << l << " " << w << ")";
        return ss.str();
    }

};

class Circle : public Shape{

private:

    double cx,cy,r;

public:

    Circle(double centerX, double centerY, double radius, std::string name = "c"):
        Shape(name), cx(centerX), cy(centerY), r(radius){}

    double area() const {return M_PI*r*r;}

    double perimeter() const {return M_PI*r*2;}

    std::string toString() const {
        std::stringstream ss;
        ss << name << "(" << cx << " " << cy << " " << r << ")";
        return ss.str();
    }

};

class Triangle : public Shape {

private:

    vertex v1;
    vertex v2;
    vertex v3;

public:

    Triangle(vertex vertex_A, vertex vertex_B, vertex vertex_C, std::string name = "t"):
        Shape(name), v1(vertex_A), v2(vertex_B), v3(vertex_C) {

            if(isTriangle(vertex_A, vertex_B, vertex_C) == false)
                throw std::string("It's not a triangle.");

        }

    static bool isTriangle(vertex vertex_A, vertex vertex_B, vertex vertex_C){

        double a = distanceOfVertexs(vertex_A, vertex_B);
        double b = distanceOfVertexs(vertex_A, vertex_C);
        double c = distanceOfVertexs(vertex_B, vertex_C);

        if((a+b)>c && (a+c)>b && (b+c)>a)
            return true;

        return false;
    }

    double area() const {

        double area;
        double a,b,c,s;

        a = distanceOfVertexs(v1, v2);
        b = distanceOfVertexs(v2, v3);
        c = distanceOfVertexs(v1, v3);

        s = (a + b + c)/(double)2;

        area = sqrt(s * (s-a) * (s-b) * (s-c));
        return area;
    }

    double perimeter() const {

        double sumOfLenghts;
        sumOfLenghts = distanceOfVertexs(v1, v2) + distanceOfVertexs(v2, v3) + distanceOfVertexs(v1, v3);

        return sumOfLenghts;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << name << "(" << v1.x << " " << v1.y << " " << v2.x << " " << v2.y << " " << v3.x << " " << v3.y << ")";
        return ss.str();
    }

};

double sumOfArea(const std::vector<Shape *> & shapes);

double sumOfPerimeter(const std::vector<Shape *> & shapes);

Shape* theLargestArea(const std::vector<Shape *> & shapes);

void sortByDecreasingPerimeter(std::vector<Shape *> & shapes);


#endif // SHAPES_H_INCLUDED
