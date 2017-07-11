/*
 * Question 2: Given two strings, write a method to decide if one is a permutation
 * of the other.
 */

#include <string>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

//Approach: Use a map and store the occurance of characters in str1. Compare
//to str2.

map<string, int> count(string str1)
{
	map<string, int> letter_count;
	pair<map<string, int>::iterator, bool> result;
	string lowerCase;
	for(string::iterator it=str1.begin(); it != str1.end(); ++it){
		lowerCase = tolower(*it);
		result = letter_count.insert(make_pair(lowerCase, 1));
		if(result.second == false){
			++result.first->second;
		}
	}

	return letter_count;
}

bool isPermutation(map<string, int> map1, map<string, int> map2){
	if(map1.size() != map2.size()){
		return false;
	}
	map<string, int>::iterator find_element;
	for (map<string, int>::iterator it=map1.begin(); it != map1.end(); ++it){
		find_element = map2.find(it->first);
		if(find_element == map2.end()){
			return false;
		}else{
			if(it->second != find_element->second){
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string str1("Hello");
	string str2("elolhas");
	map<string, int> letter_count1 = count(str1);
	map<string, int> letter_count2 = count(str2);
	bool result;
	result = isPermutation(letter_count1, letter_count2);

	if(result){
		cout << "These two words are permutations" << endl;
	}else{
		cout << "These two words are NOT permutations" << endl;
	}

	return 0;
}