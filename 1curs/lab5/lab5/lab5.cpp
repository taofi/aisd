#include <iostream>
#include <stack>
#define strl 1000

using namespace std;

bool check(char a, char b) {
    char m[] = { '[',']', '{', '}', '(', ')' };
    for (int i = 0; i < 5; i+=2) {
        if (m[i] == a && m[i + 1] == b)
            return true;
    }
    return false;
}


int main()
{
    setlocale(LC_ALL, "rus");
    stack<char> st;
    char s[strl];
    cin.getline(s, strl);
    char scob[strl];
    int scobS = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
            scob[scobS++] = s[i];
    }
    scob[scobS] = '\0';
    cout << scob << endl;
    for (int i = 0; i < strlen(scob); i++)
    {
        if (st.empty()) {
            st.push(scob[i]);
        }
        else 
        { 
            if (check(st.top(), scob[i]))
                st.pop();
            else
                st.push(scob[i]);
        }
    }
    if (st.empty())
        cout << "вернo" << endl;
    else
    {
        cout << "невернo" << endl;
    }
}