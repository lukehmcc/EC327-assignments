#include "examextra_problem1.h"

int average(int a, int b) { return (a + b) / 2; }
float average(int a, float b) { return ((float)a + b) / 2; }
float average(int a, double b) { return ((float)a + b) / 2; }
float average(float a, int b) { return (a + (float)b) / 2; }
float average(double a, int b) { return (a + (float)b) / 2; }
double average(float a, double b) { return (a + b) / 2; }
double average(double a, double b) { return (a + b) / 2; }
