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
		
		PC* slaveItem = &net.getPCArr()[slavePC - 1];

		net.getPCArr()[masterPC - 1].addItemToEndOfList(slaveItem);
	}
	
	cin >> mainPC;
	net.setMainPC(mainPC);

	net.findAccessible("Recursive");
	net.printAccessibles();

	net.findAccessible("Iterative");
	net.printAccessibles();
}