#pragma once
class CShape
{
public:

	//bool m_flag;
	//CPoint m_pt;
	CArray<CPoint, CPoint&> m_polygon;//template? - 1����
	
	CShape& operator=(const CShape& sh);

	CShape();
	//CShape(const CPoint& pt ,const bool& flag);
	~CShape();


};

