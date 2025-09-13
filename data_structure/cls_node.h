#pragma once

using namespace std;

template <typename T>

class cls_node
{

public:

	T value;
	cls_node<T>* next;
	cls_node<T>* previous;

};
