#include <iostream>

int main(){
	
	int profit=0;
	int total=0;
	
	
	while(profit != -1){
		std::cout<< "판매 금액을 만원 단위로 입력(-1 to end)";
		std::cin >> profit;
		
		if(profit >= 0){
			total= 50 + profit*0.12;
			std::cout<<"이번 달 급여:"<<total<<std: :endl;
		}
	}
	std::cout<<"프로그램을 종료합니다.";
}
