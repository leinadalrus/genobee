#include "./genobee.hpp"
#include "../include/minunit.h"

int main() {
  std::printf("Genobee");
  int width = 512, height = 320;
  const char *title = "Genobee";

  SDL_Window *window = SDL_CreateWindow(title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width,
    height,
    SDL_WINDOW_SHOWN);
  SDL_Surface *surfaceA = SDL_GetWindowSurface(window);

  SDL_Surface *keySurfaces[KeySurfaces::Final]; // `*[]` is equivalent to `**`
  SDL_Surface *currentSurface = nullptr;

  SDL_Event eventof;
  while (SDL_PollEvent(&eventof) != 0) {
    SymboliseKeySurfaces(currentSurface);
    SDL_BlitSurface(currentSurface, nullptr, surfaceA, nullptr);
    SDL_UpdateWindowSurface(window);

    if (eventof.type == SDL_QUIT) {
      // NOTE(deallocation): delete top-down code in reverse:
      SDL_FreeSurface(surfaceB);
      SDL_FreeSurface(surfaceA);
      SDL_DestroyWindow(window);
    }
  }

  // NOTE(on Quitting): don't confuse SDL_QUIT and SDL_Quit()
  SDL_Quit(); 
}
