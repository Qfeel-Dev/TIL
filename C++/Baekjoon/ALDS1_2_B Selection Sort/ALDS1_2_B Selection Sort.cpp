#include <iostream>

int SelectionSort(int arr[], int n)
{
	int min_index;
	int tmp;	
	int cnt=0;

	for(int i = 0; i<n; i++)
	{
		min_index = i;
		
		for(int j =i+1; j<n; j++)
		{
			if(arr[min_index] > arr[j])
			{
				min_index = j;
			}		
		}	
		
		if(min_index != i)
		{
			cnt++;
			tmp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = tmp;
		}
	}


	for(int k=0; k<n; k++)
	{
		std::cout << arr[k] << " ";
	}

	std::cout << std::endl;
	return cnt;
}

int main(){
	
	int n;
	int tmp;
	
	std::cin >> n;
	
	int arr[n];
		
	for(int i =0; i<n; i++)
	{
		std::cin >> arr[i];	
	}
	
	std::cout << SelectionSort(arr,n);	
}
