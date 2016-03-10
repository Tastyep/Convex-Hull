#include "Render.hh"

#include <iostream>

Render::Render(unsigned int width, unsigned int height)
    : _window(sf::VideoMode(width, height), "Hull Renderer") {}

void Render::run() {
  sf::Event event;
  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Vector2u size = _window.getSize();

  image.create(size.x, size.y, sf::Color::Black);
  texture.create(size.x, size.y);

  _window.setFramerateLimit(25);

  while (_window.isOpen()) {
    _window.clear();
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        _window.close();
      else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right ||
            event.mouseButton.button == sf::Mouse::Left) {
          sf::CircleShape sc(3);

          sc.setPosition(event.mouseButton.x, event.mouseButton.y);
          sc.setFillColor(sf::Color(255, 255, 255));
          this->points.push_back(sc);
        }
      }
    }

    for (const auto &p : this->points)
      _window.draw(p);
    _window.display();
  }
}
