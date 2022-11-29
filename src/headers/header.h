#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "./globalvariables.h"

void init();
void display();
SideLen len(Point p, double teta, int **map, int size);
double min(double x, double y);

#endif
