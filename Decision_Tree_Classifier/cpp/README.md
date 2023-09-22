# Disease Decision Tree 🌳

This project consists of an implementation of a decision tree for disease diagnosis. The decision tree is used to ask the user questions about symptoms, and based on the provided answers, arrive at a final diagnosis. The implementation of the tree was designed with the result of the `printTree` method of the decision tree made in Python from the `DecisionTreeClassifier` class, included in the `cdt.py` file.

In this project, the implementation is a result of this tree:

```text
skin_rash?
|left:chills?
||left:high_fever?
|||left:fatigue?
||||left:vomiting?
|||||left:abdominal_pain?
||||||left:Hepatitis C
||||||right:nausea?
|||||||left:Hepatitis B
|||||||right:Chronic cholestasis
|||||right:yellowing_of_eyes?
||||||left:Chronic cholestasis
||||||right:abdominal_pain?
|||||||left:hepatitis A
|||||||right:nausea?
||||||||left:hepatitis A
||||||||right:loss_of_appetite?
|||||||||left:hepatitis A
|||||||||right:yellowish_skin?
||||||||||left:Chronic cholestasis
||||||||||right:Chronic cholestasis
|||||right:vomiting?
||||||left:abdominal_pain?
|||||||left:nausea?
||||||||left:Hepatitis B
||||||||right:Hepatitis C
|||||||right:nausea?
||||||||left:Hepatitis B
||||||||right:Hepatitis D
|||||right:headache?
||||||left:loss_of_appetite?
|||||||left:nausea?
||||||||left:Jaundice
||||||||right:Hepatitis D
|||||||right:nausea?
||||||||left:Hepatitis D
||||||||right:yellowing_of_eyes?
|||||||||left:Hepatitis D
|||||||||right:abdominal_pain?
||||||||||left:Hepatitis D
||||||||||right:yellowish_skin?
|||||||||||left:Hepatitis D
|||||||||||right:Hepatitis D
||||||right:Hypoglycemia
|||right:yellowing_of_eyes?
||||left:headache?
|||||left:Jaundice
|||||right:fatigue?
||||||left:Malaria
||||||right:Chicken pox
||||right:abdominal_pain?
|||||left:Tuberculosis
|||||right:Hepatitis E
||right:yellowing_of_eyes?
|||left:fatigue?
||||left:Malaria
||||right:abdominal_pain?
|||||left:vomiting?
||||||left:Common Cold
||||||right:loss_of_appetite?
|||||||left:Typhoid
|||||||right:Dengue
|||||right:Typhoid
|||right:Tuberculosis
|right:nausea?
||left:Chicken pox
||right:Dengue
```

## Table of Contents

- [Files](#Files%20📂)
- [Usage](#Usage%20🚀)
- [Compilation](#Compilation%20⚙️)
- [Author](#Author%20👤)
- [Contributing](#Contributing%20🤝)
- [License](#License%20📜)

## Files 📂

- `diseaseDecisionTree.h`: Contains the definition of the decision tree used for disease diagnosis. The tree is implemented using the data structure of a binary tree, where each node can contain a diagnostic value or a question for the user to answer.

- `decisionTreeDoPae.h`: Contains the definition of the `DecisionTreeDoPae` class responsible for interacting with the decision tree. The class provides methods to build the tree, ask questions to the user, and obtain the final diagnosis based on the provided answers.

- `decisionTreeDoPae.cpp`: Contains the implementation of the methods of the `DecisionTreeDoPae` class defined in the `decisionTreeDoPae.h` file. The class is responsible for providing the logic to interact with the decision tree, including tree construction, user questioning, and obtaining the final diagnosis.

- `main.cpp`: Contains the main `main` function that interacts with the user and performs disease diagnosis based on the decision tree. The program prompts the user to answer a series of questions about symptoms and then provides a diagnosis based on the provided answers.

## Usage 🚀

1. Compile the files `diseaseDecisionTree.h`, `decisionTreeDoPae.h`, `decisionTreeDoPae.cpp`, and `main.cpp` using a compatible C++ compiler.

2. Run the resulting program.

3. Follow the instructions displayed in the program to answer questions about symptoms.

4. The program will provide a final diagnosis based on the answers provided.

## Compilation ⚙️

Make sure you have the C++ compiler `g++` installed on your system. Then, follow the steps below to compile the code:

1. Open a terminal or command prompt.

2. Navigate to the directory where the project files are located.

3. Execute the following command to compile the code:

   ```shell
   g++ main.cpp -o main
   ```

4. After the compilation is complete, run the program by typing the following command:

   ```bash
   ./main
   ```

## Author 👤

- [JoseEdSouza](https://github.com/JoseEdSouza)

## Contributing 🤝

We welcome contributions! If you'd like to contribute to this project, please feel free to open issues or submit pull requests on the. Your contributions are highly appreciated!

## License 📜

This project is licensed under the MIT License. For more details, please see the `LICENSE` file.
