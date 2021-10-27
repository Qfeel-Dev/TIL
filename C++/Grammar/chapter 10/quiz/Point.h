#include <iostream>

using namespace std;

class Point{
	private:
		int xpos;
		int ypos;
		
	public:
		Point(int xp, int yp):xpos(xp),ypos(yp)
		{}
		
		friend Point operator-(const Point& pos1,const Point& pos2)
		
		/*
		Point operator-(const Point& pos1,const Point& pos2)
		{
			Point pos(pos1.xpos-pos2.xpos,pos1.ypos-pos2.ypos);
			return pos;
		}
				
		Point operator-(Point & p)
		{
			Point pos(xpos-p.xpos,ypos-p.ypos);
			return pos;
		}
		*/

		
		void ShowPoint() const
		{
			cout << xpos << "," << ypos << endl;
		}

};

Point operator-(const Point& pos1,const Point& pos2)
{
	Point pos(pos1.xpos-pos2.xpos,pos1.ypos-pos2.ypos);
	return pos;
}		

