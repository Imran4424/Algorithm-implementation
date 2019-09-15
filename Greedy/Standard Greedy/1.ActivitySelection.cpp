/*
	https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

	You are given n activities with their start and finish times. Select 
	the maximum worksber of activities that can be performed by a single person, 
	assuming that a person can only work on a single activity at a time.

	Example 1 : Consider the following 3 activities sorted by 
	by finish time.

	     start[]  =  {10, 12, 20};
	     finish[] =  {20, 25, 30};

	A person can perform at most two activities. The 
	maximum set of activities that can be executed 
	is {0, 2} [ These are indexes in start[] and 
	finish[] ]

	Example 2 : Consider the following 6 activities sorted by
	finish time.

	     start[]  =  {1, 3, 0, 5, 8, 5};
	     finish[] =  {2, 4, 6, 7, 9, 9};

	A person can perform at most four activities. The 
	maximum set of activities that can be executed 
	is {0, 1, 3, 4} [ These are indexes in start[] and 
	finish[] ]
*/

/*
	this is better version of all 

	so far I hope	
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair <int, int> couple;

int MaximumWorksDone(vector <int> startTime, vector <int> finishTime)
{
	int leastStartTime = startTime[0];

	int workDoneCount = 0;

	for (int i = 0; i < startTime.size(); ++i)
	{
		if (startTime[i] < leastStartTime)
		{
			continue;
		}

		workDoneCount++;

		leastStartTime = finishTime[i];
	}

	return workDoneCount;
}

int main(int argc, char const *argv[])
{
	cout << "how many works" << endl;

	int works;
	cin >> works;

	cout << "enter the work's start and finish time " << endl;

	vector <couple> input;

	int startInput, finishInput;

	for (int i = 0; i < works; ++i)
	{
		cin >> startInput >> finishInput;

		input.push_back(make_pair(finishInput, startInput));
	}

	sort(input.begin(), input.end());

	vector <int> startTime(works);
	vector <int> finishTime(works);

	for (int i = 0; i < works; ++i)
	{
		startTime[i] = input[i].second;
		finishTime[i] = input[i].first;
	}

	cout << "maximum work done by one person: " << MaximumWorksDone(startTime, finishTime) << endl;

	return 0;
}