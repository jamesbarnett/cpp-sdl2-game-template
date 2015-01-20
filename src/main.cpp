#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

using namespace std;

int main(int argc, char** argv)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow("Hello World!", 0, 0, 1024, 768, SDL_WINDOW_SHOWN);
  if (nullptr == window)
  {
    cout << "SDL_CreateWindow error: " << SDL_GetError() << endl;
    SDL_Quit();
    return 1;
  }
  
  SDL_Delay(5000);
  SDL_Quit();

  return 0;
}

