#include "AVLTreeHeader.h"


int main() {

	//Variables
	char selection;
	int menu = 0, integer;

	//Object of AVLClass
	AVLClass tree; 

	//root declared for AVLStruct
	AVLStruct *root = NULL;

	//Menu displayed to user
	while (menu == 0) {

		cout << "--------------------------------------------------------" << endl;
		cout << setw(33) << " AVL Tree Implementation " << endl;
		cout << "A: Insert an integer to the tree and show the balanced tree at each insertion.\n";
		cout << "B: Display the balanced tree and show preorder traversal.\n";
		cout << "C: Display the balanced tree and show inorder traversal.\n";
		cout << "D: Display the balanced tree and show postorder traversal.\n";
		cout << "E: Exit.\n";
		cout << "Please enter your selection: ";
		cin >> selection;

		switch (selection) {
		//Menu A Selection: Insert an integer to the tree and show the balanced tree at each insertion.
		case 'A': 
			//User enters the integer to add to the tree
			cout << "Enter the integer to be added to tree: ";
			cin >> integer;
			root = tree.insertToAVLTree(root, integer);
		
			
			//Displays balanced AVL tree
			if (root != NULL) {
				cout << "Node (" << integer << ") inserted.\n";
				cout << endl << "Balanced AVL Tree:\n";
				tree.displayBalancedAVLTree(root, 1);
				cout << endl;
				break;
			}
			else {
				cout << "\nTree is Empty\n";
				break;
			}
	

		//Menu B Selection: Display the balanced tree and show preorder traversal.
		case 'B':		
			//Displays balanced AVL tree
			if (root != NULL) {
				cout << endl << "Balanced AVL Tree:\n";
				tree.displayBalancedAVLTree(root, 1);
				cout << endl;
			
			}
			else {
				cout << "\nTree is Empty\n";
				break;
			}

			//Displays preorder traversal of the AVL tree
			if (root != NULL) {
				cout << "\nPreorder Traversal: ";
				cout << "{ ";
				tree.preorderTraversalListAVLTree(root);
				cout << "}";
				cout << endl;
				break;
			}
			else {
				cout << "\nTree is Empty\n";
				break;
			}

		//Menu C Selection: Display the balanced tree and show inorder traversal.
		case 'C':
			//Displays balanced AVL tree
			if (root != NULL) {
				cout << endl << "Balanced AVL Tree:\n";
				tree.displayBalancedAVLTree(root, 1);
				cout << endl;
		
			}
			else {
				cout << "\nTree is Empty\n";
				break;
			}
			
			//Displays inorder traversal of the AVL tree
			if (root != NULL) {
				cout << "\nInorder Traversal: ";
				cout << "{ ";
				tree.inorderTraversalListAVLTree(root);
				cout << "}";
				cout << endl;
				break;
			}
			else {
				cout << "\nTree is Empty\n";
				break;
			}
		//Menu D Selection: Display the balanced tree and show postorder traversal.
		case 'D':
			//Displays balanced AVL tree
			if (root != NULL) {
				cout << endl << "Balanced AVL Tree:\n";
				tree.displayBalancedAVLTree(root, 1);
				cout << endl;
			
			}
			else {
				cout << "\nTree is Empty\n";
				break;
			}

			//Displays postorder traversal of the AVL tree
			if (root != NULL) {
				cout << "\nPostorder Traversal: ";
				cout << "{ ";
				tree.postorderTraversalListAVLTree(root);
				cout << "}";
				cout << endl;
				break;
			}
			else {
				cout << "\nTree is Empty\n";
				break;
			}
			
			
		//Menu E Selection: Exit.
		case 'E':
			cout << "\nThank you! The program will now exit.\n";
			menu = 1;
			break;

		//Default case when a user enters a selection that is not on the menu
		default:
			cout << "\nYou have made a selection that is not on the menu. Please try again.\n" << endl;
		}

	}
	system("pause");
	return 0;
}
