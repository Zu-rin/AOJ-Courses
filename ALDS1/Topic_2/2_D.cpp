#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void insertionSort(vector<int> & A, int g, int &cnt) {
    int i, j, v;
    for (i = g; i < A.size(); i++) {
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
}

int Log(int n) {
    int ans = 0;
    while (n > 0) {
        ans++;
        n >>= 1;
    }
    return ans;
}

void shellSort(vector<int>& A) {
    int i, m = Log(A.size()), cnt = 0;
    vector<int> G(m);
    rep(i, m)
        G[i] = 1 << i;
    reverse(G.begin(), G.end());
    cout << m << "\n";
    rep(i, m - 1)
        cout << G[i] << " ";
    cout << G[i] << "\n";
    rep(i, m)
        insertionSort(A, G[i], cnt);
    cout << cnt << "\n";
    return;
}


int main(void) {
	int num, i;
    cin >> num;
    vector<int> d(num);
    rep(i, num)
        cin >> d[i];
    shellSort(d);
    rep(i, num)
        cout << d[i] << "\n";
	return 0;
}