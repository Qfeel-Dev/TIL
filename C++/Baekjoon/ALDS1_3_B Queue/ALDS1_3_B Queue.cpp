#include <iostream>

using namespace std;

int process_num;
int qms;

int queue_st;
int queue_end;


struct Process{
	char name[11];
	int time;
};

Process prc[100001];

void init()
{
	queue_st = 0;
	queue_end = 0;
}

int is_empty()
{
	if(queue_end == queue_st) return 1;
	else return 0;
}

int is_full()
{
	if(queue_st == (queue_end+1) / 100001) return 1;
	return 0;
}

int push(Process v)
{
	if(is_full()) return 0;
	
	prc[queue_end] = v;

	if(queue_end+1 == 100001) {queue_end = 0;}
	else {queue_end++;}
}

Process pop()
{
	
	Process x = prc[queue_st];		

	if(queue_st+1 == 100001) {queue_end = 0;}
	else {queue_st++;}

	return x;
}


int main()
{

	cin >> process_num >> qms;

	Process tmp;	
	
	for(int i =0; i<process_num; i++)
	{
		cin >> tmp.name >> tmp.time;	
		push(tmp);
	}

	while(1)
	{
		if(queue_end == queue_st) break;	

		tmp = pop();
		tmp.time -= qms;
		if(tmp.time > 0) 
		{			
			push(tmp);
		}

		else 
		{
			cout << tmp.name << tmp.time << endl;

		}
	}
}
