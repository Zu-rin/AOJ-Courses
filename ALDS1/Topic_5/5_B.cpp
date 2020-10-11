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

int Merge(vector<int> & d, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    rep(i, n1)
        L[i] = d[i + left];
    rep(i, n2)
        R[i] = d[i + mid];
    L[n1] = R[n2] = INF;
    i = j = 0;
    for (k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            d[k] = L[i];
            i++;
        }
        else {
            d[k] = R[j];
            j++;
        }
    }
    return right - left;
}

int MergeSort(vector<int>& d, int left, int right) {
    int ans = 0;
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        ans = MergeSort(d, left, mid);
        ans += MergeSort(d, mid, right);
        ans += Merge(d, left, mid, right);
    }
    return ans;
}

int main(void) {
	int num, i, ans;
    cin >> num;
    vector<int> d(num);
    rep(i, num)
        cin >> d[i];
    ans = MergeSort(d, 0, num);
    rep(i, num - 1)
        cout << d[i] << " ";
    cout << d[i] << "\n";
    cout << ans << "\n";
	return 0;
}