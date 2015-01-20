#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include "game.hpp"


int main(int argc, char** argv)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  Game game;
  game.init();
  game.run();

  return 0;
}

