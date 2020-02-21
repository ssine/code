#include <iostream>
#include <cstdarg>
#include <cstring>
#include <deque>
using namespace std;
const int maxn = 16 + 2;

struct State{
    short pos[3][2];
    State(int num, ...) {
        memset(pos, 0, sizeof(pos));
        n = num;
        va_list vl;
        va_start(vl, num);
        for(int i = 0; i < num; i++) {
            pos[i][0] = va_arg(vl, short);
            pos[i][0] = va_arg(vl, short);
        }
    }
    bool operator == (const State b) const {
        for(int i = 0; i < 3; i++) {
            if(!(pos[i][0] == b.pos[i][0] && pos[i][1] == b.pos[i][1]))
                return false;
        }
        return true;
    }
}

deque<State> dq;

int main() {
    
    return 0;
}
