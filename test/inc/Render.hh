#ifndef _RENDER_H_
#define _RENDER_H_

#include "ConvexHull.hh"
#include <SFML/Graphics.hpp>

class Render {
public:
  Render(unsigned int width, unsigned int height);
  ~Render() = default;

  void run();

private:
  sf::RenderWindow _window;
  std::vector<sf::CircleShape> points;
  std::vector<Point> positions;
  ConvexHull hull;
};

#endif /* _RENDER_H_ */
