#include <iostream>

int print_star(int n) 
{
	for(int i =0; i<n; i++)
	{
		if((n+1)%3 == 0 || n==0) std::cout << "*";	
		else{
		
		}
	}

	if(n == 0) return 0;
}


int main()
{
	print_star(3);
	/*
	***
	* *
	***	
	*/ 
	

}//0,2 6 8 18,20 24 26 =  
//1 3 7 9 19 21 25 27
// 1 7 19 25
// 3 9 21 27
//3 4 9 10 12 13
