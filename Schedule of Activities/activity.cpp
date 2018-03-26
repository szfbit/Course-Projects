#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "activity.h"

using namespace std;
const int NAME_SIZE = 100;
const int SIZE = 100;

//Defiinition of the default constructor
Activity::Activity()
{
	startTime_h = 0;
	startTime_m = 0;
	durationMin = 0;
	description[0] = '\0';
}

//Showing the upper frame of the object
void showTheFrame(const Activity activities[], int n)
{
	if(n != 1)
	{
		for(int i = 0; i < (6 + 11+findTheLongestWord(activities, n) + 3 + 29); i++)
		{
			cout << '*';
		}
		cout << endl;

		cout << "|" << " Order " << "|" << " Start " << "|" << "  End  " << "|";
		if(findTheLongestWord(activities, n) <= 17)
		{
			cout << " ";
		}
		else
		{
			for(int i = 0; i <((findTheLongestWord(activities, n) - 17)/2+1); i++)
			{
				cout << " ";
			}
		}
		
		cout << "Types of activity" << "   |";

		for(int i = 0; i < 6; i++)
		{
			cout << " ";
		}

		cout << "Duration" << "      " << "|" << endl;

		for(int i = 0; i < (6 + 11+ findTheLongestWord(activities, n) + 3 + 29); i++)
		{
			cout << '*';
		}
		cout << endl;
	}
}

//Diaplay the activities
void displayActivities(const Activity activities[], int n)
{
		for (int i=0;i<n;i++)
		{
			cout << "|" << setw(4) << i+1 << "   " << activities[i];
			showTheDuration(activities, n, i);
		}

		cout << endl << endl;
}

//Definition of the input stream
istream &operator >> (istream &ins, Activity &activity)
{
	char dummy;//dummy variable

	ins >> activity.startTime_h >> dummy >> activity.startTime_m >> activity.durationMin;
	ins.get(dummy);
	ins.getline(activity.description, SIZE);

	return ins;
}

//Get the time after adding the duration to the starting time
int getChangedTime(int h, int m, int dur)
{
	int new_h = h;//temporary varibale for storing the end hour
	int new_m = m + dur;//temporary varibale for storing the end minute
	int new_time;//new time in 4 digits(easy to use)

	if(new_m >= 60)
	{
		new_m %= 60;
		new_h++;
	}

	new_time = new_h*100 + new_m;

	return new_time;
}

//Display only one activity
void displayOneActivity(const Activity activities[])
{
	cout << " Time: " << setfill('0') << setw(2) << activities[0].startTime_h << ":" << setw(2) << activities[0].startTime_m << " - "
			<< getChangedTime(activities[0].startTime_h, activities[0].startTime_m, activities[0].durationMin)/100 << ":" 
			<< setw(2) << getChangedTime(activities[0].startTime_h, activities[0].startTime_m, activities[0].durationMin)%100 << endl << " Description: "
			<< activities[0].description << endl << " Duration: " << activities[0].durationMin << " minutes" << setfill(' ') << endl;
	cout << endl;
}

//Find the longest cstring and return the length of it
int findTheLongestWord(const Activity activities[], int n)
{
	int longest = -1;//temporary variable for the longest lenght of the cstring 

	for(int i = 0; i < n; i++)
	{
		int length = strlen(activities[i].description);
		if(length > longest)
		{
			longest = length;
		}
	}

	if(n == 1)
	{
		longest = strlen(activities[0].description);
	}

	return longest;
}

//Definition of the output stream
ostream &operator << (ostream &outs, const Activity &activity)
{
	outs << "|" << " " << setfill('0') << setw(2) << activity.startTime_h << ":" << setw(2) << activity.startTime_m << " " <<  "|" << " ";
	outs << setw(2) << getChangedTime(activity.startTime_h, activity.startTime_m, activity.durationMin)/100 << ":" 
			<< setw(2) << getChangedTime(activity.startTime_h, activity.startTime_m, activity.durationMin)%100;
	outs << " " << "|" << " " << activity.description;

	return outs;
}

