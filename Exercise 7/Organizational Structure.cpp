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

	// Add a function to create the root.
	static orgnization_tree create_organization_structure(const string &pos) {

		orgnization_tree tree;
		tree.root = new node(pos, NULL, NULL);
		return tree;

	}


};


int main() {

}