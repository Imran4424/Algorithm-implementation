// C++ program to implement recursive Binary Search 
#include <iostream> 
using namespace std; 

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int BinarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 

		// If the element is present at the middle 
		// itself 
		if (arr[mid] == x) 
			return mid; 

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x); 
	} 

	// We reach here when element is not 
	// present in array 
	return -1; 
} 

int main(int argc, char const *argv[])
{
	cout << "enter the size of the array" << endl;

	int n;
	cin >> n;

	vector <int> numbers(n);

	srand(time(0)); // for managing session

	for (int i = 0; i < numbers.size(); ++i)
	{
		int temp = rand() % 100;

		

		numbers[i] = temp + 1;

		cout << numbers[i] << " ";
	}

	cout << endl << endl;

	cout << "enter your target" << endl;

	int target;

	while(cin >> target)
	{
		int position = BinarySearch(numbers, 0, numbers.size()-1, target);

		if (position == -1)
		{
			cout << "target does not exist in the array" << endl << endl;
		}
		else
		{
			cout << "found in position: " << position << endl << endl	;
		}
		
		cout << "enter your target" << endl;
	}


	return 0;
}