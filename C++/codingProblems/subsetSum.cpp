/*
 * Given a sorted list of distinct integers, write a function that returns
 * whether there are two integers in the list that add up to 0..
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	ifstream input(argv[1]);
	int tmp;
	vector<int> buffer;
	int sum = 0;

	while (input >> tmp){
		buffer.push_back(tmp);
		sum += tmp;
	}
	
	if (sum >= 0){
		cout << "True" << "\n" << endl;
		return 0;
	} 	
	
	if (buffer.size() == 1){
		if(buffer[0] == 0){
			cout << "True" << "\n" << endl;
			return 0;
		}
	}

	vector<int>::iterator bufferIterator; 
	for (bufferIterator = buffer.begin(); bufferIterator != buffer.end(); ++bufferIterator){
		
	}	
	
	/*for (auto a : buffer){
		cout << a;
	}
	cout << endl;*/

	return 0;
}
