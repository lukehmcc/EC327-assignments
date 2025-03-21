#include "hw2_problem1.h"
#include "hw2_problem2.h"
#include "hw2_problem4.h"
#include "hw2_problem5.h"
#include "hw2_structs.h"

// Write a main function that tests each problem
int main() {
  printf("--- Problem 1 ---\n");
  int xTranslation = 1;
  int yTranslation = 5;
  Rectangle rectangle = createRectangle(createPoint(0, 0), createPoint(2, 2));
  Rectangle translatedRectangle =
      translate(rectangle, xTranslation, yTranslation);
  printf("Origional rectangle: %s\n", describeRectangle(rectangle).c_str());
  printf("With offset x=%d, y=%d\n", xTranslation, yTranslation);
  printf("Translated rectangle: %s\n",
         describeRectangle(translatedRectangle).c_str());

  printf("\n--- Problem 2 ---\n");
  int xScale = -2;
  int yScale = 3;
  Rectangle rectangleToScale =
      createRectangle(createPoint(-1, -1), createPoint(2, 2));
  printf("Origional rectangle: %s\n",
         describeRectangle(rectangleToScale).c_str());
  printf("With offset x=%d, y=%d\n", xScale, yScale);
  scale(&rectangleToScale, xScale, yScale);
  printf("Translated rectangle: %s\n",
         describeRectangle(rectangleToScale).c_str());

  printf("\n--- Problem 4 ---\n");
  double inputDouble = .909;
  printf("Int: %f -> bin: %s\n", inputDouble,
         convertToBinaryFraction(inputDouble).c_str());

  printf("\n--- Problem 5 ---\n");
  Rectangle rectangle1 = createRectangle(createPoint(1, 1), createPoint(2, 2));
  Rectangle rectangle2 = createRectangle(createPoint(0, 0), createPoint(3, 3));
  printf("First rectangle: %s\nSecond rectangle: %s\nOverlap results: %s\n\n",
         describeRectangle(rectangle1).c_str(),
         describeRectangle(rectangle2).c_str(),
         describeOverlap(rectangle1, rectangle2).c_str());
  return 0;
}
