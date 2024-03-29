// TempObject.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//제작자 코드
class CTestData
{
public:
	CTestData(int nParam, char *pszName)
		: m_nData(nParam), m_pszName(pszName)
	{
		cout << "CTestData(int): " << m_pszName << endl;
	}

	~CTestData()
	{
		cout << "~CTestData(): " << m_pszName << endl;
	}

	CTestData(const CTestData &rhs)
		: m_nData(rhs.m_nData), m_pszName(rhs.m_pszName)
	{
		cout << "CTestData(const CTestData &): " << m_pszName  << endl;
	}

	CTestData& operator=(const CTestData &rhs)
	{
		//값은 변경하지만 이름(m_pszName)은 그대로 둔다.
		m_nData = rhs.m_nData;
		return *this;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
	char *m_pszName = nullptr;	//변수명을 저장하기 위한 멤버.
};

//CTestData 객체를 반환하는 함수이다.
CTestData TestFunc(int nParam)
{
	//CTestData 클래스 인스턴스인 a는 지역변수다.
	//따라서 함수가 반환하면 소멸한다.
	CTestData a(nParam, "a");
	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Before*****" << endl;
	//이름 없는 임시 객체는 _tmain() 함수가 반환한 후 소멸한다.
	CTestData &rData = TestFunc(10);
	cout << "*****After*****" << endl;
	return 0;
}

