#include <iostream>

using namespace std;

int main()
{
	int people;
	int size;
	int news[5];
	
	cin >> people >> size;
	
	for(int i =0; i<5; i++) {cin >> news[i];}

	for(int i =0; i<5; i++) {
 		cout << news[i]-people*size << " ";
	}
}
