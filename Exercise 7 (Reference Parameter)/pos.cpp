#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {

	string position;

	node *first, *second;

};


struct orgnization_tree {

	node *root;

	// Add a function to create the root.  This is a static function just to create the tree.
	static orgnization_tree create_organization_structure(const string pos) {

		orgnization_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;

	}

	// Return a pointer of node type.
	static node *find(node *root, string value) {

		if (root == NULL)
			return NULL;
		if (root->position == value)
			return root;

	}

};


int main() {

}