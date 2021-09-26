#include <iostream>

typedef struct __Point{
	int xpos;
	int ypos;

} Point;

Point& PntAdder(const Point &p1,const Point &p2){
	Point *result = new Point;
	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;
	
	return *result;
} 


int main(){
	Point *stp = new Point;		
	stp->xpos=10;
	stp->ypos=5;
	
	Point *des = new Point;
	des->xpos=2;
	des->ypos=2;

	Point &acc = PntAdder(*stp,*des);
	std::cout << acc.xpos<<std::endl;
	std::cout << acc.ypos;

	delete stp;
	delete des;
	delete &acc;
}
