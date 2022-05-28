#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define PMAX 50005

// save result
vector<int> res;

// input sentence s, pattern p
string s, p;
// size of string s & p
int n, m;
// pattern failure function
int pi[PMAX];

void init() {
	cin >> s;
	cin >> p;
	n = s.length();
	m = p.length();
}

// get failure function
void getPI() {
	int i, j = 0;
	pi[0] = 0;

	for (i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}

// get KMP
void kmp() {
	int j = 0;
	for (int i = 0; i < n;) {
		if (s[i] == p[j]) {
			if (j == m - 1) {
				// save result
				res.push_back(i - j);

				// if size of pattern is 1
				if (j == 0) {
					cout << "1 ";
					i++;
				}
				else {

					if (s[i] == p[pi[j - 1]])
						cout << j - pi[j - 1] << ' ';
					else {
						cout << j - pi[j - 1] + 1 << ' ';
						i++;
					}
					j = pi[j - 1];
				}
			}
			else {
				i++;
				j++;
			}
		}
		else {
			// if size of pattern is 1
			if (j == 0) {
				i++;
				cout << "1 ";
			}
			else {
				cout << j - pi[j - 1] << ' ';
				j = pi[j - 1];
			}
		}
	}

	cout << '\n';
}

void print() {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	getPI();
	kmp();
	print();
	return 0;
}