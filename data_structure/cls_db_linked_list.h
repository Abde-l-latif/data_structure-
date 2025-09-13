#pragma once
#include "cls_node.h" 
#include <iostream>

using namespace std; 

template <typename O>

class cls_db_linked_list
{
private:

	cls_node<O>* _Head;

	cls_node<O>* _Tail;

	short _counter;

	cls_node <O>* _create_new_node(O & value)
	{
		cls_node <O>* new_node = new cls_node<O>();
		new_node->value = value; 
		new_node->next = nullptr; 
		new_node->previous = nullptr; 
		return new_node; 
	}


public:

	O get_first_node()
	{
		return _Head->value;
	}

	O get_last_node()
	{
		return _Tail->value;
	}

	bool is_head_empty()
	{
		return _Head == NULL;
	}

	cls_db_linked_list() : _Head(NULL), _Tail(NULL)
	{
		_counter = 0;
	};

	void insert_at_beginning(O value)
	{
		cls_node <O>* new_node = new cls_node<O>();

		new_node->previous = NULL;

		new_node->value = value;

		if (is_head_empty())
		{
			new_node->next = NULL;
			_Head = _Tail = new_node;
			_counter++;
			return;
		}

		new_node->next = _Head;

		_Head->previous = new_node;

		_Head = new_node;

		_counter++;

	}

	void insert_at_beginning()
	{
		cls_node <O>* new_node = new cls_node<O>;

		new_node->previous = NULL;

		if (is_head_empty())
		{
			new_node->next = NULL;
			_Head = _Tail = new_node;
			_counter++;
			return;
		}

		new_node->next = _Head;

		_Head->previous = new_node;

		_Head = new_node;

		_counter++;

	}

	void normal_print()
	{
		if (is_head_empty())
			return;

		cls_node<O>* temp = _Head;
		while (temp != NULL) {
			cout << temp->value << " >> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	cls_node <O>* find(O value)
	{
		if (is_head_empty())
			return NULL;

		cls_node <O>* current = _Head;

		while (current != NULL)
		{
			if (current->value == value)
				return current;
			current = current->next;
		}

		return NULL;
	}

	void insert_after(O after, O value)
	{
		if (is_head_empty())
			return;

		cls_node <O>* after_node = find(after);

		if (after_node == NULL)
			return;

		cls_node<O>* new_node = _create_new_node(value);

		new_node->previous = after_node;

		new_node->next = after_node->next;


		if (after_node->next != NULL)
			after_node->next->previous = new_node;

		after_node->next = new_node;

		_counter++;
	}

	void insert_at_the_end(O value)
	{
		cls_node <O>* new_node = new cls_node<O>();

		new_node->value = value;

		new_node->next = NULL;

		if (is_head_empty()) {
			new_node->previous = NULL;
			_Head = _Tail = new_node;
			_counter++;
			return;
		}

		new_node->previous = _Tail;
		_Tail->next = new_node;
		_Tail = new_node;
		_counter++;
	}

	void reverse_print()
	{
		if (_Tail == NULL)
			return;

		cls_node<O>* temp = _Tail;
		while (temp != NULL) {
			cout << temp->value << " << ";
			temp = temp->previous;
		}
		cout << "NULL" << endl;
	}

	void reverse()
	{
		cls_node<O>* temp = nullptr;
		cls_node<O>* current = _Head;

		while (current != nullptr)
		{
			temp = current->previous;
			current->previous = current->next; 
			current->next = temp;
			current = current->previous; 
		}

		if (temp != nullptr) {
			_Head = temp->previous;
		}

	}

	short size()
	{
		return _counter;
	}

	void delete_node(O value)
	{
		if (is_head_empty())
			return;

		cls_node <O>* get_node = find(value);

		if (get_node == NULL)
		{
			cout << "Node not found !!" << endl;
			return;
		}

		if (get_node->next == NULL && get_node->previous != NULL)
		{
			get_node->previous->next = NULL;
			_Tail = get_node->previous;
			delete get_node;
			_counter--;
			return;
		}

		if (get_node->next != NULL && get_node->previous == NULL)
		{
			_Head = get_node->next;
			get_node->next->previous = NULL;
			delete get_node;
			_counter--;
			return;
		}

		if (get_node->next != NULL && get_node->previous != NULL)
		{
			get_node->previous->next = get_node->next;
			get_node->next->previous = get_node->previous;
			delete get_node;
			_counter--;
			return;
		}

		_Head = _Tail = NULL;
		delete get_node;
		_counter--;

	}

	void delete_first_node()
	{
		if (is_head_empty())
		{
			return;
		}

		cls_node<O>* current = _Head;

		if (current->next == NULL)
		{
			_Head = _Tail = NULL;
			delete current;
			_counter--;
			return;
		}

		_Head = current->next;
		_Head->previous = NULL;
		delete current;
		_counter--;
	}

	void delete_last_node()
	{
		if (is_head_empty())
		{
			return;
		}

		cls_node<O>* current = _Tail;

		if (current->previous == NULL)
		{
			_Head = _Tail = NULL;
			delete current;
			_counter--;

			return;
		}

		_Tail = current->previous;
		_Tail->next = NULL;
		delete current;
		_counter--;

	}

	void clear()
	{
		while (_Head != NULL)
		{
			delete_first_node();
		}
	}

	cls_node<O>* get_node(int index )
	{
		cls_node<O>* current = nullptr; 

		if (index > _counter - 1 || index < 0 )
		{
			cout << "Index out of range " << endl;
			return nullptr;
		}

		if (index < _counter / 2)
		{
			current = _Head; 
			for (short i = 0; i < index ; i++ )
			{
				current = current->next; 
			}
		} 
		else
		{
			current = _Tail; 
			for (short i = _counter - 1 ; i > index ; i--)
			{
				current = current->previous; 
			}

		}

		return current;
	}

	O get_item(int index)
	{

		cls_node<O>* node = get_node(index); 
		if (node == nullptr)
			return NULL; 
		return node->value; 
	}

	bool update_node(int index , O value )
	{
		cls_node<O>* node = get_node(index);

		if (node == nullptr)
			return false; 

		node->value = value; 
		return true; 
	}

	void insert_index(int index, O value)
	{
		O item = get_item(index);

		if (value == NULL)
			return;

		insert_after(item, value);

	}

	~cls_db_linked_list()
	{
		clear(); 

		if (is_head_empty())
			cout << "Linked list is empty !!" << endl;
	}
};

