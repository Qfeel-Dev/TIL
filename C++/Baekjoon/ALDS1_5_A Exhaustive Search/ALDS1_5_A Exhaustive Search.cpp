#include <iostream>

using namespace std;

int n;
int q;

int A[21];
int m[201];


int E_Search(int des){
	int pivot;
	
	for(int i = 0; i<n; i++)
	{
		if(des < A[i])
		{
			if(i == 0) return 0;
			pivot = i;		
		}	
	}
	

}

int main()
{
	int tmp;
	
	cin >> n;
	
	
	for(int i=0; i<n; i++){
		cin >> A[i];	
	}

	cin >> q;	

	for(int i=0; i<q; i++){
		cin >> m[i];	
	}
	
	for(int i = 0; i<n; i++){//»ðÀÔ Á¤·Ä 
		for(int j = i+1; j<n; j++){
			if(A[i] < A[j])
			{
				tmp = A[i];
				A[i] = A[j];
				A[i] = tmp;			
			}	
		}	
	}
	
	for(int i=0; i<n; i++){
		cout << A[i] << " ";	
	}
	
		
	for(int i=0; i<q; i++){
		E_Search(m[i]);
		
	}
 }
