/*
 * Question 1: Is Unique : Implement an algorithm to determine if a
 * string has a unique characters. What if you cannot use additional
 * data structures?
 */

#include <string>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

//With data structure. Use a hash function.
//Disadvantage is more overhead with a hash function: But worst case is O(n)
bool usingSetIsUnique(string a)
{
	set<string> isUnique;
	pair<set<string>::iterator, bool> result;
	string c;
	for (string::iterator it = a.begin(); it != a.end(); ++it){
		c = tolower(*it);
		result = isUnique.emplace(c);
		if (result.second == false){
			return false;
		}
	}
	return true;
}

//No data structure approach
//Disadvantage of this solution: In worst case O(n^2).
bool noDataStructureIsUnique(string a)
{
	for (string::iterator it = a.begin(); it != a.end(); ++it){
		for (string::iterator next = (it + 1); next != a.end(); ++next){
			cout << "Comparing " << *it << " with " << *next << endl;
			if (tolower(*it) == *next){
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string str1 = "Hello";
	string str2 = "Health";
	//bool result = noDataStructureIsUnique(str2);
	bool result = usingSetIsUnique(str2);
	if (result == true){
		cout << "This string is unique" << endl;
	}
	else{
		cout << "This string is not unique" << endl;
	}
	return 0;
}