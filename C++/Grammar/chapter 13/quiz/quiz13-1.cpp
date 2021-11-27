#include <iostream>



template <typename T>
T SwapDate(T* num1, T* num2)
{
	T tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}


class Point
{
	private:
		int xpos,ypos;
	public:	
		Point(int x=0, int y=0) : xpos(x), ypos(y)
		{}
		
		void ShowPosition() const
		{
			std::cout<<xpos<<" "<<ypos<<std::endl;
		}

};



int main()
{
	Point p1(10,20);
	Point p2(30,40);
	
	p1.ShowPosition();
	p2.ShowPosition();

	SwapDate(&p1,&p2);

	p1.ShowPosition();
	p2.ShowPosition();
}
