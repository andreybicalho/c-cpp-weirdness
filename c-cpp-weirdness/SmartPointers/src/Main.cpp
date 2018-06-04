#include <iostream>
#include <memory>
#include <string>

class Entity
{
private:
	std::string name;
public:
	Entity(std::string name) : name(name) { std::cout << "Entity " << name << " is created!" << std::endl; }
	Entity() { name = "nameless";  std::cout << "Entity " << name << " is created!" << std::endl; }
	~Entity() { std::cout << "Entity " << name << " is destroyed!" << std::endl; }
	void printName() { std::cout << "Entity: " << name << std::endl; }
};

int main()
{
	// example 1: shared pointers, counting references 1
	std::cout << std::endl << "\nExample 1:" << std::endl;
	{
		std::shared_ptr<Entity> p(new Entity("entityOne")); // count = 1
		p->printName();
		std::cout << "count: " << p.use_count() << std::endl;
	}
	// p count = 0 and p is destroyed


	// example 2: shared pointers, counting references 2
	std::cout << std::endl << "\nExample 2:" << std::endl;
	{
		std::shared_ptr<Entity> p(new Entity("entityTwo")); // p count = 1
		
		{
			std::shared_ptr<Entity> p2 = p;
			std::cout << "count: " << p.use_count() << std::endl; // p count = 2
			p2->printName();
		}
		// p2 is destroyed and p count = 1

		std::cout << "count: " << p.use_count() << std::endl;
	}
	// p is destroyed and p count = 0


	// example 3: shared pointers, Raw pointer should not be used.
	std::cout << std::endl << "\nExample 3 would crash" << std::endl;
	/*
	{
		Entity* e = new Entity("entityThree");
		std::shared_ptr<Entity> p(e); // p.use_count() == 1
		std::shared_ptr<Entity> p2(e); // p2.use_count() == 1
	}*/
	// p and p2 will be destroyed?!?! undefined behavior!


	// example 4: shared pointers
	std::cout << std::endl << "\nExample 4:" << std::endl;
	{
		Entity* e = new Entity("entityThree"); // bad idea
		std::shared_ptr<Entity> p = std::make_shared<Entity>("entityThree"); // faster and safer
	}

	// example 5: shared pointers, deleting
	std::cout << std::endl << "\nExample 5:" << std::endl;
	{
		std::shared_ptr<Entity> p1 = std::make_shared<Entity>("entityOne");
		std::shared_ptr<Entity> p2 = std::make_shared<Entity>("entityTwo");

		// 3 ways of deleting entityOne
		p1 = p2; // entityOne is deleted and p1 count = 2
		std::cout << "p1.use_count() == " << p1.use_count() << std::endl;
		p1->printName();
		
		p1 = nullptr; // entityOne is deleted, p1 count = 0
		std::cout << "p1.use_count() == " << p1.use_count() << std::endl;
		// p1->printName(); this will crash
		
		p1.reset(); // entityOne is deleted, p1 count = 0
		std::cout << "p1.use_count() == " << p1.use_count() << std::endl;
		// p1->printName(); this will crash
	}


	// example 6: shared pointers, custom deleting with lambdas
	std::cout << std::endl << "\nExample 6:" << std::endl;
	{
		std::shared_ptr<Entity> p1 = std::make_shared<Entity>("entityOne"); // using default deleter: operator delete
		std::shared_ptr<Entity> p2 = std::shared_ptr<Entity>(new Entity("entityTwo"),
			[](Entity* p) {std::cout << "Custom deleting. " << std::endl; delete p; }); // using lambda

		// practical use of custom deleting with lambdas
		std::shared_ptr<Entity> p3(new Entity[3]); // dog[1] and dog[2] have memory leaks!
		std::shared_ptr<Entity> p4(new Entity[3], [](Entity* p) {delete[] p; }); // all 3 Entity will be deleted when p4 goes out of scope
	}


	// example 7: shared pointers, returning the raw pointer
	std::cout << std::endl << "\nExample 6:" << std::endl;
	{
		std::shared_ptr<Entity> p1 = std::make_shared<Entity>("entityOne"); // using default deleter: operator delete
		
		Entity* e = p1.get(); // returns the raw pointer, bad idea, use it with extra care!

		// this would lead to undefined behaviors
		// delete e;
		// std::shared_ptr<Entity> p2(e);
	}





	// TODO (andrey): casting smart pointers to a different pointer
	// static_pointer_cast
	// dynamic_pointer_cast
	// const_pointer_cast




	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}