#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    try {
        io_context io;
        tcp::socket socket(io);
        socket.connect(tcp::endpoint(make_address("127.0.0.1"), 5001));

        std::string request = "GET / HTTP/1.1\r\nHost: server\r\n\r\n";
        write(socket, buffer(request));

        char response[1024] = {0};
        boost::system::error_code error;
        size_t bytes = socket.read_some(buffer(response, sizeof(response) - 1), error);

        if (error == boost::asio::error::eof) {
            std::cout << "Server closed connection.\n";
        } else if (error) {
            throw boost::system::system_error(error);
        }
        std::cout << "Server response: " << std::string(response, bytes) << "\n";

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
