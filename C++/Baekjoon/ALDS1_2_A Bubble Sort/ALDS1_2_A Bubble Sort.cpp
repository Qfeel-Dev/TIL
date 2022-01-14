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
버블정렬 정리
최적의 경우 : O(n) - (오름차순 정렬되 있는 경우)
최악의 경우 : O(N^2)-(내림차순으로 정렬된 경우) 
끝에서 인접한 두개의 숫자를 비교해가며 앞쪽으로 정렬을 해나가는 방식이다. 
*/
