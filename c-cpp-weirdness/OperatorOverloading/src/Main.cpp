#include <iostream>
#include <string>


struct Vector2
{
	float x, y;

	Vector2(float x, float y) : x(x), y(y) {}

	Vector2 Add(const Vector2& other) const 
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	// overloading operators
	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	bool operator==(const Vector2& other) const 
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		return !(*this == other); // remember == is already overloaded
	}

};

// overloading '<<' operator from std::ostream
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;

	return stream;
}

int main()
{
	// situation
	Vector2 position(4.f, 4.f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerUp(1.1f, 1.1f);

	{
		Vector2 result = position.Add(speed.Multiply(powerUp));
	}


	{
		// same thing with operator overloading
		Vector2 result = position + speed * powerUp;
		
		// now overloading std '<<' operator
		std::cout << result << std::endl;
	}


	{
		// another example with '==' and '!=' operators
		Vector2 positionA(1.5f, 2.f);
		Vector2 positionB( 1.f, 1.1f);
		Vector2 positionC(1.5f, 2.f);
		if (positionA == positionB)
		{
			std::cout << "Position A is equal to Position B" << std::endl;
		}

		if (positionA != positionB)
		{
			std::cout << "Position A is different from Position B" << std::endl;
		}

		if (positionA == positionC)
		{
			std::cout << "Position A is equal to Position C" << std::endl;
		}
	}



	std::cout << std::endl << std::endl << "Press any key to exit..." << std::endl;
	std::cin.get();
	return 0;
}