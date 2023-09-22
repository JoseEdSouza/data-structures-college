# 🚀 ArrayDoPae - C++ Sequential List Implementation

Welcome to the ArrayDoPae project! This C++ project provides a versatile sequential list implementation with various methods for manipulating and working with arrays. Whether you're a beginner or an experienced developer, ArrayDoPae can be a valuable addition to your C++ toolkit.

## 📝 Table of Contents

- [Overview](#🗺️%20Overview)
- [Features](#🌟%20Features)
- [Methods](#⚙️%20Methods)
- [Usage](#💻️%20Usage)
- [License](#📜%20License)
- [Contributing](#👥%20Contributing)

## 🗺️ Overview

ArrayDoPae is a C++ project that provides an sequential list data structure with dynamic resizing capabilities. It offers a range of methods for adding, removing, sorting, and manipulating elements within the array. This project is designed to be user-friendly and efficient, making it suitable for various applications and learning purposes.

## 🌟 Features

- ✨ Dynamic resizing: ArrayDoPae can automatically resize itself when the number of elements exceeds its capacity, ensuring efficient memory usage.
- ✨ Element manipulation: You can easily add, remove, insert, replace, and sort elements within the array.
- ✨ Exception handling: The project includes robust exception handling to provide meaningful error messages when accessing elements or performing operations on the array.

## ⚙️ Methods

- `insertion_sort`: An efficient sorting algorithm for sorting elements in ascending order.
- `resize`: Resizes the array to a specified size while preserving existing elements.
- `size`: Returns the size of the array.
- `begin` and `end`: Retrieve the first and last elements of the array, respectively.
- `empty`: Checks if the array is empty.
- `add`: Adds an element to the array, automatically resizing if needed.
- `remove`: Removes an element at a specified index and resizes the array if necessary.
- `insert`: Inserts an element at a specified index and resizes the array if needed.
- `remove_element`: Removes the first occurrence of a specified element.
- `remove_all`: Removes all occurrences of a specified element.
- `replace`: Replaces an element at a specified index.
- `sort`: Sorts the elements in the array using the insertion sort algorithm.
- `operator[]`: Allows you to access elements in the array safely, with proper bounds checking and error handling.

## 💻️ Usage

1. Clone the repository to your local machine:

   ```shell
   git clone link-to-repo
   ```

2. Include the `ArrayDoPae.h` header in your C++ code:

   ```cpp
   #include "ArrayDoPae.h"
   ```

3. Create an `ArrayDoPae` object and utilize the available methods:

   ```cpp
   // Create an ArrayDoPae object
   ArrayDoPae<int> arr;

   // Add elements to the array
   arr.add(42);
   arr.add(23);
   arr.add(17);

   // Get the size of the array
   size_t size = arr.size(); // Should return 3

   // Access elements safely
   int element = arr[1]; // Accesses the second element (index 1)

   // Remove an element
   arr.remove(0); // Removes the first element

   // Sort the array
   arr.sort(); // Sorts the elements in ascending order

   // Replace an element
   arr.replace(1, 99); // Replaces the second element with 99
   ```

## 📜 License

This project is licensed under the MIT License. For more details, pleasesee the `LICENSE` file.

## 👥 Contributing

We welcome contributions! If you'd like to contribute to this project, please feel free to open issues or submit pull requests. Your contributions are highly appreciated!

Happy coding! 🚀
