#ifndef GENOBEE_HPP
#define GENOBEE_HPP

#if _WIN32 || __linux__

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

// Collections
#include <array>
#include <string>
#include <vector>

#endif // _WIN32 || __linux__

#ifdef _WIN32

#include <C:/MinGW/include/SDL2/SDL2-devel-2.28.5-mingw/SDL2-2.28.5/x86_64-w64-mingw32/include/SDL2/SDL.h>

#endif // _WIN32

#ifdef __linux__

#include <SDL2/SDL.h>

#endif // __linux__

#endif // GENOBEE_HPP
