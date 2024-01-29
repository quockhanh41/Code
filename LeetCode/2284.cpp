#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int countWord(string s)
{
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            count++;
    }
    return count + 1;
}
string largestWordCount(vector<string> &messages, vector<string> &senders)
{
    int max = -1;
    string res = "A";
    map<string, int> m;
    for (int i = 0; i < senders.size(); i++)
    {
        m[senders[i]] += countWord(messages[i]);
    }
    for (auto x : m)
        if (x.second > max)
            max = x.second;
    for (auto x : m)
    {
        if (x.second == max && x.first > res)
            res = x.first;
    }
    return res;
}
int main()
{
    vector<string> messages = {"MRC", "x ht F", "c e", "P", "mZ p p", "SD", "vU MM I", "y xX C r n", "nBD", "V U S", "wz iB X", "RU fa x s O", "PW xh U ZL", "o IT T bI th fk", "DB u hN zJ ia", "V k w ub C", "Mn Pg s", "eL L C", "GO z", "F XU", "LA C HM E cr hEp", "Xx V PC w aO l k OU", "j Fy Z oU rE dm", "D r i n k d w Jm u", "V fx soF", "SD cD", "B t", "b jB he", "O tv aPS", "Lb f N KfN", "O x FO Ea mY pu E V", "M w L ubA", "YO J QFP", "i mg jm s", "TT q zD US BQ X a", "Om R kJ JF Ek", "jk os p mb h GY", "h R", "YF Oj Nw a V Qca", "e sB t l F Wb", "wa Xe xC Umh", "ot r", "BU Mb w P O e rw B H", "b JS", "Uw kD wJ EF", "Q M E bd S", "Cb ga BFI", "O E f Kb", "rW x b m r e T g", "wR aE AV kM", "i", "ex x", "c J VV h pi w Gr u a", "s q nx nW GRa", "r H", "M Or", "Y v f", "QH", "FL T gR oC Ec", "BI vB sz Ib pW hj", "G", "Mke", "g nR tkP"};
    vector<string> senders = {"uFZ", "CH", "uFZ", "V", "uFZ", "Yn", "Yn", "V", "uFZ", "YUvIabdxz", "CH", "HuySXDI", "Yn", "wAcTIEIwe", "wAcTIEIwe", "uFZ", "HuySXDI", "CH", "V", "YUvIabdxz", "wAcTIEIwe", "iqOh", "wAcTIEIwe", "Yn", "Yn", "wAcTIEIwe", "wAcTIEIwe", "V", "mfL", "CH", "iqOh", "CH", "V", "Yn", "uFZ", "YUvIabdxz", "V", "HuySXDI", "wAcTIEIwe", "YUvIabdxz", "YUvIabdxz", "iqOh", "YUvIabdxz", "iqOh", "V", "wAcTIEIwe", "HuySXDI", "YUvIabdxz", "uFZ", "iqOh", "CH", "CH", "YUvIabdxz", "uFZ", "Yn", "V", "YUvIabdxz", "HuySXDI", "CH", "V", "iqOh", "HuySXDI", "wAcTIEIwe"};
    cout << largestWordCount(messages, senders);
}