#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "игра «Угадайка!» " << endl;
	bool cycle = true;
	cout << "введите промежуток в ктором хотите загадть число. От 0 до ";
	int ans;
	int top , bot = 0, mid, countHod = 1;
	cin >> top;
	int topM = top;
	while (bot < top) {
		countHod++;
		mid = ceil(bot + (top - bot) / 2);
		cout << "ваше число: " << mid << endl;
		cout << "ваш ответ: 1 - Меньше, 2 - Больше, 3 - Угадал" << endl;
		cin >> ans;
		if(ans == 1) {
			if (mid == bot + 1)
			{
				break;
			}
			else
			top = mid;
		}
		if(ans == 2) {
			if (mid == top - 1)
			{
				break;
			}
			else {
				bot = mid;
			}
		}
		if(ans == 3) {
			cycle = false;
		}
		//cout << chast << " " << sr << endl;
	}
	int max_shag = 0, gread = topM;
	while (gread != 0) {
		gread = gread / 2;
		max_shag ++;
	}
	if (countHod > max_shag)
		countHod = max_shag;
	cout << "ваше число: " << mid << endl;
	cout << "количество ходов: " << countHod << endl;
	cout << "максимальное количество ходов: " << max_shag << endl;
}