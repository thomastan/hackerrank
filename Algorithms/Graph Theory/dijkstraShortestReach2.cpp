// http://hackerrank.com/challenges/dijkstrashortreach
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define infinity numeric_limits<double>::max()

struct edge {
	int dest;
	double weight;  // double type has infty: numeric_limits<double>::infinity()
};

class Graph {
	int V;
	vector<edge> *adj;  // (->j,k) weighted links (edges) from node's index by i

  public:
	Graph(int V);
	void addEdge(int i, int j, unsigned k);
	double *dijkstra(int s);  // for unweighted links: int *BFS(int s);

	~Graph();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new vector<edge>[V + 1];  // node indexing is from 1..N
}

void Graph::addEdge(int i, int j, unsigned k) {
	edge e = {j, (double) k};
	adj[i].push_back(e);
}

bool compare(const edge &a, const edge &b) {
	return a.weight > b.weight;
}

double *Graph::dijkstra(int s) {
	double *distance = new double[V + 1];  // stores the min distance answers
	edge queue[V + 1];  // implements the min heap-based priority queue of edges
	// C++ does not support mutable queue - we use an array with heap functions

	for (int i = 0; i <= V; i++) {
		queue[i].dest = i, queue[i].weight = infinity;
		distance[i] = infinity;
	}

	unsigned n = V + 1;  // number of elements in the queue
	queue[s].weight = distance[s] = 0;
	make_heap(queue, queue + n, compare);  // [q, q+n) is now a min heap

	for (int i = 0; i < V; i++) {			  // we will leave node 0 in queue
		pop_heap(queue, queue + n, compare);  // mov min element to back q+ n-1

		int u = queue[n - 1].dest;  // the min heap became [q, q+ n), u was at n
		n--;

		vector<edge>::iterator it;
		// iterate over the edges that are connected to u
		for (it = adj[u].begin(); it != adj[u].end(); it++) {
			int v = it->dest;

			if (distance[u] == infinity)
				continue;

			// calc distance through u to v, update dist[v] if this is shorter
			double distanceThroughU = distance[u] + it->weight;
			if (distanceThroughU < distance[v]) {
				distance[v] = distanceThroughU;

				// update the distances in the min heap priority queue (vector)
				for (unsigned j = 0; j <= V; j++)
					if (queue[j].dest == v) {
						queue[j].weight = distanceThroughU;
						break;
					}
			}
		}

		make_heap(queue, queue + n, compare);
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
			unsigned u, v, k;
			cin >> u >> v >> k;

			if (u != v)
				g.addEdge(u, v, k), g.addEdge(v, u, k);  // graph is undirected
		}

		cin >> s;
		double *distanceList = g.dijkstra(s);

		for (int k = 1; k <= N; k++) {
			if (k == s)
				continue;
			cout << (distanceList[k] == infinity ? -1 : distanceList[k]);
			cout << (k == N ? '\n' : ' ');
		}

		delete[] distanceList;
	}

	return 0;
}
