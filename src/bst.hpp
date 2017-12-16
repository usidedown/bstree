#pragma once
#include <deque>

template <typename T>
struct node
{
	using size_type = size_t; // TODO get this from container?

	size_type left;
	size_type right;
	size_type parent;
	T value;
};

template<typename T>
class binary_search_tree
{
	using Container = std::deque<node<T>>; // TODO use template magicke to allow to change this to vector
	using size_type = typename Container::size_type;

public:
	// TODO return iterator
	// TODO T&& version
	size_type insert(const T& value);

	// TODO return iterator
	// TODO T&& version
	size_type erase(const T& value);

	// TODO return iterator, get iterator
	size_type erase(size_type index);

	size_type size() const
	{
		return _storage.size();
	}

	size_type capacity() const
	{
		return _storage.size();
	}

	void reserve(size_type capacity)
	{
		_storage.reserve(capacity);
	}

private:
	Container _storage;
	size_type root;
};

