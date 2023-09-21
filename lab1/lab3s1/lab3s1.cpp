#include <iostream>

using namespace std;

void BuiltHanoi( int n, int startPeg, int endPeg)
{
    int buffPeg;
    if (n == 1)
    {
        cout << "Переместить диск " << n << " с " << startPeg << " на " << endPeg << endl;
        return;
    }
    buffPeg = 6 - startPeg - endPeg;
    BuiltHanoi(n - 1, startPeg, buffPeg);
    cout << "Переместить диск " << n << " с " << startPeg << " на " << endPeg << endl;
    BuiltHanoi(n - 1, buffPeg, endPeg);

}

int main()
{
    int N, k;
    setlocale(LC_ALL,"rus");
    cin >> N >> k;
    if(k != 1 && k <= 3)
        BuiltHanoi(N, 1, k);
    return 0;
}