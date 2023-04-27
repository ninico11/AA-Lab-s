
#include <bits/stdc++.h>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

vector<vector<int> > generateDenseGraph(int numNodes) {
    vector<vector<int> > adjacencyMatrix(numNodes, vector<int>(numNodes, 0));
    for(int i = 0; i < numNodes; i++){
        int j = 0;
        while(j < numNodes){
            if(i != j){
                adjacencyMatrix[i][j] = rand() % 10 + 1;
            }
            else{
                adjacencyMatrix[i][j] = 0;
            }
            j++;
        }
    }
    return adjacencyMatrix;
}

vector<vector<int> > generateSparseGraph(int numNodes) {
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

int minDistance(int dist[], bool visited[], int vertices)
{
    int minDist = INT_MAX, minIndex = -1;
    for (int v = 0; v < vertices; v++)
    {
        if (visited[v] == false && dist[v] <= minDist)
        {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(vector<vector<int> > graph, int startVertex, int vertices)
{
    int dist[vertices];
    bool visited[vertices];

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minDistance(dist, visited, vertices);
        visited[u] = true;

        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distances from vertex " << startVertex+1 << " to all other vertices:\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << i+1 << ": " << dist[i] << "\n";
    }
}

void floydWarshall(vector<vector<int> > graph, int n) {
    vector<vector<int> > dist = graph;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] != 0){
                continue;
            }
            else{
                dist[i][j] = INT_MAX;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < 10000 && dist[k][j] < 10000)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j){
                dist[i][j] = INT_MAX;
            }
            else{
                continue;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] > 10000) {
                cout << "INF ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout<< endl;
    
}

int main()
{
    clock_t begin1, end1, begin2, end2, begin3, end3, begin4, end4;
	int numNodes;
    cout << "Enter number of nodes: ";
    cin >> numNodes;

    vector<vector<int> > graph1 = generateSparseGraph(numNodes);
	vector<vector<int> > graph2 = generateDenseGraph(numNodes);
    cout << "Adjacency Matrix for Sparse Graph:\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << graph1[i][j] << ", ";
        }
        cout << "\n";
    }
    cout<< "\n";
    cout << "Adjacency Matrix for Dense Graph:\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << graph2[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "----------------------------------------------\n";
    cout << "Paths for Sparse Graph(Dijkstra):\n";
    cout << "----------------------------------------------\n";
    begin1 = clock();
    for(int i = 0; i < numNodes; i++){
        dijkstra(graph1, i, numNodes);
    }
    end1 = clock();
    float time_taken1 = float(end1 - begin1) / float(CLOCKS_PER_SEC);
    cout << "----------------------------------------------\n";
    cout << "Paths for Dense Graph(Dijkstra):\n";
    cout << "----------------------------------------------\n";
    begin2 = clock();
    for(int i = 0; i < numNodes; i++){
        dijkstra(graph2, i, numNodes);
    }
    end2 = clock();
    float time_taken2 = float(end2 - begin2) / float(CLOCKS_PER_SEC);
    cout << "----------------------------------------------\n";
    cout << "Paths for Sparse Graph(FloydWarsall):\n";
    cout << "----------------------------------------------\n";
    begin3 = clock();
    
    floydWarshall(graph1, numNodes);
    
    end3 = clock();
    float time_taken3 = float(end3 - begin3) / float(CLOCKS_PER_SEC);
    cout << "----------------------------------------------\n";
    cout << "Paths for Dense Graph(FloydWarsall):\n";
    cout << "----------------------------------------------\n";
    begin4 = clock();
    
    floydWarshall(graph2, numNodes);;
    
    end4 = clock();
    float time_taken4 = float(end4 - begin4) / float(CLOCKS_PER_SEC);
    cout << "----------------------------------------------\n";
    cout << "The time to find all the shortest paths for all the nodes in the sparse graph(Dijkstra): " << time_taken1 << " sec" << "\n";
    cout << "The time to find all the shortest paths for all the nodes in the dense graph(Dijkstra): " << time_taken2 << " sec" << "\n";
    cout << "The time to find all the shortest paths for all the nodes in the sparse graph(FloydWarshall): " << time_taken3 << " sec" << "\n";
    cout << "The time to find all the shortest paths for all the nodes in the dense graph(FloydWarshall): " << time_taken4 << " sec" << "\n";
    return 0;
}
