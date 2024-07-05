#include <iostream>
#include <queue>
using namespace std;

struct Node {

	const char* position;

	Node* first;
	Node* second;

};


struct Tree {

	Node* root;

	// Add a function to create the root.  This is a static function just to create the tree.
	static Tree create_a_root_node(const char* position) {

		Tree tree;
		tree.root = new Node{ position, NULL, NULL };

		return tree;

	}

	// Find a node based on a value.
	static Node* find(Node* root, const char* value) {

		if (root == NULL)
			return NULL;

		/* While traversing the tree in search of an element, either the element will be the node
		  we are at,  */
		if (root->position == value)
			return root;

		if (strcmp(root->position, value) == 0)
			return root;

		// , or it will be in ether of the right subtree
		auto firstFound = Tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		//  or left subtrees
		return Tree::find(root->second, value);
	}

	// The func's return type is bool, indicating whether we can insert the node successfully or not.
	bool insertion(const char* name_of_existing_node, const char* name_of_new_node) {

		/*
		  Insert a node under a node.  In other words, add a sub-node to a node.
		*/

		Node* node = find(root, name_of_existing_node);

		if (node == NULL) {
			printf("No position named %s .\n", name_of_existing_node);

			return false;
		}

		if (node->first && node->second) {
			printf("%s already has two sub-nodes.\n", name_of_existing_node);

			return false;
		}

		if (node->first == NULL)
			node->first = new Node{ name_of_new_node, NULL, NULL };
		else 
			node->second = new Node{ name_of_new_node, NULL, NULL };

		return true;
	}


	// Add a subrdinate of an employee.
	bool addSubordinate(const char* manager, const char* subordinate) {

		/*

		The function takes two parameters - the name of the already existing employee in the tree

		And the name of the new employee to be added as a subordinate.

		*/

		Node* managerNode = find(root, manager);

		if (!managerNode) {
			cout << "No position named " << manager << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) {
			cout << manager << " already has 2 subordinates." << endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new Node{ subordinate, NULL, NULL };
		else
			managerNode->second = new Node{ subordinate, NULL, NULL };

		return true;
	}
};


int main() {

	Tree tree = Tree::create_a_root_node("CEO");

	if (tree.insertion("CEO", "Deputy Director"))
		printf("Added Deputy Director in the tree.\n");
	else
		printf("Couldn't add Deputy Director in the tree\n");

	if (tree.insertion("Deputy Director", "IT Head"))
		printf("Added IT Head in the tree.\n");
	else
		printf("Coudln't add IT Head in the tree.\n");

	if (tree.insertion("Deputy Director", "Marketing Head"))
		printf("Added Marketing Head in the tree.\n");
	else
		printf("Couldn't add Marketing Head in the tree.\n");

	if (tree.insertion("IT Head", "Security Head"))
		printf("Added Security Head in the tree.\n");
	else
		printf("Couldn't add Security Head in the tree.\n");

}

// References:
// 
// 1. https://stackoverflow.com/questions/8840026/compare-two-equal-array-in-c-but-output-shows-unequal
// 