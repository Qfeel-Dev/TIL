#include <iostream> 

int main(){
	char name[100];
	char tel[100];
	
	
	std::cout<<"너의 이름은?";
	std::cin>>name;
	std::cout<<"너의 번호는?";
	std::cin>>tel;

	std::cout<<"Hello "<<name<<std::endl;
	std::cout<<tel;
}
