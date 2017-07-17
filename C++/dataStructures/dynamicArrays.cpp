#include <iostream>
using namespace std;

/*
 * Goal: Implement dynamic sizing arrays 
 * Design: 
 * 	1. Automatic resizing will be done when array is at 50% capacity and space will be doubled
 * 	2. Space will be halfed when at 50% capacity
 * 	3. Needed functionality:
 * 		- Add item
 * 		- Delete item
 */

class myVector{
	public:
		myVector() = default;
		myVector(int *p): beginning(p) {};
	private:
		int* beginning; 
};

int main(){
	int a1({1, 2 ,3});
	myVector v1(a1);
	cout << v1 << endl;
	return 0;
}

