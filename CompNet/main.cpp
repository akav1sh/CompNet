#include "ComputerNetwork.h"

void main()
{
	int size, connectionAmount, masterPC, slavePC, mainPC;

	cin >> size;
	ComputerNetwork net(size);

	cin >> connectionAmount;

	for (int i = 0; i < connectionAmount; ++i)
	{
		cin >> masterPC >> slavePC;

		if (masterPC <= 0 || slavePC <= 0)
			exit(INVALID_INPUT_ERROR);
		
		net.getPCArr()[masterPC - 1].addItemToEndOfList(&net.getPCArr()[slavePC - 1]);
	}
	
	cin >> mainPC;
	net.setMainPC(mainPC);

	net.findAccessible("Recursive");

	net.findAccessible("Iterative");
}