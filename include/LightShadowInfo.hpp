//
// Created by Dave on 2023-10-28.
//

#include "../genobee.hpp"
#include "./PlayerEntity.hpp"

#ifndef LIGHT_SHADOW_INFO_HPP
#define LIGHT_SHADOW_INFO_HPP

int constexpr MaxBoxes = 20;
int constexpr MaxShadows = MaxBoxes;
int constexpr MaxLights = MaxBoxes;

int constexpr RgbAlpha = 0x0302;
int constexpr RgbaMax = 0x8008;
int constexpr RgbaMinimum = 0x8007;

struct ShadowGeometry {
  Vector2 vertices[MaxBoxes/4];
};

struct LightInformation {
  int active, dirty, valid;

  Rectangle bounds;
  Vector2 position;
  float outerCircle;

  SDL_Texture *mask;

  ShadowGeometry shadows[MaxShadows];
};

LightInformation constexpr Lights[MaxLights] = {0};

#endif // LIGHT_SHADOW_INFO_HPP
