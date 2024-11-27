#include <bits/stdc++.h>
using namespace std;

#define int long long 

struct assistants{
    int t, z, y;
};



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int m, n;
int blown(assistants &x, int min_time){
    int blown_balloons = 0;
    int total_time_taken_by_assistant = (x.t * x.z) + x.y;
    int share_of_balloons_blown_by_assistant = x.z * (min_time / total_time_taken_by_assistant);
    blown_balloons += share_of_balloons_blown_by_assistant;
    int remaining_time = min_time % total_time_taken_by_assistant;
    if(remaining_time >= (x.t * x.z)){
        blown_balloons += x.z;
    }else{
        blown_balloons += remaining_time / x.t;
    }
    return blown_balloons;
}
bool pred(int min_time, vector<assistants> &v){
    int blown_balloons = 0;
    for(auto &x : v){
        blown_balloons += blown(x, min_time);
    }
    return blown_balloons >= m;
}
/*----------------------------------------------------------------------MAIN CODE------------------------------------------------------------------------------------------------------------------------*/
void solve()
{

    // cout << 1 << "\n";
    int m = 15000;
    int n = 2;
    cout << m << " " << n << "\n";
    for(int i = 0; i < n; i++){
        int t = min(100ll, (int)50 + rng() % 100);
        int y = min(100ll, (int)50 + rng() % 100);
        int z = min(1ll, (int)100 + rng() % 1000);
        cout << t << " " << z << " " << y << "\n";
    }

    // cin >> m >> n;
    // vector<assistants> v(n);
    // int ma = 0;
    // for(int i = 0; i < n; i++){
    //     cin >> v[i].t >> v[i].z >> v[i].y;
    // };

    // int lo = 0, hi = 1e18;
    // while(hi - lo > 1){
    //     int mid = lo + ((hi - lo) >> 1);
    //     if(pred(mid, v)){
    //         hi = mid;
    //     }else{
    //         lo = mid;
    //     }
    // }
    // cout << hi << endl; //the minimum time
    // for(auto &x : v){
    //     int curr =  blown(x, hi);
    //     cout << min(m, curr) << " ";
    //     m -= min(m, curr);
    // }
}
int32_t main(){
    solve();
}