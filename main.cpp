#include <iostream>
#include <fstream>
#include <sstream>
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
    /*for (const auto& iter : g.nodes) {
        cout << iter.first << ": ";
        for (auto it : iter.second->neighbors)
            cout << it.first->name <<" " << it.second<< "  ";
        cout << endl;
    }*/
	
	
	cout << "Welcome to PooFL! " << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Find the closest bathroom to me based off my needs" << endl;
	cout << "2. Search for a specific bathroom" << endl;
	int choice;
	cin >> choice;
    if (choice == 1) {
        cout << "Please Enter Your Current Location: " << endl;
        string location;
        cin >> location;
        cout << "What aspect of a bathroom is most important to you?" << endl;
        cout << "1. Cleaniness" << endl;
        cout << "2. Privacy" << endl;
        cout << "3. Temperature" << endl;
        cout << "4. All" << endl;
        int pref1;
        cin >> pref1;
        int rating;
        vector<string> desiredbathrooms;
        if (pref1 == 1) {
            cout << "What is your desired quality rating for the Cleaniness(1-100)?" << endl;
            cin >> rating;
            desiredbathrooms = g.DesiredRating("Cleaniness", rating);
        }
        if (pref1 == 2) {
            cout << "What is your desired quality rating for the Privacy(1-100)?" << endl;
            cin >> rating;
            desiredbathrooms = g.DesiredRating("Privacy", rating);
        }
        if (pref1 == 3) {
            cout << "What is your desired quality rating for the Temperature(1-100)?" << endl;
            cin >> rating;
            desiredbathrooms = g.DesiredRating("Temperature", rating);
        }
        if (pref1 == 4) {
            cout << "What is your desired Overall quality rating(1-100)?" << endl;
            cin >> rating;
            desiredbathrooms = g.DesiredRating("Overall", rating);
        }


        if (desiredbathrooms.size() == 0)
            cout << "There are no bathrooms nearby that align with your preferences." << endl;
        else {
            cout << "These are the closest locations with bathrooms that satisfy your desired preferences!" << endl;
            for (int j = 0; j < desiredbathrooms.size(); j++) {
                cout << desiredbathrooms[j] << endl;
            }
        }
    }
    if (choice == 2) {
        string word;
        cout << "Please enter a one word." << endl;
        cout << "Search query: " << endl;
        cin >> word;
        vector<string> bathrooms = g.trie.prefix(word);
        for (auto iter : bathrooms) {
            cout << iter << endl;
        }
    }

    return 0;
}
