#include <iostream>

int main(){
	
	int num = 0;
	int	result = 0;
	
	for(int i =0; i<5; i++){
		std::cout << i+1 <<"��° ���� �Է�: " ;
		std::cin >> num;
		result += num;		
	}
	
	std::cout <<"�հ�: "<< result;	
} 
