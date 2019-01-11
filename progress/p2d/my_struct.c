/*
This file should contain the 9 functions defined in prototypes.h

Funtions are:

void InitializeCircle(Circle *, double radius, double originX, double originY);
void InitializeRectangle(Rectangle *, double minX, double maxX, double minY, double maxY);
void InitializeTriangle(Triangle *, double pt1X, double pt2X, double minY, double maxY);

double GetCircleArea(Circle *);
double GetRectangleArea(Rectangle *);
double GetTriangleArea(Triangle *);

void GetCircleBoundingBox(Circle *, double *);
void GetRectangleBoundingBox(Rectangle *, double *);
void GetTriangleBoundingBox(Triangle *, double *);
*/

#include <prototypes.h>
#include <stdio.h>

//Rectangle

void InitializeRectangle(struct Shape *s, double minX, double maxX, double minY, double maxY){
   	s->su.r.minX = minX;
   	s->su.r.maxX = maxX;
   	s->su.r.minY = minY;
   	s->su.r.maxY = maxY;

    s->st = TypeRectangle;
    s->ft.GetArea = GetRectangleArea;
    s->ft.GetBoundingBox = GetRectangleBoundingBox;
}

double GetRectangleArea(struct Shape *s){
    double width = (s->su.r.maxX-s->su.r.minX);
    double height = (s->su.r.maxY-s->su.r.minY);
    double area = width*height;
   	return area;
}

void GetRectangleBoundingBox(struct Shape *s, double *bbox){
   	bbox[0] = s->su.r.minX;
   	bbox[1] = s->su.r.maxX;
   	bbox[2] = s->su.r.minY;
   	bbox[3] = s->su.r.maxY;
}

//Circle

void InitializeCircle(struct Shape *s, double radius, double originX, double originY){
   	s->su.c.radius = radius;
   	s->su.c.originX = originX;
   	s->su.c.originY = originY;

    s->st = TypeCircle;
    s->ft.GetArea = GetCircleArea;
    s->ft.GetBoundingBox = GetCircleBoundingBox;
}

double GetCircleArea(struct Shape *s){
    double pi = 3.14159;
    double radius = s->su.c.radius;
    double area = pi*radius*radius;
   	return area;
}

void GetCircleBoundingBox(struct Shape *s, double *bbox){
    double minX = (s->su.c.originX-s->su.c.radius);
    double maxX = (s->su.c.originX+s->su.c.radius);
    double minY = (s->su.c.originY-s->su.c.radius);
    double maxY = (s->su.c.originY+s->su.c.radius);
   	bbox[0] = minX;
   	bbox[1] = maxX;
   	bbox[2] = minY;
   	bbox[3] = maxY;
}

//Triangle

void InitializeTriangle(struct Shape *s, double pt1X, double pt2X, double minY, double maxY){
 	  s->su.t.pt1X = pt1X;
   	s->su.t.pt2X = pt2X;
   	s->su.t.minY = minY;
   	s->su.t.maxY = maxY;

    s->st = TypeTriangle;
    s->ft.GetArea = GetTriangleArea;
    s->ft.GetBoundingBox = GetTriangleBoundingBox;
}

double GetTriangleArea(struct Shape *s){
    double base = (s->su.t.pt2X-s->su.t.pt1X);
    double height = (s->su.t.maxY-s->su.t.minY);
    double area = (base*height)/2;
   	return area;
}

void GetTriangleBoundingBox(struct Shape *s, double *bbox){
   	bbox[0] = s->su.t.pt1X;
   	bbox[1] = s->su.t.pt2X;
   	bbox[2] = s->su.t.minY;
   	bbox[3] = s->su.t.maxY;
}
