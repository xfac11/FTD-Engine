
#include <d3d11.h>
#include <math.h>
#include<SimpleMath.h>
#include <ctime>
#include<chrono>
#include <iostream> 
#include<vector>
using namespace DirectX::SimpleMath;
namespace FTD 
{
	

	struct Vector3
	{
		float x;
		float y;
		float z;

		const float& dot(const Vector3& vec)
		{
			return (x * vec.x + y * vec.y + z * vec.z);
		};
		static const float& dot(const Vector3& vec, const Vector3& vec2)
		{
			return (vec2.x * vec.x + vec2.y * vec.y + vec2.z * vec.z);
		};
		const Vector3& add(const Vector3& vec)
		{
			return Vector3{ vec.x + x,vec.y + y,vec.z + z };
		};
		static const Vector3& add(const Vector3& vec, const Vector3& vec2)
		{
			return Vector3{ vec.x + vec2.x,vec.y + vec2.y,vec.z + vec2.z };
		};
		const Vector3& operator+(const Vector3& vec)
		{
			return Vector3{ vec.x + x,vec.y + y,vec.z + z };
		};
		const Vector3& operator-(const Vector3& vec)
		{
			return Vector3{ vec.x - x,vec.y - y,vec.z - z };
		};
		const Vector3& operator*(const float& scale)
		{
			return Vector3{ scale * x, scale * y, scale * z };
		};
		const Vector3& operator/(const float& scale)
		{
			return Vector3{ scale / x, scale / y, scale / z };
		};
		const Vector3& operator+(const float& vec)
		{
			return Vector3{ vec + x,vec + y,vec + z };
		};
	};
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	/*FTD::Vector3 test = { 2,4,1 };
	FTD::Vector3 test2 = { 3,2,6 };
	std::vector<FTD::Vector3> vecTest;
	for (int i = 0; i < 20; i++)
	{
		float dot = FTD::Vector3::dot(test, test2);
		test = test + dot;
		vecTest.push_back(test);
	}*/
	/*for (int i = 0; i < 20; i++)
	{
		float dot = FTD::Vector3::dot(test, test2);
		test = test + dot;
		vecTest.push_back(test);

	}
	for (int i = 0; i < 20; i++)
	{
		float dot = FTD::Vector3::dot(test, test2);
		test = test + dot;
		vecTest.push_back(test);

	}*/
	/*std::vector<Vector3> vecTest;
	Vector3 test = { 12,4,1 };
	Vector3 test2 = { 3,2,6 };
	for (int i = 0; i < 20000; i++)
	{
		float dot = test.Dot(test2);
		test = test + test2;
		test = test * (dot * 0.1f);
		vecTest.push_back(test);

	}
	for (int i = 0; i < 20000; i++)
	{
		float dot = test.Dot(test2);
		test = test + test2;
		test = test * (dot * 0.1f);
		vecTest.push_back(test);

	}
	for (int i = 0; i < 20000; i++)
	{
		float dot = test.Dot(test2);
		test = test + test2;
		test = test * (dot*0.1f);
		vecTest.push_back(test);

	}*/
	std::vector<Vector3> vecTest;
	Vector3 test = { 12,4,1 };
	Vector3 test2 = { 3,2,6 };
	for (int i = 0; i < 20; i++)
	{
		float dot = test.Dot(test2);
		test.x = test.x + dot;
		test.y = test.y + dot;
		test.z = test.z + dot;

		vecTest.push_back(test);

	}
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;

	std::cout << test.x << std::endl;

	system("pause");
	return 0;
}