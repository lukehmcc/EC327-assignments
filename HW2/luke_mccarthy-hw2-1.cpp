#include "hw2_structs.h"

Rectangle translate(Rectangle rectangle, int xTranslation, int yTranslation) {
  Point newLowerLeft = createPoint(rectangle.lowerLeft.x + xTranslation,
                                   rectangle.lowerLeft.y + yTranslation);
  Point newUpperRight = createPoint(rectangle.upperRight.x + xTranslation,
                                    rectangle.upperRight.y + yTranslation);
  return createRectangle(newLowerLeft, newUpperRight);
}
