#include <iostream>
#include <vector>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string re;
    cout<<"Enter regular expression: ";
    cin>>re;
    int q[20][3],i=0,j=1;
    for(int a=0;a<20;a++){
        for(int b=0;b<3;b++){
            q[a][b]=0;
        }
    }
    cout<<"Characters in the regular expression: "<<re.length()<<endl;
    while(i<re.length())
    {
        if((re[i]=='a'||re[i]=='b'||re[i]=='e')&&re[i+1]!='|'&&re[i+1]!='*') { q[j][(int)sqrt(re[i]-'a')]=j+1; j++; }
        if((re[i]=='a'||re[i]=='b') &&re[i+1]=='|'&&re[i+2]=='b')
        {
            int k=re[i]+1;
          q[j][2]=((j+1)*10)+(j+3);
          j++;
          q[j][k%2]=j+1;
          j++;
          q[j][2]=j+3;
          j++;
          q[j][(k+1)%2]=j+1;
          j++;
          q[j][2]=j+1;
          j++;
          i=i+2;
        }
        if((re[i]=='a'||re[i]=='b')&&re[i+1]=='*')
        {
            q[j][2]=((j+1)*10)+(j+3); j++;
            q[j][re[i]-'a']=j+1; j++;
            q[j][2]=((j+1)*10)+(j-1); j++;
        }
        if(re[i]==')'&&re[i+1]=='*')
        {
            q[0][2]=((j+1)*10)+1;
            q[j][2]=((j+1)*10)+1;
            j++;
        }
        i++;
    }
    string rr="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<vector<string>> s(11,vector<string>(3));
    for(int i=0;i<11;i++){
        for(int j=0;j<3;j++){
            s[i][j]="-";
        }
    }
    for(int i=0;i<11;i++){
        for(int j=0;j<3;j++){
            if(q[i][0]!=0)
                s[i][0]=rr[q[i][0]];
            if(q[i][1]!=0)
                s[i][1]=rr[q[i][1]];
            if(q[i][2]!=0)
            {
                if(q[i][2]<10)
                    s[i][2]=rr[q[i][2]];
                else{
                    s[i][2]=rr[q[i][2]%10];
                    s[i][2].push_back(rr[q[i][2]/10]);
                }
            }
        }
    }
    for(int i=0;i<11;i++){
        for(int j=0;j<3;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
