#include <iostream>
#include <queue>
using namespace std;

struct node {

	const char* position;

	node* first;
	node* second;

};


struct tree {

	node* root;

	// Add a function to create the root.  This is a static function just to create the tree.
	static tree create_organization_structure(const char* position) {

		tree tree;
		tree.root = new node{ position, NULL, NULL };

		return tree;

	}

	// Find a node based on a value.
	static node* find(node* root, const char* value) {

		if (root == NULL)
			return NULL;

		/* While traversing the tree in search of an element, either the element will be the node
		  we are at,  */
		if (root->position == value)
			return root;

		if (strcmp(root->position, value) == 0)
			return root;

		// , or it will be in ether of the right subtree
		auto firstFound = tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		//  or left subtrees
		return tree::find(root->second, value);
	}

	// The func's return type is bool, indicating whether we can insert the node successfully or not.
	bool insertion(const char* name_of_existing_node, const char* name_of_new_node) {

	}


	// Add a subrdinate of an employee.
	bool addSubordinate(const char* manager, const char* subordinate) {

		/*

		The function takes two parameters - the name of the already existing employee in the tree

		And the name of the new employee to be added as a subordinate.

		*/

		auto managerNode = find(root, manager);

		if (!managerNode) {
			cout << "No position named " << manager << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) {
			cout << manager << " already has 2 subordinates." << endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
	}
};


int main() {

}

// References:
// 
// 1. https://stackoverflow.com/questions/8840026/compare-two-equal-array-in-c-but-output-shows-unequal
// 