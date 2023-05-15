#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 1;
    cin >> t;
    int i = 1;
    while(i <= t){
        string s;
        cin >> s;
        unordered_set<char> vow = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        if(s.back() == 'y' || s.back() == 'Y'){
            cout << "Case #" << i << ": " << s << " is ruled by nobody." << "\n";
        }
        else if(vow.find(s.back())!= vow.end()){
            cout << "Case #" << i << ": " << s << " is ruled by Alice." << "\n";
        }
        else {
            cout << "Case #" << i << ": " << s << " is ruled by Bob." << "\n";
        }
        i++;
    }
}