#pragma once

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <SFML/Network.hpp>

#define logl(x) std::cout << x << "\n"
#define log(x) std::cout << x


class ServerNet
{
private:
	sf::TcpListener listener_;
	std::vector<sf::TcpSocket*> clients_;

	unsigned short listen_port_;
public:
	ServerNet(unsigned short port);
	void ConnectClients(std::vector<sf::TcpSocket*>* clients);
	void DisconnectClients(sf::TcpSocket* socket, size_t position);
	void ManagePackets();
	void BroadcastPacket(sf::Packet& packet, sf::IpAddress exclude_address, unsigned short port);
	void Run();

};

