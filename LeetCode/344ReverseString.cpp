

void reverseString(vector<int> &s)
{

    reverse(s.begin(), s.end());
}
int main()
{
    vector<int> s = {1, 2, 3, 4, 5, 6};
    reverseString(s);
    for (auto x : s)
        cout << x << " ";
}