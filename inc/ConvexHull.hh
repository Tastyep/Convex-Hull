#ifndef CONVEXHULL_HH_
#define CONVEXHULL_HH_

#include <vector>

struct Point {
  int x;
  int y;

  bool operator<(const Point &p) const {
    return (x < p.x || (x == p.x && y < p.y));
  }
};

class ConvexHull {
public:
  ConvexHull(const std::vector<Point> &points);

  ~ConvexHull() = default;
  ConvexHull(const ConvexHull &other) = default;
  ConvexHull(ConvexHull &&other) = default;
  ConvexHull &operator=(const ConvexHull &other) = default;
  ConvexHull &operator=(ConvexHull &&other) = default;

  const std::vector<Point> &computeHull();

private:
  int cross(const Point &O, const Point &A, const Point &B) const;

private:
  std::vector<Point> points;
  std::vector<Point> hull;
};

#endif /* end of include guard: CONVEXHULL_HH_ */
