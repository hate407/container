#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int N; cout << "Give N "; cin >> N;								// N -- �����
	int k; cout << "Give k "; cin >> k;								// k -- ���������� �����
	int a[k]; cout << "Give all the a ";							// a[k] -- ������ �������� �����
	for (int i = 0; i < k; i++) cin >> a[i];						// ���������� ������� ����� � ����������
	int res[N+1]; 
	res[0] = 0;
	cout << "\n\n";
	for (int m = 1; m <= N; m++) {									// ���������� ������� ���������� ����������� ����� ��� ������
		res[m] = 999999999;											// ����� ������� ����������� ���������
	}												
	
	for (int m = 1; m <= N; m++) {									// ���������� ������� ���������� ����������� ����� ���������� 
		for (int i = 0; i < k; i++) {								// ��� ������ �����
			if (a[i] <= m && res[m - a[i]] + 1 < res[m]) {			// ������ a[i] �������� ������, ���� ������ ���� ����� ����������� �����
				res[m] = res[m - a[i]] + 1;							// � ���� ���. ���������� ����� ��� ������ ����� ����� ������, ��� � ������
			}														// �������� ������ ������
		}
	}
	if (res[N] == 999999999) {
		cout << "Sorry, there is no way to solve";
	}	
	else {
		cout << N << " can be gifted with " << res[N] << " bills: ";// ����� ���������� ��� ������� �����
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
