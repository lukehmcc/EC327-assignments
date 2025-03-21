#include "hw2_problem2.h"

Rectangle copyRectangle(const Rectangle *rectangle);

bool scale(Rectangle *rectangle, double xScale, double yScale) {
  // Save the rectangle state
  Rectangle copyRect = copyRectangle(rectangle);
  rectangle->upperRight.x =
      (rectangle->upperRight.x - rectangle->lowerLeft.x) * xScale +
      rectangle->lowerLeft.x;
  rectangle->upperRight.y =
      (rectangle->upperRight.y - rectangle->lowerLeft.y) * yScale +
      rectangle->lowerLeft.y;
  // check if return values are correct
  if (rectangle->lowerLeft.x < rectangle->upperRight.x &&
      rectangle->lowerLeft.y < rectangle->upperRight.y) {
    return true;
  } else {
    *rectangle = copyRect;
    return false;
  }
}

Rectangle copyRectangle(const Rectangle *rectangle) {
  // Create a new Rectangle object and copy the values
  Rectangle newRectangle;
  newRectangle.lowerLeft = rectangle->lowerLeft;
  newRectangle.upperRight = rectangle->upperRight;
  return newRectangle;
}