//Shoe the duration
void showTheDuration(const Activity activities[], int n, int order)
{
	int length = 3 + findTheLongestWord(activities, n) ;//the variable for the formatting

	cout << setfill(' ') << setw(length - strlen(activities[order].description));
	cout << "| ";

	if(activities[order].durationMin < 60)
	{
		cout << setfill(' ') << setw(2) << activities[order].durationMin;

		if(activities[order].durationMin > 1)
		{
			cout << " minutes"; 
		}
		else
		{
			cout << " minute";
		}

		cout << setw(10) << "|" << endl;
	}
	else if(activities[order].durationMin == 60)
	{
		cout << " 1" << " hour" << setw(13) << "|" << endl;
	}
	else
	{
		cout << setfill(' ') << setw(2) << activities[order].durationMin/60;

		if( activities[order].durationMin/60 == 1)
		{
			cout  << " hour ";
		}
		else
		{
			cout << " hours ";
		}

		cout << activities[order].durationMin%60;

		if(activities[order].durationMin%60 > 1)
		{
			cout << " minutes";
		}
		else
		{
				cout << " minute";
		}

		cout << setw(2) << "|" << endl;
	}

	for(int i = 0; i < (6 + 11+ findTheLongestWord(activities, n) + 3 + 29); i++)
	{
		cout << '-';
	}

	cout << endl;
}

//To decide whether the information of the activity is valid
bool isValid(const Activity &activity)
{
	if(activity.startTime_h >= 0 && activity.startTime_h <= 23 
		&& activity.startTime_m >= 0 && activity.startTime_m <= 59 
		&& activity.durationMin > 0 
		&& getChangedTime(activity.startTime_h, activity.startTime_m, activity.durationMin)/100 >= 0 && getChangedTime(activity.startTime_h, activity.startTime_m, activity.durationMin)/100 <= 23
		&& getChangedTime(activity.startTime_h, activity.startTime_m, activity.durationMin)%100 >=0 && getChangedTime(activity.startTime_h, activity.startTime_m, activity.durationMin)%100 <= 59)
	{
		return true;
	}

	return false;
}

//Extend the duration of activities
void extendDuration(Activity activities[], int n, int addedTime, int number)
{
	int h = activities[number-1].startTime_h;//the start hour
	int m = activities[number-1].startTime_m;//the start minute
	int dur = activities[number-1].durationMin;//the duration
	int new_time_end = getChangedTime(h, m, dur+addedTime);//the modified time after adding the duration
	int new_h_end = new_time_end/100;//the end hour
	int new_m_end = new_time_end%100;//the end minute

	if(new_h_end > activities[number].startTime_h)
	{
		cout << "Time added is not valid, the figures remain the same" << endl;
		cout << endl;

		return;
	}

	if(new_h_end == activities[number].startTime_h)
	{
		if(new_m_end > activities[number].startTime_m)
		{
			cout << endl;
			cout << "Time added is not valid, the figures remain the same" << endl;
			cout << endl;

			return;
		}
	}

	activities[number-1].durationMin += addedTime;

	cout << "Add successfully!" << endl;
	cout << endl;

	showTheFrame(activities, n);
	displayActivities(activities, n);
}

//Read the information of the activities from a file
void readFileOfActivities(Activity activities[], int &n)
{
	char pathname[NAME_SIZE];//the pathname
	ifstream inFile;//a file object
	n = 0;//initialize the counter

	do
	{
		cout << "Type the pathname of the input file: ";
		cin >> pathname;
		inFile.open(pathname);

		if(inFile.fail())
		{
			cout << "Can not open the file" << endl;
			memset(pathname, 0, NAME_SIZE);
		}
	}
	while(inFile.fail());

	while(!inFile.eof())
	{
		if(!inFile.fail())
		{
			Activity tempActivity;//temporary object

			while(inFile >> tempActivity)
			{
				if(isValid(tempActivity))
				{
					activities[n] = tempActivity;
					n++;
				}
			}
		}
	}
}

