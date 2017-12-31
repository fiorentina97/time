#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct timer
{
	int h;
	int m;
	int s;
};

class Time
{
public:
	int hour;
	int minute;
	int second;
	Time();
	Time(char t[]);
	Time(timer t1);
	~Time(){};
	int different(Time t1, Time t2);//разница в секундах
	void sum(int sec);//сумма текущего момента времени и секунд
	void differentSec(int sec);//разница текущего момента времени и секунд
	void simule(Time t1, Time t2);//сравнение времени в t1 будет большее время
	int insecond();//перевод в секунды
	int inminute();//перевод в минуты
	void init();//ввод с клавиатуры
	void init_key();
	void init_str();
	void init_sec();
	void print();//печать
};
Time::Time()
{
	hour=0;
	minute=0;
	second=0;
}
Time::Time(char t[])
{
	int h,m,s;
	if (strlen(t)!=8) cout<<endl<<"wrong format time"<<endl;
	else
	{
		h = atoi(&t[0]); 
		m = atoi(&t[3]);
		s = atoi(&t[6]);
		if (h>23) cout<<endl<<"wrong format time"<<endl;
		else hour = h;
		if (m>59) cout<<endl<<"wrong format time"<<endl;
		else minute = m;
		if (s>59) cout<<endl<<"wrong format time"<<endl;
		else second = s;
	}
}

Time::Time(timer t1)
{	
	if (t1.h>24) cout<<endl<<"wrong format time"<<endl;
	else hour = t1.h;
	if (t1.m>60) cout<<endl<<"wrong format time"<<endl;
	else minute = t1.m;
	if (t1.s>60) cout<<endl<<"wrong format time"<<endl;
	else second = t1.s;
}

int Time::different(Time t1, Time t2)
{
	int s = (t1.hour-t2.hour)*60*60+
			(t1.minute-t2.minute)*60+
			(t1.second-t2.second);
	if (s<0) s*=-1;
	return s;
}

void Time::sum(int sec)
{
	//выделяем часы минуты и секунды
	int h=0,m=0,s=0;
	if (sec>3600) 
	{
		h = sec/3600;
		sec-=h*3600;
	}
	if (sec>60) 
	{
		m = sec/60;
		sec-=m*60;
	}
	s=sec;
	//складываем
	second+=s; 
	if (second>59)
	{
		minute+=second/60;
		second-=60;
	}
	minute+=m;
	if (minute>59)
	{
		hour+=minute/60;
		minute-=60;
	}
	hour+=h;
	if (hour>23)
	{
		hour-=24;
	}
}

void Time::differentSec(int sec)
{
	//выделяем часы минуты и секунды
	int h=0,m=0,s=0;
	if (sec>3600) 
	{
		h = sec/3600;
		sec-=h*3600;
	}
	if (sec>60) 
	{
		m = sec/60;
		sec-=m*60;
	}
	s=sec;
	//вычитаем
	second-=s; 
	if (second<0)
	{
		minute--;
		second+=60;
	}
	minute-=m;
	if (minute<0)
	{
		hour--;
		minute+=60;
	}
	hour-=h;
	if (hour<0)
	{
		hour+=24;
	}
}

void Time::simule(Time t1, Time t2)
{
	if (t1.hour<t2.hour)
	{
		t1.hour = t2.hour;
		t1.minute = t2.minute;
		t1.second = t2.second;
	}
	else if (t1.minute<t2.minute)
	{
		t1.minute = t2.minute;
		t1.second = t2.second;
	}
	else t1.second = t2.second;
}

int Time::insecond()
{
	return(3600*hour + 60*minute + second);
}

int Time::inminute()
{
	return(60*hour + 60);
}

void Time::init()
{	
	Time t1;
	int number;
		cout << " Выберите один из способов ввода времени:" << endl;
		cout << "1. Ввод времени строкой" << endl;
		cout << "2. Ввод времени числами" << endl;
		cout << "3. Ввод в секундах" << endl;
		cin >> number;
		cout << endl << endl;
		switch (number)
		{
		case 1: t1.init_str(); break;
		case 2: t1.init_key(); break;
		case 3: t1.init_sec(); break;
		default: cout << "??????????? ???? " << endl; break;
		}
}

void Time::init_sec()
{
	int h,m,s;
	do
	{
		cout<<"Ввод времени"<<endl<<"Введите секунды"<<endl;
		cin>>h;
		if (s>59) cout<<"Неправильный формат времени. Повторите попытку."<<endl;
		else second = s;
		
	}
	while (s>59);
	hour = second / 3600  % 24;
	minute = second / 60 % 60;
	
}

void Time::init_str()
{
	int h,m,s;
	char t[255];
	cout<<"input time"<<endl;
	cin>>t;
	if (strlen(t)!=8) cout<<endl<<"wrong format time"<<endl;
	else
	{
		h = atoi(&t[0]); 
		m = atoi(&t[3]);
		s = atoi(&t[6]);
		if (h>23) cout<<endl<<"wrong format time"<<endl;
		else hour = h;
		if (m>59) cout<<endl<<"wrong format time"<<endl;
		else minute = m;
		if (s>59) cout<<endl<<"wrong format time"<<endl;
		else second = s;
	}
}

void Time::init_key()
{
	int h,m,s;
	do
	{
		cout<<"Ввод времени"<<endl<<"Введите час"<<endl;
		cin>>h;
		if (h>23) cout<<"Неправильный формат времени. Повторите попытку."<<endl;
		else hour = h;
		
	}
	while (h>23);
	do
	{
		cout<<"Введите минуты"<<endl;
		cin>>m;
		if (m>59) cout<<"Неправильный формат времени. Повторите попытку."<<endl;
		else minute = m;
	}
	while (m>59);
	do
	{
		cout<<"Введите секунды"<<endl;
		cin>>s;
		if (s>59) cout<<"Неправильный формат времени. Повторите попытку."<<endl;
		else second = s;
	}
	while (s>59);

}

void Time::print()
{
	
	cout<<"Время = "<<hour<<":"<<minute<<":"<<second<<endl;
}

int main()
{
	Time t1,t2,t3;
	int number,sec;
	setlocale( LC_ALL,"Russian" );

	for (; ;)
	{
		cout << " Выберите один из пунктов меню  " << endl;
		cout << "1. Ввод времени с клавиатуры" << endl;
		cout << "2. Вывод данных" << endl;
		cout << "3. Разность между двумя моментами времени в секундах" << endl;
		cout << "4. Сложение времени и заданного кол-ва секунд" << endl;
		cout << "5. Вычитание из времени заданного кол-ва секунд" << endl;
		cout << "6. Сравнение моментов времени," << endl;
		cout << "7. Перевод в секунды" << endl;
		cout << "8. Перевод в минуты " << endl << endl;
		cout << "9. Выход" << endl << endl;
		cin >> number;
		switch (number)
		{
		case 1: t1.init(); break;
		case 2: t1.print(); break;
		case 3: t1.different(t1,t2); break;
		case 4: t1.sum(sec); break;
		case 5: t1.differentSec(sec); break;
		case 6: t1.simule(t1,t2); break;
		case 7: t1.insecond(); break;
		case 8: t1.inminute(); break;
		case 9: cout << "?? ???????? " << endl; exit(1); break;
		default: cout << "??????????? ???? " << endl; break;
		}
		getchar();
	}
}

