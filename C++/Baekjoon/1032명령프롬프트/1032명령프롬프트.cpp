#include <iostream>

using namespace std;


int main()
{
	int num;
	char file_name_com1[51];
	char file_name_com2[51];
	
	cin >> num;
	
	cin >>file_name_com1;
	
	if(num == 1) {cout << file_name_com1; return 0;}
	
	
	for(int i = 1; i<num; i++){		
		cin >>file_name_com2;		
		for(int j = 0; j<51; j++){				
			if(file_name_com1[j] == file_name_com2[j]) {
				continue;
			}
			
			else{
				file_name_com1[j] = '?';	
			}
		}
	}
	
	cout << file_name_com1; 
	return 0;	
}
