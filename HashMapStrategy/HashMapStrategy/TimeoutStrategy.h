#pragma once
#include "Strategy.h"
#include <chrono>
#include <unordered_map>
#include <Windows.h>
template<class TypeOfKey>
class TimeoutStrategy : public Strategy<TypeOfKey>
{
	using iterator = typename std::unordered_map<TypeOfKey, ULONGLONG>::iterator;
	ULONGLONG limit;
	std::unordered_map<TypeOfKey, ULONGLONG> startingTime;

public:

	TimeoutStrategy(ULONGLONG _limit) : limit(_limit) {}

	bool getAccess(const TypeOfKey& key) override
	{
		if (startingTime.find(key) == startingTime.end())
		{
			return false;
		}
		return GetTickCount64() - startingTime[key] < limit;
	}

	void remove(const TypeOfKey& key) override
	{
		startingTime.erase(key);
	}

	bool insert(const TypeOfKey& key) override
	{
		ULONGLONG currentTime = GetTickCount64();
		std::pair<iterator, bool> insertedPair = startingTime.insert(std::pair<const TypeOfKey, ULONGLONG>(key, currentTime));
		return insertedPair.second;
	}

	bool getPermission(const TypeOfKey& key) override
	{
		return ((startingTime.find(key) != startingTime.end()) && (GetTickCount64() - startingTime[key]) < limit);
	}
};