#include <iostream>

class Base
{
public:
	Base() { }
	virtual ~Base() { }
};

class Derived : public Base 
{
public:
	Derived() { }
	~Derived() { }
};

class AnotherClass : public Base
{
public:
	AnotherClass() { }
	~AnotherClass() { }
};

int main()
{

	std::cout << "Casting is all about interpreting memory as some desired type.\n";

	std::cout << "\nExample 1: C Style\n";
	{
		double value = 5.25;
		int a = (int)value;
		std::cout << a << "\n";
	}


	std::cout << "\nExample 2: C++ Style\n";
	{
		double value = 5.25;
		int a = static_cast<int>(value);
		std::cout << a << "\n";
	}


	std::cout << "\nExample 3: C++ dynamic cast\n";
	{
		Derived* derived = new Derived();

		Base* base = derived;

		AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
		if (!ac)
		{
			std::cout << "\nbase is NOT an instance of AnotherClass!\n";
		}

		Derived* d = dynamic_cast<Derived*>(base);
		if (d)
		{
			std::cout << "\nbase is an instance of Derived!\n";
		}
	

	}


	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}