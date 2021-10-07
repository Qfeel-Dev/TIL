#include <iostream>

using namespace std;

class Point{
	int xpos,ypos;
	
	public :
		void Init(int x, int y){
			xpos = x;
			ypos = y;					
		}
		
		void ShowPointInfo() const{
			cout << xpos<<","<<ypos<<endl;			
		}

};

class Circle{
	Point pos;
	int radius;
	
	public :
		void Init(int x, int y,int r){
			pos.Init(x,y);
			radius =r;					
		}
		
		void ShowPointInfo() const{
			pos.ShowPointInfo();
			cout << radius<<endl;	
		}
};

class Ring{
	Circle c1;
	Circle c2;	
	
	public :
		void Init(int x1, int y1,int r1,int x2, int y2,int r2){
			c1.Init(x1,y1,r1);
			c2.Init(x2,y2,r2);			
		}
		
		void ShowPointInfo() const{
			c1.ShowPointInfo();
			c2.ShowPointInfo();
		}		
};


int main(){
	Ring ring;
	ring.Init(1,1,3,2,2,9);
	ring.ShowPointInfo();
	return 0;


}

