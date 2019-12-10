#include <d3d11.h>
#include <math.h>
#include<SimpleMath.h>
#include <ctime>
#include<chrono>
#include <iostream> 
#include<vector>
#include"Maths.h"
using namespace DirectX::SimpleMath;


int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	FTD::Vector3 test = { 2.01f,3,4 };
	FTD::Vector3 test2 = { 0,10,0 };
	FTD::Vector3 result = test.cross(test2);
	FTD::Vector4 wow(test, 1.0f);
	test2.normalize();
	FTD::Vector3 resutlREf = FTD::Vector3::reflect(test, FTD::Vector3(0, 1, 0));
	FTD::Vector3 testM = test*22;

	Vector3 ban(1, 23, 4);
	Vector3 testMS = ban * 2.0f;
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;

	std::cout << test2 << std::endl;

	return 0;
}