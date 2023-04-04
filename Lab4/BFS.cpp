#include <bits/stdc++.h>
#include <iomanip>
#include <initializer_list>
using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    vector<int> findPathBFS(int start, int target)
    {
        vector<bool> visited;
        vector<int> parent;
        visited.resize(V, false);
        parent.resize(V, -1);

        list<int> queue;

        visited[start] = true;
        queue.push_back(start);

        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop_front();

            for (auto adjacent : adj[curr]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    parent[adjacent] = curr;
                    queue.push_back(adjacent);

                    if (adjacent == target) {
                        // Build the path
                        vector<int> path;
                        int node = adjacent;
                        while (node != -1) {
                            path.push_back(node);
                            node = parent[node];
                        }
                        reverse(path.begin(), path.end());
                        return path;
                    }
                }
            }
        }
        return vector<int>();
    }
};


Graph BalancedGraph(){
	Graph g(8);
	g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 6);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    
    return g;
	
}
Graph UnbalancedGraph(){
	Graph g(17);
	g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 6);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
	g.addEdge(4, 11);
	g.addEdge(11, 15);
	g.addEdge(5, 16);
	g.addEdge(6, 12);
	g.addEdge(12, 13);
	g.addEdge(13, 14);
	g.addEdge(14, 17);
	g.addEdge(8, 9);
	g.addEdge(9, 10);
	
	return g;
}

int main()
{
	clock_t begin, end;
    int n = 2;

    while(n<=8){
    	Graph g1 = BalancedGraph();
    	int src = 1;
    	begin = clock();
    	for(int i = 2; i<=n; i++){
    		vector<int> path = g1.findPathBFS(src, i);
    	}
		end = clock();
    	double time_taken = double(end - begin) / double(CLOCKS_PER_SEC);
		cout << "\n";	
	    cout << n-1 << " " << time_taken << " sec" << "\n";
		n++;
	}
	cout << "-------------------------------\n";
	n = 2;
	while(n<=14){
    	Graph g2 = UnbalancedGraph();
    	int src = 1;
    	begin = clock();
    	for(int i = 2; i<=n; i++){
    		vector<int> path = g2.findPathBFS(src, i);
    	}
		end = clock();
    	float time_taken = float(end - begin) / float(CLOCKS_PER_SEC);
		cout << "\n";	
	    cout << n-1 << " " << time_taken << " sec" << "\n";
		n++;
	}
    return 0;
}

