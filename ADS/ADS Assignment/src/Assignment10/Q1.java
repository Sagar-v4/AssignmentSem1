package Assignment10;

public class Q1 {
}

/*


#include<iostream>
#include <list>
#include <map>

using namespace std;

class Graph {
public:
	map<int, bool> visited{};
	map<int, list<int> > adj{};

	void addEdge(int v, int w);

	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

int main()
{
	Graph g;
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(3, 7);
	g.addEdge(4, 8);
	g.addEdge(5, 9);
	g.addEdge(7, 10);
	g.addEdge(7, 11);
	g.addEdge(8, 12);

	g.DFS(1);

	return 0;
}


 */