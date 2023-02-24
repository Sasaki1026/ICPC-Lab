#include<bits/stdc++.h>
#define ll long long
#define max 1e18
using namespace std;

struct road
{
    int to;
    ll weight;
    int time;

    road(int _to, ll _weight, int _time)
    {
        this->to = _to;
        this->weight = _weight;
        this->time = _time;
    }
};

ll ans[1000010];
vector<road> graph[1000010];

signed main(void)
{

    ios::sync_with_stdio(0), cin.tie(0);

    int cityNum, roadNum, begin, end;

    cin >> cityNum >> roadNum >> begin >> end;
    

    for (int i = 1; i <= cityNum; i++){
        ans[i] = max;
    }//init answer

    for (int i = 1; i <= roadNum; i++){
        int a, b, d;
        ll c;
        cin >> a >> b >> c >> d;
        graph[a].emplace_back(road(b, c, d));
        graph[b].emplace_back(road(a, c, d));
    }// make graph

    ans[begin] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	pq.emplace(0, begin);

    while(!pq.empty())
    {
		auto current = pq.top();
		pq.pop();

		if (ans[current.second] < current.first)continue;

		for (auto i : graph[current.second]) {
			int wait = i.time - ans[current.second] % i.time;
			if (wait == i.time)
				wait = 0;
			if (ans[i.to] > ans[current.second] + wait + i.weight) {
				ans[i.to] = ans[current.second] + wait + i.weight;
				pq.emplace(ans[i.to], i.to);
			}
		

	    }

    }

    cout << (ans[end] == 1e18 ? -1 : ans[end]) << "\n";

}
