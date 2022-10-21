
#include "Header.h"


/*
* 
* ******************************************************************************************************
            *************Advantages of using an Array*******************
*linked list easily edited
*pointers not required
*less memory needed
*used in my delete node command
* *array is also used in my load command

        **********************Disadvantages using an array****************

*The size of array cannot be modified. 
*array must be defined


        ******************Advantages of Using an Linked List******************
		* 
*Dynamic memory allocation is easeir
*Deleting/inserting Nodes is simple
*used in my LinkedList Class

         *******************Disadvantages of Using an Linked List**************
		 * 
*all nodes must be accessed before reaching specified node
*cannot access nodes randomly. 

**************************************************************************************************************
*/
int main() {
	ifstream in;
	in.open("Commands.csv");
	string x, go, goinfo;
	LinkedList Links;
	int menu;
	string addgomand, addgomandinfo;


	while (getline(in, x)) {
		stringstream dash(x);
		getline(dash, go, ',');
		getline(dash, goinfo);
		Links.insert(go, goinfo);
	}
	cout << "\n" << "\n" << "\n";
	do {
		cout << "" << "\n";
		cout << "****************** Choose from below **********************" << "\n";
		cout << "" << "\n";
		cout << "****************** [1] Game rules          *****************" <<  "\n";
		cout << "****************** [2] Play Game           *****************" << "\n";
		cout << "****************** [3] Load Previous Game  *****************" << "\n";
		cout << "****************** [4] Add command         *****************" << "\n";
		cout << "****************** [5] delete command      *****************" << "\n";
		cout << "****************** [6] Exit                *****************" << "\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Here is how this works, you can choose up to 30 questions to answer" << endl;
			cout << "-------------------------------------------------------------------" << endl;
			cout << "answer a question right and you get 1 point, answer wrong...and you get -1 point." << endl;
			cout << "-------------------------------------------------------------------" << endl;
			cout << "3 questions will pop up, but only 1 question is right..." << endl;
			cout << "-------------------------------------------------------------------" << endl;
			cout << "choose the 'play game' option when you are ready. " << endl;
			break;
		case 2:
			Links.playGame();
			break;
		case 3:
			Links.loadPreviousGame();
			break;
		case 4:
			cout << "input comm\n";
			cin >> addgomand;
			cout << "input comm info\n";
			cin.ignore();
			getline(cin, addgomandinfo);
			Links.insert(addgomand, addgomandinfo);
			break;
		case 5:
			cout << "input comm to be deleted";
			cin >> go;
			Links.deletefromgomand(go);
			break;
		default:
			Links.placeinDoc();
			break;
		}
	} while (menu <= 5);

}