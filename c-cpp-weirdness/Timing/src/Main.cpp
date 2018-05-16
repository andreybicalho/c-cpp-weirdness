#include <iostream>
#include <thread>
#include <chrono>


struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
			
		float durationInMiliseconds = duration.count() * 1000.f;
		std::cout << "Timer took " << durationInMiliseconds << "ms" << std::endl;
	}
};

void Function(int n)
{
	Timer timer;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Hello " << i << std::endl;
	}
}


int main()
{
	using namespace std::literals::chrono_literals;

	{
		// example 1: counting duration of some code
		auto start = std::chrono::high_resolution_clock::now(); // current time

		std::this_thread::sleep_for(1s);

		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> duration = end - start;
		std::cout << duration.count() << std::endl;
	}


	{
		// example 2: elegant way of counting how long some piece of code took to execute
		Function(100);
	}


	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}