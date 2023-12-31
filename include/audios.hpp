#ifndef AUDIOS_HPP
#define AUDIOS_HPP

class AudioService {
public:
    AudioService(AudioService const *rhs[]);
    AudioService(AudioService const &rhs);

    void run_sound(int sound_id);
    void mute_sound(int sound_id);
};

class AudioServiceAnnul {
  ~AudioServiceAnnul() = default;

  void destroy(AudioServiceAnnul *self, void *user_table_data) {
    delete self;
    self = nullptr;
  }
}

#endif
