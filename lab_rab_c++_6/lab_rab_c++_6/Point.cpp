#include "Point.h"

Point::Point(int r, int c) : row(r), col(c) {}

bool Point::operator==(const Point& other) const {
    return row == other.row && col == other.col;
}