// FunctionAndClass.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData(int nParam) : m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData &rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	//읽기 전용인 상수형 메서드.
	int GetData() const { return m_nData; }
	//멤버에 쓰기를 시도하는 메서드.
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

//매개변수가 CTestData 클래스 형식이므로 복사 생성자가 호출된다.
void TestFunc(CTestData param)
{
	cout << "TestFunc()" << endl;
	//피호출자 함수에서 매개변수 인스턴스의 값을 변경한다.
	param.SetData(20);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	CTestData a(10);
	TestFunc(a);
	//함수 호출 후 a의 값을 출력한다.
	cout << "a: " << a.GetData() << endl;
	cout << "******End******" << endl;
	return 0;
}
