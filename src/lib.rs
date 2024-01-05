mod utils;

use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern "C" {
  fn log(s : &str);
}

#[wasm_bindgen]
pub fn main()
{
  log("Hello, gen-o-bee!");
}
