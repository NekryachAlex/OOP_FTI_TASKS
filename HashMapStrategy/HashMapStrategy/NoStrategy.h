#pragma once
#include "Strategy.h"
#include <unordered_set>

template<class TypeOfKey>
class NoStrategy : public Strategy<TypeOfKey>
{
	std::unordered_set<TypeOfKey> keys;
	using iterator = typename std::unordered_set<TypeOfKey>::iterator;

	virtual bool getPermission(const TypeOfKey& key)
	{
		return (keys.find(key) != keys.end());
	}

	virtual bool getAccess(const TypeOfKey& key)
	{
		return getPermission(key);
	}

	virtual void remove(const TypeOfKey& key)
	{
		keys.erase(key);
	}
	virtual bool insert(const TypeOfKey& key)
	{
		std::pair<iterator, bool> stdIterator = keys.insert(key);
		return stdIterator.second;
	}
	
};