//
// Created by ahmed-kashkoush on 2/19/23.
//

#ifndef COMPETITIVE_PROGRAMMING_CODES_MACROS_H
#define COMPETITIVE_PROGRAMMING_CODES_MACROS_H
#include<bits/stdc++.h>
#define el '\n'
#define ll long long
#define reset(v, d) memset(v, d , sizeof(v))
#define all(s)  s.begin(), s.end()
#define cin(v)  for(auto &i:v)cin>>i
#define cout(v) for(auto i:v)cout<<i<<" "
using namespace std;
const double pi = 3.1415926535897932384;
void judge() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
#endif //COMPETITIVE_PROGRAMMING_CODES_MACROS_H
