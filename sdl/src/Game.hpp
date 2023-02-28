#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS.hpp"
#include "Components.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

class Game
{
public:
  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running();

  static SDL_Renderer *renderer;

private:
  bool isRunning;
  SDL_Window *window;
};

#endif