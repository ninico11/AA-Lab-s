#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
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
	bubbleSort(arr, N);
	end = clock();
	cout << "Sorted array: \n";
	printArray(arr, N);
	double time_taken = double(end - begin) / double(CLOCKS_PER_SEC);
	cout << setprecision(6) << time_taken << "sec" << "\n";
	return 0;
}

