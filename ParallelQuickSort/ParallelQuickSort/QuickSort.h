#pragma once
#include <execution>
#include <algorithm>
#include <vector>
#include <iterator>
#include <future>
#include <cmath>
#include "Policies.h"
#pragma optimize( "", off )

namespace sortFunction
{
	template <class RandomAccessIterator, typename Compare = std::less<>>
	void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp = Compare{}) {
		auto size = std::distance(first, last);
		if (size < 2) {
			return;
		}

		RandomAccessIterator left = first;
		RandomAccessIterator right = last - 1;
		RandomAccessIterator pivot = (first + size / 2);
		
		while (1)
		{
			while (comp(*left, *pivot))
			{
				++left;
			}
			while (comp(*pivot, *right))
			{
				--right;
			}
			if (left >= right)
			{
				break;
			}

			std::iter_swap(left++, right--);
		}
		sortFunction::sort(first, left, comp);
		sortFunction::sort(left, last, comp);
	}

	template <class RandomAccessIterator, typename Compare = std::less<>,
			typename T = std::enable_if<std::is_same<typename std::iterator_traits<RandomAccessIterator>::iterator_category,
			std::random_access_iterator_tag>::value>>
		void quickSort(RandomAccessIterator first, RandomAccessIterator last,  Compare comp = Compare{}) {
		size_t NumberOfThreads = std::thread::hardware_concurrency();
		auto size = std::distance(first, last);
		auto SizeOfSlice = static_cast<size_t>(floor(static_cast<double>(size) / static_cast<double>(NumberOfThreads)));

		if (NumberOfThreads != 1 && NumberOfThreads != 0) {
			std::vector<RandomAccessIterator> slices;

			for (size_t i = 0; i < NumberOfThreads; ++i)
			{
				auto slice = first + i * SizeOfSlice;
				slices.push_back(slice);
			}
			slices.push_back(last);

			std::vector<std::future<void>> futures;
			for (size_t i = 0; i < slices.size() - 1; ++i)
			{
				futures.push_back(std::async(std::launch::async,
					sortFunction::sort<RandomAccessIterator, Compare>, std::ref(slices[i]), std::ref(slices[i + 1]), std::ref(comp)));
			}

			for (auto& thread : futures)
			{
				thread.wait();
			}

			for (size_t i = 0; i < slices.size() - 2; ++i)
			{
				std::inplace_merge(slices[0], slices[i + 1], slices[i + 2], comp);
			}
		}
		else
		{
			sortFunction::sort(first, last, comp);
		}
	}
};