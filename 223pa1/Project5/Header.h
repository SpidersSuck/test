
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;
struct Node {
	string cmd;
	string info;
	Node* push;
};

class LinkedList
{
	Node* Order;
	string playerName;
	int Scores, Qs;

public:
	LinkedList()
	{
		Order = NULL;
		Scores = 0;
	}
	void insert
	(string cmd, string cmdinfo)
	{
		Node* junction = new Node;
		junction->cmd = cmd;
		junction->info = cmdinfo;
		junction->push = NULL;
		if (Order == NULL)
			Order = junction;
		else
		{
			junction->push = Order;
			Order = junction;
		}
	}

	void playGame() {

		char menu;
		Node* prime = Order;
		Node* Description;
		cout << "Input name please";
		cin >> playerName;
		cout << "how many questions would you like to answer 1-30";
		cin >> Qs;
		int i = 0;
		while (i < Qs)
		{
			Description = prime;
			cout << Description->cmd << "\n";
			cout << "**** 1 ****" << Description->info << "\n";
			cout << "**** 2 ****" << Description->push->info << "\n";
			cout << "**** 3 ****" << Description->push->push->info << "\n";
			prime = prime->push;
			cin >> menu;
			if (menu == '1') {
				Scores = Scores + 1;
			}
			else
			{
				Scores = Scores - 1;
			}
			i++;
		}
		cout << "Your score is" << Scores << "\n";
		storeData();
		return;
	}

	void loadPreviousGame()
	{
		ifstream in;
		string name, sub, line;
		string Score;
		cout << "input name used for old game";
		cin >> name;
		in.open("profiles.csv");
		while (getline(in, line))
		{
			stringstream dash(line);
			getline(dash, sub, ',');
			if (sub == name)
			{
				getline(dash, Score);
				playerName = sub;
				stringstream implament(Score);
				implament >> Scores;
				break;
			}
		}
		return;
	}

	void deletefromgomand
	(string cmd)
	{
		if (Order->cmd == cmd)
		{
			delete Order;
			Order = Order->push;
			return;
		}
		if (Order->push == NULL)
		{
			if (Order->cmd == cmd)
			{
				delete Order;
				Order = NULL;
				return;
			}
			cout << "Error" << endl;
			return;
		}

		Node* prime = Order;
		while (prime->push != NULL)
		{
			if (prime->push->cmd == cmd)
			{
				Node* newNodez = prime->push->push;
				delete prime->push;
				prime->push = newNodez;
				return;
			}
			prime = prime->push;
		}
		cout << "Error" << endl;
	}

	void show()
	{
		Node* prime = Order;
		while (prime != NULL)
		{
			cout << prime->cmd << " " << prime->info << "\n";
			prime = prime->push;
		}
		cout << endl;
	}

	

	void storeData() {
		ofstream out("profiles.csv", ios::app);
		if (out.is_open()) {
			out << playerName << "," << Scores << "\n";
			out.close();
		}
		else
		{
			cout << "Error";
		}
		return;
	}


	void placeinDoc()
	{
		Node* prime = Order;
		ofstream out("Commands.csv");
		if (out.is_open()) {
			while (prime != NULL)
			{
				out << prime->cmd << "," << prime->info << "\n";
				prime = prime->push;
			}
			out.close();
		}
		else
		{
			cout << "not able to write into file";
		}
		return;

	}
};
