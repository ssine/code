#include<iostream>
#include<vector>
#include<string>
#include<strstream>
using namespace std;
void mvot(int a, int b, int st[][26], int pt[][2], int sz[]);
void mvov(int a, int b, int st[][26], int pt[][2], int sz[]);
void plot(int a, int b, int st[][26], int pt[][2], int sz[]);
void plov(int a, int b, int st[][26], int pt[][2], int sz[]);

int main(){
    freopen(".\\in&outputs\\input50.txt","r",stdin);
    freopen(".\\in&outputs\\output50.txt","w",stdout);
    int pt[26][2],st[26][26],sz[26];
    string s,f,l;
    char cmd[100];
    int n,a,b;
    cin >> n;
    getchar();
    for(int i=0;i<n;i++){
        st[i][0] = i;
        for(int j=1;j<26;j++) st[i][j] = -1;
        sz[i] = 1;
        pt[i][0] = i;
        pt[i][1] = 0;
    }
    cin.getline(cmd,100);
    while(cmd[0]!='q'){
        istrstream strin(cmd);
        strin >> f >> a >> l >> b;
        if(pt[a][0]!=pt[b][0]){
            if(f == "move"){
                if(l == "onto") mvot(a,b,st,pt,sz);
                else mvov(a,b,st,pt,sz);
            }else{
                if(l == "onto") plot(a,b,st,pt,sz);
                else plov(a,b,st,pt,sz);
            }
        }
        cin.getline(cmd,100);
    }
    for(int i = 0;i<n;i++){
        cout << i << ':';
        for(int j = 0;j<sz[i];j++)
            cout << ' ' << st[i][j];
        cout << endl;
    }
    return 0;
}

void mvot(int a, int b, int st[][26], int pt[][2], int sz[]){
    for(int i = sz[pt[a][0]]-1; i > pt[a][1]; i--){
        int cur = st[pt[a][0]][i];
        st[cur][sz[cur]] = cur; sz[cur]++;
        pt[cur][0] = cur; pt[cur][1] = sz[cur]-1;
        sz[pt[a][0]]--;
    }
    for(int i = sz[pt[b][0]]-1; i > pt[b][1]; i--){
        int cur = st[pt[b][0]][i];
        st[cur][sz[cur]] = cur; sz[cur]++;
        pt[cur][0] = cur; pt[cur][1] = sz[cur]-1;
        sz[pt[b][0]]--;
    }
    sz[pt[a][0]]--;
    sz[pt[b][0]]++;
    st[pt[b][0]][pt[b][1]+1] = a;
    pt[a][0] = pt[b][0]; pt[a][1] = pt[b][1]+1;
}

void mvov(int a, int b, int st[][26], int pt[][2], int sz[]){
    for(int i = sz[pt[a][0]]-1; i > pt[a][1]; i--){
        int cur = st[pt[a][0]][i];
        st[cur][sz[cur]] = cur; sz[cur]++;
        pt[cur][0] = cur; pt[cur][1] = sz[cur]-1;
        sz[pt[a][0]]--;
    }
    sz[pt[a][0]]--;
    sz[pt[b][0]]++;
    st[pt[b][0]][sz[pt[b][0]]-1] = a;
    pt[a][0] = pt[b][0]; pt[a][1] = sz[pt[b][0]]-1;
}

void plot(int a, int b, int st[][26], int pt[][2], int sz[]){
    int i,l,n;
    for(i = sz[pt[b][0]]-1; i > pt[b][1]; i--){
        int cur = st[pt[b][0]][i];
        st[cur][sz[cur]] = cur; sz[cur]++;
        pt[cur][0] = cur; pt[cur][1] = sz[cur]-1;
        sz[pt[b][0]]--;
    }
    l = pt[a][0]; n = pt[a][1];
    for(i = pt[a][1]; i < sz[l]; i++){
        int cur = st[l][i];
        st[pt[b][0]][sz[pt[b][0]]] = cur;
        sz[pt[b][0]]++;
        pt[cur][0]=pt[b][0];pt[cur][1]=sz[pt[b][0]]-1;
    }
    sz[l] -= sz[l]-n;
}

void plov(int a, int b, int st[][26], int pt[][2], int sz[]){
    int i,l,n;
    l = pt[a][0]; n = pt[a][1];
    for(i = pt[a][1]; i < sz[l]; i++){
        int cur = st[l][i];
        st[pt[b][0]][sz[pt[b][0]]] = cur;
        sz[pt[b][0]]++;
        pt[cur][0]=pt[b][0];pt[cur][1]=sz[pt[b][0]]-1;
    }
    sz[l] -= sz[l]-n;
}
