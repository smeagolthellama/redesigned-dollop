#include <iostream>
#include <fstream>

using namespace std;

#define MAX 10

struct graf{
    bool g[MAX][MAX];
    bool erint[MAX]={0};
    int n;
};

void melysegi(graf g){
    int verem[MAX];
    bool found;
    cin>>verem[0];
    g.erint[verem[0]]=1;
    int szint=0,i;
    cout<<verem[0]<<' ';
    while(szint>=0){
        found=false;
        for(i=1;i<=g.n && !found;i++){
            if(g.g[verem[szint]][i] && !g.erint[i]){
                g.erint[i]=true;
                verem[++szint]=i;
                cout<<verem[szint]<<' ';
                found=1;
            }
        }
        if(!found){
            szint --;
        }
    }
}

int main()
{
    graf g;
    ifstream in("in.in");
    int i,j;
    in>>g.n;
    for( i=1;i<=g.n;i++){
        for(j=1;j<=g.n;j++){
            in>>g.g[i][j];
        }
    }
    melysegi(g);
    return 0;
}
