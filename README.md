📚 C++ Data Structures Library

This project is a C++ implementation of fundamental data structures using manual memory management. It includes linked lists, dynamic arrays, queues, and stacks, both linked-list–based and array–based.

✨ Features

🔗 Doubly Linked List (cls_db_linked_list)

📦 Dynamic Array (cls_dynamic_array)

⏩ Queue (Array-based & Linked-list-based)

📚 Stack (Array-based & Linked-list-based)

🔄 Reversal operations

🔍 Searching, updating, deleting

🧹 Memory cleanup (clear() methods + destructors)

📂 Project Structure
├── cls_node.h             # Node for doubly linked list
├── cls_db_linked_list.h   # Doubly linked list implementation
├── cls_dynamic_array.h    # Dynamic array implementation
├── cls_my_queue_arr.h     # Queue built on top of dynamic array
├── cls_queue.h            # Queue built on top of doubly linked list
├── cls_stack.h            # Stack built on top of doubly linked list
├── cls_stack_array.h      # Stack built on top of dynamic array
└── main.cpp               # Example usage (to be added)

🏗 Implemented Classes
1️⃣ cls_node<T>

A node used in the doubly linked list.

Stores value, next, and previous.

2️⃣ cls_db_linked_list<T>

Custom doubly linked list with full CRUD support.

✅ Features:

Insert at beginning / end / after node

Delete first / last / by value

Traverse forward & backward

Reverse list in-place

Get / update item by index

3️⃣ cls_dynamic_array<T>

A resizable array implementation.

✅ Features:

Resize dynamically

Insert / delete at index

Reverse in-place

Search & update

Clear contents

4️⃣ cls_my_queue_arr<T>

Queue built on dynamic array.

✅ Features:

Push / Pop

Front / Back

Reverse queue

Insert before / after index

5️⃣ cls_queue<T>

Queue built on doubly linked list.

✅ Features:

Push / Pop

Front / Back

Insert at front / back / after index

Reverse queue

Update item

6️⃣ cls_stack<T>

Stack built on doubly linked list.

✅ Features:

Push (Top insertion)

Top / Bottom access

Insert at top / bottom

7️⃣ cls_stack_array<T>

Stack built on dynamic array.

✅ Features:

Push (End insertion)

Top / Bottom access

🚀 Example Usage
#include <iostream>
#include "cls_queue.h"
#include "cls_stack.h"
#include "cls_stack_array.h"

using namespace std;

int main() {
    cls_queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue Front: " << q.front() << endl; // 10
    cout << "Queue Back: " << q.back() << endl;   // 30

    cls_stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);

    cout << "Stack Top: " << s.top() << endl;     // 300
    cout << "Stack Bottom: " << s.bottom() << endl; // 100

    cls_stack_array<int> sa;
    sa.push(5);
    sa.push(15);
    sa.push(25);

    cout << "Stack Array Top: " << sa.top() << endl; // 25
}

🛠 Compilation
g++ main.cpp -o datastructures
./datastructures

🎯 Learning Goals

This project is designed for:

Practicing C++ templates

Understanding data structure internals

Learning manual memory management

Comparing array-based vs linked-list–based implementations

📌 Future Improvements

Add iterators for range-based loops (for(auto x : list)).

Implement copy constructors / assignment operators (Rule of 5).

Add unit tests.

Replace raw pointers with smart pointers.

🔥 With these classes, you now have a mini STL-like library built from scratch.
