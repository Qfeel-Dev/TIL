#include <iostream>

using namespace std;


int main(int N){
	scanf("%x",&N);
	printf("%d",N);
	/*
	string hex;
	unsigned int dec;
	unsigned int tot = 0;
	int weight = 1;
	

	cin >> hex;
	

	for(int i =hex.length()-1; i>=0; i--){
		dec= hex[i] - '0';
		if(dec > 16) dec -= 7;
		
		tot += weight * dec;
		weight *= 16;
	}
	cout << tot;
	*/
	
}

//
//A 1
//10*16 + 1*1
//161
