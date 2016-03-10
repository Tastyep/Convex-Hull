#include "ConvexHull.hh"

#include <algorithm>

ConvexHull::ConvexHull(const std::vector<Point> &points) : points(points) {
  std::sort(this->points.begin(), this->points.end());
}

int ConvexHull::cross(const Point &O, const Point &A, const Point &B) const {
  return (A.x - O.x) * (B.y - O.y) * (A.y - O.y) * (B.x - O.x);
}

const std::vector<Point> &ConvexHull::computeHull() {
  int nbPoint = this->points.size();
  int k = 0;

  this->hull.clear();
  this->hull.reserve(2 * nbPoint);

  // Build lower hull
  for (int i = 0; i < nbPoint; ++i) {
    while (k >= 2 &&
           cross(this->hull[k - 2], this->hull[k - 1], this->points[i]) <= 0)
      --k;
    this->hull[k] = this->points[i];
    ++k;
  }

  // Build upper hull
  for (int i = nbPoint - 2, t = k + 1; i >= 0; i--) {
    while (k >= t &&
           cross(this->hull[k - 2], this->hull[k - 1], this->points[i]) <= 0)
      --k;
    this->hull[k] = this->points[i];
    ++k;
  }

  this->hull.resize(k);
  return this->hull;
}