/*
 * Assignment: Create a phone contact list
 * Functions needed: Add, Delete, Search, Total, Print
 */

#include <string>
#include <cstddef>
#include <iostream>
#include <vector>

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
			os << this->firstName << "\n"  << this->lastName << "\n" << this->phoneNum;
			return os;
		};
	
		void setFirst(std::string name){
			firstName = name;
		};
		void setLast(std::string name){
			lastName = name;
		};
		void setNumber(std::string number){
			phoneNum = number;
		};
	private:
		std::string firstName, lastName, phoneNum;	
};

/*
 * Class contactBook is a vector that takes in the class contactPeople
 */
class contactBook{
	public:
		contactBook() = default;
		
		contactBook &add(contactPerson &person){
			contactList.push_back(person);
			return *this;
		};
		
		std::ostream &print(std::ostream &os){
			
			return os;
		}
	private:
		std::vector<contactPerson> contactList;
};

int main(){
	contactBook book1;

	std::string a = "blah";
	contactPerson person1(a, a);

	std::string b = "world";
	contactPerson person2(b, b);

	std::string c = "12345";
	person2.setNumber(c);

	book1.add(person2);
	//book1.print(std::cout);
	
	/*std::vector<int> v{1, 2, 3, 4, 5};
	for (auto i : v)
		std::cout << i << ' ';
	std::cout << std::endl;*/

	return 0;
};
