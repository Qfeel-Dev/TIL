#include <iostream>

struct Space {
	int	Planet_Index; 
	int Planet_Size;
};

int main()
{
	int m;//멀티버스의 갯수
	int n;//행성의 수 
	int min;
	int flag = 0;
	int cnt = 0;
	int j=0;
	Space tmp;

	std::cin >> m >> n;

	Space bus[m][n];

	for(int i =0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			std::cin >> bus[i][j].Planet_Size;
			bus[i][j].Planet_Index = j;
		}	
	}

	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{	
			for(int k= n-1; k>= j+1; k--)	
			{
				if(bus[i][k].Planet_Size < bus[i][k-1].Planet_Size)
				{
					tmp = bus[i][k];
					bus[i][k] = bus[i][k-1];
					bus[i][k-1] = tmp;		
				}
			}
		}
	}

	for(int i = 0; i<m; i++)
	{
		for(int j = i+1; j<m; j++)	
		{
			flag = 0;
			for(int k = 0; k<n; k++)
			{					
				if(bus[i][k].Planet_Index != bus[j][k].Planet_Index)	{flag = 0; break;}
				flag =1;
			}			
			if(flag == 1) cnt++;
		}
	}

	std::cout << cnt;
	return 0;
}


/*

	for(int k = 0; k<m; k++)
	{
		j=0;
		while(1)
		{
			if(j == n) break;
			for(int i = n-1; i>=j+1; i--)
			{
			
				if(bus[k][i].Planet_Size < bus[k][i-1].Planet_Size)	
				{
					tmp = bus[i][j];
					bus[i][j] = bus[i][min];
					bus[i][min] = tmp;		
				}
			}
			j++;
		}
	}

*/

/*
for(int i = 0; i<m; i++)
{
	for(int j = 0; j<n; j++)
	{
		min = j;
		for(int k = j+1; k<n; k++)
		{
			if(bus[i][min].Planet_Size > bus[i][k].Planet_Size)
			{
				min = k;
			}
		}	

		if(min != j)
		{
			tmp = bus[i][j];
			bus[i][j] = bus[i][min];
			bus[i][min] = tmp;							
		}
	}
}//selection sort
*/



/*
std::cout << std::endl;
std::cout << std::endl;

for(int i = 0; i<m; i++)
{
	for(int j = 0; j<n; j++)	
	{
		std::cout << bus[i][j].Planet_Index << "|" << bus[i][j].Planet_Size << std::endl;
		std::cout << bus[i][k].Planet_Index << "|" << bus[j][k].Planet_Index << std::endl; 
	}
	std::cout << std::endl;
}
*/
/*
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
}*/

