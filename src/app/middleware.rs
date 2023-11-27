// middleware.rs := Client-Server (Files) Middleware

use actix_web::{get, post, HttpResponse, HttpServer, Responder};

#[get("/")]
async fn index() -> impl Responder {
    return HttpResponse::Ok().json("/");
}

#[post("/users")]
async fn post(request: String) -> impl Responder {
    return HttpResponse::Ok().json(request);
}

pub(crate) async fn response() -> impl Responder {
    return HttpResponse::Ok().json("/");
}

async fn handle_supervised() -> impl Responder {
    tokio::time::sleep(Duration::from_secs(10)).await;
    return "supervise";
}