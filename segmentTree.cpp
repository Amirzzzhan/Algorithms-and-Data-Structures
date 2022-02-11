#define ll long long
#define se second
#define fi first
#define pb push_back
#define in insert
#define MX INT_MAX
#define MAX LLONG_MAX
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
template<typename T> 
void print(T &v){
	cout << v.size() << '\n';
	for(auto i : v) cout << i << ' ';
	cout << '\n';
}

class segmentTree{
	vector<ll> tr;
	int sz = 1;
	
	ll sum(int x, int l, int r, int xl, int xr){
		if(xl >= r || l >= xr){
			return 0;
		}
		else if(l <= xl && r >= xr){
			return tr[x];
		}
		int xm = (xl + xr) / 2;
		ll s1 = sum(2*x + 1, l, r, xl, xm);
		ll s2 = sum(2*x + 2, l, r, xm, xr);
		return s1 + s2;
	}
	
	void setup(int i, int n, int x, int xl, int xr){
		if(xl == xr - 1){
			tr[x] = n;
			return;
		}
		int xm = (xl + xr) / 2;
		if(i < xm){
			setup(i,n,2*x + 1,xl,xm);
		}
		else{
			setup(i,n,2*x + 2,xm,xr);
		}
		tr[x] = tr[2*x + 1] + tr[2*x + 2];
	}
public:
	segmentTree(int n){
		while(sz < n){
			sz *= 2;
		}
		tr.assign(2*sz - 1,0);
		for(int i = 0; i < n; ++i){
			cin >> tr[sz + i - 1];
		}	
		for(int i = sz - 2; i >= 0; --i){
			tr[i] = tr[2 * i + 1] + tr[2 * i + 2];
		}
	}
	
	ll sum(int l, int r){
		return sum(0,l,r,0,sz);
	}
	
	void setup(int i, int n){
		setup(i, n, 0, 0, sz);
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	segmentTree* a = new segmentTree(n);
	string s;
	while(cin >> s){
		int l,r;
		cin >> l >> r;
		if(s == "sum"){
			cout << a->sum(l-1,r) << '\n';
		}
		else{
			a->setup(l-1,r);
		}
	}
}

