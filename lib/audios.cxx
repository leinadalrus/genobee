#include "../include/audios.hpp"

AudioService::AudioService(AudioService const *rhs[]) {} // move constructor

AudioService::AudioService(AudioService const &rhs) {} // copy constructor

void AudioService::run_sound(int sound_id) {}

void AudioService::mute_sound(int sound_id) {}