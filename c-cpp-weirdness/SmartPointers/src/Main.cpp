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

	// shared pointers: smart pointers that can be shared, deleting only happens when all shared references go out of scope.

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
			[](Entity* p) { std::cout << "Custom deleting. " << std::endl; delete p; }); // using lambda

		// practical use of custom deleting with lambdas
		// std::shared_ptr<Entity> p3(new Entity[3]); // dog[1] and dog[2] have memory leaks! this will crash
		// the safer way is by using lambdas:
		std::shared_ptr<Entity> p4(new Entity[3], [](Entity* p) {delete[] p; }); // all 3 entities will be deleted when p4 goes out of scope
	}


	// example 7: shared pointers, returning the raw pointer
	std::cout << std::endl << "\nExample 7:" << std::endl;
	{
		std::shared_ptr<Entity> p1 = std::make_shared<Entity>("entityOne"); // using default deleter: operator delete
		
		Entity* e = p1.get(); // returns the raw pointer, bad idea, use it with extra care!

		// this would lead to undefined behaviors
		// delete e;
		// std::shared_ptr<Entity> p2(e);
	}








	// unique pointers: light weight smart pointer, this is the fastest smart pointer.

	// example 8: unique pointers, don't copy it. 
	std::cout << std::endl << "\nExample 8:" << std::endl;
	{
		std::unique_ptr<Entity> p1 = std::make_unique<Entity>("entityOne"); 
		// std::unique_ptr<Entity> p2 = p1; this can't be done
	}


	// example 9: unique pointers, releasing auto management
	std::cout << std::endl << "\nExample 9:" << std::endl;
	{
		std::unique_ptr<Entity> p1 = std::make_unique<Entity>("entityOne");
		
		Entity* e = p1.release(); // p1 give up ownership

		if(!p1)
		{ 
			std::cout << "\np1 is empty.\n";
		}

		e->printName();
	}
	// entityOne is not deleted

	// example 10: unique pointers, transferring ownership
	std::cout << std::endl << "\nExample 10:" << std::endl;
	{
		std::unique_ptr<Entity> p1 = std::make_unique<Entity>("entityOne");
		std::unique_ptr<Entity> p2 = std::make_unique<Entity>("entityTwo");

		p2->printName();
		p2 = std::move(p1);
		p2->printName();
		// consequences:
		// 1. entityTwo is destroyed
		// 2. p1 becomes empty
		// 3. p2 owns entityOne
	}

	// example 11: unique pointers, deleting arrays
	std::cout << std::endl << "\nExample 11:" << std::endl;
	{
		std::unique_ptr<Entity[]> ps(new Entity[3]);
		// don't need to make a lambda function to delete the array... all 3 entities will be automatically deleted
	}








	// weak pointers: same as shared pointers but it doesn't have the counting management system
	// example 12: unique pointers, deleting arrays
	std::cout << std::endl << "\nExample 12:" << std::endl;
	{
		std::weak_ptr<Entity> p1;

		{
			std::shared_ptr<Entity> p2 = std::make_shared<Entity>("entityOne");

			p1 = p2;
		}
		// p2 is destroyed, so does p1, however we can check if p1 is still 'valid', or better saying 'expired'

		if(p1.expired())
		{ 
			std::cout << "p1 is invalid!\n";
		}
	}




	// TODO (andrey): casting smart pointers to a different pointer
	// static_pointer_cast
	// dynamic_pointer_cast
	// const_pointer_cast


	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}