# 📦 Double Linked List - C++ Implementation

Welcome to the Double Linked List project! This C++ project provides a versatile and efficient implementation of a doubly linked list, a fundamental data structure, with various methods for adding, removing, inserting, and accessing elements. It offers flexibility for managing dynamic data structures and is particularly useful when you need to maintain a collection of elements with easy insertion and removal.

## 📝 Table of Contents

- [Overview](#🗺️%20Overview)
- [Features](#🌟%20Features)
- [Methods](#⚙️%20Methods)
- [Usage](#💻️%20Usage)
- [License](#📜%20License)
- [Contributing](#👥%20Contributing)

## 🗺️ Overview

The Double Linked List project provides a C++ implementation of a doubly linked list data structure. A doubly linked list is a linear data structure that consists of a sequence of elements, each of which points to both the previous and next elements in the list. This bidirectional linking allows for efficient insertion and removal of elements at both ends of the list.

### 🔑 Key Points

- Efficient insertion and removal of elements at the beginning, end, or any position in the list.
- Supports indexed access to elements.
- Provides methods for checking if an element is present in the list.
- Designed for ease of use and integration into C++ projects.

## 🌟 Features

- **Efficient Insertion and Removal**: The doubly linked list allows for efficient insertion and removal of elements at any position within the list.

- **Indexed Access**: You can access elements in the list by their index, providing direct access to specific elements.

- **Element Presence Check**: The list includes methods to check if a specific element is present within it.

## ⚙️ Methods

- `DoubleLinkedList()`: Constructor that initializes an empty doubly linked list.

- `DoubleLinkedList(std::initializer_list<T> initial)`: Constructor that initializes a doubly linked list with elements from an initializer list.

- `size_t size()`: Returns the size of the doubly linked list.

- `void add(T element)`: Adds an element to the end of the list.

- `void remove(size_t index)`: Removes a node at the specified index from the list.

- `void insert(size_t index, T element)`: Inserts an element at a specified index in the list.

- `bool contains(T element)`: Checks if a given element is present in the list.

- `T operator[](int index)`: Provides indexed access to elements in the list.

## 💻️ Usage

1. Clone the repository to your local machine:

   ```shell
   git clone link-to-repo
   ```

2. Include the `DoubleLinkedList.h` header in your C++ code:

   ```cpp
   #include "DoubleLinkedList.h"
   ```

3. Create a `DoubleLinkedList` object and utilize the available methods:

   ```cpp
   // Create a double linked list with initial values
   DoubleLinkedList<int> myList{1, 2, 3, 4};

   // Check if an element exists in the list
   bool containsElement = myList.contains(2); // Should return true

   // Access elements by index
   int thirdElement = myList[2]; // Should return 3

   // Add elements to the end of the list
   myList.add(5);

   // Insert elements at a specific index
   myList.insert(2, 6);

   // Remove elements by index
   myList.remove(1);

   // Get the size of the list
   size_t listSize = myList.size();

   // Iterate through the list
   for (size_t i = 0; i < listSize; ++i) {
       std::cout << myList[i] << " ";
   }
   std::cout << std::endl;

   // Clear the entire list
   myList.clear();
   ```

## 📜 License

This project is licensed under the MIT License. For more details, please see the `LICENSE` file.

## 👥 Contributing

We welcome contributions! If you'd like to contribute to this project, please feel free to open issues or submit pull requests. Your contributions are highly appreciated!

Happy coding! 🚀
