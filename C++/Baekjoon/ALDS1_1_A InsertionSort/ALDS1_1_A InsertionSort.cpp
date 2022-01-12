#include <iostream>

int main(){
	
	int n;
	int tmp;
		
	std::cin >> n;
	
	int arr[n];
	
	
	for(int i =0; i<n; i++)
	{
		std::cin >> arr[i];	
	}
	
	for(int k=0; k<n; k++)
	{
		std::cout << arr[k] << " ";
	}
	std::cout << std::endl;
/*

	for(int i =1; i<n; i++)
	{
		for(int j =0; j<i; j++)
		{
			if(arr[i] > arr[j])
			{
				tmp = arr[i];
				
				for(int k=i-1; k>j; k++)
				{
					arr[k];
					
				
				}
			
			}
		}	
	}
*/
	for(int i =1; i<n; i++)
	{
		for(int j =i-1; j>=0; j--)
		{
			if(arr[i] < arr[j])
			{
				arr[j+1] = arr[j] 
				arr[j]


			}
		
		}	
		
						
		for(int k=0; k<n; k++)
		{
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
	}
	
	

}
