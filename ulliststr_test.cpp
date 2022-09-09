/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{

	//GET FUNCTIONS SHOULD TEST GETVALLOC()

	//1. Test cases for push_back
	cout << "Testing push_back" << endl;
	
	ULListStr dat1;
	cout << dat1.size() << endl; 
	cout << "Should print: 0" << endl;
	dat1.push_back("0"); //test for when list is empty
	dat1.push_back("1");
	dat1.push_back("2");

	cout << dat1.get(0) << " " << dat1.get(1) << " " << dat1.get(2) << endl;
	cout << "Should print: 0 1 2" << endl;

	//during this loop, has to create a new node
	for(int i = 3; i < 11; i++){
		dat1.push_back(to_string(i));
	}

	//during this loop, has to create a new node
	for(int i = 11; i < 21; i++){
		dat1.push_back(to_string(i));
	}

 	for(int i = 3; i < 21; i++){ 
	 	cout << dat1.get(i) << " ";
	 }

	cout << endl << "Should print: 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" << endl;

	//2. Test cases for push_front
	cout << "Testing push_front" << endl;

	ULListStr dat2;
	dat2.push_front("0"); //Test for when list is empty
	dat2.push_front("1");
	dat2.push_front("2");

	cout << dat2.get(0) << " " << dat2.get(1) << " " << dat2.get(2) << endl;
	cout << "Should print: 2 1 0" << endl;

	//during this loop, has to create a new node
	for(int i = 3; i < 11; i++){
		dat2.push_front(to_string(i));
	}

	//during this loop, has to create a new node
	for(int i = 11; i < 21; i++){
		dat2.push_front(to_string(i));
	}

	for(int i = 0; i < 18; i++){
		cout << dat2.get(i) << " ";
	}
	cout << endl << "Should print: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3" << endl;

	//3. Test cases for pop_back
	cout << "Testing pop_back" << endl;

	//checks condition for when we skip to the next node
	dat1.pop_back();
	dat1.pop_back();
	cout << dat1.back() << " ";

	//checks condition for when we have one value in array
	for(int i = 18; i > 1; i--){
		dat1.pop_back();
	}
	cout << dat1.back() << " ";
	
	cout << endl << "Should print: 18 1" << endl;

	//checks conditions for when we have no values
	dat1.pop_back(); 
	dat1.pop_back();
	dat1.pop_back();

	//4. Test cases for pop_front
	cout << "Testing pop_front" << endl;

	//checks condition for when we skip to the next node
	dat2.pop_front();
	dat2.pop_front();
	cout << dat2.front() << " ";

	//checks condition for when we have one value in array
	for(int i = 18; i > 1; i--){
		dat2.pop_front();
	}
	cout << dat2.front() << " ";

	cout << endl << "Should print: 18 1" << endl;
	
	//checks conditions for when we have no values
	dat2.pop_front(); 
	dat2.pop_front();
	dat2.pop_front();

	//5. Test cases for back
	cout << "Testing back" << endl;

	ULListStr dat3;

	//checking for normal conditions
	for(int i = 0; i < 10; i++){
		dat3.push_back(to_string(i));
	}
	cout << dat3.back() << " ";

	//checking for when we go to next node
	dat3.push_back("10");
	cout << dat3.back() << " ";

	//after popping back?
	for(int i = 10; i > 0; i--){
		dat3.pop_back();
	}
	cout << dat3.back();

	cout << endl << "Should print: 9 10 0" << endl;

	//6. Test cases for front
	cout << "Testing front" << endl;

	ULListStr dat4;
	//checking for normal conditions
	for(int i = 0; i < 10; i++){
		dat4.push_front(to_string(i));
	}
	cout << dat4.front() << " ";

	//checking for when we go to next node
	dat4.push_front("10");
	cout << dat4.front() << " ";

	//after popping front?
	for(int i = 10; i > 0; i--){
		dat4.pop_front();
	}
	cout << dat4.front();
	cout << endl << "Should print: 9 10 0" << endl;

	//7. Random Test (copied from instructions)
	cout << "Instructions Test" << endl;
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	// prints: 8 7 9
	cout << "Should print: 8 7 9" << endl;

	cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
	cout << "Should print: 3" << endl;

  return 0;
}
