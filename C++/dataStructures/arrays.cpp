#include <iostream>
using namespace std;

/*
 * Goal: Implement a vector using a class 
 * Design: 
 * 	1. Automatic resizing will be done when array is at 75% capacity and space will be doubled
 * 	2. Space will be halfed when at 40% capacity 
 */

class myVector{
	int size; //Stores current size of the vector
	int capacity; //Stores current capacity of the vector
	int *head; //Point to the head of the vector	

	public:
		int size();
		int capacity();
		void insert(int);
};



int main(){
	myVector testVector();

	return 0;
}

