#include <iostream>
using namespace std;
const int CSTRING_SIZE = 26;

class Activity
{
public:
	Activity();//default constructor of the activity

	friend void readFileOfActivities(Activity activities[], int &n);
	friend void findTotalTime(const Activity activities[], int n);
	friend void findLongestDuration(const Activity activities[], int n);
	friend void addActivities(Activity activities[], int &n);
	friend void displayOneActivity(const Activity activities[]);
	friend void showTheFrame(const Activity activities[], int n);
	friend void displayActivities(const Activity activities[], int n);
	friend void chooseActivityToExtend(Activity activities[], int n);
	friend void extendDuration(Activity activities[], int n, int addedTime, int number);
	friend void insertion_sort_S(Activity activities[], int n);
	friend void insertion_sort_D(Activity activities[], int n);
	friend void insertion_sort_L(Activity activities[], int n);
	friend void showTheDuration(const Activity activities[], int n, int order);
	friend void searchByDuration(Activity activities[], int n, int time);
	friend void searchByDescription(Activity activities[], int n, char des[]);
	friend void isSearched(Activity activities[], int n, int search_hh, int search_mm, int &id_found);

	friend int findTheLongestWord(const Activity activities[], int n);

	friend bool isConflict(const Activity &activity, const Activity activities[], int n);
	friend bool isLarger(const Activity &activity, Activity activities[]);
	friend bool isValid(const Activity &activity);
	friend bool binary_search(Activity activities[], int n,int search_hh, int search_mm, int &idFound);
	friend bool operator > (const Activity &activity1, const Activity &activity2);

	friend ostream &operator << (ostream &outs, const Activity &activity);
	friend istream &operator >> (istream &ins, Activity &activity);
	

private:
	int startTime_h;//member variable for starting hour
	int startTime_m;//member variable for starting minute
	int durationMin;//the duration time in minute
	char description[CSTRING_SIZE];//the description of the activity
};