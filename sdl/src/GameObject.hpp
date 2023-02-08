#pragma once
#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Game.hpp"

class GameObject
{
  public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void Update();
    void Render();

  private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};

#endif