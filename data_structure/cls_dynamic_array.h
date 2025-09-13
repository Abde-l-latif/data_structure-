#pragma once
#include <iostream>

using namespace std; 

template <class T>
class cls_dynamic_array
{

private : 

	short _size;

public :

	T * arr; 

	cls_dynamic_array(short size = 0)
	{
		if (size < 0)
			size = 0 ;

		_size = size; 
		arr = new T[_size];
	}

	bool is_empty()
	{
		return _size == 0;
	}

	short size()
	{
		return _size; 
	}

	void re_size(short size)
	{
		if (size < 0)
			size = 0;

		T* new_arr; 

		new_arr = new T[size];

		short elementsToCopy = (size < _size) ? size : _size;

		for (short i = 0; i < elementsToCopy; i++)
		{
			new_arr[i] = arr[i];
		} 

		delete[] arr; 

		arr = new_arr; 

		_size = size; 

	}

	T get_item(int index)
	{
		if (index >= _size || index < 0)
			return NULL;

		return arr[index]; 
	}

	void clear()
	{
		_size = 0;
		T* new_arr = new T[_size];
		delete[] arr;
		arr = new_arr;
	}

	void print_array()
	{
		for (short i = 0; i < _size; i++)
		{
			cout << arr[i] << "    ";
		}
		cout << endl;
	}

	bool set_item(int index , T value)
	{
		if (index < 0 || index > _size - 1)
			return false; 

		arr[index] = value;
		return true;
	}

	void reverse()
	{
		for (short i = 0; i < _size / 2; i++)
		{
			T temp = arr[i];
			arr[i] = arr[_size - i - 1];
			arr[_size - i - 1] = temp;
		}
	}

	void delete_item_at(int index)
	{
		if (index < 0 || index > _size - 1)
			return; 

		_size = _size - 1; 

		T* new_arr;

		new_arr = new T[_size];

		for (int i = 0; i < index; i++)
		{
			new_arr[i] = arr[i];
		}

		for (int i = index + 1; i < _size; i++)
		{
			new_arr[i - 1] = arr[i];
		}

		delete[] arr; 

		arr = new_arr; 
	}

	void delete_first_item()
	{
		delete_item_at(0); 
	}

	void delete_last_item()
	{
		delete_item_at(_size - 1); 
	}

	int find(T value)
	{

		for (short i = 0; i < _size; i++)
		{
			if (arr[i] == value)
				return i; 
		}
		return -1; 
	}

	bool delete_item(T value)
	{

		int index = find(value); 

		if (index == -1)
			return false; 

		delete_item_at(index);
		return true;

	}

	void insert_at(int index , T value)
	{

		if (index < 0 || index > _size)
			return; 

		T* new_arr;

		_size++; 

		new_arr = new T[_size];

		for (short i = 0; i < index; i++)
		{
			new_arr[i] = arr[i];
		}

		for (short i = index + 1; i < _size; i++)
		{
			new_arr[i] = arr[i - 1];
		}

		new_arr[index] = value;
		
		delete[] arr; 

		arr = new_arr; 

	}

	void insert_at_beginning(T value)
	{
		insert_at(0, value);
	}

	void insert_at_end(T value)
	{
		insert_at(_size, value);
	}

	void insert_before(int index, T value)
	{
		if (index <= 0)
		{
			insert_at(0, value);
			return;
		}

		insert_at(index - 1, value);
	}

	void insert_after(int index, T value)
	{
		if (index >= _size)
		{
			insert_at(_size, value);
		}
		insert_at(index + 1, value);
	}

};

