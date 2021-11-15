#include <iostream>
#include <cstring>


using namespace std;

class String{
	private:
		char *txt;
	public:
		
	
		
		String(const char *str)
		{
			txt = new char[strlen(str)+1];
			strcpy(txt,str);			
		}
		
		String operator=(char* str)
		{
			delete []txt;
			txt = new char[strlen(str)+1];
			strcpy(txt,str);			
		}
	
		
		
		
		
		void Show() const
		{
			cout << txt << endl;
		}


};



int main(void)
{
	String str1("I like a girl");
	String str2 = "hello";
	String str3();
	
	str2 = "I love girl";
	str3 ="I love";
	
	str1.Show();
	str2.Show();
	

}
