#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {

	char position[50];

	node* first;
	node* second;

};


struct tree {

	node* root;

	// Add a function to create the root.  This is a static function just to create the tree.
	static tree create_organization_structure(const char position) {

		tree tree;
		tree.root = new node{ position, NULL, NULL };

		return tree;

	}

	// Find a node based on a value.
	static node* find(node* root, const char value) {

		if (root == NULL)
			return NULL;
		if (root->position == value)
			return root;

		auto firstFound = tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		return tree::find(root->second, value);
	}


};


int main() {

}