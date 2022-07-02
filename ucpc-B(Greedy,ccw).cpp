#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

struct knife {
    ll sx;
    ll sy;
    ll ex;
    ll ey;

    knife() {

    }

    knife(int sx, int sy,int ex,int ey) {
        this->sx = sx;
        this->sy = sy;
        this->ex = ex;
        this->ey = ey;
    }
};

struct point {
    ll x;
    ll y;
};

pair<ll, knife> p[2505];

bool operator<(const knife& a, const knife& b) {
    return false;
}

int ccw(point a, point b, point c) {
    ll temp = a.x * b.y + b.x * c.y + c.x * a.y;
    temp -= a.x * c.y + b.x * a.y + c.x * b.y;

    if (temp > 0)
        return 1;
    else if (!temp)
        return 0;
    else
        return -1;
}

bool isOverlapped(knife a, knife b) {
    int ans1 = ccw({ a.sx, a.sy }, { a.ex,a.ey }, { b.sx,b.sy }) * ccw({ a.sx, a.sy }, { a.ex,a.ey }, { b.ex,b.ey });;
    int ans2 = ccw({ b.sx, b.sy }, { b.ex,b.ey }, { a.sx,a.sy }) * ccw({ b.sx, b.sy }, { b.ex,b.ey }, { a.ex,a.ey });

    return (ans1 < 0) && (ans2 < 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int sx, sy, ex, ey, w;

        cin >> sx >> sy >> ex >> ey >> w;
        p[i] = make_pair(w, knife(sx,sy,ex,ey));
    }

    sort(p, p + n);

    ll result = 0;

    for (int i = 0; i < n; i++) {
        result += p[i].first;
        ll cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (isOverlapped(p[i].second, p[j].second)) {
                cnt++;
            }
        }
        result += cnt * p[i].first;
    }

    cout << result << '\n';
    return 0;
}