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

		PC* slaveItem = &net.getPCArr()[slavePC - 1];

		net.getPCArr()[masterPC - 1].addItemToEndOfList(slaveItem);
	}
	cin >> mainPC;
	net.setMainPC(mainPC);

	net.findAccessible("Iterative");
	net.printAccessibles();
}