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
	static orgnization_tree create_organization_structure(const string &pos) {

		orgnization_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;

	}

	// Write another function that will help us find a particular node based on a value to make our insertion 
	// function easier.
	static node *find(node *root, const string &value) {

		if (root == NULL)
			return NULL;
		if (root->position == value)
			return root;

		auto firstFound = orgnization_tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		return orgnization_tree::find(root->second, value);
	}


};


int main() {

}