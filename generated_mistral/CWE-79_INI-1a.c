#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include <string>
#include <iostream>
#include <cstdio>

namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;
using string = std::string;
using buffer_type = boost::beast::flat_buffer;
using stream_type = std::istream;
using string_type = std::string;

void http_hello_page(http::request<buffer_type> req, http::response<buffer_type> res, http::application& app) {
    // Read the request body into the username variable
    string_type body;
    if (req.need_body()) {
        auto stream = app.get_read_stream();
        stream.transfer_all(req.body(), req.body().size());
        body = {std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()};
        req.consume(req.body().size());
    }

    // Construct the response body (HTML page) into the outputbuf variable
    buffer_type output_buffer;
    string_type output_str = R"HTML(
        <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>Hello</title>
            </head>
            <body>
                <h1>Hello, <%= username %>!</h1>
            </body>
        </html>
    )HTML";
    output_str = boost::beast::make_printable(output_str);

    // Set the response status and headers
    res.result(http::status::ok);
    res.set(http::field::server, "My Server");
    res.set(http::field::content_type, "text/html");

    // Write the response body to the outputbuf
    output_buffer.append(output_str.data(), output_str.size());
    res.body() = output_buffer.data();
    res.body_size(output_buffer.size());

    // Write the response to the response stream
    auto const write_stream = app.get_write_stream();
    write_stream.write(res.data(), res.body().size());

    // Close the response stream
    app.get_executor().run();
}