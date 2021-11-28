#include <iostream>
using namespace std;

int arr[2000]; // main array size, n
int tree[4002]; // segment tree minimum size, 2 * n

void buildTree(int node, int startP, int endP) {
	if (startP == endP) {
		tree[node] = arr[startP];
		return;
	}

	int mid = (startP + endP) / 2;
	buildTree(node * 2, startP, mid);
	buildTree(node * 2 + 1, mid + 1, endP);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void updateSingleElement(int node, int startP, int endP, int index, int val) {
	if (startP == endP) {
		if (startP == index) {
			tree[node] = val;
		}

		return;
	}

	int mid = (startP + endP) / 2;

	if (index <= mid) {
		updateSingleElement(node * 2, startP, mid, index, val);
	} else {
		updateSingleElement(node * 2 + 1, mid + 1, endP, index, val);
	}

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int getIndexSum(int node, int startP, int endP, int sum) {
	if (startP == endP) {
		if (sum <= tree[node]) {
			return startP;
		}

		return -1;
	}

	int mid = (startP + endP) / 2;

	if (sum <= tree[node * 2]) {
		return getIndexSum(node * 2, startP, mid, sum);
	}

	return getIndexSum(node * 2 + 1, mid + 1, endP, sum - tree[node * 2]);
}

void display() {
	cout << "Choose option" << endl;
	cout << "1. update single element" << endl;
	cout << "2. get index for sum" << endl;
	cout << "-1. Terminate" << endl;
}

int main(int argc, char const *argv[])
{
	cout << "enter the array size" << endl;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	buildTree(1, 0, n - 1);

	bool running = true;
	int command;

	while(running) {
		display();
		cin >> command;
		if (-1 == command) {
			running = false;
			continue;
		}

		if (1 == command) {
			int index;
			int value;

			cout << "input index and value" << endl;
			cin >> index >> value;

			while(index >= n && index < 0) {
				cout << "invalid index" << endl;
				cin >> index >> value;
			}

			updateSingleElement(1, 0, n - 1, index, value);
		} else if (2 == command) {
			cout << "enter sum" << endl;
			int targetSum;
			cin >> targetSum;

			cout << "Required index for sum: " << getIndexSum(1, 0, n - 1, targetSum) << endl; 
		}
	}

	return 0;
}