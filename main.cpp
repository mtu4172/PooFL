#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Trie.h"

int main() {
    Graph g;
    ifstream theFile("DSAProject3Data.csv");
	if (theFile.is_open())
	{
		string firstLine;
		getline(theFile, firstLine, '\r');

		for (int i = 0; i < 100000; i++)
		{
			getline(theFile, firstLine, '\r');
			istringstream stream1(firstLine);

			int cleany;
			int privacy;
			int temp2;
			int overall;
			int br;

			string namer;
			string name2;
			string clean1;
			string privacy1;
			string temp1;
			string overall1;
			string br1;
			bool br2 = false;

			getline(stream1, namer, ',');
			getline(stream1, namer, ',');
			getline(stream1, name2, ',');
			namer.append(" ").append(name2);
			getline(stream1, clean1, ',');
			cleany = stoi(clean1);
			getline(stream1, privacy1, ',');
			privacy = stoi(privacy1);
			getline(stream1, temp1, ',');
			temp2 = stoi(temp1);
			getline(stream1, overall1, ',');
			overall = stoi(overall1);
			getline(stream1, br1, ',');
			br = stoi(br1);

			if (br == 1)
				br2 = true;

			g.AddNode(namer, privacy, temp2, cleany, overall, br2);
		}

	}
	theFile.close();
	
  	//menu asking what selection you want
	cout << "Welcome to PooFL! " << endl;
	cout << "What aspect of a bathroom is most important to you?" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "1. Cleaniness (A clean bathroom is important!)" << endl;
	cout << "2. Privacy (Everyone wants their privacy! Go YOU!)" << endl;
	cout << "3. Temperature (No one likes an icky bathroom!)" << endl;
	cout << "4. All (You have a lot of demands don't you...)" << endl;

	int selection;
	cin >> selection;

	int rating;

	string currentLocation;


	cout << "Please input a minimum rating(0-100): ";
	cin >> rating;

	int rating2 = rating;
	int select = selection;

	if(selection == 1)
	{
		vector<string> bathrooms;
		bathrooms = g.DesiredRating(select, rating2);
		for(auto it : bathrooms)
		{
			int distance = g.Dijktras("GENDER COMMONS", it);
			cout << it << "'s" << " distance from " << "you is" << ": " << distance << " and its rating is " << g.nodes[it]->clean << endl;
		}
	}
	
    return 0;
}
