// created by David in late 2023
//
mod command;
mod middleware;
mod supervisor;

use openssl::ssl::SslAcceptor;
use openssl::ssl::SslFiletype;

#[actix_web::main]
async fn main() -> std::io::Result<(), aws_sdk_iot::Error>
{
  let config = aws_config::load_from_env().await;
  let client = aws_sdk_iot::Client::new(&config);

  let mut acceptor =
    SslAcceptor::mozilla_intermediate(SslMethod::tls()).unwrap();

  acceptor.set_private_key_file("id_ed25519.pem", SslFiletype::PEM)
          .unwrap();
  acceptor.set_certificate_chain_file("pub_ed25519.pem")
          .unwrap();

  return actix_web::HttpServer::new(|| {
           actix_web::App
        ::new()
        .service(middleware::index)
        .service(middleware::post)
        .route("/", actix_web::web::get().to(middleware::response))
         }).workers(1)
           .worker_max_blocking_threads(1)
           .bind_openssl("localhost: 3000", acceptor)?
           .run()
           .await;
}
