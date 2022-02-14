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

CShape& CShape::operator=(const CShape& sh) //*** 템플릿 간의 값 전달에 따른 오류 약한복사 오류
{
	m_polygon.Copy(sh.m_polygon);
	
	return *this;
}