#include <iostream>

int main(){
	const int num=12;
	const int *num2 = &num;
	const int &num3 = *num2;


	std::cout << *num2;	
	std::cout << num3;
	


}
