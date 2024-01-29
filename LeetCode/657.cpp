#include <iostream>
#include <vector>
using namespace std;
bool judgeCircle(string moves)
{
    int x = 0, y = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        if (moves[i] == 'U')
            y++;
        else if (moves[i] == 'D')
            y--;
        else if (moves[i] == 'L')
            x--;
        else
            x++;
    }
    return (x == 0 && y == 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}