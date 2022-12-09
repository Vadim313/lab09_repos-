#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[101];
			char* dest1 = new char[151];
			dest1[0] = '\0';
			char* dest2;
			dest2 = Change(dest1, str, dest1, 0);
			Count(str, 1);
		}
	};
}
