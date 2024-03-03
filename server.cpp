// this is a simple server using the boost asio library, that open the port number 9877
// on windows, you have to install the boost asio library from this link "https://think-async.com/Asio/Download" and than include the header file in your IDE
// on linux you can use the install.sh file that you can find in my repository


#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using namespace ip::tcp;

int main() {
    io_service io;
    ip::tcp::acceptor acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), 9877));

    cout << "Listening on port 9877..." << endl;

    ip::tcp::socket socket(io);
    acceptor.accept(socket);

    cout << "Connection accepted!" << endl;
    
    return 0;
}
