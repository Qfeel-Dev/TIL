#include <iostream>

using namespace std;

void print_star(int floor,int size){
	for(int i =1; i<=size; i++){
		if((floor-2)%2 == 0 && (i-2)%2 == 0){//2 5 8 11 
			cout << " ";
		}

		else if(((size/3)+1 <= floor && floor <= (size/3)*2) && (size/3)+1 <= i && i <= (size/3)*2){			
			
			cout << " ";			
		}

		else{
			cout << "*";
		}
	}
	if(floor == size) return;
	else	{cout << "\n"; print_star(floor+1,size);}
}


int main(void){
	int num;

	cin >> num;
	print_star(1,num);	
}
