#pragma once
#ifndef POINT_H
#define POINT_H

struct Point {
    int row, col;

    Point(int r, int c);

    bool operator==(const Point& other) const;
};

#endif // POINT_H - конец