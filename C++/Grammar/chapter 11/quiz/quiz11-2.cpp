#include <iostream>

using namespace std;



class BoundCheck2DIntArray
{
	private:
		int **arr2d;
		int x_len,y_len;
		
	public:
		BoundCheck2DIntArray(int x=0, int y=0)
		:x_len(x),y_len(y)
		{
			arr2d = new int*[x];
			for(int i=0; i<y; i++)
			{
				arr2d[i] = new int[y];			
			}		
		}
		
		int* operator[](int idx)//x배열  
		{
			if(idx <0 || idx >= x_len)
			{
				cout<<"out of range";
				exit(1);			
			}		
			
			return arr2d[idx];
		}
		
		int* operator[](int* idx)//y배열  
		{
			if(idx <0 || idx >= y_len)
			{
				cout<<"out of range";
				exit(1);			
			}		
			
			return arr2d[idx];
		}


};


int main(void){

}
