#include "ClientNet.h"

ClientNet::ClientNet()
{
	logl("I'm Client");
}

void ClientNet::Connect(const char* address, unsigned short port)
{
	
	if (socket_.connect(address, port) != sf::Socket::Done)
	{
		logl("Could not connect to the server!");
	}
	else logl("I'm connected!");
}

void ClientNet::ReceivePackets(sf::TcpSocket* socket)
{

	while (true)
	{
		if (socket->receive(last_packet_) == sf::Socket::Done)
		{
			std::string received_message;
			last_packet_ >> received_message;
			logl(received_message);
		}
	}
}

void ClientNet::SendPacket(sf::Packet& packet)
{
	if (socket_.send(packet) != sf::Socket::Done)
	{
		logl("Could not send packet");
	}
}

void ClientNet::Run()
{
	std::thread reception_thread(&ClientNet::ReceivePackets, this, &socket_);

	while (true)
	{
		std::string input_msg;
		std::getline(std::cin, input_msg);

		sf::Packet reply_packet;
		reply_packet << input_msg;
		SendPacket(reply_packet);

	}
	
}
