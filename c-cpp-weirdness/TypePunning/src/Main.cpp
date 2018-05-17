#include <iostream>

struct Entity
{
	int x, y;

	int* GetPositions()
	{
		return &x;
	}
};


int main()
{
	{
		// example 1: implicit conversion
		int a = 50;
		double value = a; // go to debug, memory layout 1 and check out &a and &value

		std::cout << value << std::endl;
	}

	{
		// example 2: type punning
		int a = 50;
		double value = *(double*)&a; // copied that int memory and paste into double (don't do this!). Go to debug, memory layout 1 and check out &a and &value

		std::cout << value << std::endl;
	}


	{
		// example 3: accessing entity elements with pointers
		Entity e = {5 , 8};

		int* position = (int*)&e;

		std::cout << position[0] << ", " << position[1] << std::endl;
	}

	{
		// example 5: another way to access entity elements with pointers
		Entity e = { 5 , 8 };

		int* position = e.GetPositions();

		std::cout << position[0] << ", " << position[1] << std::endl;
	}

	{
		// example 6: accessing entity elements by knowing how many bytes we should step into memory
		Entity e = { 5 , 8 };

		int y = *(int*)((char*)&e + 4); // WTF?: get e address, cast to a char pointer (1 byte), add 4 bytes to this char pointer to get to the next int value (we know int is 4 bytes), cast to a int pointer because we know "y" is int, finally dereference the int pointer to get the value of y

		std::cout << y << std::endl;
	}

	

	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}