//Definition of the comparison operator >
bool operator > (const Activity &activity1, const Activity &activity2)
{
	bool isLarger = false;//temporary variable to show whether activity1 is larger than activity2

	if(activity1.startTime_h > activity2.startTime_h)
	{
		isLarger = true;
	}
	
	if(activity1.startTime_h == activity2.startTime_h)
	{
		if(activity1.startTime_m > activity2.startTime_m)
		{
			isLarger = true;
		}
	}
	
	return isLarger;
}

//Insertion sorting function according to start time
void insertion_sort_D(Activity activities[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int j = i;//temporary variable

		while(j > 0 && activities[j-1].durationMin > activities[j].durationMin)
		{
			Activity tempActivity = activities[j-1];
			activities[j-1] = activities[j];
			activities[j] = tempActivity;
			j--;
		}
	}
}

//Insertion sorting function according to start time
void insertion_sort_L(Activity activities[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int j = i;//temporary variable

		while(j > 0 && strlen(activities[j-1].description) > strlen(activities[j].description))
		{
			Activity tempActivity = activities[j-1];
			activities[j-1] = activities[j];
			activities[j] = tempActivity;
			j--;
		}
	}
}

//Insertion sorting function according to start time
void insertion_sort_S(Activity activities[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int j = i;//temporary variable

		while(j > 0 && activities[j-1] > activities[j])
		{
			Activity tempActivity = activities[j-1];
			activities[j-1] = activities[j];
			activities[j] = tempActivity;
			j--;
		}
	}
}

//Binary search function
bool binary_search(Activity activities[], int n,int search_hh, int search_mm, int &idFound)
{
	int start = 0, end = n-1;//the position of the start and end

	while(start <= end)
	{
		idFound = (start + end)/2;

		if(activities[idFound].startTime_h == search_hh && activities[idFound].startTime_m == search_mm)
		{
			return true;
		}

		if(activities[idFound].startTime_h > search_hh || (activities[idFound].startTime_h == search_hh && activities[idFound].startTime_m > search_mm))
		{
			end = idFound - 1;
		}
		else
		{
			start = idFound + 1;
		}
	}

	return false;
}

//Show whether the activity is found
void isSearched(Activity activities[], int n, int search_hh, int search_mm, int &id_found)
{
	if (binary_search(activities,n,search_hh,search_mm,id_found))
	{	
		cout << endl;
		cout << "Time: " << setfill('0') << setw(2) << activities[id_found].startTime_h << ":" << setw(2) << activities[id_found].startTime_m << " - "
				<< getChangedTime(activities[id_found].startTime_h, activities[id_found].startTime_m, activities[id_found].durationMin)/100 << ":" 
				<< setw(2) << getChangedTime(activities[id_found].startTime_h, activities[id_found].startTime_m, activities[id_found].durationMin)%100 << ", Description: "
				<< activities[id_found].description << ", Duration: (" << activities[id_found].durationMin << " minutes)" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "No activity is found." << endl;
		cout << endl;
	}
}

//Search activity by duration
void searchByDuration(Activity activities[], int n, int time)
{
	bool isFound = false;//to show whether the activity is found

	for(int i = 0; i < n; i++)
	{
		if(time == activities[i].durationMin)
		{
			cout << "Duartion: " << activities[i].durationMin << " minutes, Time: " << setfill('0') << setw(2) << activities[i].startTime_h << ":" << setw(2) << activities[i].startTime_m << " - "
					 << getChangedTime(activities[i].startTime_h, activities[i].startTime_m, activities[i].durationMin)/100 << ":" 
					 << setw(2) << getChangedTime(activities[i].startTime_h, activities[i].startTime_m, activities[i].durationMin)%100 << ", Description: "
					 << activities[i].description << endl;
			cout << endl;

			isFound = true;
		}
	}

	if(!isFound)
	{
		cout << "Not found" << endl;
	}
}

