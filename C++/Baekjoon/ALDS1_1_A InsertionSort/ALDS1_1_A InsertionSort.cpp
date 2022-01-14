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
	���� ���� ����  
	������ ��� : O(n) - (������� ������ �����ִ� ���)
	�־��� ��� : O(N^2)-(������������ ���ĵ� ���) 
	- ���ĵ� �κа� ������ �κ��� ����� ���ĵ� �κп����� ���� �ڸ��� ��� ���� �����鼭 �ڸ��� �ű�� ���� ��� 
	
	*/

}
