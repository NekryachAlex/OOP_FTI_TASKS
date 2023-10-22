#pragma once
#include <unordered_map>
#include <utility>

template<class TypeOfValue, class TypeOfKey, template<class TypeOfKeyOfStrategy> class Strategy, typename ... Types>
class HashMap final
{

public:	
	using Map = std::unordered_map<TypeOfKey, TypeOfValue>;
	using mapIter = typename Map::iterator;
	
private:
	Map table;
	Strategy<TypeOfKey> strategy;

	class HashMapIterator final
	{
	private:
		HashMap<TypeOfKey, TypeOfValue, Strategy, Types ...>& map;
		mapIter iterator;
		Strategy<Types ...>& strategy;
		Map& table;

	public:
		using iterator_category = std::forward_iterator_tag;;
		using difference_type = std::ptrdiff_t;
		using value_type = std::pair<const TypeOfKey, TypeOfValue>;
		using pointer = std::pair<const TypeOfKey, TypeOfValue>*;
		using reference = TypeOfValue&;

		HashMapIterator(HashMap<TypeOfValue, TypeOfKey, Strategy, Types ...>& _map, mapIter _iterator) :
			map(_map), iterator(_iterator), strategy(_map.strategy), table(_map.table) {}

		bool operator!=(const HashMapIterator& _another) const
		{
			return iterator != _another.iterator;
		}
		bool operator ==(const HashMapIterator& _another) const
		{
			return iterator == _another.iterator;
		}

		HashMapIterator& operator++()
		{
			++iterator;
			if (iterator != table.end())
			{
				TypeOfKey key = (*iterator).first;
				if (strategy.getPermission(key))
				{
					break;
				}
				++iterator;
			}
			return *this;
		}

		reference operator*() const
		{
			TypeOfKey key = (*this).first;
			bool permissoin = strategy.getAccess(key);
			if (permissoin)
			{
				return (*iterator);
			}
			throw std::out_of_range("no permissoin to this iterator");
		}

		pointer operator->()
		{
			return iterator;
		}
	};


private:
	HashMapIterator getIterator(const TypeOfKey& key)
	{
		return HashMapIterator(*this, table.find(key));
	}
public:
	HashMap(Types ... Args) : strategy(Args...) {}
	
	std::pair<HashMapIterator, bool> insert(const std::pair<const TypeOfKey, TypeOfValue>& _info)
	{

		bool permission = strategy.insert(_info.first);
		if (permission)
		{
			std::pair<mapIter, bool> stdIterator = table.insert(_info);
			HashMapIterator myIterator(*this, stdIterator.first);
			return { myIterator, stdIterator.second };
		}
		return { getIterator(_info.first), false }; //вернет end() если нет в таблице
	}

	HashMapIterator begin()
	{
		auto mapIterator = table.begin();
		if (mapIterator == table.end())
		{
			return HashMapIterator(*this, mapIterator);
		}

		TypeOfKey key = (*mapIterator).first;
		while (!strategy.getPermission(key))
		{
			++mapIterator;
			if (mapIterator == table.end())
			{
				break;
			}
			else
			{
				key = (*mapIterator).first;
			}
		}
		return HashMapIterator(*this, mapIterator);
	}

	HashMapIterator end()
	{
		return HashMapIterator(*this, table.end());
	}

	void erase(TypeOfKey _key)
	{
		strategy.remove(_key);
		table.erase(_key);
	}

	TypeOfValue& operator[] (const TypeOfKey& _key)
	{

		bool isAvailable = strategy.getAccess(_key);
		if (!isAvailable)
		{
			if (table.find(_key) != table.end())
			{
				strategy.remove(_key);
				table.erase(_key);
			}
		}
		return table[_key];
	}
};