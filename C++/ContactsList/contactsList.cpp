/*
 * Assignment: Create a phone contact list
 * Functions needed: Add, Delete, Search, Total, Print
 */

#include <string>
#include <cstddef>
#include <iostream>
#include <vector>
#include <iterator>

/*
 * This function is used to turn all input names in contactPerson to be in lower case.
 * Helps with search to ensure that "Alan" can be found with "alan"
 */
void lowerCaseAllElements(std::string &str){
	for(auto c : str){
		c = tolower(c);
	}
}

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
		
		/*
 		* A brute force search implemention
 		* Relys on iterating through the entire vector contactList
 		*/
		std::vector<contactPerson> searchByName(const std::string &first, const std::string &last = std::string()){
			std::vector<contactPerson> contacts;
			for(auto person : this->contactList){
				if(last.empty()){
					if(person.getFirstName() == first){
						contacts.push_back(person);
					}
				}else{
					if(person.getFirstName() == first && person.getLastName() == last){
						contacts.push_back(person);
					} 
				}
			}
			return contacts;
		}
		
	private:
		std::vector<contactPerson> contactList;
};

int main(){
	contactBookVector book1;

	std::string a = "blah"; 

	contactPerson person1(a, a);

	std::string b = "world";
	contactPerson person2(b, b);

	book1.add(person2);
	book1.add(person1);
	
	std::vector<contactPerson> names = book1.searchByName(a, a);
	for(auto a: names){
		a.print(std::cout);
	}

	return 0;
}
