mod app;
mod utils;

use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern "C" {
    fn log(s: &str);
}

#[wasm_bindgen]
pub fn index {
    log("Hello, Genobee!");
}
