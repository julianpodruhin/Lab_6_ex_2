#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeArrayToFile(int arr[], int size, string filename, string header);

int main()
{
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

	writeArrayToFile(a, N, "arrays.txt", "Исходный массив");

	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}

	writeArrayToFile(a, N, "arrays.txt", "Отсортированный массив");

	return 0;
}

void writeArrayToFile(int arr[], int size, string filename, string header)
{
	ofstream fout(filename, std::ios_base::app);
	if (fout.is_open())
	{
		fout << header << ": ";
		for (int i = 0; i < size; i++)
			fout << arr[i] << ' ';
		fout << endl;

		fout.close();
		cout << "Массив записан в файл " << filename << endl;
	}
	else
		cout << "Ошибка открытия файла " << filename << endl;
}
