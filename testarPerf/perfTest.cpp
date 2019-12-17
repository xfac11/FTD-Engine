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
	FTD::Vector4 test(4, 2, 4, 3);
	FTD::Matrix matrix(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	FTD::Matrix matrix2(2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);

	FTD::Vector4 result = matrix.transform(test);
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;

	std::cout << result << std::endl;

	return 0;
}