//Search activity by part of the description
void searchByDescription(Activity activities[], int n, char des[])
{
	bool isFound = false;//to show whether the activity is found

	for(int i = 0; i < n; i++)
	{
		if(strstr(activities[i].description, des) != 0)
		{
			cout << "Description: " << activities[i].description << ", Time: " << setfill('0') << setw(2) << activities[i].startTime_h << ":" << setw(2) << activities[i].startTime_m << " - "
					<< getChangedTime(activities[i].startTime_h, activities[i].startTime_m, activities[i].durationMin)/100 << ":" 
					<< setw(2) << getChangedTime(activities[i].startTime_h, activities[i].startTime_m, activities[i].durationMin)%100 << " "
					<< ", Duration: (" << activities[i].durationMin << " minutes)" << endl;
			cout << endl;

			isFound = true;
		}
	}

	if(!isFound)
	{
		cout << "Not found" << endl;
	}
}

//Choose an activity and add its duration
void chooseActivityToExtend(Activity activities[], int n)
{
	int addedTime;//added duration
	int number;//the number of the activity

	cout << "Please input the number of the activity: ";
	cin >> number;

	if(cin.fail())
	{
		cin.clear();
		cin.sync();
	}

	cout << endl;

	if(number > n)
	{
		cout << "Not found" << endl;
		cout << endl;
		return;
	}
	else
	{
		cout << " Activity " << number << endl << " Time: " << setfill('0') << setw(2) << activities[number-1].startTime_h << ":" << setw(2) << activities[number-1].startTime_m << " - "
				<< getChangedTime(activities[number-1].startTime_h, activities[number-1].startTime_m, activities[number-1].durationMin)/100 << ":" 
				<< setw(2) << getChangedTime(activities[number-1].startTime_h, activities[number-1].startTime_m, activities[number-1].durationMin)%100 << endl << " Description: "
				<< activities[number-1].description << endl << " Duration: " << activities[number-1].durationMin << " minutes" << setfill(' ') << endl;
		cout << endl;

		cout << "Please input the time to be increased: ";
		cin >> addedTime;

		if(cin.fail())
		{
			cin.clear();
			cin.sync();
		}
	}
	
	extendDuration(activities, n, addedTime, number);
}

//Checking whether the added activity is conflict with the existed activities
bool isConflict(const Activity &activity, const Activity activities[], int n)
{
	int h = activity.startTime_h;//the start hour of the added activity
	int m = activity.startTime_m;//the start minute of the added activity
	int dur = activity.durationMin;//the duration of the added activity
	int new_time_end = getChangedTime(h, m, dur);//the time after adding the duration
	int new_h_end = new_time_end/100;//the end time of the added activity
	int new_m_end = new_time_end%100;	//the end minute of the added activity
	int h_e = getChangedTime(activities[n-1].startTime_h, activities[n-1].startTime_m, activities[n-1].durationMin)/100;//the end hour of the lateset activity
	int m_e = getChangedTime(activities[n-1].startTime_h, activities[n-1].startTime_m, activities[n-1].durationMin)%100;//the end minute of the lateset activity


	if((new_h_end < activities[0].startTime_h ||((new_h_end == activities[0].startTime_h) && new_m_end < activities[0].startTime_m) )
		|| (h > h_e || ((h == h_e) && m > m_e)))
	{
		return false;
	}

	for(int i = 0; i < n; i++)
	{
		int h_t = getChangedTime(activities[i].startTime_h, activities[i].startTime_m, activities[i].durationMin)/100;//end hour of the activity
		int m_t = getChangedTime(activities[i].startTime_h, activities[i].startTime_m, activities[i].durationMin)%100;//minute of the activity
		
		//case 1
		if(h > activities[i].startTime_h && new_h_end < h_t)
		{
			return true;
		}

		if(h == activities[i].startTime_h && m >= activities[i].startTime_m && new_h_end < h_t)
		{
			return true;
		}

		if(h > activities[i].startTime_h && new_h_end == h_t && new_m_end <= m_t)
		{
			return true;
		}

		if(h == activities[i].startTime_h && m >= activities[i].startTime_m && new_h_end == h_t && new_m_end <= m_t)
		{
			return true;
		}

		//case 2
		if(h < activities[i].startTime_h && new_h_end > activities[i].startTime_h)
		{
			return true;
		}

		if(h == activities[i].startTime_h && m <= activities[i].startTime_m && new_h_end > activities[i].startTime_h)
		{
			return true;
		}

		if(h < activities[i].startTime_h && new_h_end == activities[i].startTime_h && new_m_end >= activities[i].startTime_m)
		{
			return true;
		}

		if(h == activities[i].startTime_h && m <= activities[i].startTime_m && new_h_end == activities[i].startTime_h && new_m_end >= activities[i].startTime_m)
		{
			return true;
		}

		//case 3
		if(h < h_t && new_h_end > h_t)
		{
			return true;
		}

		if(h == h_t && m <= m_t && new_h_end > h_t)
		{
			return true;
		}

		if(h < h_t && new_h_end == h_t && new_m_end >= m_t)
		{
			return true;
		}

		if(h == h_t && m <= m_t && new_h_end == h_t && new_m_end >= m_t)
		{
			return true;
		}
	}

	return false;
}

