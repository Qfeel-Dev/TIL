#include <iostream>

using namespace std;


struct Pos{
	int x;
	int y;
};

int main()
{
	
	int num;
	Pos tmp;
	
	cin >> num;

	Pos dot[num];

	for(int i = 0; i<num; i++)
	{
		cin >> dot[i].x >> dot[i].y;
	}

	for(int i = 0; i<num; i++){
		for(int j = i+1; j<num; j++){
			if(dot[i].x > dot[j].x)	{
				tmp = dot[i];
				dot[i] = dot[j];
				dot[j] = tmp;
			}
			
			else if(dot[i].x == dot[j].x){
				if(dot[i].y > dot[j].y ){
					tmp = dot[i];
					dot[i] = dot[j];
					dot[j] = tmp;
				}
			}
		}
	}
	
	for(int i = 0; i<num; i++)
	{
		cout << dot[i].x << " " << dot[i].y;
		if(i != num -1)  cout << endl;
	}
}
