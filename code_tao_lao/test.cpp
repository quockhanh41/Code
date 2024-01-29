#include <iostream>
#include <cstring>
using namespace std;

struct Team
{
    char name[41];
    int like;
    int cmt;
    int share;
};

void rerange(Team t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[j].like + 2 * t[j].cmt + 3 * t[j].share > t[i].like + 2 * t[i].cmt + 3 * t[i].share)
                swap(t[i], t[j]);
        }
    }
}

int main()
{
    Team t[100];
    int n = 0;

    while (1)
    {
        cout << "Name: ";
        cin.ignore();
        cin.getline(t[n].name, 41);

        if (strcmp(t[n].name, "000") == 0)
        {
            break;
        }

        cout << "Like: ";
        cin >> t[n].like;

        cout << "Comment: ";
        cin >> t[n].cmt;

        cout << "Share: ";
        cin >> t[n].share;

        n++;
    }

    rerange(t, n);

    // In ra tên của top 3 đội
    for (int i = 0; i < min(3, n); i++)
    {
        cout << t[i].name << " " << endl;
    }

    return 0;
}
