#include "lab4_problem3.h"

Student::Student(std::string inName) { name = inName; }
Student::Student(std::string inName, int inScore) {
  name = inName;
  addQuizScore(inScore);
}
void Student::addQuizScore(int submittedGrade) {
  grades.push_back(submittedGrade);
}
float Student::getAverageScore() {
  if (grades.empty()) {
    return 0;
  }
  float avgScore =
      (float)(std::accumulate(grades.begin(), grades.end(), 0)) / grades.size();
  return avgScore;
}
