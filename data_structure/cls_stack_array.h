#pragma once
#include "cls_my_queue_arr.h"


template <class T>

class cls_stack_array : public cls_my_queue_arr<T>
{

public:

	cls_my_queue_arr<T>::array;
	cls_my_queue_arr<T>::front;
	cls_my_queue_arr<T>::back;



	void push(T value)
	{
		array.insert_at_end(value);
	}

	T top()
	{
		return front();
	}

	T bottom()
	{
		return back();
	}



};

