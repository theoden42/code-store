

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void printTreeEdges(vector<int> prufer, int m)
{
	int vertices = m + 2;
	vector<int> vertex_set(vertices);

	// Initialize the array of vertices
	for (int i = 0; i < vertices; i++)
		vertex_set[i] = 0;

	// Number of occurrences of vertex in code
	for (int i = 0; i < vertices - 2; i++)
		vertex_set[prufer[i] - 1] += 1;

	// cout<<("\nThe edge set E(G) is:\n");

	int j = 0;

	// Find the smallest label not present in
	// prufer[].
	for (int i = 0; i < vertices - 2; i++)
	{
		for (j = 0; j < vertices; j++)
		{

			// If j+1 is not present in prufer set
			if (vertex_set[j] == 0)
			{

				// Remove from Prufer set and print
				// pair.
				vertex_set[j] = -1;
				cout<<"(" << (j + 1) << ", "
								<< prufer[i] << ") ";

				vertex_set[prufer[i] - 1]--;

				break;
			}
		}
	}

	j = 0;

	// For the last element
	for (int i = 0; i < vertices; i++)
	{
		if (vertex_set[i] == 0 && j == 0)
		{

			cout << "(" << (i + 1) << ", ";
			j++;
		}
		else if (vertex_set[i] == 0 && j == 1)
			cout << (i + 1) << ")\n";
	}
}

// generate random numbers in between l an r
int ran(int l, int r)
{
	return l + (rand() % (r - l + 1));
}

// Function to Generate Random Tree
void generateRandomTree(int n)
{

	int length = n - 2;
	vector<int> arr(length);

	// Loop to Generate Random Array
	for (int i = 0; i < length; i++)
	{
		arr[i] = ran(0, length + 1) + 1;
	}
	printTreeEdges(arr, length);
}

// Driver Code
int main()
{
	srand(time(0));
	int n = 5;
	generateRandomTree(n);

	return 0;
}


void solve() {
    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}