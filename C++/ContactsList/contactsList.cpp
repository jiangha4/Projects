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
#include <sstream>

using namespace std;
/*
 * Class contactPerson is a set of strings that contains the contacts first name,
 * last name, and phone number. This class can also edit the individual values of
 * each contact after initialization.
 */

class contactPerson{
	friend class contactBookVector;
	public:
		contactPerson() = default;
		contactPerson(string first): firstName(first) {};
		contactPerson(string first, string last)
		: firstName(first), lastName(last) {};
		contactPerson(string first, string last, string number)
		: firstName(first), lastName(last), phoneNum(number) {};

		ostream &print(ostream &os){
			os << this->firstName << ' ' << this->lastName << ' ' << this->phoneNum << endl;
			return os;
		};

	private:
		string firstName, lastName, phoneNum;
};


contactPerson createFromRecord(istringstream& record){
	string first;
	string last;
	string num;
	record >> first;
	record >> last;
	record >> num;
	contactPerson newPerson(first, last, num);

	return newPerson;
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

		vector<contactPerson> searchByFirstName(string firstName){
			vector<contactPerson> match;
			vector<contactPerson>::iterator it = this->contactList.begin();
			for(it; it != this->contactList.end(); ++it){
				contactPerson person = (*it);
				if (person.firstName == firstName){
					match.push_back(person);
				}
			}
			return match;
		};

		//vector<contactPerson> searchByLastName(string lastName){};

		//vector<contactPerson> searchByNum(string num){};


	private:
		vector<contactPerson> contactList;
};



int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Usage: " << argv[0] << " contact file name\n" << endl;
	}else{
		ifstream contactsFile(argv[1]);
		string contacts;
		contactBookVector book1;
		while(getline(contactsFile, contacts)){
			//Got a line from the file contain a record of a person 
			//First Last Number
			istringstream records(contacts);
			contactPerson personRecord = createFromRecord(records);
			book1.add(personRecord);
		}
		//book1.print(cout);
		string s("Lebron");
		vector<contactPerson> match;
		match = book1.searchByFirstName(s);
		match[0].print(cout);
	}
	return 0;
}
