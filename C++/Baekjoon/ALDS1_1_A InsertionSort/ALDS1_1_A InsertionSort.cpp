#include <iostream>

int main(){
	
	int n;
	int tmp;
	int j;
	
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


	for(int i=1; i<n; i++)
	{
		tmp = arr[i];
		j = i-1;	
		while(j>=0 && tmp < arr[j]){
			
			arr[j+1] = arr[j];			
			j--;									
		}
		arr[j+1] = tmp;
		
		for(int k=0; k<n; k++)
		{
			std::cout << arr[k] << " ";
		}
		if(i!= n-1)std::cout << std::endl;
	}
	/*
	삽입 정렬 정리  
	최적의 경우 : O(n) - (어느정도 정렬이 잡혀있는 경우)
	최악의 경우 : O(N^2)-(내림차순으로 정렬된 경우) 
	- 정렬된 부분과 비정렬 부분을 나누어서 정렬된 부분에서의 끝의 자리와 계속 비교해 나가면서 자리를 옮기는 정렬 방식 
	
	*/

}
