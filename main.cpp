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
    for (const auto& iter : g.nodes) {
        cout << iter.first << ": ";
        for (auto it : iter.second->neighbors)
            cout << it.first->name <<" " << it.second<< "  ";
        cout << endl;
    }
    return 0;
}
