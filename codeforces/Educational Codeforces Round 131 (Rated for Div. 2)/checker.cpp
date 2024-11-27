#include<bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
     
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int flag = 0;   

        for(int i = 1; i <= n; i++){
            int val = i / a[i - 1];
            if(val != b[i - 1]){
                cout << val << " " << b[i - 1] << " " << a[i - 1] << "\n";
                flag = 1;
                break;
            }
        }

        
        if(flag){
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
            for(int i = 0; i < n; i++){
                cout << b[i] << " ";
            }
        }

        cout << "\n";

    }
}
