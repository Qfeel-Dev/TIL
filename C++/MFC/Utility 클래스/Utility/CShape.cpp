#include "pch.h"
#include "CShape.h"


CShape::CShape() {

}


CShape::~CShape() {

}
/*
CShape::CShape(const CPoint& pt, const bool& flag)
	:m_pt(pt), m_flag(flag)
{

}
*/

CShape& CShape::operator=(const CShape& sh) //*** ���ø� ���� �� ���޿� ���� ���� ���Ѻ��� ����
{
	m_polygon.Copy(sh.m_polygon);
	
	return *this;
}