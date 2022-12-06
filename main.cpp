#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Trie.h"
using namespace std::chrono;

int main() {
	//initialize the graph object
    Graph g; 

	//read data from file
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
		g.AddEdges(50);
	}

	//menu asking what selection you want
	cout << "Welcome to PooFL! " << endl;

	//this will ask you what data structure/algorithm you'd like to use
	cout << "What method would you like to use?" << endl;
	cout << "(1) Graph" << endl;
	cout << "(2) Trie" << endl;

	//takes in input
	int typeOfDataStructure;
	cin >> typeOfDataStructure;

	
	if(typeOfDataStructure == 1)
	{
		//which aspect is most important to you?
		cout << "What aspect of a bathroom is most important to you?" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "1. Cleaniness (A clean bathroom is important!)" << endl;
		cout << "2. Privacy (Everyone wants their privacy! Go YOU!)" << endl;
		cout << "3. Temperature (No one likes an icky bathroom!)" << endl;
		cout << "4. All (You have a lot of demands don't you...)" << endl;
		cout << endl;

		int selection;
		cin >> selection;

		cout << "Please input a minimum rating(0-100): ";
		int rating;

		cin >> rating;
		cout << endl;

		int rating2 = rating;

		//prompts user for maximum distance;
		cout << "Please enter a maximum distance: ";
		int maxDist;
		cin >> maxDist;
		cout << endl;
	
		vector<string> bathrooms;
		bathrooms = g.DesiredRating(selection, rating2);

		//this will start the timer
		auto start = high_resolution_clock::now();

		//Clean
		if(selection == 1)
		{
			for(auto it : bathrooms)
			{
				int distance = g.Dijktras("GENDER COMMONS", it, maxDist);
				if (distance < maxDist)
				{
					cout << it << endl;
					for(int i = 0; i < it.size(); i++) cout << "-";
					cout << endl;
					cout << "Distance: " << distance << endl;
					cout << "Rating: " << g.nodes[it]->clean << endl;
					cout << "Overall: " << g.nodes[it]->avgoverall << endl;
					cout << endl;
				}
			}
		}

		//Privacy
		if(selection == 2)
		{
			for(auto it:bathrooms)
			{
				int distance = g.Dijktras("GENDER COMMONS", it, maxDist);
				if (distance < maxDist)
				{
					cout << it << endl;
					for(int i = 0; i < it.size(); i++) cout << "-";
					cout << endl;
					cout << "Distance: " << distance << endl;
					cout << "Rating: " << g.nodes[it]->priv << endl;
					cout << "Overall: " << g.nodes[it]->avgoverall << endl;
					cout << endl;
				}
			}
		}

		//Temperature
		if(selection == 3)
		{
		
			for(auto it:bathrooms)
			{
				int distance = g.Dijktras("GENDER COMMONS", it, maxDist);
				if (distance < maxDist)
				{
				cout << it << endl;
				for(int i = 0; i < it.size(); i++) cout << "-";
				cout << endl;
				cout << "Distance: " << distance << endl;
				cout << "Rating: " << g.nodes[it]->priv << endl;
				cout << "Overall: " << g.nodes[it]->avgoverall << endl;
				cout << endl;
				}
			}
		}

		//Overall
		if(selection == 4)
		{
		
			for(auto it:bathrooms)
			{
				int distance = g.Dijktras("GENDER COMMONS", it, maxDist);
				if(distance < maxDist)
				{
				cout << it << endl;
				for(int i = 0; i < it.size(); i++) cout << "-";
				cout << endl;
				cout << "Distance: " << distance << endl;
				cout << "Rating: " << g.nodes[it]->priv << endl;
				cout << "Overall: " << g.nodes[it]->avgoverall << endl;
				cout << endl;
				}
			}
		}

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);

		cout << "Here are your options! We hope you enjoy your experience." << endl;
		cout << "Time Taken: " << duration.count() << " microseconds" << endl;
	}

	//Trie
	else
	{
		string word;

        cout << "Please enter one word." << endl;
        cout << "Search query: " << endl;

        cin >> word;

        vector<string> bathrooms = g.trie.prefix(word);
		auto start = high_resolution_clock::now();

        for (auto iter : bathrooms)
		{
            cout << iter << endl;
        }

		auto stop = high_resolution_clock::now();

		cout << "Here is a list based off of your input. Which bathroom would you like a path to: " << endl;
		string word2;
		cin>>word2;

		cout << "You selected " << endl;
		cout << word2;
		cout << endl;

		for(int i = 0; i < word2.size(); i++) cout << "-";
		cout << endl;

		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Time Taken: " << duration.count() << " microseconds" << endl;
	}
    return 0;
}
