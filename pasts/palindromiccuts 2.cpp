

#include <bits/stdc++.h> 
using namespace std;

void solve(){

   	int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 1;

	map<char,int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }

    int even = 0;
    int odd = 0;

    for(auto& x: mp){
        if(x.second % 2 == 0)
            even++;
        else
            odd++;
    }

    if(odd == 0){
        cout << 1 << "\n";
        string t = "";
        for(auto& x: mp){
            if(x.second == 0)
                continue;
            t = t + x.first;
            t = x.first + t;
            x.second -= 2;
        }
        cout << t << "\n";
        return;
    }

   for(int i = 2; i * i <= n; i++){
        int k1, k2;
        if(n % i == 0){
             k1 = i;
             k2 = n / i;
        }
        else{
            continue;
        }

        if(k1 % 2 == 1){
        	if(n / k1 >= odd){
        		if((n / k1 - odd) % 2 == 0){
        			mx = max(k1, mx);
        		}
        	}
        }
        
        if(k2 % 2 == 1){
            if(n / k2 >= odd){
                if((n / k2 - odd) % 2 == 0){
                    mx = max(k2, mx);
                }
            }
        }
    }


    cout << n / mx << "\n";
    vector<pair<char,int>> freq;

    for(auto& x: mp){
        freq.push_back({x.first, x.second});
    }

    vector<string> ans(n / mx);

    for(int i = 0; i < n / mx; i++){
        if(odd == 0){
            for(auto& y: freq){
                if(y.second != 0){
                    ans[i] += y.first;
                    ans[i + 1] += y.first;
                    y.second -= 2;
                    i++;
                    break;
                }
            }
        }
        else{
            for(auto& y: freq){
                if(y.second != 0 && y.second % 2 == 1){
                    ans[i] += y.first;
                    odd--;
                    y.second -= 1;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n / mx; i++){
       while((int)ans[i].size() != mx){
            for(auto& x: freq){
                if(x.second != 0){
                    ans[i] = x.first + ans[i];
                    ans[i] = ans[i] + x.first;
                    x.second -= 2;
                }
            }
        } 
    }
    for(auto& x: ans){
        cout << x << " ";
    }
    cout << "\n";
}

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t = 1;
        //cin >> t;
        while(t--){
            solve();
        }
    }