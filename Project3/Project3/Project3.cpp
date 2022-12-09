#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;
enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { ME, MF, FI, KN, IK, };
enum bal { one = 1, two, three, four, five };

struct Student
{
	string prizv;
	Kurs kurs;
	Spec spec;
	union
	{
		bal infor;
	};
	union
	{
		bal pedagogika;
	};
	union
	{
		bal method;
	};
	bal fizika;
	bal math;

};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
int BinSearch(Student* p, const int N, const string prizv, const Kurs kurs);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, ikurs, found, ispec;
	cout << "������ ������� �������� N: "; cin >> N;
	Student* p = new Student[N];
	Kurs kurs;
	string prizv;
	double proc, count;
	int menuItem;
	do {
		cout << "\n\n\n";
		cout << "������� ��:\n\n";
		cout << " [1] - �������� ����� � ���������\n";
		cout << " [2] - ���� ����� �� �����\n";
		cout << " [3] - ������� ������������� �����\n";
		cout << " [4] - ������� ����� ���������� �� ������� �� ��������\n";
		cout << " [5] - �������� ������������� �� ���� �����\n";
		cout << " [0] - ����� �� ���������� ������ ��������\n\n";
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
			Sort(p, N);
			break;
		case 4:
			cout << "������ ����� ������:" << endl;
			cout << " ����: ";
			cin >> ikurs;
			cout << " ������������: ";
			cin >> ispec;
			kurs = (Kurs)ikurs;
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << " �������: "; getline(cin, prizv);
			cout << endl;
			if ((found = BinSearch(p, N, prizv, kurs)) != -1)
				cout << "�������� �������� � ������� " << found + 1 << endl;
			else
				cout << "�������� �������� �� ��������" << endl;
			break;
		case 5:
			PrintIndexSorted(p, IndexSort(p, N), N);
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
	int kurs, specs, fizikas, maths, infors, pedogogiks, methods;
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
		p[i].spec = (Spec)specs;
		switch (p[i].spec)
		{
		case 1:
			cout << " ��� � ��������� (1-5) "; cin >> pedogogiks; p[i].pedagogika = (bal)pedogogiks;
			break;
		case 2:
			cout << " ��� � ����������� (1-5) "; cin >> infors; p[i].infor = (bal)infors;
		case 3:
			cout << " ��� � ������������ ������ (1-5) "; cin >> methods; p[i].method = (bal)methods;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "==================================================================================================================="
		<< endl;
	cout << "| No | �������      | �������. | ���� | ��� � ������ |  ��� � ���������� |  ��� � ����������� | ���������� ������"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(8) << right << p[i].spec << " "
			<< "| " << setw(5) << left << p[1].kurs
			<< "| " << setw(12) << right << p[i].fizika << " "
			<< "| " << setw(18) << right << p[i].math
			<< "| " << setw(10) << right << p[i].infor << " "
			<< "| " << setw(10) << right << p[i].method
			<< endl;
	}
	cout << "==========================================================================================="
		<< endl;
	cout << endl;
}
void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].spec > p[i1 + 1].spec
				||
				(p[i1].spec == p[i1 + 1].spec &&
					p[i1].prizv > p[i1 + 1].prizv)))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
int BinSearch(Student* p, const int N, const string prizv, const Kurs kurs)
{ // ������� ������ ���������� �������� ��� -1, ���� ������� ������� �������
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].prizv == prizv && p[m].kurs == kurs)
			return m;
		if ((p[m].kurs < kurs)
			||
			(p[m].kurs == kurs &&
				p[m].prizv < prizv))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}
int* IndexSort(Student* p, const int N)
{ // ������������� ����� ������� ��� ���������� ���������� ������
//
// int i, j, value;
// for (i = 1; i < length; i++) {
// value = a[i];
// for (j = i - 1; j >= 0 && a[j] > value; j--) {
// a[j + 1] = a[j];
// }
// a[j + 1] = value;
// }
	int* I = new int[N]; // �������� ��������� �����
	for (int i = 0; i < N; i++)
		I[i] = i; // ��������� ���� ����������� ������
	int i, j, value; // �������� ��������� ����� �������
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((p[I[j]].spec > p[value].spec) ||
				(p[I[j]].spec == p[value].spec &&
					p[I[j]].prizv > p[value].prizv));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}
void PrintIndexSorted(Student* p, int* I, const int N)
{ // ��������� ������� Print(), ��� ������ ��������� p[i]...
// ������������� ������ �� ��������� ���������� ������ �: p[I[i]]...
	cout << "==================================================================================================================="
		<< endl;
	cout << "| No | �������      | �������. | ���� | ��� � ������ |  ��� � ���������� |  ��� � ����������� | ���������� ������"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(8) << right << p[i].spec << " "
			<< "| " << setw(5) << left << p[1].kurs
			<< "| " << setw(12) << right << p[i].fizika << " "
			<< "| " << setw(18) << right << p[i].math
			<< "| " << setw(10) << right << p[i].infor << " "
			<< "| " << setw(10) << right << p[i].method
			<< endl;
		cout << endl;
	}
	cout << "===================================================================================================================="
		<< endl;
	cout << endl;
}