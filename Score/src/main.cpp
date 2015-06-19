
#include "lib/framework.hpp"


int main() {
  AppEnv env(640, 480);
  env.bgColor(Color(0.8f, 0.8f, 0.8f));

  Font font("res/MeiryoConsolas.ttf", 2);
  font.size(100);

  int score = 123;

  while (env.isOpen()) {
    env.begin();
    
    font.draw(std::to_string(score), Vec2f::Zero(), Color::white);

    env.end();
  }
}
