#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    try {
        io_context io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 5000));

        std::cout << "Server is running on port 5000...\n";

        while (true) {
            tcp::socket socket(io);
            acceptor.accept(socket);

            std::string message = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, Client";
            write(socket, buffer(message));
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
