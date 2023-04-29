#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int recurse(int x,int y,int a,int b,int c,int d,vector<pair<int,int>> hori,vector<pair<int,int>> vert,int topx,int topy,vector<int> answs,int k){
    if(a == c and b == d and topx == 0 and topy == 0){
        answs.push_back(k);
        return 0;
    }
    if(k > x*y*2){return 0;}
    

    if(a > 1 and find(hori.begin(), hori.end(), pair (a,b)) != hori.end()){recurse(x,y,a++,b,c,d,hori,vert,(topx+1)%4,topy,answs,k++);}
    if(a < x and find(hori.begin(), hori.end(), pair (a-1,b)) != hori.end()){recurse(x,y,a--,b,c,d,hori,vert,(topx-1)%4,topy,answs,k++);}
    if(b > 1 and find(vert.begin(), vert.end(), pair (a,b)) != vert.end()){recurse(x,y,a,b++,c,d,hori,vert,topx,(topy+1)%4,answs,k++);}
    if(b < y and find(vert.begin(), vert.end(), pair (a,b-1)) != vert.end()){recurse(x,y,a,b--,c,d,hori,vert,topx,(topy-1)%4,answs,k++);}
    
    if(answs.size()==0){return 0;}
    return *min_element(answs.begin(), answs.end());
}

int main(){
    int x,y,a,b,c,d,topx = 0,topy = 0,k=0;
    ifstream ifs;
    ifs.open("input.txt");
    string line;
    pair<int,int> in;
    vector<pair<int,int>> hori,vert;
    vector<int> answs;
    ifs >> x >> y >> a >> b >> c >> d;
    while (getline(ifs, line)){
        istringstream ss(line);
        string var1;
        int n,m;
        ss >> var1;
        if(var1 == "v"){continue;}
        if(var1 == "h"){break;}
        istringstream ( var1 ) >> n;
        ss >> m;
        in.first = n;
        in.second = m;
        hori.push_back(in);
    }
    while (getline(ifs, line)){
        istringstream ss(line);
        string var1;
        int n,m;
        ss >> var1;
        istringstream ( var1 ) >> n;
        ss >> m;
        in.first = n;
        in.second = m;
        hori.push_back(in);
    }
    vert.erase(vert.begin());
    int res = recurse(x,y,a,b,c,d,hori,vert,topx,topy,answs,k);
    if(res == 0){cout << "No solution";}else{cout << res;}
}
