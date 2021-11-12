//Katie Ortiz - Homework #2 - CS 236 - 2/28/2021
#include "AVLTreeHeader.h"


//Implementation of insertToAVLTree function
AVLStruct *AVLClass::insertToAVLTree(AVLStruct *root, int value) {
	if (root == NULL) {
		root = new AVLStruct;
		root->value = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	else if (value < root->value) {
		root->left = insertToAVLTree(root->left, value);
		root = balanceAVLTree(root);
	}

	else if (value >= root->value) {
		root->right = insertToAVLTree(root->right, value);
		root = balanceAVLTree(root);
	}

	return root;
}

//Implementation of displayBalancedAVLTree function
void AVLClass::displayBalancedAVLTree(AVLStruct *parent, int level) {
	if (parent == NULL) {
		
		return;
	}

	level += count;
	displayBalancedAVLTree(parent->right, level);

	if (level == 10) {
		//Displays the root of the AVL tree
		cout << "Root " << parent->value << "<" << endl; 
	}

	else{
		for (int i = 0; i < level; i++) {
			cout << " "; 
		}
		//Checks if the node is a leaf node and displays value with a dash "-" before the value
		if (parent->left == NULL && parent->right == NULL) {
			cout << "-" << parent->value << endl;
		}
		//Checks if the node is a parent node and displays the value with a "<" after the value
		else if (parent->right != NULL || parent->left != NULL) {
			cout << parent->value << "<" << endl;
		}
		
	}

	displayBalancedAVLTree(parent->left, level);
}

//Implementation of balanceAVLTree function
AVLStruct *AVLClass::balanceAVLTree(AVLStruct *tNode) {

	int balancefactor = balanceFactorDifference(tNode);
	//The left subtree is taller 
	if (balancefactor > 1) {
		if (balanceFactorDifference(tNode->left) > 0) {
			tNode = rotateLeft(tNode);
			cout << "Tree has been rebalanced\n";
		}
		else {
			tNode = rotateLeftRight(tNode);
			cout << "Tree has been rebalanced\n";
		}
	}

	//The right subtree is taller
	else if (balancefactor < -1) {
		if (balanceFactorDifference(tNode->right) > 0) {
			tNode = rotateRightLeft(tNode);
			cout << "Tree has been rebalanced\n";
		}
		else {
			tNode = rotateRight(tNode);
			cout << "Tree has been rebalanced\n";
		}
	}

	balancefactor = 0;
	return tNode;
}

//Implementation of heightAVLTree function
int AVLClass::heightAVLTree(AVLStruct *tNode) {
	if (tNode == NULL) {

		return 0;
	}

	else {
		int height = 0;
		int heightLeft = heightAVLTree(tNode->left);
		int heightRight = heightAVLTree(tNode->right);
		int maxHeight = max(heightLeft, heightRight);
		height = maxHeight + 1;
		
		return height;
	}

}

//Implementation for balanceFactorDifference function
int AVLClass::balanceFactorDifference(AVLStruct *tNode) {
	int BalFactor = 0;
	int RHeight = heightAVLTree(tNode->right);
	int LHeight = heightAVLTree(tNode->left);
	BalFactor = LHeight - RHeight;
	return BalFactor;
}


//Implementation for preorderTraversalListAVLTree function
void AVLClass::preorderTraversalListAVLTree(AVLStruct *tNode) {
	if (tNode == NULL) {
		return;
	}
	else {
		cout << tNode->value << " ";
		preorderTraversalListAVLTree(tNode->left);
		preorderTraversalListAVLTree(tNode->right);
	}
}

//Implenentation for postorderTraversalListAVLTree function
void AVLClass::postorderTraversalListAVLTree(AVLStruct *tNode) {
	if (tNode == NULL) {
		return;
	}
	else if (tNode != NULL) {
		postorderTraversalListAVLTree(tNode->left);
		postorderTraversalListAVLTree(tNode->right);
		cout << tNode->value << " ";
	}

}

//Implementation for inorderTraversalListAVLTree function
void AVLClass::inorderTraversalListAVLTree(AVLStruct *tNode) {
	if (tNode == NULL) {
		return;
	}
	else {
		inorderTraversalListAVLTree(tNode->left);
		cout << tNode->value << " ";
		inorderTraversalListAVLTree(tNode->right);
	}
}

//Implementation for rotationRightRight function
AVLStruct *AVLClass::rotateRight(AVLStruct *parent) {
	AVLStruct *tNode = parent->right;
	parent->right = tNode->left;
	tNode->left = parent;
	return tNode;
}

//Implementation for rotationLeftLeft function
AVLStruct *AVLClass::rotateLeft(AVLStruct *parent) {
	AVLStruct *tNode = parent->left;
	parent->left = tNode->right;
	tNode->right = parent;
	return tNode;
}

//Implementation for rotationRightLeft function
AVLStruct *AVLClass::rotateRightLeft(AVLStruct *parent) {
	AVLStruct *tNode = parent->right;
	parent->right = rotateLeft(tNode);
	return rotateRight(parent);
}

//Implementation for rotationLeftRight function
AVLStruct *AVLClass::rotateLeftRight(AVLStruct *parent) {
	AVLStruct *tNode = parent->left;
	parent->left = rotateRight(tNode);
	return rotateLeft(parent);
}

