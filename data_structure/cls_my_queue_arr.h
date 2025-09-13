#pragma once
#include "cls_dynamic_array.h"
using namespace std;

template <class T>

class cls_my_queue_arr
{
protected :

	cls_dynamic_array<T> array;

public : 


	void push(T value)
	{
		array.insert_at_beginning(value);
	}

	void pop()
	{
		array.delete_last_item();
	}

	void print()
	{
		array.print_array();
	}

	short size()
	{
		return array.size();
	}

	T front()
	{
		return array.get_item(array.size() - 1);
	}

	T back()
	{
		return array.get_item(0);
	}

	T get_item(int index)
	{
		return array.get_item(index);
	}

	void reverse()
	{
		array.reverse();
	}

	void insert_at_front(T value)
	{
		array.insert_at_end(value);
	}

	void insert_at_back(T value)
	{
		array.insert_at_beginning(value);
	}

	void clear()
	{
		array.clear();
	}

	void insert_after(int index, T value)
	{
		array.insert_after(index, value);
	}

	bool update_item(int index, T value)
	{
		return array.set_item(index , value);
	}

};

