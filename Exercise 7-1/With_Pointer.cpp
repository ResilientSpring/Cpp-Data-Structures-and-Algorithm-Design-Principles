#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
	
	string position;

	node *first, *second; // [Note 1] [Note 2]
};


int main() {

}

/* Notes

1. A class (or struct) can contain a pointer to a class (or struct) of the same type, 
   but cannot contain an instance of the same type, since that would result in infinite recursion.[1]

2. A variable of a struct type is as large as all the members of the struct. 
   So, let's say you have the following:

struct foo {
  int x;
  int y;
};

Assuming that int is 4 bytes (a common assumption in many modern platforms), 
a variable of type struct foo takes 8 bytes (twice 4, because it contains two int members) in memory 
and contains two integers in it.

Now, let's do this:

struct bar {
  int a;
  int b;
  struct bar another; // "bar another;" would be OK in C++, not in C
};

So a struct bar variable will be... how long? 
You have 4 for each int, so 8, plus... its own size, since it contains a copy of itself ¡X 
it contains two int members, and then... another struct bar with two more, 
which contains yet another struct bar with two more, and so on ad infinitum. 
You'd end up with a case of infinite recursion.


What you probably want to do in this case is to have a pointer to another struct bar, 
which may or may not be null. 

struct bar {
  int a;
  int b;
  struct bar *another;    // "bar *another;" would be OK in C++, not in C
};


Going back to your cell, you'd have:

class Cell {
public:
  int row;
  int col;
  Cell * parent;
};


And in fact, at least one of your cells will have no parent; 
something will probably be the root and ancestor of all your cells. 
That one cell will have nullptr as the value of parent.[2]

*/

/*
* 
* References:
* 1. https://stackoverflow.com/questions/54965886/c-incomplete-type-not-allowed-while-declaring-struct-and-class

  2. https://stackoverflow.com/a/54965941/
*/