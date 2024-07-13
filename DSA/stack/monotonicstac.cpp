//montonic increasing 
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>s;
    vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
    for(int i=0;i<a.size();i++){
        while (!s.empty() && s.top() > a[i]) {
            s.pop();
        }
        s.push(a[i]);

    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}