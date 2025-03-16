#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    try {
        io_context io;
        tcp::socket socket(io);
        socket.connect(tcp::endpoint(make_address("server"), 5000));

        std::string request = "GET / HTTP/1.1\r\nHost: server\r\n\r\n";
        write(socket, buffer(request));

        char response[1024] = {0};
        size_t bytes = read(socket, buffer(response, sizeof(response) - 1));
        std::cout << "Server response: " << std::string(response, bytes) << "\n";

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
