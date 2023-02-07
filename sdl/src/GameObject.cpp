#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
  renderer = ren;
  objTexture = TextureManager::LoadTexture(textureSheet, ren);

  xpos = x;
  ypos = y;
}

GameObject::~GameObject()
{}

void GameObject::Update()
{
  srcRect.h = 32;
  srcRect.w = 32;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w * 2;
  destRect.h = srcRect.h * 2;

}

void GameObject::Render()
{
  SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

