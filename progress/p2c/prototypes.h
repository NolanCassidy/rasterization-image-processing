
#include <my_struct.h>

void InitializeCircle(Circle *, double radius, double originX, double originY);
void InitializeRectangle(Rectangle *, double minX, double maxX, double minY, double maxY);
void InitializeTriangle(Triangle *, double pt1X, double pt2X, double minY, double maxY);

double GetCircleArea(Circle *);
double GetRectangleArea(Rectangle *);
double GetTriangleArea(Triangle *);

void GetCircleBoundingBox(Circle *, double *);
void GetRectangleBoundingBox(Rectangle *, double *);
void GetTriangleBoundingBox(Triangle *, double *);

