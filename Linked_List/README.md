# 🖇️ LinkedList DoPae C++ Project

Welcome to the Linked List C++ project! This project provides a flexible and efficient implementation of a linked list data structure in C++. You can use this code to create, manipulate, and work with linked lists containing elements of any type.

## 📝 Table of Contents

- [Overview](#🗺️%20Overview)
- [Features](#🌟%20Features)
- [Methods](#⚙️%20Methods)
- [Usage](#💻️%20Usage)
- [License](#📜%20License)
- [Contributing](#👥%20Contributing)

## 🗺️ Overview

This C++ project offers a versatile linked list implementation that allows you to store and manage collections of data. Linked lists are fundamental data structures commonly used in various computer science applications.

With this project, you can:

- Create linked lists containing elements of any data type.
- Add, remove, and replace elements at specific positions.
- Concatenate two linked lists together.
- Check for equality between linked lists.
- Perform various operations on linked lists efficiently.

Whether you're learning about data structures or need a linked list implementation for your C++ project, this code provides a solid foundation.

## 🌟 Features

- ✨ Flexible: Store elements of any data type.
- ⚙️ Efficient: Optimized for performance.
- 🧩 Versatile: Supports various operations on linked lists.
- 🔄 Dynamic: Easily add, remove, and replace elements.
- 🤝 Equality: Check if two linked lists are equal.
- ➕ Concatenation: Combine two linked lists seamlessly.

## ⚙️ Methods

- `LinkedList()`: Constructor for creating an empty linked list.
- `LinkedList(std::initializer_list<T> initial)`: Constructor to initialize a linked list with an initializer list of elements.
- `~LinkedList()`: Destructor to clean up memory.
- `clear()`: Clear all elements in the linked list.
- `empty() const`: Check if the linked list is empty.
- `size() const`: Get the size of the linked list.
- `operator[](size_t index)`: Access elements by index.
- `at(size_t index)`: Get an element at a specific index.
- `removeAt(size_t index)`: Remove an element at a specific index.
- `removeAll(T value)`: Remove all occurrences of a given value.
- `insert(T value, size_t index)`: Insert an element at a specific index.
- `replaceAt(T value, size_t index)`: Replace an element at a specific index.
- `push_back(T value)`: Add an element to the end of the linked list.
- `push_front(T value)`: Add an element to the front of the linked list.
- `pop_back()`: Remove and return the last element.
- `pop_front()`: Remove and return the first element.
- `equals(LinkedList& other)`: Check if two linked lists are equal.
- `concat(LinkedList& other)`: Concatenate another linked list to the end of the current one.

## 💻️ Usage

1. Clone the repository to your local machine:

   ```shell
   git clone link-to-repo
   ```

2. Include the `linkedListDoPae.hpp` header in your C++ code:

   ```cpp
   #include "linkedListDoPae.hpp"
   ```

3. Create a `LinkedList` object and utilize the available methods:

   ```cpp
   // Create a linked list with initial values
   LinkedList<int> list = {1, 2, 3, 4, 5};

   // Check if the list is empty
   bool isEmpty = list.empty(); // Should return false

   // Get the size of the list
   size_t size = list.size(); // Should return 5

   // Access elements by index
   int element = list[2]; // Should return 3

   // Remove an element at a specific index
   list.removeAt(1);

   // Add an element at a specific index
   list.insert(10, 2);

   // Check if two lists are equal
   LinkedList<int> anotherList = {1, 10, 3, 4, 5};
   bool areEqual = list.equals(anotherList); // Should return true

   // Concatenate two lists
   list.concat(anotherList);

   // Clear the entire list
   list.clear();
   ```

## 📜 License

This project is licensed under the MIT License. For more details, please see the `LICENSE`` file.

## 👥 Contributing

We welcome contributions! If you'd like to contribute to this project, please feel free to open issues or submit pull requests on the. Your contributions are highly appreciated!

Happy coding! 🚀
