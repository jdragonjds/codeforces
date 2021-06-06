#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

double C2(ll x) {
	return (x * (x - 1)) / 2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	double p[n][n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> p[i][j];
		}
	}

	double dp[1 << n];
	for (int i = 0; i < (1 << n); ++i) {
		dp[i] = 0;
	}
	dp[(1 << n) - 1] = 1.;

	for (int mask = (1 << n) - 1; mask >= 0; --mask) {
		int set_bits = __builtin_popcount(mask);
		if (set_bits == 1) continue;
		for (int b = 0; b < n; ++b) {
			double val = 0.;
			for (int c = 0; c < n; ++c) {
				if (((1 << b) & mask) && ((1 << c) & mask) && c != b) {
					val += (dp[mask] * p[c][b]) / C2(set_bits);
				}
			}
			dp[(mask ^ (1 << b))] += val;
		}
	}

	cout.precision(10);
	cout << fixed;
	for (int i = 0; i < n; ++i) {
		cout << dp[1 << i] << " ";
	}
	cout << "\n";


	return 0;
}
