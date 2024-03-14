#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
##include <string>
#include <iostream>

namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;

void http_hello_page(http::request<http::string_body> req, std::string& outputbuf, std::function<void(const tcp::socket&)> next_request) {
    // Check for /hello request
    if (req.method() != http::verb::get || req.target() != "/hello") {
        next_request(std::move(req.socket()));
        return;
    }

    // Read request body (username)
    req.body().consume(req.body().size());
    std::string username = req.body().data();

    // Construct response body (HTML page)
    outputbuf = "<html><body><h1>Hello, " + username + "!</h1></body></html>";

    // Create response
    http::response<http::dynamic_body> res{http::status::ok, req.version(), req.target()};
    res.set(http::field::server, "MyServer");
    res.set(http::field::content_type, "text/html");

    // Write response body to outputbuf
    res.body().write(outputbuf.c_str(), outputbuf.size());

    // Write response headers to stream
    http::write(req.socket(), res);

    // Close response stream
    req.socket().shutdown(tcp::socket::shutdown_both);

    // Move on to the next request
    next_request(std::move(req.socket()));
}