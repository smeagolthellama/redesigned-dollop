#include <iostream>

#define MAX 10

using namespace std;

struct graph{
    bool graph[MAX][MAX];
    bool touched[MAX];
    int n;
};


class sor
{
	private:
		int c[1024];
		int first,last;
	public:
	    int g_f(){
            return first;
	    }
	    int g_l(){
            return last;
	    }
		int getfirst(){
			return c[first&1023];
		};
		void addlast(int ch){
			if((last&1023)>=(first&1023))
				c[(last++)&1023]=ch;
		};
		int pop(){
			if(first<last)
				return c[(first++)&1023];
			return 101;
		};
		sor(){
			first=0;
			last=0;
		}
		bool ures(){
			return (first==last);
		}
};

void be(graph& g){
    int i,j;
    cin>>g.n;
    for(i=1;i<=g.n;i++){
        for(j=1;j<=g.n;j++){
            cin>>g.graph[i][j];
        }
        g.touched[i]=0;
    }
}

bool alltouched(graph g){
    for(int i=1;i<=g.n;i++){
        if(g.touched[i]==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    sor s;
    graph g;
    be(g);
    int t,i;
    cin>>t;
    s.addlast(t);
    g.touched[t]=1;
    while(s.g_f()!=s.g_l()){
        cout<<s.getfirst()<<' ';
        t=s.pop();
        for(i=1;i<=g.n;i++){
            if(g.graph[t][i] && !g.touched[i]){
                s.addlast(i);
                g.touched[i]=true;
            }
        }
    }
    return 0;
}
