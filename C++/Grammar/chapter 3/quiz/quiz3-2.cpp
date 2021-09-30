#include <iostream>
#include <cstring>

class Printer{
	private:
		char str[30];
	public:
		void SetString(char * txt);	
		void ShowString();
};

void Printer::SetString(char * txt){
	strcpy(str,txt);	
}

void Printer::ShowString(){
	std::cout<<str;
}



int main(){
	Printer pnt;
	pnt.SetString("Hello world");
	pnt.ShowString();

}

