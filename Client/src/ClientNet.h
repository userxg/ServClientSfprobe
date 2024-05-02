#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <SFML/Network.hpp>

#define logl(x) std::cout << x << "\n"
#define log(x) std::cout << x

class ClientNet
{
private:
	sf::TcpSocket socket_;
	sf::Packet last_packet_;

public:
	ClientNet();
	void Connect(const char* adress, unsigned short port);
					//may be as reference
	void ReceivePackets(sf::TcpSocket* socket);
	void SendPacket(sf::Packet& packet);
	void Run();

};

