#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include <vector>

int clients_cnt = 0;
//create array for clients

struct Client
{
public:
    int id;
    sf::TcpSocket socket;
};

std::vector<Client*> clients;


void Acceptor(sf::TcpListener& listener)
{

    while (true)
    {
        //here we accept clients
        Client* some_client = new Client();
        sf::Socket::Status accept_status = listener.accept(some_client->socket);



        if (accept_status != sf::Socket::Done)
        {
            std::cout << "Error!\n";
        }

        clients.push_back(some_client);
        some_client->id = clients.size();

        std::cout << some_client->id << " Connection!\n";
    }
}

void SomeChatting()
{

    while (true)
    {
        if (clients.size() == 1)
        {
            char data[100] = { 0 };
            std::size_t received;

            sf::Socket::Status recived_status = clients[0]->socket.receive(data, 100, received);

            if (recived_status != sf::Socket::Done)
            {
                std::cout << "Error received\n";
            }

            std::cout << "Received: " << received << " bytes" << std::endl;
            std::cout << "message: " << data << "\n";
        }
    }
}


int main()
{
    std::cout << "This is Server\n";

    //-----------------------------------------------------------in thread--------------------------------------------/
      /*On the server side, a few more things have to be done.
      Multiple sockets are required: One that listens for incoming connections, and one for each connected client.*/


      /*listen for clients
      the programm stops here until any client connects

      listens on this port  2000 as in documentation
      wait for incoming connection attempts on a given port.
      */

      //also socket
    sf::TcpListener listener;
    //bind listener to listen on this port
    sf::Socket::Status listen_status = listener.listen(2000);
    if (listen_status != sf::Socket::Done)
    {
        std::cout << "Error!\n";
    }

    //Acceptor(listener);


    std::thread accept_clients(Acceptor, std::ref(listener));
    std::thread chatting(SomeChatting);


    accept_clients.join();
    chatting.join();
    

    // use "client" to communicate with the connected client,
    // and continue to accept new connections with the listener
      

    system("pause");
    /*std::string name;
    std::cout << "Enter your name\n";
    std::cin >> name;*/

    /*
    * This means that your program (more specifically the thread that contains the function call)
        will be stuck until the operation is complete.
    * 
    */
   /* socket.setBlocking(false);

    std::string message = "";

    sf::Packet packet;

    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            std::cin >> message;
        }

        if (message != "")
        {
            packet.clear();
            packet << name << message;

            socket.send(packet);

            message = "";
        }

        if (socket.receive(packet) == sf::Socket::Done)
        {
            std::string nameRec;
            std::string messageRec;

            packet >> nameRec >> messageRec;
            std::cout << nameRec << ": " << messageRec << "\n";
        }

    }*/
    return 0;
}