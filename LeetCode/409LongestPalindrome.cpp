#include <iostream>
using namespace std;
int longestPalindrome(string s)
{
    int res = 0;
    int cnt[256] = {0};
    int max_odd = 0;
    for (int i = 0; i < s.size(); i++)
        cnt[s[i]]++;

    for (int i = 0; i < 256; i++)
    {
        if (cnt[i] % 2 == 0)
            res += cnt[i];
        else
        {
            res += cnt[i] - 1;
            if (cnt[i] > max_odd)
                max_odd = cnt[i];
        }
    }
    if (max_odd > 0)
        res++;
    return res;
}
int main()
{
    cout << longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
}