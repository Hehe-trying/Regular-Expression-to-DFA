#include <iostream>
#include <vector>
using namespace std;
int main() {
    int st;
    cin>>st;
    vector<vector<char>> state;
    for(int i=0;i<st;i++){
        vector<char> temp;
        for(int j=0;j<3;j++){
            char temp1;
            cin>>temp1;
            temp.push_back(temp1);
        }
        state.push_back(temp);
    }
    cout<<"DFA Before Minimisation: "<<endl;
    for(int i=0;i<st;i++){
        for(int j=0;j<3;j++){
            cout<<state[i][j]<<" ";
        }
        cout<<endl;
    }
    char store1,store2;
    int store;
    for(int i=0;i<st-1;i++){
        for(int j=i+1;j<st-1;j++){
            if(state[i][1]==state[j][1] && state[i][2]==state[j][2]){
                store1=state[i][0];
                store2=state[j][0];
                store=j;
        }
    }
    }
    for(int i=0;i<st;i++){
        for(int j=0;j<3;j++){
            if(state[i][j]==store2 || state[i][j]==store1) state[i][j]='N';
        }
    }
    cout<<"DFA after Minimisation: "<<endl;
    for(int i=0;i<st;i++){
        for(int j=0;j<3;j++){
            if(i!=store) cout<<state[i][j]<<" ";
        }
        if(i!=store) cout<<endl;
    }
    
    return 0;
}
