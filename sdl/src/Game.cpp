#include "Game.hpp"

GameObject *player;
Map *map;

SDL_Renderer *Game::renderer = nullptr;

Manager manager;
auto &newPlayer(manager.addEntity());

Game::Game(){};

Game::~Game(){};

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  int flags = 0;

  if (fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "Subsystem Initialized!..." << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (window)
    {
      std::cout << "Window created!" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer created!" << std::endl;
    }

    isRunning = true;
  }
  else
  {
    std::cout << "Renderer with error" << std::endl;
    isRunning = false;
  }

  player = new GameObject("assets/human_f.png", 0, 0);
  map = new Map();

  newPlayer.addComponent<PositionComponent>();
};

void Game::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;

  default:
    break;
  }
};

void Game::update()
{
  player->Update();
  manager.refresh();
  manager.update();
};

void Game::render()
{
  SDL_RenderClear(renderer);

  map->DrawMap();
  manager.draw();
  player->Render();

  SDL_RenderPresent(renderer);
};

void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  std::cout << "Game Cleaned" << std::endl;
};

bool Game::running()
{
  return isRunning;
};