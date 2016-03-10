#ifndef _RENDER_H_
#define _RENDER_H_

#include <SFML/Graphics.hpp>

class Render {
public:
  Render(unsigned int width, unsigned int height);
  ~Render() = default;

  void run();

private:
  sf::RenderWindow _window;
  std::vector<sf::CircleShape> points;
};

#endif /* _RENDER_H_ */
