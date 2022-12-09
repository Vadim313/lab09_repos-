#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;
enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { ME = 1, MF, FI, KN, IK, };
enum bal { one = 1, two, three, four, five };

struct Student
{
	string prizv;
	Kurs kurs;
	Spec spec;
	union
	{
		bal pedagogika;
	};
	bal fizika;
	bal math;
	bal infor;//програмування
	bal method;//чисельний метод

};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
double LineSearcр2(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть кількість Студентів N: "; cin >> N;
	Student* p = new Student[N];
	double proc, count;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - вивід прізвищ та проценту студентів," << endl;
		cout << " чий середній бал менший 4" << endl;
		cout << " [4] - кількіст студентів які вчаться без трійок" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			proc = LineSearch(p, N);
			cout << "Процент студентів, чий середній бал менший 4:" << endl;
			cout << proc << "%" << endl;
			break;
		case 4:
			count = LineSearcр2(p, N);
			cout << "Кількість студентів які вчаться без трійок:" << endl;
			cout << count << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int kurs, specs, fizikas, maths, infors, methods, pedogogiks, spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Працівник No " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync();
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " спеціальність: "; cin >> specs; p[i].spec = (Spec)specs;
		cout << " курс "; cin >> kurs; p[i].kurs = (Kurs)kurs;
		cout << " бал з фізики(1-5) "; cin >> fizikas; p[i].fizika = (bal)fizikas;
		cout << " бал з математики(1-5) "; cin >> maths; p[i].math = (bal)maths;
		cout << " бал з інформатики(1-5) "; cin >> infors; p[i].infor = (bal)infors;
		cout << " бал з чисельних методів (1-5) "; cin >> methods; p[i].method = (bal)methods;
		p[i].spec = (Spec)spec;
		switch (p[i].spec)
		{
		case ME:
			cout << " бал з педагогіки (1-5) "; cin >> pedogogiks; p[i].pedagogika = (bal)pedogogiks;
			break;
		case MF:
			cout << " бал з педагогіки (1-5) "; cin >> pedogogiks; p[i].pedagogika = (bal)pedogogiks;
		case FI:
			cout << " бал з педагогіки (1-5) "; cin >> pedogogiks; p[i].pedagogika = (bal)pedogogiks;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "===================================================================================================================="
		<< endl;
	cout << "| No | Прізвище   | Спеціал. | Курс | бал з фізики | бал з математики |бал з інфор. | бал з чc. мт.|бал з пед.|"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(8) << right << p[i].spec << " "
			<< "| " << setw(5) << left << p[1].kurs
			<< "| " << setw(10) << right << p[i].fizika << " "
			<< "| " << setw(18) << right << p[i].math
			<< "| " << setw(10) << right << p[i].infor << " "
			<< "| " << setw(14) << right << p[i].method;
			if (p[i].spec == ME || p[i].spec == MF || p[i].spec == FI)
			{
				cout << "| " << setw(8) << right << p[i].pedagogika << " " << endl;
			}
			
	}
	cout << "====================================================================================================================="
		<< endl;
	cout << endl;
}

double LineSearch(Student* p, const int N)
{
	cout << "Прізвища студентыв, чий середный бал менший 4: ";
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		n++;
		if (((p[i].fizika + p[i].math + p[i].infor + p[i].method) / 4) < 4) {
			k++;
			cout << setw(3) << right << k
				<< " " << p[i].prizv << endl;
		}

	}
	return 100.0 * k / n;
}

double LineSearcр2(Student* p, const int N)
{

	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if ((p[i].fizika > 3) && (p[i].math > 3) && (p[i].infor > 3) && (p[i].method > 3)) {
			k++;
		}
	}
	return k;
}
