#include <iostream>

#include <fstream>

using namespace std;

#define MAX 10

ifstream in("gengraf.in");
ofstream out("gengraf.out");

struct graph{
    bool g[MAX][MAX];
    int n;
};

void ki(graph g){
    int i,j;
    for(i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            out<<g.g[i][j]<<' ';
        }
        out<<endl;
    }
}

void gen(int n){
    ///nem iranyitott
    int a=1<<((n*(n-1))/2);//3:3;4:6;5:10
    ///iranyitott
    //a=1<<(n*(n-1))
    out<<a<<endl;
    int i,j,k,l;
    graph g;
    g.n=n;
    for(i=0;i<a;i++){
        l=1;
        for(j=0;j<g.n;j++){
            g.g[j][j]=0;
            for(k=0;k<j;k++){
                g.g[j][k]=g.g[k][j]=i&l;
                l*=2;
            }
        }
        ki(g);
        out<<endl;
    }
}

int main()
{
    int n;
    in>>n;
    gen(n);
    return 0;
}
