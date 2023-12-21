#pragma once
#include <thread>
#include <map>

class Policy
{
public:
	Policy() = default;
	virtual size_t getNumberOfThreads(size_t  size) const = 0;
};

class OneThreadPolicy final : public Policy
{
public:
	OneThreadPolicy() = default;
	virtual size_t getNumberOfThreads(size_t  size) const override
	{
		return 1;
	}
};

class MaxThreadsPolicy final : public Policy
{
public:
	MaxThreadsPolicy() = default;
	virtual size_t getNumberOfThreads(size_t  size) const override
	{
		return std::thread::hardware_concurrency();
	}
};

class SuitablePolicy final : public Policy
{
private:
	std::map<size_t, size_t> suitableAmount
	{
		{500, 2},
		{1000, 3},
		{2000, 4},
		{4000, 5},
		{5000, 6},
		{13000, 7},
		{26000, 8},
		{47000, 9},
		{150000, 10},
		{440000, 11},
		{500000, 12}
	};
public:
	SuitablePolicy() = default;
	virtual size_t getNumberOfThreads(size_t  size = 100) const override
	{ 
		auto mapIterator = suitableAmount.lower_bound(size);
		if (mapIterator == suitableAmount.end())
		{
			return 1;
		}
		return mapIterator->second - 1;
	}
};