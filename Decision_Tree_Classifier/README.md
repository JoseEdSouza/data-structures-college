# Decision Tree Classifier in Python 🌳

This project implements a decision tree classifier in Python for classification tasks. It allows you to train a decision tree model based on an input dataset and make predictions based on user responses.

The code includes data preprocessing functionalities such as data splitting into training and testing sets, as well as features for training the model and making interactive predictions. The decision tree is constructed using either the information gain and the Gini impurity index.

The project consists of two main files:

1. `cdt.py`: This file contains the implementation of the `DecisionTreeClassifier` class, representing the decision tree classifier. It also includes the definition of the auxiliary `Node` class, representing a node in the tree.

2. `cdt.py`: This file serves as the entry point of the program. It contains code to load data, split it into training and testing sets, and train the decision tree model. It also allows the user to make interactive predictions based on provided symptoms.

## Table of Contents 📚

- [Requirements](#Requirements-⚙️)
- [Installation](#Installation-🛠️)
- [Running the Code](#Running-the-code-🚀)
- [Contributing](#Contributing-🤝)
- [License](#License-📜)

## Requirements ⚙️

Make sure you have the following requirements installed in your environment before running the code:

- Python (version 3.6 or higher)
- Python libraries: numpy, pandas, scikit-learn

## Installation 🛠️

Follow the steps below to set up the environment and install the dependencies:

1. Clone this repository to your local environment.
2. Navigate to the source code directory.

    ```bash
    cd path/to/source/code
    ```

3. Create a virtual environment (optional but recommended).

    ```bash
    python -m venv myenv
    source myenv/bin/activate  # (for Linux/Mac)
    myenv\Scripts\activate  # (for Windows)
    ```

4. Install the dependencies using pip and the "requirements.txt" file.

   **pip**:

   ```bash
   pip install -r requirements.txt
   ```

   **makefile**:

   ```bash
   make install
   ```

## Running the Code 🚀

To run the code, follow the specific instructions provided in the source code.
Or run `make run` after installing to run using predefined arguments and data file.

## Contributing 🤝

We welcome contributions! If you'd like to contribute to this project, please feel free to open issues or submit pull requests on the. Your contributions are highly appreciated!

## License 📜

This project is licensed under the MIT License - see the `LICENSE` file for details.
