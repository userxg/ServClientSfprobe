#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "ServerNet.h"



int main(int argc, char* argv[])
{
    ServerNet server_net(2525);
    server_net.Run();
    return 0;
}