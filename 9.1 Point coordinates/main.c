#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a):
typedef struct Point{
    double x;
    double y;
}Point;

// b):
void printPoint(Point p){
    printf("(%.1f, %.1f)\n", p.x, p.y);
}

// c):
Point createPoint(double x, double y){
    Point p = {x, y};
    return p;
}

// d):
double getDistance(Point a, Point b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main()
{

    // a):
    Point p1 = {2.0, -3.0};
    Point p2 = {-4.0, 5.0};

    // b):
    printPoint(p1);
    printPoint(p2);

    // c):
    double x1 = 2.0, y1 = -3.0;
    double x2 = -4.0, y2 = 5.0;

    Point p1c = createPoint(x1, y1);
    Point p2c = createPoint(x2, y2);

    // d):
     printf("%.1f", getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0)));

    return 0;
}
