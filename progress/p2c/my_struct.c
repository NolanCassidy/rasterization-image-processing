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

void InitializeRectangle(Rectangle *r, double minX, double maxX, double minY, double maxY){
   	r->minX = minX;
   	r->maxX = maxX;
   	r->minY = minY;
   	r->maxY = maxY;
}

double GetRectangleArea(Rectangle *r){
    double width = (r->maxX-r->minX);
    double height = (r->maxY-r->minY);
    double area = width*height;
   	return area;
}

void GetRectangleBoundingBox(Rectangle *r, double *bbox){
   	bbox[0] = r->minX;
   	bbox[1] = r->maxX;
   	bbox[2] = r->minY;
   	bbox[3] = r->maxY;
}

//Circle

void InitializeCircle(Circle *c, double radius, double originX, double originY){
   	c->radius = radius;
   	c->originX = originX;
   	c->originY = originY;
}

double GetCircleArea(Circle *c){
    double pi = 3.14159;
    double radius = c->radius;
    double area = pi*radius*radius;
   	return area;
}

void GetCircleBoundingBox(Circle *c, double *bbox){
    double minX = (c->originX-c->radius);
    double maxX = (c->originX+c->radius);
    double minY = (c->originY-c->radius);
    double maxY = (c->originY+c->radius);
   	bbox[0] = minX;
   	bbox[1] = maxX;
   	bbox[2] = minY;
   	bbox[3] = maxY;
}

//Triangle

void InitializeTriangle(Triangle *t, double pt1X, double pt2X, double minY, double maxY){
 	  t->pt1X = pt1X;
   	t->pt2X = pt2X;
   	t->minY = minY;
   	t->maxY = maxY;
}

double GetTriangleArea(Triangle *t){
    double base = (t->pt2X-t->pt1X);
    double height = (t->maxY-t->minY);
    double area = (base*height)/2;
   	return area;
}

void GetTriangleBoundingBox(Triangle *t, double *bbox){
   	bbox[0] = t->pt1X;
   	bbox[1] = t->pt2X;
   	bbox[2] = t->minY;
   	bbox[3] = t->maxY;
}
