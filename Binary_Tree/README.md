# 🌲 BinaryTreeDoPae - C++ Binary Tree Implementation 🌲

Welcome to BinaryTreeDoPae, a C++ implementation of a binary tree data structure! 🚀

## 📝 Table of Contents

- [Overview](#🗺️%20Overview)
- [Features](#🌟%20Features)
- [Usage](#💻%20Usage)
- [License](#📜%20License)
- [Contributing](#🤝%20Contributing)

## 🗺️ Overview

The 🌳 Binary TreeDoPae is a C++ implementation of a binary tree data structure using templates. It provides various methods for manipulating and accessing the elements of the tree. This binary tree is implemented using a linked structure, where each node contains a data element and pointers to its left and right child nodes.

## 🌟 Features

- ✔️ Templated implementation for flexibility.
- ➕ Insertion of elements with `insert()` method.
- ➖ Removal of elements with `remove()` method.
- ❓ Checking for the existence of a value with `contains()` method.
- 📏 Finding the maximum and minimum values with `max()` and `min()` methods.
- 🗑️ Clearing the entire tree with `clear()` method.
- 📜 Printing tree values in a specific order with `print_values()` method.

## ⚙️ Methods

- `size()`: Get the size of the binary tree.
- `empty()`: Check if the tree is empty.
- `is_leaf()`: Check if the tree is a leaf node.
- `contains(value)`: Check if a specific value exists in the tree.
- `insert(value)`: Insert a new node with the given value into the tree.
- `remove(value)`: Remove a value from the tree.
- `clear()`: Clear all nodes in the tree.
- `print_values()`: Print the values of the nodes in a specific order.
- `max()`: Get the maximum value in the tree.
- `min()`: Get the minimum value in the tree.

## 💻 Usage

To use the 🌳 Binary TreeDoPae in your C++ project, follow these steps:

1. Clone the repository to your local machine:

   ```shell
   git clone link-to-repo
   ```

2. Include the `BinaryTreeDoPae.h` header in your C++ code:

   ```cpp
   #include "BinaryTreeDoPae.h"
   ```

3. Create a `BinaryTreeDoPae` object and start using the available methods:

   ```cpp
   // Create a binary tree with an initial value
   BinaryTreeDoPae<int> tree(10);

   // Insert values into the tree
   tree.insert(5);
   tree.insert(15);
   tree.insert(3);
   tree.insert(7);
   tree.insert(12);
   tree.insert(18);

   // Check if a value exists in the tree
   bool containsValue = tree.contains(7); // Should return true

   // Remove a value from the tree
   bool removedValue = tree.remove(15); // Should return true

   // Find the maximum and minimum values in the tree
   int maxValue = tree.max();
   int minValue = tree.min();

   // Print tree values in a specific order (pre-order traversal)
   tree.print_values();

   // Clear the entire tree
   tree.clear();

    ```

## 📜 License

This project is licensed under the MIT License - see the `LICENSE` file for details.

## 🤝 Contributing

If you'd like to contribute to this project, please feel free to open issues or submit pull requests on the GitHub repository. Your contributions are greatly appreciated!

Happy coding! 🌲🍂
