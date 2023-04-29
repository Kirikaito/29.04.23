#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
typedef long long LL;
const int maxn = 900;
char Map[maxn][maxn];
bool vis[maxn][maxn];
int f[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
struct Node{
    int x,y,step;
};
queue<Node>Q;
bool jud(int i,int j){
    Node st;
    int ret = 0;
    if(Map[i-1][j] == '#'){
        ret++;
    }
    if(Map[i][j-1] == '#'){
        ret++;
    }
    if(Map[i+1][j] == '#'){
        ret++;
    }
    if(Map[i][j+1] == '#'){
        ret++;
    }
    if(ret >= 3){
        st.x = i, st.y = j, st.step = 0;
        Q.push(st);
        return true;
    }
    return false;
}
int n,m;
Node BFS(){
    Node st,tmp,en;
    en = Q.front();
    vis[en.x][en.y] = 1;
    while(!Q.empty()){
        st = Q.front();
        Q.pop();
        if(st.step > en.step){
            en = st;
        }
        int tmpx ,tmpy;
        for(int i = 0; i < 4; i++){
            tmp.x = st.x + f[i][0];
            tmp.y = st.y + f[i][1];
            if(tmp.x <= 0 ||tmp.x > m ||tmp.y <= 0 || tmp.y > n || Map[tmp.x][tmp.y] =='#' ||vis[tmp.x][tmp.y]){
                continue;
            }
            vis[tmp.x][tmp.y] = 1;
            tmp.step = st.step + 1;
            Q.push(tmp);
        }
    }
    return en;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        while(!Q.empty()) Q.pop();
        for(int i = 1; i <= m; i++){
            getchar();
            for(int j = 1; j <= n; j++){
                scanf("%c",&Map[i][j]);
            }
        }
        int flag = 0;
        for(int i = 1; i <= m; i++){
            if(flag) break;
            for(int j = 1; j <= n; j++){
                if(Map[i][j] == '.' && flag == 0){
                    flag = jud(i,j);
                }
                if(flag) break;
            }
        }
        Node st = BFS();
        memset(vis,0,sizeof(vis));
     //   printf("%d %d %d+++\n",st.x,st.y,st.step);
        st.step = 0;
        Q.push(st);
        Node en = BFS();
        printf("%d\n",en.step);
    }
    return 0;
}
