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