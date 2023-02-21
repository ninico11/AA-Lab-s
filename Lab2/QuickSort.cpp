#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low- 1); 

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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



void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{	
	clock_t begin, end;
	int arr[100000];
	int N = sizeof(arr) / sizeof(arr[0]);
	int count = getArray(arr);
	begin = clock();
	quickSort(arr, 0, N-1);
	end = clock();
	cout << "Sorted array: \n";
	printArray(arr, N);
	double time_taken = double(end - begin) / double(CLOCKS_PER_SEC);
	cout << setprecision(6) << time_taken << "sec" << "\n";
	return 0;
}

