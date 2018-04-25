/*
	Function Pointers
*/

#include <iostream>
#include <vector>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void HelloWorldWithParam(int param)
{
	std::cout << "Hello World! Param: " << param << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}

int main()
{

	// 1 - easy way ('auto')
	std::cout << "Example 1: easy way" << std::endl;
	
	auto function = HelloWorld;

	function();
	function();


	// 2 - traditionally
	std::cout << "Example 2: traditional" << std::endl;

	void(*someName)() = HelloWorld;
	
	someName();


	// 3 - using typedef to make things clear
	std::cout << "Example 3: easy to read" << std::endl;

	typedef void(*SomeCoolName)();
	SomeCoolName myFunction = HelloWorld;

	myFunction();


	// of course we can pass parameters
	// 4 - passing parameters
	std::cout << "Example 4: passing parameters" << std::endl;
	
	typedef void(*HelloWorldFunction)(int);
	HelloWorldFunction myFuncWithParam = HelloWorldWithParam;

	myFuncWithParam(1);
	myFuncWithParam(2);
	myFuncWithParam(999);


	// practical use
	// 5 - Make your own forEach
	std::cout << "Example 5: Practical use" << std::endl;

	std::vector<int> values = { 1, 2, 3, 5, 8, 13, 21 };
	ForEach(values, PrintValue);


	// 6 - lambda
	std::cout << "Example 6: Anonymous function" << std::endl;

	ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });

	std::cout << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}