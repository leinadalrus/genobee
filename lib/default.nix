with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "genobee";
  src = ./.;

  buildInputs = [gcc SDL2 emscripten];
  buildPhase = "c++ -std=c++14 -o genobee genobee.cxx";

  installPhase = ''
    mkdir -p $out/build genobee $out/bin/
  '';
}

## Run with shell command:
# nix-shell -p gcc SDL2 imgui emscripten boost

## Build the default.nix file with nix-build command arguments:
# nix-build
# ./result/bin/whiteglint
