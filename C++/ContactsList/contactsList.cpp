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

		/*
 		* Getters for access to person names
 		* Return type is a const reference to 
 		* 	1. Save computation time as it is faster to return a reference rather than
 		* 	a copy.
 		* 	2. Const to ensure that if you cannot change the name just by getting the
 		* 	reference.
 		*
 		* 	Note: Might not be doing what I think it does. 
 		*/	
		std::string const &getFirstName(){
			return this->firstName;
		} 

		 std::string const &getLastName(){
			return this->lastName;
		}
		
		std::string const &getPhoneNumber(){
			return this->phoneNum;
		}
	
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
		void search(){
			for(auto person : this->contactList){
				person.print(std::cout);
			}
		}
		
		/*
 		* QuickSort
 		*
		*contactBookVector &sortContactBook(){
		*	
		*	return *this;
		};*/
		
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
	book1.print(std::cout);

	std::cout << book1.total() << std::endl;
	
	book1.search();
	
	return 0;
}
