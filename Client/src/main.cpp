
#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <windows.h>


struct Message
{
    std::string name_from;
    std::string name_to;

    std::string message;
};

sf::Packet& operator<<(sf::Packet& inp, const Message& msg)
{
    inp << msg.name_from << msg.name_to << msg.message;
    return inp;
}

sf::Packet& operator>>(sf::Packet& out, Message& msg)
{
    out >> msg.name_from >> msg.name_to >> msg.message;
    return out;
}

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

    std::string my_name = "Nikola";
    //send and recieve data
    while (true)
    {
        Message msg;
        msg.name_from = my_name;
        std::getline(std::cin, msg.message);
        sf::Packet packet;
        packet << msg;
        

        sf::Socket::Status send_status = cl_socket.send(packet);

        if(send_status != sf::Socket::Done)
        {
            std::cout << "Send error\n";
        }

        std::cout << "send by me: " << msg.message << "\n";
    }

    system("pause");

	return 0;
}