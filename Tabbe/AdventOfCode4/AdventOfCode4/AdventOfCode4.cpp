#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	fstream file;
	file.open("Numbers.txt");
	string wholeLine;

	string winningNumbers;
	string winningLine;
	vector<string> winningVector;

	string ownedNumbers;
	string ownedLine;
	vector<string> ownedVector;
	int totalPoints = 0;

	string delimiter = " | ";
	size_t pos = 0;
	while (getline(file, wholeLine)) 
	{
		ownedVector.clear();
		winningVector.clear();
		int loopPoint = 0;

		wholeLine.erase(0,10);
		while ((pos = wholeLine.find(delimiter)) != string::npos)
		{
			ownedNumbers = wholeLine.substr(0, pos);
			winningNumbers = wholeLine.erase(0, pos + delimiter.length());
		}
		//cout << "o: " << ownedNumbers << " w: " << winningNumbers << endl;
		stringstream ownedStream(ownedNumbers);
		stringstream winningStream(winningNumbers);
		while (getline(ownedStream, ownedLine, ' '))
		{
			ownedVector.push_back(ownedLine);
		}
		//std::cout << ownedVector.size() << endl;
		while (getline(winningStream, winningLine, ' '))
		{
			winningVector.push_back(winningLine);
		}
		//std::cout << winningVector.size() << endl;


		for (size_t i = 0; i < ownedVector.size(); i++)
		{
			string compare1 = ownedVector[i];
			for (size_t j = 0; j < winningVector.size(); j++)
			{
				string compare2 = winningVector[j];
				if (compare1.compare(compare2) == 0)
				{
					loopPoint++;
					//std::cout << compare1 << " & " << compare2 << " : " << loopPoint << endl;
				}
			}
		}
		if (loopPoint > 0)
		{
			//std::cout << "added points in this card: " << (1 * pow(2, (loopPoint - 1))) << endl;
			totalPoints = totalPoints + (1 * pow(2, (loopPoint-1)));
		}
		//std::cout << "End of card total points: " << totalPoints << endl;
	}
	std::cout << totalPoints;
}