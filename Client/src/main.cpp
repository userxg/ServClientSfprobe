
#include "ClientNet.h"

int main(int argc, char* argv[])
{
	ClientNet client_net;
	client_net.Connect("localHost", 2525);
	client_net.Run();

	return 0;
}