#include<iostream>
#include<algorithm>
#include<iomanip>
#define count 9;

using namespace std;

struct AVLStruct {
	//Variables for AVLStruct
	int value;
	struct AVLStruct *right;
	struct AVLStruct *left;
};

class AVLClass {
public:
	//Member function declarations
	AVLStruct *insertToAVLTree(AVLStruct *root, int value);
	AVLStruct *rotateRight(AVLStruct *parent);
	AVLStruct *rotateLeft(AVLStruct *parent);
	AVLStruct *rotateLeftRight(AVLStruct*parent);
	AVLStruct *rotateRightLeft(AVLStruct *parent);
	AVLStruct *balanceAVLTree(AVLStruct *tNode);
	void displayBalancedAVLTree(AVLStruct *parent, int level);	
	void inorderTraversalListAVLTree(AVLStruct *tNode);
	void preorderTraversalListAVLTree(AVLStruct *tNode);
	void postorderTraversalListAVLTree(AVLStruct*tNode);
	int heightAVLTree(AVLStruct *tNode);
	int balanceFactorDifference(AVLStruct *tNode);
	
};
