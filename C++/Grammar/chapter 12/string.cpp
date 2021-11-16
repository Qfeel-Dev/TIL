#include <iostream>
#include <cstring>


using namespace std;

class String{
	private:
		char *txt;
		//static int num;
		//int id;
	public:
		
	
		
		String(const char *s)
		{
			//id = num;
			//num++; 
			//cout << id <<"Constructor" << endl;
			txt = new char[strlen(s)+1];
			strcpy(txt,s);			
		}
		
		
		String(const String& s)
		{
			//id = num;
			//num++; 
			//cout << id <<"Copy Constructor" << endl;
			txt = new char[strlen(s.txt)+1];
			strcpy(txt,s.txt);			
		}
		
		
		String operator=(const char* s)
		{
			//cout <<id << "= overloading" << endl;
			delete []txt;
			txt = new char[strlen(s)+1];
			strcpy(txt,s);			
		}
	
		String operator=(const String& s)
		{
			//cout <<id << "= overloading string" << endl;
			delete []txt;
			txt = new char[strlen(s.txt)+1];
			strcpy(txt,s.txt);			
		}
		
		
		String operator+(String& s)
		{
			char *txt;
			txt = new char[strlen(s.txt) + strlen(this->txt) + 1];
			strcpy(txt,this->txt);
			strcat(txt,s.txt);
			
			String tmp(txt);
			return tmp;
		
		}
	
		void Show() const
		{
			cout << txt << endl;
		}


};

//int String::num = 0;



int main(void)
{
	String str1("I like a girl");
	String str2 = "hello";
	String str3 = str2;

	
	str2 = "I love girl";
	
	String str4 = str1 + str2;	
	
	str1.Show();
	str2.Show();
	str3.Show();
	str4.Show();
	

}
