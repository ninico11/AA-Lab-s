#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void heapify(int arr[], int N, int i)
{

	int largest = i;

	int l = 2 * i + 1;

	int r = 2 * i + 2;

	if (l < N && arr[l] > arr[largest])
		largest = l;

	if (r < N && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, N, largest);
	}
}

void heapSort(int arr[], int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	for (int i = N - 1; i > 0; i--) {

		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

int getArray(int numbers[]) {
    int count = 0;

    ifstream file("Array.txt");
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 0;
    }

    string line;
    getline(file, line);

    stringstream ss(line);
    string number;
    while (getline(ss, number, ',')) {
        stringstream numstream(number);
        int n;
        numstream >> n;
        numbers[count++] = n;
    }

    file.close();

    return count;
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{	
	clock_t begin, end;
	int arr[100000];
	int N = sizeof(arr) / sizeof(arr[0]);
	int count = getArray(arr);
	begin = clock();
	heapSort(arr, N);
	end = clock();
	cout << "Sorted array: \n";
	printArray(arr, N);
	double time_taken = double(end - begin) / double(CLOCKS_PER_SEC);
	cout << setprecision(6) << time_taken << "sec" << "\n";
	return 0;
}

