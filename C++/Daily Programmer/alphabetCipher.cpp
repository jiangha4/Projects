/*
	Alphabet Cipher
	Input: Two strings, key, and message
	Output: String
	
	Set up a matrix of letters
	
	Main loop needs to:
		1. Iterate through every letter in message
		2. Compare letter in message to letter in key
		3. Encrypt
*/

#include <iostream>
#include <string>
#include <array>

using namespace std;

void rotate(int startPoint)
{
	char standardAlphabet[26] = 'abcdefghijklmnopqrstuvwxyz';
	char temp = standardAlphabet[shift];
	int curr = 0;
	int next = startPoint;
	int nextShift;
	for(int i=0; i<26; i++){
		temp = a[curr];
		a[curr] = a[next];
		next = curr + 1;
	}

};

int main()
{
	char lookUpTable[27][27];
	char alphabet[26] = 'abcdefghijklmnopqrstuvwxyz';

	for(int i=1; i<27; i++){
		lookUpTable[i][0] = alphabet[i-1]
		lookUpTable[0][i] = alphabet[i-1]
	}

	//cout << alphabet;
	return 0;
}