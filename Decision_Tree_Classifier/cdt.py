"""
Decision Tree Classifier

This code defines a DecisionTreeClassifier class that implements a decision tree algorithm for classification tasks. It also includes functionalities for data preprocessing, model training, and making predictions based on user inputs.

Usage:
1. Load the data from a .csv file using the path provided in DATAPATH.
2. Split the data into features and target variable using the column names specified in col_names.
3. Create an instance of the DecisionTreeClassifier class.
4. Fit the model to the training data.
5. Interact with the user, prompting for symptoms and making predictions corresponding to the diagnosis.
6. Optionally, print the generated decision tree.

Author: José Vinícius Evangelista Dias De Souza
"""

import numpy as np
import pandas as pd
from dataclasses import dataclass
from sklearn.model_selection import train_test_split

DATAPATH = 'data/Sintomas_menor.csv'
col_names = ['prognosis', 'fatigue', 'vomiting', 'high_fever', 'loss_of_appetite', 'nausea','headache', 'abdominal_pain', 'yellowish_skin', 'yellowing_of_eyes', 'chills', 'skin_rash']

# !loading data
# *loading data in a pandas dataframe data struct using col_names as its column names
data = pd.read_csv(DATAPATH, skiprows=1, header=None, names=col_names)

# !Node class
@dataclass(init=False)
class Node:
    def __init__(self, left=None, right=None, info_gain=None, threshold=None, feature_index=None, value=None) -> None:
        # *for decision Node
        self.left = left
        self.right = right
        self.info_gain = info_gain
        self.threshold = threshold
        self.feature_index = feature_index

        # *for leaf Node
        self.value = value

