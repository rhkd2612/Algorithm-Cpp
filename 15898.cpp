#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;

vector<int> v;
map<int, pair<int, int>> m;
map<char, int> rgb;

int power[10][4][4];
char color[10][4][4];

int tPower[2][4][4];
char tColor[2][4][4];

int pBoard[5][5];
char cBoard[5][5];

bool use[10];

int result;

void rotate(int idx, int deg) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tPower[0][i][j] = power[idx][i][j];
			tColor[0][i][j] = color[idx][i][j];
		}
	}

	bool cur = false;

	while (deg--) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				tPower[!cur][i][j] = tPower[cur][3 - j][i];
				tColor[!cur][i][j] = tColor[cur][3 - j][i];
			}
		}

		cur = !cur;
	}
}

void solve() {
	for (int k = 0; k < 3; k++) {
		int value = v[k];
		int idx = value % 10; value /= 10;
		int deg = value % 10; value /= 10;
		pair<int,int> sPos = m[value];
		
		deg -= 1;

		rotate(idx, deg);
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int y = i + sPos.first;
				int x = j + sPos.second;

				pBoard[y][x] += tPower[deg%2][i][j];

				if (pBoard[y][x] < 0)
					pBoard[y][x] = 0;
				else if (pBoard[y][x] > 9)
					pBoard[y][x] = 9;
				
				if (tColor[deg % 2][i][j] != 'W')
					cBoard[y][x] = tColor[deg % 2][i][j];
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if(cBoard[i][j] != 'W')
				rgb[cBoard[i][j]] += pBoard[i][j];

			pBoard[i][j] = 0;
			cBoard[i][j] = 'W';
		}
	}

	result = max(result, 7 * rgb['R'] + 5 * rgb['B'] + 3 * rgb['G'] + 2 * rgb['Y']);

	rgb['R'] = 0; rgb['B'] = 0;
	rgb['G'] = 0; rgb['Y'] = 0;
}

void com(int amount) {
	if (amount == 3) {
		solve();
		return;
	}

	for (int k = 0; k < n; k++) {
		if (!use[k]) {
			use[k] = true;
			for (int i = 1; i <= 4; i++) {
				for (int j = 1; j <= 4; j++) {
					int num = i * 100 + j * 10 + k;
					v.push_back(num);
					com(amount + 1);
					v.pop_back();
				}
			}
			use[k] = false;
		}
	}
}

void init() {
	cin >> n;

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> power[k][i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> color[k][i][j];
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			pBoard[i][j] = 0;
			cBoard[i][j] = 'W';
		}
	}

	m[1] = { 0,0 }; m[2] = { 0,1 };
	m[3] = { 1,0 }; m[4] = { 1,1 };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	com(0);

	cout << result << '\n';

	return 0;
}