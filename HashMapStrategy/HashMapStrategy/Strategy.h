#pragma once
template<class TypeOfKey>
class Strategy
{
public:

	virtual bool getAccess(const TypeOfKey& key) = 0;
	virtual void remove(const TypeOfKey& key) = 0;
	virtual bool insert(const TypeOfKey& key) = 0;
	virtual bool getPermission(const TypeOfKey& key) = 0;
};