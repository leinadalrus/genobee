use openssl::ssl::{ SslAcceptor, SslFiletype };

mod command;
mod middleware;
mod supervisor;

#[actix_web::main]
async fn main() -> std::io::Result<()> {
  let mut acceptor = SslAcceptor::mozilla_intermediate(
    SslMethod::tls()
  ).unwrap();

  acceptor.set_private_key_file("id_ed25519.pem", SslFiletype::PEM).unwrap();
  acceptor.set_certificate_chain_file("pub_ed25519.pem").unwrap();

  return actix_web::HttpServer
    ::new(|| {
      actix_web::App
        ::new()
        .service(middleware::index)
        .service(middleware::post)
        .route("/", actix_web::web::get().to(middleware::response))
    })
    .workers(1)
    .worker_max_blocking_threads(1)
    .bind_openssl("localhost: 3000", acceptor)?
    .run().await;
}
