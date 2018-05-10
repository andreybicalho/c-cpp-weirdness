#include <iostream>
#include <string>


template<typename T>
void Print(T value)
{
	std::cout << value << std::endl;
}


template<int N>
class IntArray
{
private:
	int m_Array[N];
public:
	int GetSize() const { return N; }

};

template<typename T, int N>
class Array
{
private:
	T m_Array[N];
public:
	int GetSize() const { return N; }

};

int main()
{

	{
		// 1 - function template: implicit
		std::cout << std::endl << "Example 2 - Function Template: implicit conversion" << std::endl;
		Print(5); // int
		Print("Hello"); // string
		Print(5.5f); // float

		// 2 - function template: explicit
		std::cout << std::endl << "Example 2 - Function Template: explicit conversion" << std::endl;
		Print<int>(5);
		Print<std::string>("Nuy");
		Print<float>(5.5f);
	}

	{
		// 3 - class template: a simple array (allocated on the stack)
		std::cout << std::endl << "Example 3 - Class Template: a simple array" << std::endl;
		IntArray<5> array;
		std::cout << array.GetSize() << std::endl;
	}


	{
		// 4 - class template: a generic array (allocated on the stack)
		std::cout << std::endl << "Example 4 - Class Template: a generic array" << std::endl;
		Array<float, 5> array;
		std::cout << array.GetSize() << std::endl;
	}







	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}