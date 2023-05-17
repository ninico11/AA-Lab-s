#include <bits/stdc++.h>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

vector<vector<int> > generateGraph(int numNodes) {
    vector<vector<int> > adjacencyMatrix(numNodes, vector<int>(numNodes, 0));
    for(int i = 0; i < numNodes; i++){
        int x = 0;
        while(x < 4){
            int j = rand() % numNodes;
            if(j != i){
                adjacencyMatrix[i][j] = rand() % 10 + 1;
                adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
            }
            else if(j == i and j + 1 < numNodes and j - 1 > 0){
                adjacencyMatrix[i][j+1] = rand() % 10 + 1;
                adjacencyMatrix[j+1][i] = adjacencyMatrix[i][j+1];
            }
            x++;
        }
    }
    return adjacencyMatrix;
}

int minKey(int key[], bool mstSet[], int n)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}
void printMST(int parent[], vector<vector<int> > graph, int n)
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < n; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

void primMST(vector<vector<int> > graph, int n)
{
	int parent[n];
	int key[n];
	bool mstSet[n];
	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < n - 1; count++) {
		int u = minKey(key, mstSet, n);
		mstSet[u] = true;
		for (int v = 0; v < n; v++)
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph, n);
}
int main()
{
    clock_t begin, end;
    int numNodes;
    cout << "Enter number of nodes: ";
    cin >> numNodes;

    vector<vector<int> > graph = generateGraph(numNodes);
    begin = clock();
	primMST(graph, numNodes);
    end = clock();
    float time_taken = float(end - begin) / float(CLOCKS_PER_SEC);
	cout << "The time to find minimum spaning tree: " << time_taken << " sec" << "\n";
	return 0;
}


