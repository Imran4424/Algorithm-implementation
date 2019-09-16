/*
	Given an array of jobs where every job has a deadline and associated profit 
	if the job is finished before the deadline. It is also given that every job 
	takes single unit of time, so the minimum possible deadline for any job is 1. 
	How to maximize total profit if only one job can be scheduled at a time.

	Examples:

	Input: Four Jobs with following 
	deadlines and profits
	JobID  Deadline  Profit
	  a      4        20   
	  b      1        10
	  c      1        40  
	  d      1        30

	Output: Following is maximum profit sequence of jobs
	        c, a   


	Input:  Five Jobs with following
	deadlines and profits
	JobID   Deadline  Profit
	  a       2        100
	  b       1        19
	  c       2        27
	  d       1        25
	  e       3        15

	Output: Following is maximum profit sequence of jobs
	        c, a, e

*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair <int, char> couple;
typedef pair <int, couple> nestedCouple;

vector <couple> MaximumProfit(vector <nestedCouple> givenJobs, int maxDeadline)
{
	// making the job sorted according to higher profit
	sort(givenJobs.rbegin(), givenJobs.rend());

	int currentDeadline = 1;

	vector <couple> jobList;

	for (int i = 0; i < givenJobs.size(); ++i)
	{
		if (currentDeadline > maxDeadline)
		{
			break;
		}

		if (currentDeadline <= givenJobs[i].second.first)
		{
			jobList.push_back(givenJobs[i].second);

			currentDeadline++;
		}
	}

	// making the job list sorted according to the deadline
	sort(jobList.begin(), jobList.end());

	return jobList;
}

int main(int argc, char const *argv[])
{
	cout << "how many jobs" << endl;
	int jobs;
	cin >> jobs;

	char jobId;
	int deadLine, profit;

	vector <nestedCouple> givenJobs;

	int maxDeadline;

	cout << "enter the jobId, deadline and profit" << endl;

	for (int i = 0; i < jobs; ++i)
	{
		cin >> jobId >> deadLine >> profit;

		givenJobs.push_back(make_pair(profit, make_pair(deadLine, jobId)));

		if (0 == i)
		{
			maxDeadline = deadLine;
		}
		
		if(maxDeadline < deadLine)
		{
			maxDeadline = deadLine;
		}
	}

	vector <couple> jobList = MaximumProfit(givenJobs, maxDeadline);

	for (int i = 0; i < jobList.size(); ++i)
	{
		cout << jobList[i].second << " ";
	}

	cout << endl;

	return 0;
}