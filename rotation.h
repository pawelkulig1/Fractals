#ifndef ROTATION_H
#define ROTATION_H

#include <math.h>
#include <stdio.h>

#define PI 3.14159265

int add(int x, int y); 
/*Function adds two number and returns only last digit*/

void rotate_square_array_right(int n, int array[][n]);
/* Rotates square array*/


void rotate_pixel(int *x, int *y ,int x_pocz, int y_pocz, double angle);
/*Takes cordinates x, y and rotates pixel by angle around 0,0*/

#endif
