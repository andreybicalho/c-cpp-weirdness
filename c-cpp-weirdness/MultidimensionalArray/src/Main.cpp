#include <iostream>

int main()
{
	{
		// example 1: suppose I want a 5x5 matrix.		
		int** array = new int*[5];

		for(int i=0; i < 5; i++)
		{ 
			array[i] = new int[5]; // this code may not allocate memory in a contiguous manner, leading to slow access or miss caching
		}

		// how to access elements
		for (int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5; j++)
			{ 
				array[i][j] = 1;
			}
		}

		// delete
		for (int i = 0; i < 5; i++)
		{
			delete[] array[i];
		}

		delete[] array;
	}


	{
		// optimization and keep the matrix representation (i + j * width)
		int* array = new int[5 * 5]; // while this will allocate memory in a contiguous way

		// accessing the elements and keep matrix representation
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				array[i + j * 5] = 1;
			}
		}

		delete[] array;
	}


	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}