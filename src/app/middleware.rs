// middleware.rs := Client-Server (Files) Middleware
//

use actix_web::get;
use actix_web::post;
use actix_web::HttpResponse;
use actix_web::HttpServer;
use actix_web::Responder;

#[get("/")]
async fn index() -> impl Responder
{
  return HttpResponse::Ok().json("/");
}

#[post("/users")]
async fn post(request : String) -> impl Responder
{
  return HttpResponse::Ok().json(request);
}

pub(crate) async fn response() -> impl Responder
{
  return HttpResponse::Ok().json("/");
}

async fn handle_supervised() -> impl Responder
{
  tokio::time::sleep(Duration::from_secs(10)).await;
  return "supervise";
}
