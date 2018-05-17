#include <iostream>
#include <vector>
#include <algorithm> // includes our sorting algorithm that sorts at O(N * log(N))
#include <functional> // for lambda

int main()
{	
	std::vector<int> values = { 3, 5, 1, 4, 2 };
	
	// example 1: basic case with default operator<
	{
		std::cout << "\nExample 1: default operator<" << std::endl;
		std::sort(values.begin(), values.end());
		for (int value : values)
		{
			std::cout << value << std::endl;
		}
	}

	// example 2: built in functions
	{
		std::cout << "\nExample 2: built in functions" << std::endl;
		std::sort(values.begin(), values.end(), std::greater<int>());
		for (int value : values)
		{
			std::cout << value << std::endl;
		}
	}


	// example 3: using lambda (crazy sort: the smaller goes at the end)
	{
		std::cout << "\nExample 3: using lambda" << std::endl;
		std::sort(values.begin(), values.end(), [](int a, int b)
		{
			if (a == 1)
				return false;

			if (b == 1)
				return true;

			return a < b;
		});

		for (int value : values)
		{
			std::cout << value << std::endl;
		}
	}




	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}