#include <iostream> 

using namespace std;

int main(void)
{
	int R[200000];
	int num;
	int max = -1000000000;			 
	int min = 1000000000;			 
	
	std::cin >> num;
	
	for(int i =0; i< num; i++)
	{
		std::cin >> R[i];	
	}

	/*O(n^2) 
	for(int i =num; i>=0; i--)
	{
		for(int j=0; j<i; j++)
		{
			if(R[i] - R[j] > max) max = R[i] - R[j];		
		}	
	}
	*/
	
	//O(n)
	for(int i=0; i<num; i++)
	{
		if(R[i] - min > max) max = R[i] - min;
		if(R[i] <= min) min = R[i];	
	}
	
	
	std::cout << max;	
	
}
