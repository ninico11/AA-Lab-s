#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    bool DFS(int v, int dest, vector<int>& path)
    {
        visited[v] = true;
        path.push_back(v);

        if (v == dest) {
            return true;
        }

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i] && DFS(*i, dest, path))
                return true;
                
        path.pop_back();

        return false;
    }
    
    vector<int> findPathDFS(int src, int dest)
    {
        vector<int> path;
        DFS(src, dest, path);
        return path;
    }
};

Graph BalancedGraph(){
	Graph g;
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
	Graph g;
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
    		vector<int> path = g1.findPathDFS(src, i);
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
    		vector<int> path = g2.findPathDFS(src, i);
    	}
		end = clock();
    	float time_taken = float(end - begin) / float(CLOCKS_PER_SEC);
		cout << "\n";	
	    cout << n-1 << " " << time_taken << " sec" << "\n";
		n++;
	}
    return 0;
}