//Add activities according to the user`s decision
void addActivities(Activity activities[], int &n)
{
	char choice;//choice of user whether to add an activity
	char choiceOfContinue;//choice od user whether to continue adding an activities

	do
	{
		cout << "Do you want to add an activity? [y/n]: ";
		cin >> choice;
	}
	while(choice != 'y' && choice != 'n');

	if(choice == 'y')
	{
		Activity tempActivity;//temporary object
		Activity anotherA[20];//temporary object array

		for(int i = 0; i < n; i++)
		{
			anotherA[i] = activities[i];
		}

		do
		{
			insertion_sort_S(anotherA, n);

			cout << "Please add an activity(Start Time, Duration, Description):" << endl;
			cout << endl;
			cin >> tempActivity;

 			if(isValid(tempActivity))
			{	
				if(!isConflict(tempActivity, anotherA, n))
				{
					activities[n] = tempActivity;
					anotherA[n] = tempActivity;
					n++;

					cout << "Add activities successfully!" << endl;
				}
				else
				{
					cout << "The time is conflict!" << endl;
				}
			}
			else
			{
				cout << "Wrong input!" << endl;
			}

			cout << endl;
			cout << "Add one more activity? [y/n]: ";
			cin >> choiceOfContinue;
		}
		while(choiceOfContinue == 'y');
	}

	cout << endl;
}

//Find the longest duration
void findLongestDuration(const Activity activities[], int n)
{
	int longest = 0;//longest duration

	for(int i = 0; i < n; i++)
	{
		if(activities[i].durationMin > longest)
		{
			longest = activities[i].durationMin;
		}
	}

	cout << "The longest Duration: " << endl;
	cout << " " << longest << " minutes" << endl;
	cout << endl;
	cout << "Activity/Activities: " << endl;

	for(int i = 0; i < n; i++)
	{
		if(activities[i].durationMin == longest)
		{
			cout << " " << activities[i].description << endl;
		}
	}

	cout << endl;
}

//Find the total time of activities
void findTotalTime(const Activity activities[], int n)
{
	int sum = 0;//total time

	for(int i = 0; i < n; i++)
	{
		sum =  sum + activities[i].durationMin;
	}
	
	cout << "Total time of activities: " << endl;
	cout << " ";

	if(sum < 60)
	{
		if(sum > 1)
		{
			cout << sum << " minutes";
		}
		else
		{
			cout << 1 << " minute";
		}
	}
	else if(sum == 60)
	{
		cout << 1 << " hour";
	}
	else
	{
		cout << sum/60;

		if(sum/60 > 1)
		{
			cout << " hours ";
		}
		else
		{
			cout << " hour ";
		}
		if(sum%60 > 1)
		{
			cout << sum%60 << " minutes";
		}
		else
		{
			cout << sum%60 << " minute";
		}

		cout << endl << endl;
	}
}