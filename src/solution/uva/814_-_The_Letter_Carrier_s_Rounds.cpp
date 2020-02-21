#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

void parse_addr(const string& s, string& user, string& addr) {
    int k = s.find('@');
    user = s.substr(0, k);
    addr = s.substr(k+1);
}

int main() {
    freopen(".\\in&outputs\\in1","r",stdin);
    freopen(".\\in&outputs\\out1","w",stdout);
    string s;

    set<string> MTA;
    int n;
    string addr, user;
    while(cin >> s && s[0] != '*') {
        cin >> addr >> n;
        while(n--) {cin >> user; MTA.insert(user + '@' + addr); }
    }

    string sender, smta, receiver, recmta;
    while(cin >> s && s[0] != '*') {

        string t, rec;
        int n = 0;
        set<string> vis;
        vector<string> rmta;
        map<string, vector<string> > lst;
        parse_addr(s, sender, smta);
        while(cin >> rec && rec[0] != '*') {
            parse_addr(rec, receiver, recmta);
            if(vis.count(rec)) continue;
            vis.insert(rec);
            if(lst.count(recmta)) {
                lst[recmta].push_back(receiver);
            } else {
                rmta.push_back(recmta);
                lst[recmta] = vector<string>();
                lst[recmta].push_back(receiver);
            }
        }
        getline(cin, t);

        string data;
        while(getline(cin, t) && t[0] != '*') data += "     " + t + '\n';

        for(int i = 0; i < rmta.size(); i++) {
            bool have_recevier = false;
            string x = rmta[i];
            cout << "Connection between " << smta << " and " << x << '\n';
            cout << "     HELO " << smta << "\n     250\n";
            cout << "     MAIL FROM:<" << s << ">\n     250\n";
            for(int j = 0; j < lst[x].size(); j++) {
                cout << "     RCPT TO:<" << lst[x][j] + '@' + x << ">\n";
                if(MTA.count(lst[x][j] + '@' + x)) {
                    have_recevier = true;
                    cout << "     250\n";
                } else {
                    cout << "     550\n";
                }
            }
            if(have_recevier) {
                cout << "     DATA\n";
                cout << "     354\n";
                cout << data << "     .\n";
                cout << "     250\n";
            }
            cout << "     QUIT\n     221\n";
        }
    }
    return 0;
}
