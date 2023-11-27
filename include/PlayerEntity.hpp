#ifndef PLAYER_ENTITY_HPP
#define PLAYER_ENTITY_HPP

#if _WIN32 || __linux__

/// C++ Standard Library ::
#include <cstdio>
#include <cstdlib>
#include <cstring>

/// File I/O
#include <fstream>
#include <iostream>

/// Collections: Functional
#include <array>
#include <string>
#include <vector>

/// Functional
#include <numeric>

#endif // _WIN32 || __linux__

#if _WIN32

#include <C:/MinGW/include/SDL2/SDL2-devel-2.28.5-mingw/SDL2-2.28.5/x86_64-w64-mingw32/include/SDL2/SDL.h>

#endif

#if __linux__

#include <SDL2/SDL.h>

#endif

#include "./ICommand.hpp"
#include "./IDisposal.hpp"

struct Position {
  float x, y;
};

struct Health {
  float health_points;
};

struct PlayerEntity {
  struct Position position;
  struct Health health;
  SDL_Surface *sprite;
};

struct PlayerService {
  IDisposal player_service;
};

struct PlayerBundle {
  struct PlayerEntity entity;
  struct Position position;
  struct Health health;
  struct PlayerService player_service;
  SDL_Surface *sprite;
};

class PlayerMoveCommand : public ICommand {
public:
  void Execute() override { this->move(); };

  int *move() { return 0; }
};

#endif /// PLAYER_ENTITY_HPP
