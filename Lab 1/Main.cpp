#include <winsock2.h>
#include <iostream>
#include "Net.h"
#include <string>

int main()
{
	Net net = Net();
	net.initialise();

	std::string x;
	std::cin >> x;
	std::cout << std::endl;

	if (x == "a")
	{
		net.setupUDP(28000, "120.0.0.1");
		std::cout << "Player A's IP is " << net.getSenderIP() << ":" << std::to_string(net.getSenderPort()) << std::endl;
	}
	else if (x == "b")
	{
		net.setupUDP(28001, "120.0.0.1");
		std::cout << "Player B's IP is " << net.getSenderIP() << ":" << std::to_string(net.getSenderPort()) << std::endl;
	}

	system("PAUSE");

	return 0;
}