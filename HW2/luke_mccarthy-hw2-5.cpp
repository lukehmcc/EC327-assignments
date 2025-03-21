
#include "hw2_structs.h"
#include <cmath>
#include <sstream>
#include <string>

std::string describeOverlap(Rectangle rectangleOne, Rectangle rectangleTwo) {
  // check if the two rectangles overlap
  bool rect2xLLInBound = rectangleOne.lowerLeft.x <= rectangleTwo.lowerLeft.x &&
                         rectangleOne.upperRight.x >= rectangleTwo.lowerLeft.x;
  bool rect2xURInBound =
      rectangleOne.lowerLeft.x <= rectangleTwo.upperRight.x &&
      rectangleOne.upperRight.x >= rectangleTwo.upperRight.x;
  bool rect2yLLInBound = rectangleOne.lowerLeft.y <= rectangleTwo.lowerLeft.y &&
                         rectangleOne.upperRight.y >= rectangleTwo.lowerLeft.y;
  bool rect2yURInBound =
      rectangleOne.lowerLeft.y <= rectangleTwo.upperRight.y &&
      rectangleOne.upperRight.y >= rectangleTwo.upperRight.y;

  bool rect1xLLInBound = rectangleTwo.lowerLeft.x <= rectangleOne.lowerLeft.x &&
                         rectangleTwo.upperRight.x >= rectangleOne.lowerLeft.x;
  bool rect1xURInBound =
      rectangleTwo.lowerLeft.x <= rectangleOne.upperRight.x &&
      rectangleTwo.upperRight.x >= rectangleOne.upperRight.x;
  bool rect1yLLInBound = rectangleTwo.lowerLeft.y <= rectangleOne.lowerLeft.y &&
                         rectangleTwo.upperRight.y >= rectangleOne.lowerLeft.y;
  bool rect1yURInBound =
      rectangleTwo.lowerLeft.y <= rectangleOne.upperRight.y &&
      rectangleTwo.upperRight.y >= rectangleOne.upperRight.y;

  bool rectInBound = ((rect2xLLInBound || rect2xURInBound) &&
                      (rect2yLLInBound || rect2yURInBound)) ||
                     ((rect1xLLInBound || rect1xURInBound) &&
                      (rect1yLLInBound || rect1yURInBound));
  // debug print all rectInBound values
  if (rectInBound) {
    return "Rectangles overlap.";
  } else {
    // find distance between botton two bottom points
    double LLdistance = std::sqrt(
        std::pow((rectangleTwo.lowerLeft.x - rectangleOne.lowerLeft.x), 2) +
        std::pow((rectangleTwo.lowerLeft.y - rectangleOne.lowerLeft.y), 2));
    std::ostringstream oss;
    oss.precision(2);
    oss << std::fixed << LLdistance;
    return "Rectangles do not overlap.  Distance between lower corners is: " +
           oss.str() + ".";
  }
}
