#include <iostream>
#include <vector>
using namespace std;
bool reachingPoints(int sx, int sy, int tx, int ty)
{
    // cout << sx << " " << sy << " " << tx << " " << ty << endl;
    if (sx > tx || sy > ty)
        return 0;
    if (sx == tx && sy == ty)
        return 1;
    return reachingPoints(sx + sy, sy, tx, ty) || reachingPoints(sx, sx + sy, tx, ty);
}
int main()
{
    cout << reachingPoints(1, 1, 2, 2);

    return 0;
}