/*
	Problem statement
	Given a sorted array of N distinct elements. Find a key in the array using least number of comparisons. 


*/


int binarySearch(int arr[], int low, int high, int target) {
	int mid;

	while(high - low > 1) {
		mid = low + (high - low) / 2;
		
		if(arr[mid] <= target) {
			low = mid;
		} else {
			high = mid;
		}

		if (arr[low] == target) {
			return low;
		}

		if(arr[high] == target) {
			return high;
		}
	}

	return -1;
}