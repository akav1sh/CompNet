//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// Ronel David Gekhman  - 313564510.                                                 //
// This project creates a network of computers connected to each other, and can      //
// return the connections of any chosen computer from the network.                   //
// The code finds the connections twice, once recursively and once iteratively.      //
// The iterative function uses stack to go over the computers and their connections. //
//                                                                                   //
// First you input amount of cmputers in the network, after that the amount of       //
// connections you will be inputting.                                                //
// After that you input connections in two's, first input is the main computer and   //
//  the second input is the computer connectin to the main.                          //
// Lastly you input the number of the computer you want to know its accessibles.     //
//***********************************************************************************//
#include "ComputerNetwork.h"

int main()
{
	int size, connectionAmount, masterPC, slavePC, mainPC;

	cin >> size;
	ComputerNetwork net(size);

	cin >> connectionAmount;

	for (int i = 0; i < connectionAmount; ++i)
	{
		cin >> masterPC >> slavePC;

		net.checkConnectionInput(masterPC);
		net.checkConnectionInput(slavePC);


		net.getPCArr()[masterPC - 1].addItemToEndOfList(new ItemType(net.getPCArr()[slavePC - 1]));
	}

	cin >> mainPC;
	net.checkConnectionInput(mainPC);
	net.setMainPC(mainPC);

	net.findAccessible("Recursive");

	net.findAccessible("Iterative");
	return 0;
}