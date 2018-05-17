#include <iostream>

struct Vector2
{
	float x, y;
};


struct Vector4
{
	float x, y, z, w;

	Vector2 AccessingElementByCopy() // not efficient
	{
		Vector2 xy = { x, y };
		return xy;
	}

	Vector2& AccessViaTypePunning() // efficient way, but a bit confusing
	{
		return *(Vector2*)&x;
	}	
};


struct Vector4Union
{
	union
	{
		struct  
		{
			float x, y, z, w;
		};
		struct  
		{
			Vector2 a, b;
		};
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	{
		// example 1: union as a way of "type punning"
		struct MyUnion
		{
			// two different ways to access the same address because a and b has the same memory address
			union
			{
				float a; 
				int b;
			};
		};

		MyUnion u;
		u.a = 2.0f;
		std::cout << u.a << ", " << u.b << std::endl;
	}


	{
		// example 2: accessing elements with type punning
		Vector4 v4 = { 1.1f, 2.2f, 3.3f, 4.4f };
		
		// not efficient way
		Vector2 v = v4.AccessingElementByCopy();

		// we know we could access elements without copying them
		Vector2& v2 = v4.AccessViaTypePunning();

		std::cout << v2.x << ", " << v2.y << std::endl;
	}

	{
		// example 3: accessing elements with union
		Vector4Union v4 = { 1.1f, 2.2f, 3.3f, 4.4f };
		PrintVector2(v4.a);
		PrintVector2(v4.b);
		
		std::cout << "----------------------" << std::endl;

		v4.z = 500.f;

		PrintVector2(v4.a);
		PrintVector2(v4.b);
	}





	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}