# !Tree class
class DecisionTreeClassifier:
    def __init__(self, min_samples_split=2, max_depth=2) -> None:
        '''tree constructor'''
        # *initialize root node
        self.root = None

        # *stopping conditions
        self.min_samples_split = min_samples_split
        self.max_depth = max_depth

    def __buildTree(self, dataset: np.ndarray, curr_depth=0) -> Node:
        '''recursive function to build the tree'''
        X = dataset[:, :-1]
        num_samples, num_features = np.shape(X)
        # *split until conditions are met
        if num_samples >= self.min_samples_split and curr_depth <= self.max_depth:
            # *find the best split
            best_split = self.__getBestSplit(dataset, num_samples, num_features)
            # *check if info gain is positive
            if best_split['info_gain'] > 0:
                # *recur left
                left_subtree = self.__buildTree(best_split['dataset_left'], curr_depth+1)
                # *recur right
                right_subtree = self.__buildTree(best_split['dataset_right'], curr_depth+1)
                # *return decision Node
                return Node(
                    feature_index=best_split['feature_index'],
                    threshold=best_split['threshold'],
                    info_gain=best_split['info_gain'],
                    left=left_subtree,
                    right=right_subtree)

        Y = dataset[:, -1]
        leaf_value = self.__leafValue(Y)
        return Node(value=leaf_value)

    def __getBestSplit(self, dataset: np.ndarray, num_samples: int, num_features: int) -> dict:
        '''method that return the best split of the data
        \n Args:
            dataset: the dataset to be used in order to get the best split
            num_samples: a int tha represents the number of samples of the given dateset
            num_features: a float number that represents the number of features of the given dataset
        \n Returns:
            A dict containing the best split in this format:
                'feature_index' : feature_index
                'threshold' : threshold
                'dataset_left' : dataset_left
                'dataset_right' : dataset_right
                'info_gain' : curr_info_gain
        '''
        best_split = {
            'info_gain': 0
        }
        max_info_gain = -float('inf')

        # *loop all the features
        for feature_index in range(num_features):
            feature_values = dataset[:, feature_index]
            possible_thresholds = np.unique(feature_values)
            # *loop for all feature values present on data
            for threshold in possible_thresholds:
                # *get current split
                dataset_left, dataset_right = self.__splitDataset(dataset, feature_index, threshold)
                # *check if the childs are not null
                if len(dataset_left) > 0 and len(dataset_right) > 0:
                    y, left_y, right_y = dataset[:, -1], dataset_left[:, -1], dataset_right[:, -1]
                    # *calculate info gain
                    curr_info_gain = self.__informationGain(y, left_y, right_y, 'gini')
                    # *update best split if needed
                    if curr_info_gain > max_info_gain:
                        best_split['feature_index'] = feature_index
                        best_split['threshold'] = threshold
                        best_split['dataset_left'] = dataset_left
                        best_split['dataset_right'] = dataset_right
                        best_split['info_gain'] = curr_info_gain
                        max_info_gain = curr_info_gain
        return best_split

    def __splitDataset(self, dataset, feature_index, threshold) -> tuple:
        '''method to split the data'''
        dataset_left = np.array([row for row in dataset if row[feature_index] <= threshold])
        dataset_right = np.array([row for row in dataset if row[feature_index] > threshold])
        return dataset_left, dataset_right

    def __informationGain(self, parent, l_child, r_child, mode='entropy') -> float:
        '''method that calculates the info gain
            \nargs:
            parent: parent node
            l_child: left child node of parent
            r_child: right child node of parent
            mode: a string that chooses the algorithm of the calculated info gain
                \n- 'gini' => Gini's ppurity index algorithm
                \n- 'entropy' => entropy algorithm
            \nreturns a float representing the info gain of the parent node.
        '''
        weight_l = len(l_child) / len(parent)
        weight_r = len(r_child) / len(parent)
        if mode == 'gini':
            gain = self.giniIndex(parent) - ((self.giniIndex(l_child)*weight_l) + (self.giniIndex(r_child)*weight_r))
        else:
            gain = self.entropy(parent) - ((self.entropy(l_child)*weight_l) + (self.entropy(r_child)*weight_r))
        return gain

    def entropy(self, threshold: np.ndarray) -> float:
        '''method that calculates the entropy of the given threshold'''
        class_labels = np.unique(threshold)
        entropy = 0
        for clabel in class_labels:
            p_cls = len(threshold[threshold == clabel])/len(threshold)
            entropy += -p_cls * np.log2(p_cls)
        return entropy

    def giniIndex(self, threshold: np.ndarray) -> float:
        ''' method that calculates the giniIdex of the given threshold'''
        class_labels = np.unique(threshold)
        gini = 0
        for clabel in class_labels:
            p_cls = len(threshold[threshold == clabel])/len(threshold)
            gini += p_cls**2
        return 1 - gini

    def __leafValue(self, y: np.ndarray):
        '''method to calculate the leaf value'''
        unique_classes, counts = np.unique(y, return_counts=True)
        majority_class = unique_classes[np.argmax(counts)]
        return majority_class

    def printTree(self, node: Node = None, indent: str = '|') -> None:  # ? prints the generated Tree
        '''method to print the tree'''
        if not node:
            node = self.root

        if node.value is not None:
            print(node.value)
        else:
            print(f'{col_names[node.feature_index+1]}?')
            print(f'{indent}left:', end='')
            self.printTree(node.left, indent+'|')
            print(f'{indent}right:', end='')
            self.printTree(node.right, indent+'|')

    def fit(self, X, Y) -> None:
        '''method to train the tree and call the buildTree method'''
        dataset = np.concatenate((X, Y), axis=1)
        self.root = self.__buildTree(dataset=dataset)

    def ask(self):
        '''method ta asks the user and predicts the feature
        based on the given yes/no answers'''
        self.__askHelper(self.root)

    def __askHelper(self, node: Node):
        '''ask helper recursive method'''
        if (node == None):
            return  # ?checks if it is a null node
        if node.feature_index != None:  # ?checks if it is a feature node or a leaf node
            ans = input(
                f'Sympton: {col_names[node.feature_index+1]}? (yes/no) ').lower()
            if ans == 'yes':
                self.__askHelper(node.right)
            elif ans == 'no':
                self.__askHelper(node.left)
            else:
                print('Invalid answer. Please answer with yes or no.')
                self.__askHelper(node)
        else:
            print(f'The diagnosis is: {node.value}\n')


# !main
if __name__ == '__main__':
    # !Train-Test split
    """
    Prepares data for machine learning tasks by separating features and target variable and splitting into training and testing sets.

    Parameters:
        data (pandas.DataFrame): Input DataFrame containing the data.

    Returns:
        X_train (pandas.DataFrame): DataFrame containing the features for the training set.
        X_test (pandas.DataFrame): DataFrame containing the features for the testing set.
        Y_train (numpy.ndarray): Array containing the target variable values for the training set.
        Y_test (numpy.ndarray): Array containing the target variable values for the testing set.
    """
    A = data.iloc[:, 1:]
    B = data.iloc[:, 0].values.reshape(-1, 1)
    X_train, X_test, Y_train, Y_test = train_test_split(A, B, test_size=.2, random_state=21)

    # !Fit the model
    # *creating and training the tree
    # ?creating tree using its constructor
    classifier = DecisionTreeClassifier(min_samples_split=2, max_depth=2000)
    classifier.fit(X_train, Y_train)  # ?training it

    #! Asking user
    flag = True
    while (True):
        print('>>--Sistema--<<')
        if flag:
            op = input('Would you like to make a prognosis? (yes/no) ').lower()
            flag = False
        else:
            op = input(
                'Would you like to make another prognosis? (yes/no) ').lower()
        match op:
            case 'yes':
                classifier.ask()
            case 'no':
                print('Bye bye!')
                break
            case _:
                print('Invalid answer. Please answer with yes or no.\n')
                continue
    op = input('Do you want to print the tree? (yes/no) ').lower()
    if op == 'yes':
        classifier.printTree()
