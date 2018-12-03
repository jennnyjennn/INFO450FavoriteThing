#include <iostream>

#include <string>

using namespace std;


void instructions();


// VideoGames Item Class
class VideoGames
{
private:
	int ID;
	string gameName;
	string consoleType;
	string ratingESRB;
	int maxPlayers;
	static int IDGenerator;
	double personalRating;
public:
	VideoGames();
	void getVideoGames();
	friend ostream& operator<<(ostream &o, VideoGames& i);
};

//intialize the static variable to be used when generating the ID
int VideoGames::IDGenerator = 1;

// VideoGames List Class
class VideoGamesList
{
private:
	int numItems;
	VideoGames iList[1000];
public:
	VideoGamesList();
	void addItem();
	void showList();
	//bool checkItem(string gameName, string consoleType);
	//int removeFromList(int ID);
};

// Constructor
VideoGames::VideoGames()
{
	ID = IDGenerator++;
	gameName = "";
	consoleType = "";
	ratingESRB = "";
	maxPlayers = 0;
	personalRating = 0;
}

// overloaded insertion operation << for printing object to the console
ostream& operator<<(ostream &o, VideoGames& i)
{
	o << "ID: " << i.ID << endl;
	o << "Game Title: " << i.gameName << endl;
	o << "Console Type: " << i.consoleType << endl;
	o << "ESRB Rating: " << i.ratingESRB << endl;
	o << "Max Players:" << i.maxPlayers << endl;
	o << "Personal Rating:" << i.personalRating << endl;

	return o;
}

// gets input from the user for the VideoGames object
void VideoGames::getVideoGames()
{
	cout << "Enter Game Title: " << endl;
	getline(cin, gameName);
	cout << "Enter Game Console Type: " << endl;
	getline(cin, consoleType);
	cout << "Enter Game ESRB Rating: " << endl;
	getline(cin, ratingESRB);
	cout << "Enter Game Maximum Players: " << endl;
	cin >> maxPlayers;
	cout << "Enter Personal Rating: " << endl;
	cin >> personalRating;
	cin.ignore();
	cin.clear();
}


// VideoGames List constructor
VideoGamesList::VideoGamesList()
{
	numItems = 0;
}

// adds an VideoGames item to the list
void VideoGamesList::addItem()
{

	iList[numItems].getVideoGames();
	numItems++; // keeps track of the number of items

}

//Method used to check if the object you want to add already exists
//bool VideoGamesList::checkItem(string n, string t)
//{
	//int i;
	//for (i = 0; i < numItems; i++)
	//{
		
	//}

//}

// shows the contents of the list
void VideoGamesList::showList()
{
	int i;
	for (i = 0; i < numItems; i++)
		cout << iList[i] << endl;
}

int main()
{
	char answer;

	instructions();

	VideoGamesList myList; // create list object 
	
	do
	{

		myList.addItem();

		cout << "\n";
		cout << "Would you like to add another game? Enter (Y) to continue. " << endl;

		cin >> answer;
		
		cin.clear();
		cin.ignore();

		cout << "\n";
	} while (answer == 'Y' || answer == 'y');
	
	// displays list of objects to user 
	
	cout << "Your list of favorite games: " << endl;
	cout << "\n";

	myList.showList();

	system("pause");
	return 0;

}


void instructions()
{
	cout << "**" << " *********************** " << "**" << endl;
	cout << "**" << "                         " << "**" << endl;
	cout << "**" << "       Keep a list       " << "**" << endl;
	cout << "**" << "     of your favorite    " << "**" << endl;
	cout << "**" << "       video games.      " << "**" << endl;
	cout << "**" << "                         " << "**" << endl;
	cout << "**" << "     You can enter:      " << "**" << endl;
	cout << "**" << "     Game Title,         " << "**" << endl;
	cout << "**" << "     Console Type,       " << "**" << endl;
	cout << "**" << "     ESRB Rating,        " << "**" << endl;
	cout << "**" << "     Max Players,        " << "**" << endl;
	cout << "**" << "     Personal Rating     " << "**" << endl;
	cout << "**" << "                         " << "**" << endl;
	cout << "**" << " *********************** " << "**" << endl;
	cout << endl;
	cout << endl;
}