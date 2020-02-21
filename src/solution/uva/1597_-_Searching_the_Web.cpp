#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct DID{
    int num;
    int line;
    DID() {}
    DID(int a, int b) :num(a), line(b) {}
    bool operator < (const DID& b) const {
        if(num != b.num) return num < b.num;
        else return line < b.line;
    }
    bool operator == (const DID& b) const {
        return line == b.line && num == b.num;
    }
};

struct word{
    string s;
    vector<DID> bucket;
    set<DID> DIDs;
    vector<int> ids;
    set<int> idset;
    word() {}
    word(string _s) : s(_s) {}
    friend ostream& operator << (ostream& out, const word& a);
};
ostream& operator << (ostream& out, const word& a) {
    out << a.s << endl;
    for(int i = 0 ; i < a.bucket.size(); i++) {
        out << a.bucket[i].num << ' ' << a.bucket[i].line << '\n';
    }
    out << '\n';
    return out;
}

struct document{
    vector<string> lines;
    friend ostream& operator << (ostream& out, const document& a);
};
ostream& operator << (ostream& out, const document& a) {
    for(int i = 0; i < a.lines.size(); i++)
        out << a.lines[i] << '\n';
    return out;
}

void part(string&, int, int);

vector<document> Ds;              //documents
map<string, int> wdmap;           //map words to vector index
vector<word> vocabulary;          //the vocabulary

int main() {
    freopen(".\\in&outputs\\in10","r",stdin);
    freopen(".\\in&outputs\\out10","w",stdout);
    freopen(".\\in&outputs\\out10","w",stderr);
    int N; cin >> N; getchar();
    Ds.resize(N);
    for(int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        while(s[0] != '*') {
            Ds[i].lines.push_back(s);
            part(s, i, Ds[i].lines.size() - 1);
            getline(cin, s);
        }
    }

    cin >> N; getchar();
    while(N--) {
        string s, term1, cater, term2;
        getline(cin, s);
        stringstream ss(s);
        
        if(s.find("AND") != -1) {

            vector<int> did;
            ss >> term1 >> cater >> term2;
            if(wdmap.count(term1) && wdmap.count(term2)) {
                word& wd1 = vocabulary[wdmap[term1]];
                word& wd2 = vocabulary[wdmap[term2]];
                for(int i = 0; i < wd2.ids.size(); i++)
                    if(wd1.idset.count(wd2.ids[i]))
                        did.push_back(wd2.ids[i]);
                for(int i = 0; i < did.size(); i++) {
                    if(i > 0) cout << "----------\n";
                    for(int j = 0; j < Ds[i].lines.size(); j++) {
                        if(wd1.DIDs.count(DID(did[i], j))) {cout << Ds[did[i]].lines[j] << '\n'; continue;}
                        if(wd2.DIDs.count(DID(did[i], j))) cout << Ds[did[i]].lines[j] << '\n';
                    }
                }
                if(did.size() == 0) cout << "Sorry, I found nothing.\n";
            } else {
                cout << "Sorry, I found nothing.\n";
            }
            cout << "==========\n";

        } else if(s.find("OR") != -1) {

            ss >> term1 >> cater >> term2;
            if(wdmap.count(term1) || wdmap.count(term2)) {
                vector<DID> uniondid;
                if(wdmap.count(term1)) {
                    word& wd1 = vocabulary[wdmap[term1]];
                    for(int i = 0; i < wd1.bucket.size(); i++)
                        uniondid.push_back(wd1.bucket[i]);
                }
                if(wdmap.count(term2)) {
                    word& wd2 = vocabulary[wdmap[term2]];
                    for(int i = 0; i < wd2.bucket.size(); i++)
                        uniondid.push_back(wd2.bucket[i]);
                }
                sort(uniondid.begin(), uniondid.end());
                vector<DID>::iterator it = unique(uniondid.begin(), uniondid.end());
                uniondid.erase(it, uniondid.end());
                for(int i = 0; i < uniondid.size(); i++) {
                    if(i > 0 && uniondid[i].num != uniondid[i-1].num)
                        cout << "----------\n";
                    cout << Ds[uniondid[i].num].lines[uniondid[i].line] << '\n';
                }

            } else {
                cout << "Sorry, I found nothing.\n";
            }
            cout << "==========\n";
            
        } else if(s.find("NOT") != -1) {
            
            ss >> cater >> term1;
            if(wdmap.count(term1) && Ds.size()==1) {
                cout << "Sorry, I found nothing.\n";
            } else {
                if(wdmap.count(term1)) {
                    word& wd = vocabulary[wdmap[term1]];
                    int j = 0;
                    for(int i = 0; i < Ds.size(); i++) {
                        if(wd.idset.count(i)) continue;
                        if(j > 0) cout << "----------\n";
                        cout << Ds[i];
                        j++;
                    }
                    if(j == 0) cout << "Sorry, I found nothing.\n";
                } else {
                    for(int i = 0; i < Ds.size(); i++) {
                        if(i > 0) cout << "----------\n";
                        cout << Ds[i];
                    }
                }
            }
            cout << "==========\n";

        } else {

            ss >> term1;
            if(wdmap.count(term1)) {
                word& wd = vocabulary[wdmap[term1]];
                int j = 0;
                for(int i = 0; i < wd.ids.size(); i++) {
                    if(i > 0) cout << "----------\n";
                    while(wd.bucket[j].num == wd.ids[i]) {
                        cout << Ds[wd.ids[i]].lines[wd.bucket[j].line] << '\n';
                        j++;
                    }
                }
            } else {
                cout << "Sorry, I found nothing.\n";
            }
            cout << "==========\n";

        }
    }

    /*for(int i = 0 ; i < vocabulary.size(); i++) {
        cout << vocabulary[i];
    }*/

    return 0;
}

void part(string& s, int num, int line) {
    int st, l;
    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
        if(isalpha(s[i])) {
            st = i; l = 0;
            while(i < s.length() && isalpha(s[i])) i++, l++, s[i] = tolower(s[i]);
            string wd = s.substr(st, l);
            if(wdmap.count(wd)) {
                word& curwd = vocabulary[wdmap[wd]];
                if(!curwd.DIDs.count(DID(num, line))) {
                    curwd.bucket.push_back(DID(num, line));
                    curwd.DIDs.insert(DID(num, line));
                }

                if(!curwd.idset.count(num)) {
                    curwd.idset.insert(num);
                    curwd.ids.push_back(num);
                }
            } else {
                int n = vocabulary.size();
                wdmap[wd] = n;
                vocabulary.push_back(word(wd));
                word& curwd = vocabulary[n];
                curwd.bucket.push_back(DID(num, line));
                curwd.DIDs.insert(DID(num, line));

                curwd.ids.push_back(num);
                curwd.idset.insert(num);
            }
        }
    }
}
