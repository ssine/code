#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
//#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct player{
    string name;
    bool amateur;
    int place;
    bool tie;
    int rd;
    bool DQ;
    int RD[4];
    int sc36;
    int tot;
    double price;

    player() {
        amateur = false;
        tie = false;
        DQ = false;
        rd = 0;
        price = -1;
        sc36 = -1;
        memset(RD, 0, sizeof(RD));
        tot = 0;
    }

    bool operator < (const player& b) const {
        if(rd != b.rd) return b.rd < rd;

        if(tot != b.tot) return tot < b.tot;

        int a = 0;
        for(int i = 0; i < 4; i++)
            if(RD[i] != 0) a += RD[i];
        int c = 0;
        for(int i = 0; i < 4; i++)
            if(RD[i] != 0) c += RD[i];
        if(a != c) return a < c;

        return name < b.name;
    }

    bool operator == (const player& b) const {
        return rd == b.rd && tot == b.tot;
    }
};
vector<player> lst;
void print(player&);
bool kocmp(const player& a, const player& b) {
    //if(a.DQ && !b.DQ) return true;
    //if(b.DQ && !a.DQ) return false;
    bool c = !a.RD[0] || !a.RD[1];
    bool d = !b.RD[0] || !b.RD[1];
    if(c && b.RD[0] && b.RD[1]) return false;
    if(d && a.RD[0] && a.RD[1]) return true;
    return a.sc36 < b.sc36;
}

double purse, percent[1000] = {0};
stringstream stream;
int cutnum;

int main(){
    freopen(".\\in&outputs\\input66.txt","r",stdin);
    freopen(".\\in&outputs\\output66.txt","w",stdout);
    freopen(".\\in&outputs\\output66.txt","w",stderr);
    int N;
    cin >> N;
    while(N--) {
        cin >> purse;
        memset(percent, 0, sizeof(percent));
        for(int i = 0; i < 70; i++) cin >> percent[i];

        int totn;
        cin >> totn; getchar();
        lst.clear();
        lst.resize(totn);
        for(int i = 0; i < totn; i++) {
            string line;
            getline(cin, line);
            lst[i].name = line.substr(0,20);
            if(lst[i].name.find('*') != -1) lst[i].amateur = true;

            stream.str("");
            stream.clear();
            stream << line.substr(20);
            for(int j = 0; stream >> lst[i].RD[j]; j++)
                lst[i].tot += lst[i].RD[j], lst[i].rd++;
            if(line.substr(20).find('D') != -1) lst[i].DQ = true;
            lst[i].sc36 = lst[i].RD[0]+lst[i].RD[1];
            if(lst[i].rd < 2) lst[i].sc36 = -1;
        }


        // knock out
        sort(lst.begin(),lst.end(),kocmp);
        int i = 69;
        //int j = 0;
        //while(lst[j].DQ) i++,j++;
        i = min(i, totn-1);
        while(i < totn-1 && (lst[i].sc36 == lst[i+1].sc36)) i++;
        //while(i < totn-1 && lst[i+1].rd == 1) i++;
        //while(i < totn-1 && lst[i+1].DQ) i++;
        for(int j = totn-1; j > i; j--) lst.pop_back();
        cutnum = i;

        //test
        /*int a = 1;
        for(vector<player>::iterator it = lst.begin(); it != lst.end(); it++) {
            cout << a++ << " : " << (*it).name << (*it).RD[0]+(*it).RD[1] << '\n';
        }*/

        // place sort
        sort(lst.begin(), lst.end());

        // judge the place
        bool tiejud = false;
        for(int i = 0, p = 0; i <= cutnum; i++) {
            lst[i].place = i + 1;
            p++; tiejud = false;
            if(lst[i] == lst[i+1]) {
                int j = i, ct = 0;
                if(!lst[i].amateur) ct++;
                if(p <= 70) tiejud = true;
                while(lst[i] == lst[i+1]) {
                    lst[i+1].place = j + 1;
                    if(!lst[i+1].amateur) ct++, p++;
                    i++;
                }
                if(ct > 1)
                    for(int k = j; k <= i; k++)
                        if(!lst[k].amateur && tiejud) lst[k].tie = true;
            }
        }

        // allocate the price
        int p = 0;
        for(int i = 0; i <= cutnum; i++) {
            if(p > 70) break;
            double pct = 0;
            if(lst[i].amateur) continue;
            if(lst[i].tie) {
                int j = i+1, ct = 1;
                pct += percent[p++];
                while(lst[j].place == lst[i].place) {
                    if(!lst[j].amateur) {
                        ct++;
                        pct += percent[p++];
                    }
                    j++;
                }

                double price = pct * purse / ct;
                for(int k = i; k < j; k++)
                    if(!lst[k].amateur)
                        lst[k].price = price;
                i = j - 1;
            } else {
                pct = percent[p++];
                double price = pct * purse;
                lst[i].price = price;
            }
        }

        // print!
        cout << "Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n";
        cout << "-----------------------------------------------------------------------\n";
        for(int i = 0; i <= cutnum; i++) {
            print(lst[i]);
        }
        if(N > 0) cout << '\n';
    }
    return 0;
}

void print(player& a) {
    //if(a.RD[1] == 0) return;

    cout << a.name << ' ';

    string s;
    if(a.DQ) printf("          ");
    else {
        stream.clear(); stream.str("");
        stream << a.place;
        if(a.tie) stream << 'T';
        stream >> s;
        cout << s;
        for(int i = s.size(); i < 10; i++) cout << ' ';
    }

    for(int i = 0; i < 4 ; i++)
        if(a.RD[i]) printf("%-5d", a.RD[i]);
        else printf("     ");

    int l;
    if(a.DQ) printf("DQ"), l = 2;
    else {
        printf("%d", a.tot);
        s.clear();
        stream.clear(); stream.str("");
        stream << a.tot;
        stream >> s;
        l = /*3*/s.length();
    }
    if(!a.amateur && !a.DQ && a.price >= 0) {
        for(int i = l; i < 10; i++) cout << ' ';
        cout << "$" ;//<< setw(8) << setiosflags(ios::right) << a.price;
        //if(int(a.price * 1000)%10 == 5 && int(a.price * 1e7)%10 == 0) a.price -= 0.001;
        //float b = floor((a.price * 100)) / 100.0;
        printf("%9.2lf", a.price / 100.0);
    }

    cout << '\n';
}
