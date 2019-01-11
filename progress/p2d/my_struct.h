/* This file should contain your struct definitions for Circle, Triangle, and
   Rectangle */

struct Rectangle;
struct Circle;
struct Triangle;
struct Shape;

typedef struct{
   	double minX, maxX, minY, maxY;
} Rectangle;

typedef struct{
   	double radius, originX, originY;
} Circle;

typedef struct{
   	double pt1X, pt2X, minY, maxY;
} Triangle;

//New code for 2D

typedef union{
    Rectangle r;
    Circle c;
    Triangle t;
} ShapeUnion;

typedef struct{
    void (*GetBoundingBox)(struct Shape*, double *);
    double (*GetArea)(struct Shape *);
} FunctionTable;

typedef enum{
    TypeRectangle,
    TypeCircle,
    TypeTriangle
} ShapeType;

struct Shape{
    ShapeUnion su;
    FunctionTable ft;
    ShapeType st;
};
