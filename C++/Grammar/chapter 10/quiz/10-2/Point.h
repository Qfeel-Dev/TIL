#include <iostream>

using namespace std;

class Point{
	private:
		int xpos;
		int ypos;
		
	public:
		Point(int xp, int yp):xpos(xp),ypos(yp)
		{}
		
		void ShowPoint() const
		{
			cout << xpos << "," << ypos << endl;
		}
		
		Point& operator-()
		{
			Point ref(this->xpos,this->ypos);
			
			ref.xpos = this->xpos*-1;
			ref.ypos = this->ypos*-1;
			return ref;		
		}
};

