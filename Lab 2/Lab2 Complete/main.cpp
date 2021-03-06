#include <iostream>
#include <string>

#include "TcpListener.h"
#include "Qotd.h"

using namespace std;

void Listener_MessageReceived(CTcpListener* listener, int client, string msg, std::string sock);

// This is kinda bad because it's global.
CQotd quotes("wisdom.txt");

void main()
{
	CTcpListener server("149.153.106.162", 5050, Listener_MessageReceived);
	
	if (server.Init())
	{
		server.Run();
	}
}

void Listener_MessageReceived(CTcpListener* listener, int client, string msg, std::string sock)
{

	if (msg.find("$QUOTE") != std::string::npos)
	{
		listener->Send(client, quotes.GetRandomQuote());
	}
	else if (msg.find("say:") != std::string::npos)
	{
		std::string holder = "say:";

		std::string::size_type i = msg.find(holder);

		msg.erase(i, holder.length());

		std::string holder_ = sock + " : " + msg;

		listener->Send(client, holder_);
	}
}
