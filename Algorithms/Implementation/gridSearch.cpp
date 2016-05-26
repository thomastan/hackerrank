// http://hackerrank.com/challenges/the-grid-search
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPresent(vector<string> G, vector<string> P) {
	const unsigned int R = G.size(), C = G[0].length();
	const unsigned int r = P.size(), c = P[0].length();  // subgrid

	// search for upper-left element of P within a upper-left subgrid of G
	for (int i = 0; i < R; i++)
		for (int j = 0; j <= C - c; j++) {
			int z = 0;  // row within P
			if (G[i].substr(j, c) == P[z])
				for (z = 1; z < r && i + z < R; z++) {
					if (G[i + z].substr(j, c) != P[z])
						break;
					if (z == r - 1)
						return true;
				}
		}

	return false;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int R, C;
		cin >> R >> C;

		vector<string> G(R);
		for (int i = 0; i < R; i++)
			cin >> G[i];

		int r, c;
		cin >> r >> c;

		vector<string> P(r);
		for (int i = 0; i < r; i++)
			cin >> P[i];

		cout << (isPresent(G, P) ? "YES" : "NO") << endl;
	}
}
