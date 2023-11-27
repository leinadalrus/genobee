#include "../include/services.hpp"
#include "../include/minunit.h"

int annul_player_service_location(PlayerService *player_service) {
  free(player_service);
  player_service = NULL;
  return 0;
}

int initd_checked_player_instance(PlayerService *service_instance) {
  struct PlayerEntity {
    PlayerService player_service;
  } player_entity = {
      .player_service = *service_instance,
  };

  return 0;
}

struct PlayerBundle *designate_entity_scalar(struct PlayerBundle player_instance) {
  struct PlayerService *player_service;
  // TODO: move player_entity data into a new ServiceLocator function

  struct PlayerBundle *new_player = &player_instance;
  new_player->player_service = *player_service;

  return new_player; // return address of stack memory associated with local
                     // variable
}

int annul_player_entity_instance(struct PlayerEntity *player_entity) {
  free(player_entity);
  player_entity = NULL;
  return 0;
}

struct PlayerBundle *init_player_bundle_instance() {
  struct PlayerBundle {
    struct PlayerEntity entity;
    struct Position position;
    struct Health health;
    SDL_Surface *sprite;
  } player = {
      .entity = *designate_entity_scalar(
          &player.entity), // pointer-to-address because of
                           // addres of stack memory
      .position = {350.f, 280.f},
      .health = {100},
      .sprite = SDL_LoadBMP(
          "/public/assets/sprites/DuboisCranceM1A1-Export/spritesheet.png"),
  };

  return &player; // may need memcpy and memmove
}

int check_linked_bundle_instance(PlayerEntity *player_instance) {
  struct PlayerBundle {
    struct PlayerEntity entity;
    struct Position position;
    struct Health health;
    SDL_Surface *sprite;
  } bundle_instance = {
      .entity = *designate_entity_scalar(
          *player_instance), // pointer-to-address because of
                             // address of stack memory
      .position = {350.f, 280.f},
      .health = {100},
      .sprite = SDL_LoadBMP(
          "./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png"),
  };

  return 0;
}

struct PlayerBundle *init_player_bundle_instance(PlayerBundle *bundle_instance,
                                                 PlayerEntity player_instance) {
  bundle_instance->entity =
      *designate_entity_scalar(player_instance); // pointer-to-address because
                                                 // of address of stack memory
  bundle_instance->position.x = 100.0f;
  bundle_instance->position.y = 100.0f;
  bundle_instance->health.health_points = 100.0f;
  bundle_instance->sprite =
      SDL_LoadBMP("./assets/sprites/DuboisCranceM1A1-Export/spritesheet.png");

  PlayerBundle *bundled = bundle_instance;

  return bundled; // may need memcpy and memmove
}

namespace {
char *testPlayerMoveCommand() {
  PlayerMoveCommand *playerMoveCommand = nullptr;
  char constexpr *playerMoveComposite = nullptr;

  mu_assert(
      _strdup("TEST: playerMoveComposite is-equal to := playerMoveCommand"),
      playerMoveComposite == nullptr);

  return playerMoveComposite;
}

char *testAll() {
  mu_run_test(testPlayerMoveCommand);
  return 0;
}
} // namespace

void *create();
void *create() {
  int retVal = 0;
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    retVal = 1;

  int windowWidth = 512;
  int windowHeight = 320;
  const char *appTitle = "White Glint";

  SDL_Window *window =
      SDL_CreateWindow(appTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       windowWidth, windowHeight, SDL_WINDOW_SHOWN);
  if (window == NULL)
    retVal = 1;

  auto screenSurface = SDL_GetWindowSurface(window);
  if (screenSurface == NULL)
    retVal = 1;

  Uint32 renderFlags = SDL_RENDERER_ACCELERATED;
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, renderFlags);
  SDL_Delay(1000); // ms := 1000ms === 1 second

  return window;
}

void *read(void const *context);
void *read(void const *window) {
  SDL_Window *windowConvert = (SDL_Window *)window;
  auto surface = SDL_GetWindowSurface((SDL_Window *)window);
  auto layer = SDL_CreateRGBSurfaceWithFormat(
      SDL_HasWindowSurface(windowConvert), 1, 1, surface->format->BitsPerPixel,
      SDL_PIXELFORMAT_RGBA32);

  SDL_BlitSurface(surface, 0, surface, 0);
  return surface;
}

int update(void const *context);
int update(void const *window) {
  SDL_UpdateWindowSurface((SDL_Window *)window);
  return 0;
}

int destroy(void const *context);
int destroy(void const *window, void const *surface) {
  SDL_FreeSurface((SDL_Surface *)surface);
  surface = nullptr;

  SDL_DestroyWindow((SDL_Window *)window);
  window = nullptr;

  SDL_Quit();
  return 0;
}

int main() {
  auto context = create();
  auto surface = read(&context);

  char *testResults = testAll();

  if (testResults != 0)
    printf("%s\n\t", testResults);

  update(&context);
  destroy(&context, &surface);

  return testResults != 0;
}