#include <iostream>
#include <SFML/Network.hpp>


int main()
{
	sf::Int32 a = 5;
	std::string msg = " messag";

	sf::Packet pack_c1;

	pack_c1 << a << msg;

	sf::Packet pack_c2;
	pack_c2 = pack_c1;

	sf::Int32 a2= 0;
	std::string msg_c2 = "";
	if (pack_c2 >> a2 && pack_c2 >> msg_c2)
	{
		std::cout << a2 << msg_c2;
	}


	return 0;
}