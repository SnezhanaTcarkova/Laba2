#include <iostream>
using namespace std;


class Mass
{
	int  *mas;
	int n;

public:
	Mass(int n1=0); //параметр n1
	Mass(const Mass&);
	int Masper(Mass mas1, Mass mas2);
	int Masob(Mass mas1, Mass mas2);
	void Vvod();
	void Vivod();
	~Mass();
};
//конструктор 
Mass::Mass(int n1)
{
	n = n1;
	mas = new int[n];
}

//конструктор копирования
Mass::Mass(const Mass& mas1)
{
	n = mas1.n;
	mas = new int[n];
	for (int i = 0; i < n; i++)
	mas[i] = mas1.mas[i];

}




Mass::~Mass()
{	
	delete[] mas;
}


void Mass::Vvod()
{
	
	for (int i = 0; i < n; i++)

		cin >> mas[i];

}


void Mass::Vivod()
{
	for (int i = 0; i < n; i++)
		cout << "Элемент "<<i<<":  "<< mas[i] << endl;

}


int Mass::Masper(Mass mas1,Mass mas2)
{
	
	bool flag=false;
	int i=0, j=0,k=0;
	int buf = mas1.mas[0];
	for (i = 0; i < n; i++)
	{
		if (i != 0 && buf == mas1.mas[i])
		{
			buf = mas1.mas[i];
			continue;
		}
		for (j = 0; j < n; j++)
		{
			if (mas1.mas[i] == mas2.mas[j])
			{
				flag = true;
				cout << "Пересечение " << mas1.mas[i] << endl;
				break;
				
				
			}
			
		}
	}	
	
	if (flag == false)
	{
		cout << "Нет чисел пересечения" << endl;
		
	}	
	return 0;
	
}

int Mass::Masob(Mass mas1, Mass mas2)
{

	int i = 0, j = 0, k = 0, k1 = n * 2;
	int* mas4 = new int[k1];
	int buf = 0;

	mas4 = mas1.mas;
	cout <<"Размер массива "<< k1 << endl;
	for (k = 0; k < n; k++)
	{	
		for (j = 0; j < n; j++)
		{	
		mas4[n + j] = mas2.mas[j];
	
		}

	}
	for (k = 0; k < k1; k++)
	{
		cout <<"Элемент: "<<k<<"="<< mas4[k] << endl;
	}

	// иногда при выполнении данного цикла происходит ошибка
	for (k = 0; k < k1; k++)
	{
		for (j = k + 1; j < k1; j++)
		{
			
			if (mas4[k] == mas4[j])
			{
				buf = 1;

				cout << "Повторяющиеся числа" << mas4[k] << endl;
				for (i = j; i < k1 - 1; i++)
				{
					mas4[i] = mas4[i + 1];
					
				}
				k1--;
			}
			if (buf==0)
			{
				//cout << "Нет повторяющихся значений";
				
			}
		
		}
	}

	for (k = 0; k < k1; k++)
	{
		cout << "Элемент: " << k << "=" << mas4[k] << endl;
	}
	return 0;
}



int main()
{
	
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива" << endl;
	cin >> n;
	Mass mas1(n);
	cout << "Введите значения первого массива" << endl;
	mas1.Vvod();
	mas1.Vivod();

	Mass mas2 = mas1;
	cout << "Введите значения второго массива" << endl;
	mas2.Vvod();
	mas2.Vivod();

	Mass mas3 = mas1;
	mas3.Masper(mas1,mas2);
	
	Mass mas4=mas1;
	mas4.Masob(mas1,mas2);
	cout << "Проверка";

	return 0;
}

