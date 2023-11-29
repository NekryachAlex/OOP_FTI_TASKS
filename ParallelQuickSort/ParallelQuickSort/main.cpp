#include "QuickSort.h"
#include <iostream>
#include <array>
#include <fstream>
#include <random>
#pragma optimize( "", off )
int main()
{

	std::ofstream testFile;   
	testFile.open("LowerBorderTest.txt");
	if (testFile.is_open())
	{
		testFile << "Size of array" << " | " << " Time of one thread sort, ms" << " | " << "Time of parallel sort, ms" << std::endl;   
		//testFile << "Size of array" << " | " << "Threads " << " | " << " Time of sort, mcs" << std::endl;
		/*for (size_t i = 20; i < 1000; i += 10)
		{
			testFile << "------\n";
			std::vector<int> testArray;
				for (int k = 0; k < i; k++)
				{
					testArray.push_back(rand());
				}
		
			for (size_t j = 1; j <= 12; j++)
			{
				testFile << i << ";";
				testFile << j << ";";
				auto beginParallel = std::chrono::steady_clock::now();
				sortFunction::quickSort(testArray.begin(), testArray.end(),j);
				auto endParallel = std::chrono::steady_clock::now();
				auto durationParallel = std::chrono::duration_cast<std::chrono::microseconds>(endParallel - beginParallel);
				testFile << durationParallel.count() << "\n";
			}*/
		}
		
		for (size_t i = 100; i < 120000; i += 100)
		{
			testFile << i << " | ";
			std::vector<int> testArray;
			for (int k = 0; k < i; k++)
			{
				testArray.push_back(rand());
			}
			std::random_device rd;
			std::mt19937 g(rd());
			std::shuffle(testArray.begin(), testArray.end(), g);
			auto beginOneThread = std::chrono::steady_clock::now();
			sortFunction::sort(testArray.begin(), testArray.end());
			auto endOneThread = std::chrono::steady_clock::now();
			auto durationOneThread = std::chrono::duration_cast<std::chrono::microseconds>(endOneThread - beginOneThread);
			testFile << durationOneThread.count() << " | ";

			auto beginParallel = std::chrono::steady_clock::now();
			sortFunction::quickSort(testArray.begin(), testArray.end());
			auto endParallel = std::chrono::steady_clock::now();
			auto durationParallel = std::chrono::duration_cast<std::chrono::microseconds>(endParallel - beginParallel);
			testFile << durationParallel.count() << "\n";

			
		}
	
	testFile.close();
	std::cout << "File has been written" << std::endl;

	return 0;
}