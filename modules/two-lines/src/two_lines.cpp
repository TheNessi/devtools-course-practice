// Copyright 2018 Panov Aleksander

#include <algorithm>
#include "include/two_lines.h"

using std::swap;
using std::max;
using std::min;

Point::Point() : x(0), y(0) {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

inline double orientedArea(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool checkProjection(double startLine1_coord, double endLine1_coord,
    double startLine2_coord, double endLine2_coord) {
    if (startLine1_coord > endLine1_coord)
        swap(startLine1_coord, endLine1_coord);
    if (startLine2_coord > endLine2_coord)
        swap(startLine2_coord, endLine2_coord);
    return (max(startLine1_coord, startLine2_coord)
        <= min(endLine1_coord, endLine2_coord));
}

bool intersect(Point startLine1, Point endLine1,
    Point startLine2, Point endLine2) {
    bool isX, isY;
    isX = checkProjection(startLine1.x, endLine1.x, startLine2.x, endLine2.x);
    isY = checkProjection(startLine1.y, endLine1.y, startLine2.y, endLine2.y);
    double orientedArea1, orientedArea2, orientedArea3, orientedArea4;
    orientedArea1 = orientedArea(startLine1, endLine1, startLine2);
    orientedArea2 = orientedArea(startLine1, endLine1, endLine2);
    orientedArea3 = orientedArea(startLine2, endLine2, startLine1);
    orientedArea4 = orientedArea(startLine2, endLine2, endLine1);
    return
        (isX && isY
         && orientedArea1 * orientedArea2 <= 0
         && orientedArea3 * orientedArea4 <= 0);
}
