/* This file should contain your struct definitions for Circle, Triangle, and
   Rectangle */

struct Rectangle;
struct Circle;
struct Triangle;

typedef struct{
   	double minX, maxX, minY, maxY;
} Rectangle;

typedef struct{
   	double radius, originX, originY;
} Circle;

typedef struct{
   	double pt1X, pt2X, minY, maxY;
} Triangle;
