#include <iostream> 
#include <cstring> 

using namespace std;

int main()
{
	int max;
	char tmp;
	
	string str;

	cin >> str;
	
	for(int i = 0; i<str.length(); i++){
		for(int j = i+1; j<str.length(); j++){
			if(str[i] < str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
	
	cout << str;	
}
