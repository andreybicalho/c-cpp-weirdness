#include <iostream>


struct Data
{
	double v1; // 8 bytes - 0 to 8
	
	int v2; // 1 byte - 

	float v3; // 4 bytes
	float v4; // 4 bytes

	double v5; // 1 byte
};

int main()
{
	std::cout << "sizeof(double) = " << sizeof(double) << "\nsizeof(float) = " << sizeof(float) << "\nsizeof(int) = " << sizeof(int)  << "\nsizeof(char) = " << sizeof(char) << std::endl;
	



	int v1_offset = (int)&((Data*)nullptr)->v1;
	int v2_offset = (int)&((Data*)nullptr)->v2;
	int v3_offset = (int)&((Data*)nullptr)->v3;
	int v4_offset = (int)&((Data*)nullptr)->v4;
	int v5_offset = (int)&((Data*)nullptr)->v5;

	std::cout << "v1 = " << v1_offset << " v2 = " << v2_offset << " v3 = " << v3_offset << " v4 = " << v4_offset << " v5 = " << v5_offset << std::endl;

	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}