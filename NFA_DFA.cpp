#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;
class T{
public:
stack<char> ss;
vector<string> epsilon{"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string rr="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void eps(int x){
    for(int j=0;j<x;j++){
    ss.push(rr[j]);
    while(!ss.empty()){
        char c=ss.top();
        ss.pop();
        for(int i=0;i<s[c-'A'][2].length();i++){
            if(epsilon[j].find(s[c-'A'][2][i])==string::npos && s[c-'A'][2][i]!=45){
                epsilon[j].push_back(s[c-'A'][2][i]);
                ss.push(s[c-'A'][2][i]);
            }
        }
    }
    }
}
bool same(string str1, string str2)
{
    if (str1.length()!= str2.length()) return false;
   
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < str1.length(); i++) if (str1[i] != str2[i]) return false;
 
    return true;
}
string rem(string s)
{
   for (int i=0; i<s.size(); i++) {
     for (int j=i+1; j<s.size(); j++) {
     if (s[i] == s[j]){
         s.erase(s.begin()+j);
     }
     }
   }
    for (int i=0; i<s.size()-1; i++)
        if(s[i]==s[s.size()-1]) s.erase(s.end()-1);
   return s;
}

  vector<vector<string>> s;  
 void input(int nn){
 	for(int i=0;i<nn;i++){
            vector<string> s1;
            string ss,ss1,ss2;
            cin>>ss>>ss1>>ss2;
            s1.push_back(ss);
            s1.push_back(ss1);
            s1.push_back(ss2);
            s.push_back(s1);
        }
 }
 
  vector<vector<string>> v;
    queue<string> q;
    vector<string> brr;
void dfa(int nn){
        
        eps(nn);
        for(int i=0;i<nn;i++){
            cout<<"EPSILON of "<<rr[i]<<": "<<epsilon[i]<<endl;
        }
        brr.push_back(epsilon[0]);
        q.push(epsilon[0]);
    while(!q.empty()){
        string st=q.front();
        q.pop();
        vector<string> tt;
            tt.push_back(st);
        for(int k=0;k<2;k++){
            string s8;
        for(int i=0;i<st.length();i++){
            for(int j=0;j<s[st[i]-'A'][k].length();j++){
                if(s[st[i]-'A'][k][j]!=45){
                    s8.append(epsilon[s[st[i]-'A'][k][j]-'A']);}
            }

        }
            string rs8=rem(s8);
            tt.push_back(rs8);
            int stuti=0;
            for(int f=0;f<brr.size();f++){
                if(same(rs8,brr[f])==1) stuti++;
            }
            if(stuti==0){
            brr.push_back(rs8);
            q.push(rs8);
            }
        }
        v.push_back(tt);
        }
        for(int i=0;i<brr.size();i++){
            cout<<brr[i]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
        }
}

};
int main() {
    T u;
    int n;
    cout<<"Enter number of states: ";
    cin>>n;
    u.input(n);
    u.dfa(n);
    return 0;
}
