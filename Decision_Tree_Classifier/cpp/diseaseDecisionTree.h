/**
 * diseaseDecisionTree.h
 *
 * This file contains the definition of a decision tree for disease diagnosis. The decision tree is represented
 * through interconnected nodes, where each node can contain a diagnosis value or a question for the user to
 * answer. The tree structure is used to traverse and make the diagnosis based on the user's provided answers.
 *
 * The decision tree is implemented using the data structure of a binary tree, where each node has pointers to
 * its child nodes (right and left).
 *
 * Author: José Vinícius Evangelista Dias de Souza
 */


#ifndef DISEASEDECISIONTREE_H
#define DISEASEDECISIONTREE_H
#include "decisionTreeDoPae.h"
#define str std::string
#define nl '\n'

Node<str>* node50 = new Node(str("Chronic cholestasis"));
Node<str>* node49 = new Node(str("Hepatitis B"));
Node<str>* node38 = new Node(str("nausea?"), node49, node50);
Node<str>* node37 = new Node(str("Hepatitis C"));
Node<str>* node36 = new Node(str("abdominal pain?"), node37, node38);
Node<str>* node56 = new Node(str("Chronic cholestasis"));
Node<str>* node55 = new Node(str("Hepatitis A"));
Node<str>* node54 = new Node(str("loss of apetite?"), node55, node56);
Node<str>* node53 = new Node(str("Hepatitis A"));
Node<str>* node52 = new Node(str("nausea?"), node53, node54);
Node<str>* node51 = new Node(str("Hepatitis A"));
Node<str>* node35 = new Node(str("abdominal pain?"), node51, node52);
Node<str>* node34 = new Node(str("Chronic cholestasis"));
Node<str>* node33 = new Node(str("yellowing of eyes?"), node34, node35);
Node<str>* node44 = new Node(str("Hepatitis D"));
Node<str>* node43 = new Node(str("Hepatitis B"));
Node<str>* node32 = new Node(str("nausea ?"), node43, node44);
Node<str>* node42 = new Node(str("Hepatitis C"));
Node<str>* node41 = new Node(str("Hepatitis B"));
Node<str>* node31 = new Node(str("nausea ?"), node41, node42);
Node<str>* node30 = new Node(str("Hypoglycemia"));
Node<str>* node46 = new Node(str("Hepatitis D"));
Node<str>* node48 = new Node(str("Hepatitis D"));
Node<str>* node47 = new Node(str("Jaundice"));
Node<str>* node45 = new Node(str("nausea?"), node47, node48);
Node<str>* node29 = new Node(str("loss of appetite?"), node45, node46);
Node<str>* node28 = new Node(str("headache?"), node29, node30);
Node<str>* node27 = new Node(str("abdominal pain?"), node31, node32);
Node<str>* node26 = new Node(str("vomiting?"), node27, node28);
Node<str>* node25 = new Node(str("vomiting?"), node36, node33);
Node<str>* node24 = new Node(str("Chicken pox"));
Node<str>* node23 = new Node(str("Malaria"));
Node<str>* node22 = new Node(str("fatigue?"), node23, node24);
Node<str>* node21 = new Node(str("Jaundice"));
Node<str>* node20 = new Node(str("Hepatitis E"));
Node<str>* node19 = new Node(str("Tuberculosis"));
Node<str>* node18 = new Node(str("abdominal pain?"), node19, node20);
Node<str>* node17 = new Node(str("headache?"), node21, node22);
Node<str>* node16 = new Node(str("yellowing of eyes?"), node17, node18);
Node<str>* node15 = new Node(str("fatigue?"), node25, node26);
Node<str>* node40 = new Node(str("Dengue"));
Node<str>* node39 = new Node(str("Typhoid"));
Node<str>* node14 = new Node(str("loss of apetite?"), node39, node40);
Node<str>* node13 = new Node(str("Common Cold"));
Node<str>* node12 = new Node(str("Typhoid"));
Node<str>* node11 = new Node(str("vomiting?"), node13, node14);
Node<str>* node10 = new Node(str("abdominal pain?"), node11, node12);
Node<str>* node9 = new Node(str("Malaria"));
Node<str>* node8 = new Node(str("Tuberculosis"));
Node<str>* node7 = new Node(str("fatigue?"), node9, node10);
Node<str>* node6 = new Node(str("yellowing of eyes?"), node7, node8);
Node<str>* node5 = new Node(str("high ferver?"), node15, node16);
Node<str>* node4 = new Node(str("Dengue"));
Node<str>* node3 = new Node(str("Chicken pox"));
Node<str>* node2 = new Node(str("nausea?"), node3, node4);
Node<str>* node1 = new Node(str("chills?"), node5, node6);
Node<str>* root = new Node(str("skin rash?"), node1, node2);
DecisionTreeDoPae<str> diseasePrognosisTree = root;

#undef nl
#undef str
#endif