#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

// Collections
#include <array>
#include <string>
#include <vector>

#include "../include/PlayerEntity.hpp"

enum class KeySurfaces { Init, Up, Down, Left, Right, Final };

// NOTE(const vs constexpr): `const` is initialised as-of-now (presently)-
// -`constexpr` is a compile-time initialisation,
// which means a pointer becomes constant, not the object as constant
void const *SymboliseKeySurfaces(SDL_Surface *currentSurface) {
  auto movements_final =
      static_cast<std::make_unsigned<decltype(KeySurfaces::Final)>::type>(
          KeySurfaces::Final);

  auto movements_up =
      static_cast<std::make_unsigned<decltype(KeySurfaces::Up)>::type>(
          KeySurfaces::Up);

  auto movements_down =
      static_cast<std::make_unsigned<decltype(KeySurfaces::Down)>::type>(
          KeySurfaces::Down);

  auto movements_left =
      static_cast<std::make_unsigned<decltype(KeySurfaces::Left)>::type>(
          KeySurfaces::Left);

  auto movements_right =
      static_cast<std::make_unsigned<decltype(KeySurfaces::Right)>::type>(
          KeySurfaces::Right);

    auto movements_init =
      static_cast<std::make_unsigned<decltype(KeySurfaces::Init)>::type>(
          KeySurfaces::Init);

  SDL_Surface *keySurfaces[movements_final]; // `*[]` is equivalent to `**`
  SDL_Surface *bmpImageSurface = SDL_LoadBMP(
      "./public/assets/avatar/user-avatar.png"); // <-- 80th column mark

  SDL_Event eventof;
  switch (eventof.key.keysym.sym) {
  case SDLK_UP:
    keySurfaces[movements_down] = bmpImageSurface;
    currentSurface = keySurfaces[movements_down];
    break;

  case SDLK_DOWN:
    keySurfaces[KeySurfaces::Down] = bmpImageSurface;
    currentSurface = keySurfaces[movements_down];
    break;

  case SDLK_LEFT:
    keySurfaces[movements_left] = bmpImageSurface;
    currentSurface = keySurfaces[movements_left];
    break;

  case SDLK_RIGHT:
    keySurfaces[movements_right] = bmpImageSurface;
    currentSurface = keySurfaces[movements_right];
    break;

  default:
    keySurfaces[movements_init] = bmpImageSurface;
    currentSurface = keySurfaces [movements_init];
    break;
  }

  return currentSurface;
}
