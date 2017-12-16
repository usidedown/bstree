#pragma once
#include <deque>
#include <tuple> // for pair
#include <limits> // for max limit

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

	static const auto NULL_VALUE = std::numeric_limits<size_type>::max();

public:
	// TODO return iterator
	// TODO T&& version
	std::pair<size_type,bool> insert(const T& value);

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

	bool empty() const
	{
		return _storage.empty();
	}

	void reserve(size_type capacity)
	{
		_storage.reserve(capacity);
	}

private:


private:
	Container _storage;
	size_type root;
};

template <typename T>
std::pair<typename binary_search_tree<T>::size_type, bool> binary_search_tree<T>::insert(const T& value)
{
	if (empty())
	{
		_storage.push_back(node<T>{ NULL_VALUE, NULL_VALUE, NULL_VALUE, value});

		root = 0;
		return { 0, true };
	}

	// gotta find position
	auto cur = root;
	auto prev = cur;
	bool is_left_child = false;
	while (true)
	{
		const auto& cur_node = _storage[cur];
		const auto& cur_value = cur_node.value;
		const auto& left = cur_node.left;
		const auto& right = cur_node.right;

		prev = cur;

		if (value < cur_value)
		{
			cur = left;
			is_left_child = true;
		}
		else if (value > cur_value)
		{
			cur = right;
			is_left_child = false;

		}
		else
		{
			return { cur, false };
		}

		if (cur == NULL_VALUE)
		{
			break;
		}
	}

	_storage.push_back(node<T>{ prev, NULL_VALUE, NULL_VALUE, value});
	const auto pos = size() - 1;

	if (is_left_child)
	{
		_storage[prev].left = pos;
	}
	else
	{
		_storage[prev].right = pos;
	}

	return { pos, true };
}
