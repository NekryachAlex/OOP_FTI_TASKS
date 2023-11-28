#include "Policies.h"
#include "QuickSort.h"
#include <iostream>
#include <array>
#include <fstream>
int main()
{

	std::ofstream testFile;   
	testFile.open("LowerBorderTest.txt");
	if (testFile.is_open())
	{
		testFile << "Size of array" << " | " << "Time of parallel sort, ms" << " | " << " Time of one thread sort, ms" << std::endl;

		for (size_t i = 900; i < 1000; i += 100)
		{
			testFile << i << " | ";
			std::vector<int> testArray;
			for (int k = 0; k < i; k++)
			{
				testArray.push_back(rand());
			}

			auto beginParallel = std::chrono::steady_clock::now();
			sortFunction::quickSort(testArray.begin(), testArray.end());
			auto endParallel = std::chrono::steady_clock::now();
			auto durationParallel = std::chrono::duration_cast<std::chrono::microseconds>(endParallel - beginParallel);
			testFile << durationParallel.count() << " | ";

			auto beginOneThread = std::chrono::steady_clock::now();
			sortFunction::sort(testArray.begin(), testArray.end());
			auto endOneThread = std::chrono::steady_clock::now();
			auto durationOneThread = std::chrono::duration_cast<std::chrono::microseconds>(endOneThread - beginOneThread);
			testFile << durationOneThread.count() << "\n";
		}

	}
	testFile.close();
	std::cout << "File has been written" << std::endl;

	return 0;
}