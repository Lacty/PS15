
#include "lib/framework.hpp"

#define SPEED 7

enum Direction {
  Right = 1,
  Left = -1
};

void Move(AppEnv& env, Vec2f& pos, Direction& direction) {
  if (env.isPressKey(GLFW_KEY_W)) { pos.y() += SPEED; }
  if (env.isPressKey(GLFW_KEY_S)) { pos.y() -= SPEED; }
  if (env.isPressKey(GLFW_KEY_D)) {
    pos.x() += SPEED;
    direction = Direction::Right;
  }
  if (env.isPressKey(GLFW_KEY_A)) {
    pos.x() -= SPEED;
    direction = Direction::Left;
  }
}

void Draw(Texture& image, Vec2f& pos, Direction& direction) {
  drawTextureBox(pos.x(), pos.y(), image.width(), image.height(),
                 0, 0, image.width(), image.height(),
                 image,
                 Color::black,
                 0,
                 Vec2f(direction, 1),
                 Vec2f(image.width() * 0.5f,
                 image.height() * 0.5f));
}

int main() {
  AppEnv env(640, 480);
  env.bgColor(Color::white);

  Texture image("res/player.png");
  Vec2f pos = Vec2f::Zero();
  Direction direction = Direction::Right;

  while (env.isOpen()) {
    env.begin();

    Move(env, pos, direction);
    Draw(image, pos, direction);

    env.end();
  }
}
