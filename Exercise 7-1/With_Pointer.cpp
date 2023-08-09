#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
	
	string position;

	node *first, *second; // [Note 1]
};


int main() {

}

/* Notes

1. A class (or struct) can contain a pointer to a class (or struct) of the same type, 
   but cannot contain an instance of the same type, since that would result in infinite recursion.

*/

/*
* 
* References:
* 1. 


*/