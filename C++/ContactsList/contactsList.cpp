/*
 * Project: Create a phone contact list.
 * Basic functions needed: Add, Delete, Search, Total, Print
 * Should haves:
 * 	- Ability to read first names, last names, and numbers from a text file and construct a contact book.
 * 	- Ability to write all the names to a output file in alphabetical order
 * 	- Ability to search by first or last name and return all matching contacts
 * 	- Ability to search by phone number and return matching contact
 */

#include <algorithm>
#include <string>
#include <cstddef>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;
/*
 * Class contactPerson is a set of strings that contains the contacts first name,
 * last name, and phone number. This class can also edit the individual values of
 * each contact after initialization.
 */

class contactPerson{
	public:
		contactPerson() = default;
		contactPerson(string first): firstName(first) {};
		contactPerson(string first, string last)
		: firstName(first), lastName(last) {};
		contactPerson(string first, string last, string number)
		: firstName(first), lastName(last), phoneNum(number) {};

		ostream &print(ostream &os){
			os << this->firstName << "\n"  << this->lastName << "\n" << this->phoneNum << std::endl;
			return os;
		};

		string getFirstName(){
			return this->firstName;
		};

		 string getLastName(){
			return this->lastName;
		};

		string getPhoneNumber(){
			return this->phoneNum;
		};

	private:
		string firstName, lastName, phoneNum;
};

/*
 * Class contactBook is a vector that takes in the class contactPeople
 */
class contactBookVector{
	public:
		contactBookVector() = default;

		contactBookVector &add(contactPerson &person){
			contactList.push_back(person);
			return *this;
		};

		vector<contactPerson>::size_type total(){
			return this->contactList.size();
		};

		ostream &print(ostream &os){
			vector<contactPerson>::iterator it = this->contactList.begin();
			for(it; it != this->contactList.end(); ++it){
				(*it).print(os);
			}
			return os;
		};

	private:
		vector<contactPerson> contactList;
};

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Usage: " << argv[0] << " conctact file name\n" << endl;
	}else{
		ifstream contactsFile(argv[1]);
		string contacts;
		while(getline(contactsFile, contacts)){
			cout << contacts << '\n' << endl;
		}
	}
	return 0;
}
