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
	bal infor;//�������������
	bal method;//��������� �����

};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
double LineSearc�2(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "������ ������� �������� N: "; cin >> N;
	Student* p = new Student[N];
	double proc, count;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���� ������ �� �������� ��������," << endl;
		cout << " ��� ������� ��� ������ 4" << endl;
		cout << " [4] - ������ �������� �� ������� ��� �����" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "������� ��������, ��� ������� ��� ������ 4:" << endl;
			cout << proc << "%" << endl;
			break;
		case 4:
			count = LineSearc�2(p, N);
			cout << "ʳ������ �������� �� ������� ��� �����:" << endl;
			cout << count << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int kurs, specs, fizikas, maths, infors, methods, pedogogiks, spec;
	for (int i = 0; i < N; i++)
	{
		cout << "��������� No " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync();
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ������������: "; cin >> specs; p[i].spec = (Spec)specs;
		cout << " ���� "; cin >> kurs; p[i].kurs = (Kurs)kurs;
		cout << " ��� � ������(1-5) "; cin >> fizikas; p[i].fizika = (bal)fizikas;
		cout << " ��� � ����������(1-5) "; cin >> maths; p[i].math = (bal)maths;
		cout << " ��� � �����������(1-5) "; cin >> infors; p[i].infor = (bal)infors;
		cout << " ��� � ��������� ������ (1-5) "; cin >> methods; p[i].method = (bal)methods;
		p[i].spec = (Spec)spec;
		switch (p[i].spec)
		{
		case ME:
			cout << " ��� � ��������� (1-5) "; cin >> pedogogiks; p[i].pedagogika = (bal)pedogogiks;
			break;
		case MF:
			cout << " ��� � ��������� (1-5) "; cin >> pedogogiks; p[i].pedagogika = (bal)pedogogiks;
		case FI:
			cout << " ��� � ��������� (1-5) "; cin >> pedogogiks; p[i].pedagogika = (bal)pedogogiks;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "===================================================================================================================="
		<< endl;
	cout << "| No | �������   | �������. | ���� | ��� � ������ | ��� � ���������� |��� � �����. | ��� � �c. ��.|��� � ���.|"
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
	cout << "������� ���������, ��� �������� ��� ������ 4: ";
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

double LineSearc�2(Student* p, const int N)
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
