#include <iostream>

int main(){

	int n;
	int tmp;
	int j=0;
	int cnt = 0;
	
	std::cin >> n;
	
	int arr[n];
		
	for(int i =0; i<n; i++)
	{
		std::cin >> arr[i];	
	}


	while(1)
	{
		if(j == n) break;
		for(int i = n-1; i>=j; i--)
		{
			if(arr[i] < arr[i-1]){
				tmp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = tmp;
				cnt++;
			}
		}
		j++;
	}


	for(int k=0; k<n; k++)
	{
		std::cout << arr[k] << " ";
	}
	std::cout << std::endl;
	std::cout << cnt;
}

/*
�������� ����
������ ��� : O(n) - (�������� ���ĵ� �ִ� ���)
�־��� ��� : O(N^2)-(������������ ���ĵ� ���) 
������ ������ �ΰ��� ���ڸ� ���ذ��� �������� ������ �س����� ����̴�. 
*/
