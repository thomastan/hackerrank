// http://hackerrank.com/challenges/bfsshortreach
#include <iostream>
#include <set>
#include <queue>
using namespace std;

// struct edge {
// 	int dest;
// 	unsigned length;
//
// };

class Graph {
	int V;
	set<int> *adj;  // (->j) unweighted links (edges) from node's index by i

  public:
	Graph(int V);
	void addEdge(int i, int j);
	int *BFS(int s);

	~Graph();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new set<int>[V + 1];  // node indexing is from 1..N
}

void Graph::addEdge(int i, int j) {
	adj[i].insert(j);
	adj[j].insert(i);
}

int *Graph::BFS(int s) {
	bool *visited = new bool[V + 1];
	int *distance = new int[V + 1];

	for (int i = 0; i <= V; i++) {
		visited[i] = false;
		distance[i] = -1;
	}

	deque<int> queue;  // queue of the nodes to visit in the BFS

	distance[s] = 0;  // visit and enqueue node
	queue.push_back(s);

	while (!queue.empty()) {
		// dequeue node and iterate over its adjacent nodes
		s = queue.front();
		queue.pop_front();

		set<int>::iterator it;  // iterate over the adjacent nodes of s
		for (it = adj[s].begin(); it != adj[s].end(); it++)
			if (!visited[*it]) {
				visited[*it] = true;
				distance[*it] = distance[s] + 1;
				queue.push_back(*it);
			}
	}

	return distance;
}

Graph::~Graph() {
	delete[] adj;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, s;
		long M;
		cin >> N >> M;

		Graph g(N);
		for (long j = 0; j < M; j++) {
			unsigned u, v;
			cin >> u >> v;

			if (u != v)
				g.addEdge(u, v);  // graph is undirected
		}

		cin >> s;
		int *distanceList = g.BFS(s);

		for (int k = 1; k <= N; k++) {
			if (k == s)
				continue;
			cout << (distanceList[k] >= 0 ? distanceList[k] * 6 : -1);
			cout << (k == N ? '\n' : ' ');
		}

		delete[] distanceList;
	}

	return 0;
}
