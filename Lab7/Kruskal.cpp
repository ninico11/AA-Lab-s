#include <bits/stdc++.h>
#include <vector>
#include <iomanip>
#include <climits>
#include <algorithm>

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
struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int v) {
        if (v != parent[v])
            parent[v] = find(parent[v]);
        return parent[v];
    }
    
    void unionSet(int v1, int v2) {
        int root1 = find(v1);
        int root2 = find(v2);
        
        if (rank[root1] < rank[root2])
            parent[root1] = root2;
        else if (rank[root1] > rank[root2])
            parent[root2] = root1;
        else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

void kruskalMST(vector<vector<int> >& graph) {
    int V = graph.size();
    vector<Edge> edges;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                Edge e;
                e.src = i;
                e.dest = j;
                e.weight = graph[i][j];
                edges.push_back(e);
            }
        }
    }

    sort(edges.begin(), edges.end(), compareEdges);
    
    DisjointSet ds(V);
    vector<Edge> mst;

    for (const Edge& e : edges) {
        int srcParent = ds.find(e.src);
        int destParent = ds.find(e.dest);
        
        if (srcParent != destParent) {
            mst.push_back(e);
            ds.unionSet(srcParent, destParent);
        }
    }
    
    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& e : mst) {
        cout << e.src << " -- " << e.dest << " \tWeight: " << e.weight << endl;
    }
}

int main() {
	clock_t begin, end;
    int numNodes;
    cout << "Enter number of nodes: ";
    cin >> numNodes;

    vector<vector<int> > graph = generateGraph(numNodes);
    begin = clock();
    kruskalMST(graph);
    end = clock();
	float time_taken = float(end - begin) / float(CLOCKS_PER_SEC);
    cout << "The time to find minimum spaning tree: " << time_taken << " sec" << "\n";
    return 0;
}
