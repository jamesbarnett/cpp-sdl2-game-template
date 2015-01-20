#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

using namespace std;

class Game
{
private:
  SDL_Window* mainWindow_;
  bool isRunning_ = true;
  
public:
  Game() 
  {

  }

  ~Game()
  {
    SDL_DestroyWindow(mainWindow_);
    SDL_Quit();
  }

  bool init()
  {
    mainWindow_ = SDL_CreateWindow("Hello World!", 
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, 
      1024, 768, SDL_WINDOW_SHOWN);

    if (nullptr == mainWindow_)
    {
      cout << "SDL_CreateWindow error: " << SDL_GetError() << endl;
      SDL_Quit();
      return 1;
    }
  
    return true;
  }

  bool run()
  {
    long timeDelta = 1000 / 60L;
    long timeAccumulator = 0L;
    long timeForFrame;
    long startTime = SDL_GetTicks();
    SDL_Event event;

    while (isRunning_)
    {
      timeForFrame = 0L;
      startTime = SDL_GetTicks();
      
      while (timeAccumulator >= timeDelta)
      {
        update(timeDelta);
        timeAccumulator -= timeDelta;
      }

      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT) isRunning_ = false;

        // process user input here
      }

      draw();
      timeAccumulator += SDL_GetTicks() - startTime;
    }

    return true;
  }

private:
  void update(long msecs)
  {

  }

  void draw()
  {

  }
};

