#ifndef SCENE_HPP__
#define SCENE_HPP__

#include <iostream>
#include <SDL2/SDL.h>
#include "entity.hpp"
#include "level.hpp"
#include "sprite.hpp"

class GameObject;

void silence(long ms);

class Scene
{
private:
  string name_;
  std::vector<Entity> entities_;
  SDL_Texture* texture_;
  long currentTicks_;
  long targetTicks_;
  bool pause_;
  int pauseSeconds_;
  SDL_Color backgroundColor_;
  Level level_;
  GameObject* gameObject_;
  Sprite backSprite_;

public:
  Scene(GameObject* gameObject) : name_(""), entities_(vector<Entity>())
    , texture_(nullptr), currentTicks_(0L), targetTicks_(0L), pause_(false)
    , pauseSeconds_(0), backgroundColor_({0, 0, 0, 0}), gameObject_(nullptr)
  {
    gameObject_ = gameObject;
  }

  inline std::string name() const { return name_; }
  inline void name(const std::string& val) { name_ = val; }

  inline std::vector<Entity> entities() const { return entities_; }

  inline SDL_Texture* texture() const { return texture_; }
  inline void texture(SDL_Texture* val) { texture_ = val; }

  inline long currentTicks() const { return currentTicks_; }
  inline void currentTicks(long val) { currentTicks_ = val; }

  inline long targetTicks() const { return targetTicks_; }
  inline void targetTicks(long val) { targetTicks_ = val; }

  inline bool pause() const { return pause_; }
  inline void pause(bool val) { pause_ = val; }

  inline int pauseSeconds() const { return pauseSeconds_; }
  inline void pauseSeconds(int val) { pauseSeconds_ = val; }

  inline SDL_Color backgroundColor() const { return backgroundColor_; }
  inline void backgroundColor(SDL_Color val) { backgroundColor_ = val; }

  inline Level level() const { return level_; }
  inline void level(const Level& val) { level_ = val; }

  inline GameObject* gameObject() const { return gameObject_; }
  
  void addEntity(const Entity& entity) { entities_.push_back(entity); }

  virtual void initialize() {}

  virtual void reset() {}

  virtual void run() {}

  virtual void update(long ms)
  {
    silence(ms);
  }

  virtual void move() {}

  virtual void drawBackground();

  virtual void draw() {}

  virtual void userPause() {}

  virtual void onPause() {}

  virtual void afterPause() {}

  friend std::ostream& operator<<(std::ostream&, const Scene&);
};

std::ostream& operator<<(std::ostream&, const Scene&);

#endif

