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

/*
 * Class contactPerson is a set of strings that contains the contacts first name,
 * last name, and phone number. This class can also edit the individual values of
 * each contact after initialization.
 */

class contactPerson{
	public:
		contactPerson() = default;
		contactPerson(std::string first): firstName(first) {};
		contactPerson(std::string first, std::string last)
		: firstName(first), lastName(last) {};
		contactPerson(std::string first, std::string last, std::string number)
		: firstName(first), lastName(last), phoneNum(number) {};

		std::ostream &print(std::ostream &os){
			os << this->firstName << "\n"  << this->lastName << "\n" << this->phoneNum << std::endl;
			return os;
		};

		std::string getFirstName(){
			return this->firstName;
		};

		 std::string getLastName(){
			return this->lastName;
		};

		std::string getPhoneNumber(){
			return this->phoneNum;
		};

	private:
		std::string firstName, lastName, phoneNum;
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

		std::vector<contactPerson>::size_type total(){
			return this->contactList.size();
		};

		std::ostream &print(std::ostream &os){
			std::vector<contactPerson>::iterator it = this->contactList.begin();
			for(it; it != this->contactList.end(); ++it){
				(*it).print(os);
			}
			return os;
		};

	private:
		std::vector<contactPerson> contactList;
};

int main(){
	return 0;
}
