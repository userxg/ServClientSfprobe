
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

    std::cout << "I'm connected\n";

    system("pause");

	return 0;
}