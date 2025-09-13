#include <iostream>
#include "cls_stack_array.h"

using namespace std; 

int main()
{

	cls_stack_array <int> arr;

	arr.push(5);
	arr.push(10);
	arr.push(15);
	arr.push(20);

	arr.pop();
	
	arr.print();

	cout << arr.top() << endl;
	cout << arr.bottom() << endl;


}

