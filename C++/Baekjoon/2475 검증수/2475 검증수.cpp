#include <iostream>
using namespace std;
 
int main(){
	int serial_num[6];
	int tmp;

	for(int i =0; i<5; i++){
		cin >> serial_num[i];
		serial_num[5] += serial_num[i]*serial_num[i];
	}
	
	cout << serial_num[5]%10;
} 
