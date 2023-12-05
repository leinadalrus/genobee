with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "genobee";
  src = ./.;

  nativeBuildInputs = [ pkg-config ];
  buildInputs = [
    emscripten
    gcc
    hidapi
    libusb1
    portaudio
    SDL2
  ];

  buildPhase = "c++ -std=c++14 -o genobee genobee.cxx";
  installPhase = ''
    mkdir -p $out/build genobee $out/bin/
  '';
}

## Run with shell command:
# nix-shell -p pkg-config emscripten gcc hidapi imgui libusb1 portaudio SDL2

## Build the default.nix file with nix-build command arguments:
# nix-build
# ./result/bin/genobee
