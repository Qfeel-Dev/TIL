#include <iostream>

int main(){
	
	int profit=0;
	int total=0;
	
	
	while(profit != -1){
		std::cout<< "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end)";
		std::cin >> profit;
		
		if(profit >= 0){
			total= 50 + profit*0.12;
			std::cout<<"�̹� �� �޿�:"<<total<<std: :endl;
		}
	}
	std::cout<<"���α׷��� �����մϴ�.";
}
