#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
using namespace std;
static void ShowTasks(vector<string> list)
{
	cout << "Tasks: " << endl;

	int i = 0;
	for (string& word : list)
	{
		cout << i << " " << word << "" << endl;
		i++;
	}
}
int main()
{
	bool active = true;
	vector<string> wordList;
	while (active)
	{
		system("cls");
		cout << "1: View tasks \n2: Add task \n3: Mark task as done \n4: Remove task \n5: Quit" << endl;
		int answer;
		string input;
		cin >> answer;
		cin.ignore();
		switch (answer)
		{
		case 1:
			system("cls");
			if (wordList.size() == 0)
			{
				cout << "No tasks" << endl;
			}
			else
			{
				ShowTasks(wordList);
			}
			Sleep(2000);
			break;
		case 2:
			system("cls");
			cout << "Type what you want to add " << endl;
			getline(cin, input);
			wordList.push_back(input);
			ShowTasks(wordList);
			break;
		case 3:
			system("cls");
			if (wordList.size() == 0)
			{
				cout << "No tasks" << endl;
			}
			else
			{
				cout << "Which task would you like to mark as done" << endl;
				ShowTasks(wordList);
				cin >> answer;
				if (answer >= 0 && answer < wordList.size())
				{
					string selectedTask = wordList.at(answer);
					string done = selectedTask + " done";
					wordList.at(answer) = done;
				}
			}
			break;
		case 4:
			system("cls");
			if (wordList.size() == 0)
			{
				cout << "No tasks to remove" << endl;
			}
			else
			{
				ShowTasks(wordList);
				cout << "Type what task you want to remove " << endl;
				cin >> answer;
				if (answer >= 0 && answer < wordList.size())
				{
					wordList.erase(wordList.begin() + answer);
				}
			}
			break;
		case 5:
			active = false;
			break;
		default:
			break;
		}
	}
	
}