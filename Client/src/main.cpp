
#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <windows.h>



int main()
{

    std::cout << "This is Client\n";

    sf::TcpSocket cl_socket;

    /*
    * will be successful if remote peer is accceping on this port
    */
    //where we want to send data
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();

    //ip and port of remote peer
    sf::Socket::Status status = cl_socket.connect(ip, 2000);

    if (status != sf::Socket::Done)
    {
        std::cout << "Error!\n";
    }

    std::cout << "I'm connected\n\n";

    //send and recieve data
    while (true)
    {
        std::string msg;
        std::getline(std::cin, msg);

        sf::Socket::Status send_status = cl_socket.send(msg.data(), 100);

        if(send_status != sf::Socket::Done)
        {
            std::cout << "Send error\n";
        }

        std::cout << "send by me: " << msg << "\n";
    }

    system("pause");

	return 0;
}