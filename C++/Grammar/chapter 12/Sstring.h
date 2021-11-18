#include <iostream>
#include <cstring>

using namespace std;


class String{
	private:
		char *txt;

	public:
				
		String(const char *s);//String s("aaa"), String s = "aaa";
		String(const String& s);//String s(str), String s = str;
		
		
		//String operator=(const char* s);//s=str??

		String operator=(const String& s);//s=str
		
		String operator+(const String& s);//str1+str2
		
		String operator+=(const String& s);
		
		////
		
		
		friend bool operator==(const String& str1 , const String& str2);
		
		friend ostream& operator<<(ostream& os, const String& s);

		friend istream& operator<<(istream& is, String& s);
	
};
