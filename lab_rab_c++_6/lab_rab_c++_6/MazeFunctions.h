#pragma once

#ifndef MAZE_FUNCTIONS_H
#define MAZE_FUNCTIONS_H

#include <vector>
#include "Point.h"

using namespace std;

bool isValid(int row, int col, const vector<vector<int>>& maze);
bool findShortestPath(const vector<vector<int>>& maze, Point start, Point end, vector<Point>& path);
void printMaze(const vector<vector<int>>& maze, const vector<Point>& path);

#endif // MAZE_FUNCTIONS_H - конец