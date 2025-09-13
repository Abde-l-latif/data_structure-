#pragma once
#include "cls_db_linked_list.h"

using namespace std; 


template<class T>

class cls_queue
{

protected :

	cls_db_linked_list <T> _list; 

public :

	void push(T value)
	{
		_list.insert_at_the_end(value);
	}

	void insert_at_front(T value)
	{
		_list.insert_at_beginning(value);
	}

	void insert_at_back(T value)
	{
		_list.insert_at_the_end(value);
	}

	void clear()
	{
		_list.clear(); 
	}

	void pop()
	{
		_list.delete_first_node(); 
	}

	short size()
	{
		return _list.size();
	}

	T front()
	{
		return _list.get_first_node();
	}

	T back()
	{
		return _list.get_last_node();
	}

	T get_item(int index)
	{
		return _list.get_item(index);
	}

	void reverse()
	{
		_list.reverse();
	}

	bool update_item(int index, T value)
	{
		return _list.update_node(index, value);
	}

	void insert_after(int index, T value)
	{
		_list.insert_index(index, value);
	}

	void print()
	{
		_list.normal_print();
	}
};





























// QUEUE USING VECTOR 

//#pragma once
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//template<class T>
//
//class cls_queue
//{
//private:
//
//	vector<T> _v_items = {};
//
//	short _size;
//
//public:
//
//	cls_queue()
//	{
//		_size = 0;
//	}
//
//	void push(T value)
//	{
//		_v_items.push_back(value);
//		++_size;
//	}
//
//	void pop()
//	{
//		if (_v_items.empty()) {
//			throw out_of_range("Queue is empty!");
//		}
//		_v_items.erase(_v_items.begin());
//		--_size;
//	}
//
//	short size()
//	{
//		return _size;
//	}
//
//	T front()
//	{
//		if (_v_items.empty()) {
//			throw out_of_range("Queue is empty!");
//		}
//		return *_v_items.begin();
//	}
//
//	T back()
//	{
//		if (_v_items.empty()) {
//			throw out_of_range("Queue is empty!");
//		}
//		return _v_items.back();
//	}
//
//	void print()
//	{
//		if (_v_items.empty()) {
//			throw out_of_range("Queue is empty!");
//		}
//		for (T& v : _v_items)
//		{
//			cout << v << "  -  ";
//		}
//		cout << endl;
//	}
//};
