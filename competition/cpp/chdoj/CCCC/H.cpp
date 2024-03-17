#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)
using namespace std;

/*我真不想写大模拟啊*/

void solve() {
	int m, n;
	cin >> m >> n;
	vector<unordered_map<int, bool>> mp(m + 1, unordered_map<int, bool>());//机器现在是否被使用
	vector<int> cnt(n + 1, 0);//当前工件的序号
	vector<int> cur(n + 1, 0);//当前工件结束的时间

	vector<int> od(m * n + 1, 0);
	vector<vector<int>> object(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> time(n + 1, vector<int>(m + 1, 0));
	rep(i, 1, m * n) cin >> od[i];
	rep(i, 1, n) rep(j, 1, m) cin >> object[i][j];
	rep(i, 1, n) rep(j, 1, m) cin >> time[i][j];

	auto check = [&](int st, int ed, int id) -> bool {
		rep(i, st, ed) if (mp[id][i]) return false;
		return true;
	};

	int rs = 0;

	rep(i, 1, m * n) {
		int machine = object[od[i]][++cnt[od[i]]];
		int time_need = time[od[i]][cnt[od[i]]];
		int cur_end = cur[od[i]];
		while (true) {
			if (check(cur_end, cur_end + time_need - 1, machine)) {
				rep(j, 0, time_need - 1) mp[machine][cur_end + j] = true;
				rs = max(rs, cur_end + time_need);
				cur[od[i]] = cur_end + time_need;
				break;
			}
			cur_end++;
		}
	}

	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}