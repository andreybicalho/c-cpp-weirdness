/*
	Function Pointers
*/

#include <iostream>
#include <vector>



//////////////////////////////////////////////////////////////////////////
/*
	Casey Muratori C Style function pointer
*/
#include "SomeCoolFunction.h"

#define COOL_FUNCTION(name) int name(int a, int b)
typedef COOL_FUNCTION(FunctionSignature_Type);
COOL_FUNCTION(SumToNumbers_Stub) // stub default, if nothing is assigned to Sum it will have this body
{
	std::cout << std::endl << "Stub default, please use a real SUM function." << std::endl;

	return -1;
}

static FunctionSignature_Type* Sum_ = SumToNumbers_Stub;
#define Sum Sum_
//////////////////////////////////////////////////////////////////////////







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
	{		
		std::cout << "Example 1: easy way" << std::endl;

		auto function = HelloWorld;

		function();
		function();
	}

	// 2 - traditionally
	{
		std::cout << std::endl << "Example 2: traditional" << std::endl;

		void(*someName)() = HelloWorld;

		someName();


		// 3 - using typedef to make things clear
		std::cout << std::endl << "Example 3: easy to read" << std::endl;

		typedef void(*SomeCoolName)();
		SomeCoolName myFunction = HelloWorld;

		myFunction();
	}

	// of course we can pass parameters
	// 4 - passing parameters
	{
		std::cout << std::endl << "Example 4: passing parameters" << std::endl;

		typedef void(*HelloWorldFunction)(int);
		HelloWorldFunction myFuncWithParam = HelloWorldWithParam;

		myFuncWithParam(1);
		myFuncWithParam(2);
		myFuncWithParam(999);
	}

	// practical use
	// 5 - Make your own forEach
	{
		std::cout << std::endl << "Example 5: Practical use" << std::endl;

		std::vector<int> values = { 1, 2, 3, 5, 8, 13, 21 };
		ForEach(values, PrintValue);
	}

	// 6 - lambda
	{
		std::cout << std::endl << "Example 6: Anonymous function" << std::endl;

		std::vector<int> values = { 1, 2, 3, 5, 8, 13, 21 };
		ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
	}



	
	
	// wait for it...





	// 7 - coolest function pointer ever - C Style by Casey Muratori
	{
		std::cout << std::endl << "Example 7: C Style by Casey Muratori" << std::endl;
		int a = 5;
		int b = 5;
	
		// nothing is assigned to Sum. it will call default stub
		int c = Sum(a, b);
		std::cout << a << " + " << b << " = " << c << std::endl;

		// lets point to the cool function
		Sum = (FunctionSignature_Type*)coolStuff::SumTwoNumbers;
		
		c = Sum(a, b);
		std::cout << a << " + " << b << " = " << c << std::endl;	
	}




	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}