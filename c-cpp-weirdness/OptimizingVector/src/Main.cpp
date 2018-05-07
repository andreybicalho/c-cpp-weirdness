#include <iostream>
#include <vector>


struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{
		std::cout << "Constructor!" << std::endl;
	}

	// copy constructor to show when things are copied
	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copy Constructor!" << std::endl;
	}
};


int main() 
{
	{
		// worst case scenario
		std::cout << "\nWorst case scenario: copy everything" << std::endl;

		std::vector<Vertex> vertices;
		vertices.push_back(Vertex(1, 2, 3));
		vertices.push_back(Vertex(4, 5, 6));
		vertices.push_back(Vertex(7, 8, 9));
	}


	{
		// optimization 1
		std::cout << "\nOptimization 1, when you already know how many instances you need, you can reserve it before pushing!" << std::endl;
		std::vector<Vertex> vertices;
		vertices.reserve(3);
		vertices.push_back(Vertex(1, 2, 3));
		vertices.push_back(Vertex(4, 5, 6));
		vertices.push_back(Vertex(7, 8, 9));
	}


	{
		// optimization 2
		std::cout << "\nOptimization 2, know how many instances you need, using memory created on this \"main\" function and also don't use copy constructor: " << std::endl;
		std::vector<Vertex> vertices;
		vertices.reserve(3);
		vertices.emplace_back(1, 2, 3); // also don't use copy constructor 
		vertices.emplace_back(4, 5, 6);
		vertices.emplace_back(7, 8, 9);
	}



	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}