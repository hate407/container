#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int N; cout << "Give N "; cin >> N;								// N -- сумма
	int k; cout << "Give k "; cin >> k;								// k -- количество купюр
	int a[k]; cout << "Give all the a ";							// a[k] -- массив значений купюр
	for (int i = 0; i < k; i++) cin >> a[i];						// заполнение массива купюр с клавиатуры
	int res[N+1]; 
	res[0] = 0;
	cout << "\n\n";
	for (int m = 1; m <= N; m++) {									// заполнение массива количества минимальных купюр для каждой
		res[m] = 999999999;											// суммы условно невозможным значением
	}												
	
	for (int m = 1; m <= N; m++) {									// заполнение массива количества минимальных купюр значениями 
		for (int i = 0; i < k; i++) {								// для каждой суммы
			if (a[i] <= m && res[m - a[i]] + 1 < res[m]) {			// купюра a[i] является лучшей, если меньше либо равна проверяемой суммы
				res[m] = res[m - a[i]] + 1;							// и если мин. количество купюр для данной суммы будет меньше, чем в случае
			}														// невзятия данной купюры
		}
	}
	if (res[N] == 999999999) {
		cout << "Sorry, there is no way to solve";
	}	
	else {
		cout << N << " can be gifted with " << res[N] << " bills: ";// вывод результата для искомой суммы
		while (N > 0) {
			for (int i = 0; i < k; i++) {
				if (res[N - a[i]] + 1 == res[N]) {
					cout << a[i] << " ";							
					N -= a[i];
					break;
				}
			}
		}
	}
}
