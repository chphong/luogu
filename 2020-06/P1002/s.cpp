#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Cor {
    int x;
    int y;
    Cor(int x, int y) : x(x), y(y) {}
    bool operator==(Cor o) {
        return x==o.x && y==o.y;
    }
};

// 如果cur是马控制点，那么返回false，否则true
bool check(Cor cur, Cor h) {
    if ((cur.x==h.x || cur.y==h.y) && !(cur==h)) return true;
    int dis = abs(cur.x-h.x) + abs(cur.y-h.y);
    return dis!=3;
}

int main(int argc, char const *argv[])
{
    int bx, by, hx, hy;
    cin >> bx >> by>> hx >> hy;

    int res = 0;

    Cor B = Cor(bx, by);
    Cor H = Cor(hx, hy);
    queue<Cor*> q;
    Cor* a = new Cor(0, 0);
    q.push(a);
    while (!q.empty())
    {
        Cor* c = q.front();
        q.pop();
        if (*c == B) {
            res++;
        } else {
            Cor* bottom = new Cor(c->x+1, c->y);
            Cor* right = new Cor(c->x, c->y+1);
            if (bottom->x <= bx && check(*bottom, H)) {
                // 没有出界
                q.push(bottom);
            } 
            if (right->y <= by && check(*bottom, H)) {
                q.push(right);
            }
        }
        delete c;
    }
    cout << res << endl;

    return 0;
}
