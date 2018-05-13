#include <iostream>

// example 1
#define OPEN_CURLY {

// example 2
#define SIMPLE_LOG(x) std::cout << x << std::endl;

// example 3
#if 0 // will inactive all of this
#define PI 3.14
#endif

// example 4
#define WAIT std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;\
std::cin.get();

// example 5
//#define C_CPP_WEIRDNESS_DEBUG 1 // or we can add C_CPP_WEIRDNESS_DEBUG=1 (without spaces!) in the preprocessor for Debug mode
#if C_CPP_WEIRDNESS_DEBUG == 1 // (better than using #ifdef C_CPP_WEIRDNESS_DEBUG) since we could use #define C_CPP_WEIRDNESS_DEBUG 1 somewhere in our code
#define LOG(x) std:: cout << x << std::endl;
#else
#define LOG(x)
#endif

int main()
OPEN_CURLY // example 1 - don't use preprocessor this way! it is obfuscating the code!

	{
		// example 2 - an useful example
		SIMPLE_LOG("Hello")
	}


	{
		// example 5 - more robust log: this will log on Debug mode and will not in Release mode
		// added C_CPP_WEIRDNESS_DEBUG to preprocessor definitions for Debug and C_CPP_WEIRDNESS_RELEASE for Release
		LOG("This Hello will show only in Debug mode")
	}

	{
		// example 3 - inactivating codes
		// float pi = PI; // will never see "PI" since "if 0" is present there
	}




	// example 4 - multiple lines
	//std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	//std::cin.get();
	WAIT
	return 0;
}
