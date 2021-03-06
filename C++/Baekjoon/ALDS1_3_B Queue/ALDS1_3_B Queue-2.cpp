#include <iostream>
#include <cstring>

using namespace std;
int head,tail;


struct Process{
	char name[11];
	int size;
};

Process prc_arr[100001];

void init(){
	head = 0;
	tail = 0;
}

int isempty()
{
	if(head == tail) return 1;
	return 0;
}

int equeue(Process v)
{
	prc_arr[tail] = v;

	tail++;
	//tail = (tail +1)%100001; // 원형큐 
}

Process dequeue()
{
	/*원형큐 
	Process q = prc_arr[head];
	head = (head+1) % 100001;
	return q; 
	*/	

	return prc_arr[head++];
}

int main()
{
	int n,q;
	Process tmp;
	int q_total = 0;
	
	init();

	cin >> n >> q;
	
	for(int i =0; i<n; i++)
	{
		cin >> tmp.name >> tmp.size;	
		equeue(tmp);
	}
/*
	for(int i = 0 ; i<10; i++)
	{
		cout << prc_arr[i].name << " " << prc_arr[i].size << endl;
	}

	cout << head << "||"<< tail << endl << endl;
*/

	while(!isempty())
	{
		tmp = dequeue();
		if(tmp.size > q) 
		{
			tmp.size -= q;
			q_total += q;
			equeue(tmp);
		}
		else
		{
			q_total += tmp.size;
			cout << tmp.name << " " << q_total << endl;
		}
	}
}
