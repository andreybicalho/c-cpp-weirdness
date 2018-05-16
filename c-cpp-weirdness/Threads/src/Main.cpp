#include <iostream>
#include <thread>

static bool s_Finished = false;


void DoWork()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;

	while (!s_Finished) {
		std::cout << "Working...\n";
		std::this_thread::sleep_for(1s); // wait 1 second
	}
}


int main()
{
	{ 
		// example 1
		std::thread worker(DoWork);

		std::cin.get();
		s_Finished = true;

		worker.join(); // wait till DoWork finish its job
		std::cout << "Finished." << std::endl;
	}



	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}