// MyNode.cpp: implementation of the CMyNode class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "MyNode.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyNode::CMyNode()
{
	m_pNext = NULL;
	m_pszPriKey = NULL;
}

CMyNode::~CMyNode()
{

}

char* CMyNode::GetPriKey()
{
	return m_pszPriKey;
}

void CMyNode::PrintData()
{

}
