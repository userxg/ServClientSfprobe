#include "ServerNet.h"

ServerNet::ServerNet(unsigned short port) : listen_port_(port)
{
	logl("Server started");
	if (listener_.listen(listen_port_) != sf::Socket::Done)
	{
		logl("Cound not listen");

	}else logl("Server is listenning");
}

void ServerNet::ConnectClients(std::vector<sf::TcpSocket*>* clients)
{


	while (true)
	{

		sf::TcpSocket* new_client = new sf::TcpSocket();
		if (listener_.accept(*new_client) == sf::Socket::Done)
		{
			new_client->setBlocking(false);
			clients->push_back(new_client);
			log("Added client ");
			std::cout << new_client->getRemoteAddress() << " : " << new_client->getRemotePort() << " on slot " << clients->size() << "\n";
		}
		else logl("Coudn not connect");
	}
}

void ServerNet::DisconnectClients(sf::TcpSocket* socket, size_t position)
{
	logl("client" << socket->getRemoteAddress() << " : " << socket->getRemotePort() << " disconnected");
	delete(socket);
	clients_.erase(clients_.begin() + position);
}

void ServerNet::ManagePackets()
{
	while (true)
	{
		for (size_t i = 0; i < clients_.size(); ++i)
		{
			sf::TcpSocket* client = clients_[i];

			sf::Packet received_packet;
			if (client->receive(received_packet) == sf::Socket::Disconnected)
			{
				DisconnectClients(client, i);
				break;
			}

			//correct this
			if (received_packet.getDataSize() > 0)
			{
				std::string received_msg;
				received_packet >> received_msg;
				received_packet.clear();

				std::string reply_msg;
				reply_msg.append(client->getRemoteAddress().toString() + ": " + received_msg);
				received_packet << reply_msg;
				BroadcastPacket(received_packet, client->getRemoteAddress(), client->getRemotePort());
				logl(client->getRemoteAddress().toString() << " : " << received_msg);
			}
		}
	}
}

void ServerNet::BroadcastPacket(sf::Packet& packet, sf::IpAddress exclude_address, unsigned short port)
{
	for (size_t i = 0; i < clients_.size(); ++i)
	{
		sf::TcpSocket* client = clients_[i];
		if (client->getRemoteAddress() != exclude_address || client->getRemotePort() != port)
		{
			if (client->send(packet) != sf::Socket::Done)
			{
				logl("Cound't send packet");
			}
		}
	}
}

void ServerNet::Run()
{
	std::thread connection_thread(&ServerNet::ConnectClients, this, &clients_);
	
	ManagePackets();
}
