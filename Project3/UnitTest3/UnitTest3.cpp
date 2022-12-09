#include "pch.h"
#include "CppUnitTest.h"
#include "../Project3/Project3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 2;
			Student* p = new Student[N];

			void Create(Student * p, const int N);
			void Print(Student * p, const int N);
			void Sort(Student * p, const int N);
			int BinSearch(Student * p, const int N, const string prizv, const Kurs kurs);
			int* IndexSort(Student * p, const int N);
			void PrintIndexSorted(Student * p, int* I, const int N);
		}
	};
}
