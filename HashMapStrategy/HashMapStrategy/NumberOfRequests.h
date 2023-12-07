#pragma once
#include "Strategy.h"
#include <unordered_map>
template<class TypeOfKey>
class NumberOfRequestStrategy final : public Strategy<TypeOfKey>
{
	std::unordered_map<TypeOfKey, size_t> counter;
	using iterator = typename std::unordered_map<TypeOfKey, size_t>::iterator;

	size_t limit;

public:
	NumberOfRequestStrategy(size_t _counter) : limit(_counter){}

	void remove(const TypeOfKey& key) override
	{
		counter.erase(key);
	}

	bool getPermission(const TypeOfKey& key) override
	{
		return ((counter.find(key) != counter.end()) && (counter[key] != limit));
	}

	bool getAccess(const TypeOfKey& key) override
	{
		if (getPermission(key))
		{
			++counter[key];
			return true;
		}
		return false;
	}

	bool insert(const TypeOfKey& key) override
	{
		std::pair<iterator, bool> insertedValue = counter.insert(std::pair<const TypeOfKey, size_t>(key, 0));
		return insertedValue.second;
	}
};