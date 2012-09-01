#include <QtCore/QCoreApplication>

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>
#include <fstream>

//c/////
//c parameters:
//1] IP
//2] PORT
//3] packet.zip
using namespace boost::asio::ip;
void    print_usage();
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "NOT ENOUGH PARAMETERS" << std::endl;
        print_usage();
        exit(1);
    }
    boost::system::error_code error;
    address addr = address::from_string(argv[1], error);

    if (error)
    {
        std::cout << "INVALID IP ADDRESS" << std::endl;
        print_usage();
        exit(1);
    }

    unsigned short int port = 0;
    try {
        port = boost::lexical_cast<unsigned short int> (argv[2]);
    } catch( boost::bad_lexical_cast&)
    {
        std::cout << "INVALID PORT" << std::endl;
        print_usage();
        exit(1);
    }

    boost::system::error_code ec;
    boost::filesystem::path file (argv[3]);
    if (!boost::filesystem::exists(file, ec))
    {
        std::cout << "MISSING FILE" << std::endl;
        print_usage();
        exit(1);
    }



    boost::asio::io_service io_service;
    io_service.post
    tcp::socket socket (io_service);
    tcp::endpoint endpoint (addr, port);
    socket.connect(endpoint, error);
    if (error)
    {
        std::cout << "FAILED TO CONNECT TO [";
        std::cout << endpoint.address().to_string();
        std::cout << ":" << endpoint.port() << "]" << std::endl;
        exit(1);
    }
    std::cout << "connected." << std::endl;
    socket.write_some()
    const size_t BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];




    return a.exec();
}

void    print_usage()
{
    std::cout << "usage:" << std::endl;
    std::cout << "./rcclient IPCIM PORT" << std::endl;
}
