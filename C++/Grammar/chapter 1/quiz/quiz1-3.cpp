#include <iostream>

int main(){
	int num;
	
	std::cin>>num;
	
	for(int i=0; i<9; i++){
		std::cout<<num<<"*"<<i+1<<"="<<num*(i+1)<<std::endl;
	}

}
