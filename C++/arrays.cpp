#include <iostream>
using namespace std;

class myVector{
	int value, size;

	public:
		int size();
		int capacity();
		bool is_empty();
		void insert(int);
};

void myVector::insert(int x){
	value = x; 
}


int main(){
	myVector testVector();

	cout << "Hello World" << endl;
	return 0;
}

