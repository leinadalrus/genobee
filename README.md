# Genobee

##### A rework utilising already existing technologies.

###### The Idea for Genobee:

Experimental project in creating a basic UI in SDL2 v.s Raylib \[4.5] for the sake of Digital Signal Processing and Audio Streaming/Handling.
_One side of me is like intralogue-ing on the idea I should just use ImGui, but the problem with ImGui is that it doesn't have Emscripten support for web-browser usage._

I've come to an epiphany that I should possibly direct this project into creating an accessible kind of "Flash" and "ActionScript" alternative to what modern web browsers currently offer. I hope I can garner more help and create a headless API for the project.

##### Why not Yew and Tauri?

_Yew and Tauri for Rust would also work really well, but it's the fact in which there's so much magic happening within Yew and Tauri that I won't be able to pull off what I need to do.
<br>
Attaching Tauri into a pre-existing project through Cargo with the CLI and as a dependency would be good, but then again, more abstraction.
<br>
I also chose Leptos because I can isolate a lot of the events occurring in the web-application as components._

As of note: `.cfg` and-or `.ini` files may also see some application in the future...

#### David Tolnay's CXX

David Tolnay's CXX is used for multi-language tiers of the project.

- I have C++14 code in the high-level programming tiers of the project because it's _"safer."_
- It also helps if we in turn have to 'interop' with another user's C++ code, especially with Soloud being unupdated for years.
- 'C89/90' itself (mainly this edition because it's Portable C, and not Common C) will not allow us to write code in a modern sense with polymorphism/inheritance. But will still be utilised for ARM vs x86_64 architecture interpreter(s) and compiler(s).
- Procedural programming with some _this and that_ of functional and object-oriented programming would be nice. (_Oooooh_ maybe data-oriented programming as well!?)
- At some point in the program we'll need to use a Strategy design pattern with a Singleton since we're working with peripherals after all.

#### `libc`

'libc' enables us to 'interop' with the C code of PortAudio and 'libsndfile' which helps us do some explorative programming.

- We can also test minimally. Testing for trivially but ideal unit tests before doing any form of non-context-free programming with how software revolves with Singletons combined with Strategy patterns sometimes.

#### `ASMJIT` for ASM & ARM Interpreter / Compiler

I have also decided to use "ASMJIT" and will update the JIT interpreter and compiler in the future. Right now I just need to get Raylib and a makeshift game to work with WebGL2 or WebGPU and then further develop the project from there.

##### The general idea as-of-now...

- Currently using C++14 to create a far-more robust application audio backend.
- Develop a branching Action-Role-Playing Game to reinforce my software engineering fundamentals and learning materials.
- Recreate an old C++14/Rust project in order to further understand FFI-ing and be able to work with multiple technologies without bias(?)

###### Why the use of multiple languages?

C++14 is also employed because I love C, alas C++ enables us to use OOP practices better to practice (preferably Composition over Inheritance),
but I tend to shoot myself in the foot with it anyways, which is as to why am experimenting with new and old technologies.

I will still use C, especially since writing Structures-of-Arrays in C is great, and fun to write function pointers with.

<div align="center">

  <h1><code>wasm-pack-template</code></h1>

<strong>A template for kick starting a Rust and WebAssembly project using <a href="https://github.com/rustwasm/wasm-pack">wasm-pack</a>.</strong>

  <p>
    <a href="https://travis-ci.org/rustwasm/wasm-pack-template"><img src="https://img.shields.io/travis/rustwasm/wasm-pack-template.svg?style=flat-square" alt="Build Status" /></a>
  </p>

  <h3>
    <a href="https://rustwasm.github.io/docs/wasm-pack/tutorials/npm-browser-packages/index.html">Tutorial</a>
    <span> | </span>
    <a href="https://discordapp.com/channels/442252698964721669/443151097398296587">Chat</a>
  </h3>

<sub>Built with 🦀🕸 by <a href="https://rustwasm.github.io/">The Rust and WebAssembly Working Group</a></sub>

</div>

## About

[**📚 Read this template tutorial! 📚**][template-docs]

This template is designed for compiling Rust libraries into WebAssembly and
publishing the resulting package to NPM.

Be sure to check out [other `wasm-pack` tutorials online][tutorials] for other
templates and usages of `wasm-pack`.

[tutorials]: https://rustwasm.github.io/docs/wasm-pack/tutorials/index.html
[template-docs]: https://rustwasm.github.io/docs/wasm-pack/tutorials/npm-browser-packages/index.html

## 🚴 Usage

### 🐑 Use `cargo generate` to Clone this Template

[Learn more about `cargo generate` here.](https://github.com/ashleygwilliams/cargo-generate)

```
cargo generate --git https://github.com/rustwasm/wasm-pack-template.git --name my-project
cd my-project
```

### 🛠️ Build with `wasm-pack build`

```
wasm-pack build
```

### 🔬 Test in Headless Browsers with `wasm-pack test`

```
wasm-pack test --headless --firefox
```

### 🎁 Publish to NPM with `wasm-pack publish`

```
wasm-pack publish
```

## 🔋 Batteries Included

- [`wasm-bindgen`](https://github.com/rustwasm/wasm-bindgen) for communicating
  between WebAssembly and JavaScript.
- [`console_error_panic_hook`](https://github.com/rustwasm/console_error_panic_hook)
  for logging panic messages to the developer console.
- `LICENSE-APACHE` and `LICENSE-MIT`: most Rust projects are licensed this way, so these are included for you

## License

Licensed under either of

- Apache License, Version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
- MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)

at your option.

### Contribution

Unless you explicitly state otherwise, any contribution intentionally
submitted for inclusion in the work by you, as defined in the Apache-2.0
license, shall be dual licensed as above, without any additional terms or
conditions.

### Questions & Answers

> Q: How is this a "Webby" RPC build system?

- A: Genobee is meant to mirror or at least loosely copy `brunch/brunch` but in a Peer-to-Peer (P2P) network sense. Like a Content Delivery Network (CDN).

> Q: What happened to the Raylib dependency usage?

- A: I needed the Raylib Rust bindings, but the most popular "crate" for it isn't updated (as-of-this README post).

> Q: Isn't this your weird `leinadalrus/tintagel-head` project from before?

- A: It is. BUT! Tintagel-Head had too many scope-creeps and project went out of scope. This is a refresh, rework of Tintagel-Head.

> Q: Why the dual license of Apache V2 and MIT?

- A: WASM Pack generated.

> Q: There is a game within this supposed "Webby" RPC. Why is that?

- A: The SDL2 game is meant for integration testing. Heck, it may turn into a full-fledged game! Maybe ... ?
