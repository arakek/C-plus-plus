#include <iostream>

using namespace std;

class EightQueens {
protected:
	int count_rez;
	int *x_line;
	char **board;
	int n_x;
	int n_y;
	char figure;
public:
	EightQueens()
	{
		cout << "В случае прямоугольного поля ширина по X должна превышать значение по Y!" << endl;
		cout << "В случае квадратного поля размеры должна совпадать." << endl;
		cout << "Введите размер поля по X: "; cin >> n_x;
		cout << "Введите размер поля по Y: "; cin >> n_y;
		if (n_y > n_x)
		{
			cout << "Некорректный ввод данных" << endl;
			exit(1);
		}
		cout << "Какую фигуру расставить?\nQ - Ферзь. R - Ладья." << endl;
		cin >> figure;
		if (figure != 'Q') 
			if (figure != 'R') 
						{
							cout << "Ошибка ввода!" << endl;
							exit(1);
						}
		if (figure == 'Q')
			if (n_x == 2 || n_x == 3)
			{
				cout << "Решения для поля " << n_x << "x" << n_x << " не существует!" << endl;
				exit(0);
			}
		x_line = new int[n_y];
		board = new char*[n_y]; //строки
		for (int i = 1; i <= n_y; i++)
		{
			board[i] = new char[n_x];
		}
		count_rez = 0;
		cout << "Поиск решений для поля " << n_x << "x" << n_y << endl;
	}

	~EightQueens()
	{
		for (int i = 1; i <= n_y; i++)
		{
			delete[] board[i];
		}
		delete[] x_line;
	}
	bool Set(int *x, int k)
	{
		for (int i = 1; i < k; i++)
		{
			if (figure == 'Q')
			{
				if (x[i] == x[k] || i + x[i] == k + x[k] || i - x[i] == k - x[k])
				{
					return false;
				}
			}
			if (figure == 'R')
			{
				if (x[i] == x[k])
				{
					return false;
				}
			}
		}
		return true;
	}
	void Run()
	{
		int k = 1;
		x_line[k] = 0;
		while (k != 0)
		{
			x_line[k]++;
			while ((!Set(x_line, k)) && (x_line[k] <= n_x))
			{
				x_line[k]++;
			}
			if (x_line[1] == n_y + 1)
			{
				exit(0);
			}
			if (x_line[k] <= n_x)
			{
				if (k == n_y)
				{
					count_rez++;
					cout << "Решение " << count_rez << ":\n";
					ShowRez(x_line);
					cout << endl;
				}
				else
				{
					k++;
					x_line[k] = 0;
				}
			}
			else
			{
				k--;
			}
		}
	}
	void ShowRez(int *x)
	{
		for (int i = 1; i <= n_y; i++)
		{
			for (int j = 1; j <= n_x; j++)
			{
				board[i][j] = 'O';
			}
		}
		for (int i = 1; i <= n_y; i++)
		{
			board[i][x[i]] = 'X';
		}
		for (int i = 1; i <= n_y; i++)
		{
			for (int j = 1; j <= n_x; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	EightQueens QR;
	QR.Run();
	return 0;
}

