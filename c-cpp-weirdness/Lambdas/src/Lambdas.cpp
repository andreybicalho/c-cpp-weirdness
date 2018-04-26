/*
	Lambdas in C++
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}

void ForEach2(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);
}

int main()
{
	// 1 - previously in function pointers...
	{
		std::cout << "Example 1:" << std::endl;

		std::vector<int> values = { 1, 2, 3, 5, 8, 13, 21 };
		auto lambda = [](int value) { std::cout << "Value: " << value << std::endl; };

		ForEach(values, lambda);
	}

	// captures
	// 2 - capture by copy
	{
		std::cout << std::endl << "Example 2:" << std::endl;
		int somethingToCapture = 5;

		auto lambda = [somethingToCapture]() {std::cout << "Value: " << somethingToCapture << std::endl; };

		lambda();
	}

	// 3 - capture by reference
	{
		std::cout << std::endl << "Example 3:" << std::endl;
		int somethingToCapture = 10;

		auto lambda = [&somethingToCapture]() {std::cout << "Value: " << somethingToCapture << std::endl; };
		lambda();
	}

	// 4 - capture all by copy
	{
		std::cout << std::endl << "Example 4:" << std::endl;
		int somethingToCapture = 10;
		int otherThingToCapture = 99;

		auto lambda = [=]() {std::cout << "Values: " << somethingToCapture << ", " << otherThingToCapture << std::endl; };
		lambda();
	}

	// 5 - capture all by reference
	{
		std::cout << std::endl << "Example 5:" << std::endl;
		int somethingToCapture = 10;
		int otherThingToCapture = 99;

		auto lambda = [&]() { somethingToCapture = 50;  std::cout << "Values: " << somethingToCapture << ", " << otherThingToCapture << std::endl; };
		lambda();
	}

	// 6 - mutable
	{
		std::cout << std::endl << "Example 6:" << std::endl;
		int somethingToCapture = 10;

		// this will not compile
		// auto lambda = [somethingToCapture]() { somethingToCapture = 5;   std::cout << "Values: " << somethingToCapture << std::endl; };
		
		auto lambda = [somethingToCapture]() mutable { somethingToCapture = 5;   std::cout << "Values: " << somethingToCapture << std::endl; };
		
		lambda();
	}

	// 7 - using std functional lib
	{
		std::cout << std::endl << "Example 7:" << std::endl;
		std::vector<int> values = { 1, 2, 3, 5, 8, 13, 21 };

		auto lambda = [](int value) { std::cout << "Values: " << value << std::endl; };

		ForEach2(values, lambda);
	}

	// 8 - practical use: use lambada function thats returns bool to find the first number greater than 3 in the array (find_if from algorithm lib)
	{
		std::cout << std::endl << "Example 8:" << std::endl;
		std::vector<int> values = { 1, 5, 4, 2, 3, 10 };

		auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
		std::cout << *it << std::endl;
	}



	std::cout << std::endl << std::endl <<  "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}