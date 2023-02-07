#include <iostream>

#include "Game.hpp"

Game *game = nullptr;

int main()
{
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 framestart;
  int frameTime;

  game = new Game();

  game->init("teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);

  while (game->running())
  {
    framestart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - framestart;

    if (frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();

  return 0;
}
