#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;

	cin>>t;
	while(t!=0)
	{
        string s;
        cin>>s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string s1 = "selena";
        string s2 = "gomez";
        int n = s.size();

        long long count = 0;
        long long ans = 0;

        for(int i = 0; i < n - 4; i++){

            if(i < n - 5){
                string temp = s.substr(i, 6);
                if(temp == s1){
                    count++;
                    continue;
                }
            }
            string temp2 = s.substr(i, 5);
            if(temp2 == s2){
                ans += count;
            }
        }
        cout << ans << "\n";
        t--;
	}
	return 0;
}