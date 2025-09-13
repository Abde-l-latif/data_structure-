#pragma once
#include "cls_db_linked_list.h"
#include "cls_queue.h"

using namespace std;

template<class T>

class cls_stack : public cls_queue<T>
{
private : 
	cls_db_linked_list _list; 

public : 

	void push(T value)
	{
		_list.insert_at_beginning(value);
	}

	void insert_at_top(T value)
	{
		_list.insert_at_beginning(value);
	}

	void insert_at_bottom(T value)
	{
		_list.insert_at_the_end(value);
	}

	T top()
	{
		return _list.get_first_node();
	}

	T bottom()
	{
		return _list.get_last_node();
	}

};

