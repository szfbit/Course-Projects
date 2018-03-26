#include <iostream>
#include <iomanip>
#include <time.h>
#include "activity.h"
#pragma warning(disable : 4996)
using namespace std;

const int SIZE = 100;

//Ask the user whether to change way of sorting
char wayOfSorting()
{
	char choice;//choice of whether to change way of sorting
	char choiceOfSorting = 'n';//type of choice of sorting

	do
	{
		cout << "Want to change the way of sorting? [y/n]: ";
		cin >> choice;

		if(cin.fail())
		{
			cin.clear();
			cin.sync();
		}
	}
	while(choice != 'y' && choice != 'n');

	if(choice == 'y')
	{
		do
		{
			cout << "Please enter way of sorting S, D or L (S-Start Time, D-Duration, L-Description Length): ";
			cin >> choiceOfSorting;

			if(cin.fail())
			{
				cin.clear();
				cin.sync();
			}
		}
		while(choiceOfSorting != 'S' && choiceOfSorting != 'D' && choiceOfSorting != 'L');
		cout << endl;
	}

	return choiceOfSorting;
}

//Change way of sorting
void changeWayOfSorting(Activity activities[], int n, char &choice)
{
	char choiceOfSorting = wayOfSorting();//choice of sorting

	choice = choiceOfSorting;

	switch(choiceOfSorting)
	{
	case 'S': 	
		insertion_sort_S(activities,n);
		break;
	case 'D':
		insertion_sort_D(activities,n);
		break;
	case 'L':
		insertion_sort_L(activities,n);
		break;
	default:
		insertion_sort_S(activities,n);
	}
}

//Show part E
void showPartE(Activity activities[], int n, char &choice)
{
	changeWayOfSorting(activities, n, choice);

	if(choice != 'n')
	{
		cout << setfill(' ');
		showTheFrame(activities, n);
		displayActivities(activities, n);
	}
}

//Get the choice of search
void choiceOfSearching(Activity activities[], int n, int &id_found)
{
	char choice;//a temporary variable storing the choice of the user

	do
	{
		cout << "Choose a way to search S, T or D (S-Start Time, T-Duration Time, D-Description): ";
		cin >> choice;
		cin.ignore();

		if(cin.fail())
		{
			cin.clear();
			cin.sync();
		}
	}
	while(choice != 'S' && choice != 'T' && choice != 'D');

	switch(choice)
	{
	case 'S':
		int search_hh, search_mm;//star time and minute
		char dummy; //colon between search_hh and search_mm

		cout << "Please input the start time: ";
		cin >> search_hh >> dummy >> search_mm;

		if(cin.fail())
		{
			cin.clear();
			cin.sync();
		}

		cout << endl;
		isSearched(activities, n, search_hh, search_mm, id_found);
		cout << endl;
		break;
	case 'T':
		int time;//the duration

		cout << "Please input the duration (in minutes): ";
		cin >> time;

		if(cin.fail())
		{
			cin.clear();
			cin.sync();
		}

		cout << endl;
		searchByDuration(activities, n, time);
		cout << endl;
		break;
	case'D':
		char * des =  new char[SIZE];//search by description

		do
		{
			memset(des, 0 ,SIZE);
			cout << "Please input the full or part of description of the activity (at least 3 letters, case sentisitive): ";
			cin.getline(des,SIZE);
		}
		while(strlen(des) < 3);

		cout << endl;
		searchByDescription(activities, n, des);
		cout << endl;
		cin.clear();
		delete [] des;
		break;
	}
}

//Show the current time
void showTime()
{
	time_t t; //time object
	tm *lt; //point to an address
	t = time(NULL); //reset t
	lt = localtime(&t); //give local time to lt

	switch(lt->tm_wday)
	{
	case 0:
		cout << "Sunday, ";
		break;
	case 1:
		cout << "Monday, ";
		break;
	case 2:
		cout << "Tuesday, ";
		break;
	case 3:
		cout << "Wednesday, ";
		break;
	case 4:
		cout << "Thursday, ";
		break;
	case 5:
		cout << "Friday, ";
		break;
	case 6:
		cout << "Saturday, ";
		break;
	}

	cout << "Current Time: " << endl;
	cout << " " << lt->tm_mday << "/" << (lt->tm_mon) + 1  << "/" << (1900 + lt->tm_year) << ", " << lt->tm_hour << ":" << lt->tm_min <<  endl;
	cout << endl;
}

void main()
{
	Activity activities[SIZE];//the activities array
	int n;//count of activities
	int id_found;//the found activities
	char choice = 'n';//choice of whether to change way of sorting
	
	//Part A
	cout << "[A] Input activities from file\n";
	cout << "==============================\n";
	readFileOfActivities(activities, n);
	cout << endl;
	cout << n << " activitie(s) are extracted.\n\n\n";
	addActivities(activities, n);
	cout << endl;

	//Part B
	cout << "[B] Display list of activities\n";
	cout << "==============================\n";

	if(n == 1)
	{
		displayOneActivity(activities);
		return;
	}

	showTheFrame(activities, n);
	displayActivities(activities, n);
	cout << endl;

	//Part C
	cout << "[C] Sort activities and extend duration\n";
	cout << "=======================================\n";
	insertion_sort_S(activities,n);
	showTheFrame(activities, n);
	displayActivities(activities, n);
	chooseActivityToExtend(activities, n);
	cout << endl;

	//Part D
	cout << "[D] Search activities\n";
	cout << "=====================\n";
	choiceOfSearching(activities, n, id_found);

	//Part E
	cout << "[E] Change Sorting\n";
	cout << "==================\n";
	showPartE(activities, n, choice);
	cout << endl;

	//Part F
	cout << "[F] Some statics\n";
	cout << "================\n";
	showTime();
	findLongestDuration(activities, n);
	findTotalTime(activities, n);
	cout << endl;

	//End of the program
	cout << "Thank you for using this program.\n\n";
}