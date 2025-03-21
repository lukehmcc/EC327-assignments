#ifndef HW2_PROBLEM1_H
#define HW2_PROBLEM1_H
#include "hw2_structs.h"
/**
* Given a rectangle, return a new rectangle that represents the
* translation of the original one by xTranslation along the
* x-axis and yTranslation along the y-axis.
*
* For example, given a rectangle with bottom left corner of (-3,8)
* and upper right corner of (2, 20), an xTranslation of 4 and
* yTranslation of -10, this function should return a rectangle with
* bottom left corner at (1, -2) and upper right corner at (6, 10)
*
* If the passed in rectangle is illegal, i.e. it is current left
* corner is not really the left corner, the behavior is undefined.
*
* @param rectangle original rectangle
* @param xTranslation translation along the x-axis
* @param yTranslation translation along the y-axis
* @return a new rectangle representing the translation of
* the original one.
*/
Rectangle translate(Rectangle rectangle, int xTranslation, int
yTranslation);
#endif //HW2_PROBLEM1_H
