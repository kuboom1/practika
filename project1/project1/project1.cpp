// ConsoleApplication1.cpp : main project file.
#include "stdafx.h" // ����������� ���������
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <clocale>

using namespace std; // ����������� ����������� ���
using namespace System;
using namespace System::IO;

#define ENTER 13 // ����������� ������
#define ESC 27
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79

int menu(int); // �������� �������� ������������ �������
void maxim(struct z*);
float text_to_time(char *);
void kolvo(struct z*);
void match(struct z*);
void alfalist(struct z*, struct sp*);
void vstavka(struct z*, char*,  struct sp**);
void best_on_dist(struct z*);
void diagram(struct z*, struct sp*);

struct z {
	char name[20]; // ��� ����������
	int year; // ��� �������� ����������
	char style[7]; // ����� ��������
	int distant; // ���������
	char new_time[10]; // ���������� �����
	char prev_time[10]; // ���������� �����
	int points; //���������� �����
	char city[10]; // �����
}; // ������ ��������� ��� �������� ������

struct sp {
	char fio[20];
	int points;
	struct sp* pred;
	struct sp* sled;
} *spisok; // ������ ��������� ������ | ���������� �������� ��������� ������������� ������ 
 
int main(array<System::String ^> ^args)
{
	int i, n, NC;
	char dan[7][55] = { 
 "����� ������ ������ ������ ����� �����?               ",
 "���� �� ������, ��������� ���������� ���������� �����?",
 "������� ������� �������� ���� ����������?             ",
 "��� ���� ������ �� ���������:                         ",
 "���������� ������ ���������� ������������             ",
 "��������� �� ��������� ����� � ���������� ����������� ",
 "�����                                                 "}; 
    // ������ �� �������� ��� ����������
    char BlankLine[] = "                                                        "; 
	FILE *in; // �� ��������� ������ ������������ �������� �����
	struct z *swimmers; // ��������� ������ �� ����� � ���������� ������
	//setlocale(LC_CTYPE, "Russian");
	system("chcp 1251>nul"); // ������������ ��������� 1251
	Console::CursorVisible::set(false); //��������� ��������� �������
	Console::WindowWidth = 112; // ������������� ������ ����������� ����
	Console::WindowHeight = 31; // ������������� ������ ����������� ����
	Console::BufferHeight = Console::WindowHeight; //��������� ������� ������ �� ������
	Console::BufferWidth = Console::WindowWidth; //��������� ������� ������ �� ������
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	swimmers = (struct z*)malloc(NC*sizeof(struct z)); // �������� ������
	for(i=0;i<NC;i++) // ���� ��� ���������� ������ �� �����
	{
		fscanf(in ,"%s%d%s%d%s%s%d%s", swimmers[i].name, &swimmers[i].year, swimmers[i].style, 
      &swimmers[i].distant, swimmers[i].new_time, swimmers[i].prev_time, &swimmers[i].points, swimmers[i].city);
	}
	printf("\n\t\t+%-20s %-5s %-6s %-9s %-11s %-12s %-4s %-7s+\n", "���", "���", "�����", "���������", "����� �����", "������ �����", "����", "�����");
	printf("\t\t|---------------------------------------------------------------------------------|");
	for(i=0;i<NC;i++) // ���� ��� ������ ������ �� �����
	{
		printf("\n\t\t|%-20s %-5d %-6s %-9d %-11s %-12s %-4d %-7s|", swimmers[i].name, swimmers[i].year, swimmers[i].style, 
			swimmers[i].distant, swimmers[i].new_time, swimmers[i].prev_time, swimmers[i].points, swimmers[i].city);
	}
	getch();

	while (1) //� ����� ������� ������� ��� �������� � ���������� � � �����
	{
		Console::BackgroundColor = ConsoleColor::Gray; // ������������� ������� ���� �����
		Console::Clear(); // ������� ������� (������ � � ����� ����)
		Console::ForegroundColor = ConsoleColor::Yellow; // ������������� ���� ������ ������
		Console::BackgroundColor = ConsoleColor::DarkMagenta; // ������������� ������� ���� ����������
		Console::CursorLeft = 10;
		Console::CursorTop = 4; //������ �����, ������ ����� ����������� ������� ����
		printf(BlankLine);
		for(i = 0; i < 7; i++) //���������� ��������
		{
			Console::CursorLeft = 10;
			Console::CursorTop = i + 5;
			printf(" %s ", dan[i]);
		}
		Console::CursorLeft = 10;
		Console::CursorTop = 12; //��������� �����, ��� ����� ������������� ���������� ������� ��� ����
		printf(BlankLine);
		n = menu(7);
		switch (n) //����� ������� � ����
		{
		case 1: maxim(swimmers); break;
		case 2: match(swimmers); break;
		case 3: kolvo(swimmers); break;
		case 4: best_on_dist(swimmers); break;
		case 5: alfalist(swimmers, spisok); break;
		case 6: diagram(swimmers, spisok); break;
		case 7: exit(0);
		}
	} // ����� while(1)...
	return 0;
} // ����� main()
  
int menu(int n)
{
	char dan[7][55] = { 
 "����� ������ ������ ������ ����� �����?               ",
 "���� �� ������, ��������� ���������� ���������� �����?",
 "������� ������� �������� ���� ����������?             ",
 "��� ���� ������ �� ���������:                         ",
 "���������� ������ ���������� ������������             ",
 "��������� �� ��������� ����� � ���������� ����������� ",
 "�����                                                 "}; 
 // ������ �� �������� ��� ����������
    char BlankLine[]="                                                        "; 
    int y1 = 0, y2 = n - 1; //������������� ��������� ��� �������
	char c = 1;
	while (c != ESC) //��� ������� ������ ESC, ���� ���������
	{
		switch (c)
		{
		case DOWN: y2 = y1; y1++; break; // ������ DOWN ��������� ������������ ����
		case UP: y2 = y1; y1--; break; // ������ UP ��������� ������������ �����
		case HOME: y2 = y1; y1 = 0; break; // ������ HOME ��������� ������������ � ����� ����
		case END: y2 = y1, y1 = n-1; break; // ������ END ��������� ������������ � ����� ���
		case ENTER: return y1 + 1; // ������ ENTER ��������� ������� ������
		}
		if (y1 > n - 1) { y2 = n - 1; y1 = 0; } //�������,����� ����������� ������ DOWN
		if (y1 < 0) { y2 = 0; y1 = n - 1; } //�������,����� ����������� ������ UP
		Console::ForegroundColor = ConsoleColor::White; //��� ������ �������
														//����� ������������ � ����� ����
		Console::BackgroundColor = ConsoleColor::Magenta; //��� ������ �������,
														//���� �� ������� �������������� �������
		Console::CursorLeft = 11;
		Console::CursorTop = y1 + 5;
		printf("%s", dan[y1]);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::BackgroundColor = ConsoleColor::DarkMagenta;
		Console::CursorLeft = 11;
		Console::CursorTop = y2 + 5;
		printf("%s", dan[y2]);
		c = getch();
	} // ����� while(c!=ESC)...
	exit(0);
}

// ����� ������ ������ ������ ����� �����?
// ������� ������ ���������
void maxim(struct z* swimmers){
	int i=0, NC; struct z best;
	FILE *in; // �� ��������� ������ ������������ �������� �����
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	strcpy(best.name,swimmers[0].name);
	best.points = swimmers[0].points; //� ���������� ��������� ���������� ������� �������
	for(i=1;i<NC;i++)
		if (swimmers[i].points>best.points) // ���������� ������������� ������� � ���������
		{
			strcpy(best.name,swimmers[i].name); // ���������� ��� ���������� � ���������� best.name
			best.points=swimmers[i].points; // ���������� ���� ���������� � ���������� best.points
		}
		Console::ForegroundColor=ConsoleColor::DarkMagenta;
		Console::BackgroundColor=ConsoleColor::Gray;
		Console::CursorLeft=10; //������ �������, ��� ����� �������� ���
		Console::CursorTop=15;
		printf("���������� ������������ � ����� ������ %s",best.name); //����� �����
		Console::CursorLeft=10;
		Console::CursorTop=16; //������ �������, ��� ����� �������� ����.����������
		printf("����� � ����� %d �����!",best.points); // ����� ������������� ����������
		getch();
		fclose(in);
}
// ��������������� ������� �������������� ������� �� ������ � �����
float text_to_time(char *time) // char 1:14:06 -> int 74.06 s
{
	float res;
	char temp[3];
	res = (float)atoi(time+5); res /= 100.0;
	strncpy(temp, time+2, 2); temp[2] = 0; res += atoi(temp);
	strncpy(temp, time, 1); temp[1] = 0; res += atoi(temp)*60;
	return res;
}
// ���������� ����������, ���������� ���������
// ������� �������� ����������
void kolvo(struct z *swimmers)
{
	int i, k=0, NC;
	float prev_res, new_res;
	FILE *in; // �� ��������� ������ ������������ �������� �����
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	for(i=0;i<NC;i++)
	{
		prev_res = text_to_time(swimmers[i].prev_time);
		new_res = text_to_time(swimmers[i].new_time);
		if ((prev_res - new_res) > 0) k++;
	}
	Console::ForegroundColor=ConsoleColor::DarkMagenta;
	Console::BackgroundColor=ConsoleColor::Gray;
	Console::CursorLeft=10;
	Console::CursorTop=15;
	printf("%d �� 27 ���������� �������� ���� ���������.", k);
	getch();
	fclose(in);
}

// ����� �����������, ��������� ���������� ���������� �����
// ������� ���������� ����������
void match(struct z *swimmers)
{
	char name_of_match[20] = "";
	int i, j, NC;
	struct z examp;
	FILE *in; // �� ��������� ������ ������������ �������� �����
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	for(j=0;j<NC;j++)
	{
		strcpy(examp.name, swimmers[j].name);
		examp.points = swimmers[j].points;
		for(i=j+1;i<NC-j;i++)
			if (swimmers[i].points == examp.points)
			{
				strcpy(name_of_match, swimmers[i].name);
				strcat(name_of_match, "\0");
				break;
			}
			if (strlen(name_of_match)>1) break;
	}
	Console::ForegroundColor=ConsoleColor::DarkMagenta;
	Console::BackgroundColor=ConsoleColor::Gray;
	Console::CursorLeft=10;
	Console::CursorTop=15;
	printf("������ ���������� ����� - %d", examp.points);
	Console::CursorLeft=10;
	Console::CursorTop=16;
	printf("������� %s � %s", examp.name, name_of_match);
	getch();
	fclose(in);
}

// ������� ������ ����������� � ��������� ������
void alfalist(struct z* swimmers, struct sp* spisok)
{
	int i, x=3, NC;
	struct sp* nt, *z;
	FILE *in; // �� ��������� ������ ������������ �������� �����
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	Console::ForegroundColor=ConsoleColor::DarkMagenta;
	Console::BackgroundColor=ConsoleColor::Gray;
	if(!spisok)
		for(i=0;i<NC;i++) vstavka(swimmers, swimmers[i].name, &spisok);
	Console::Clear();
	printf("\n ���������� ������ ����������:\n");
	printf(" ===============================");
	for(nt=spisok; nt!=0; nt=nt->sled)
	{
		Console::CursorLeft = 0;
		Console::CursorTop = x + 1;
		printf("\n %-20s %d" , nt->fio, nt->points);
		x += 1;
	}
	x = 3;
	Console::CursorLeft = 40;
	Console::CursorTop = 0;
	printf("  �������� ������ ����������: ");
	Console::CursorLeft = 40;
	Console::CursorTop = 1;
	printf(" ===============================");
	for(nt = spisok; nt != 0; z = nt, nt=nt->sled);
	for(nt = z; nt != 0; nt=nt->pred)
	{
		Console::CursorLeft = 40;
		Console::CursorTop = x + 1;
		printf(" %-20s %d" , nt->fio, nt->points);
		x += 1;
	}
	getch();
	fclose(in);
}

// ������� ������� �������� � ������� ������
void vstavka(struct z* swimmers, char* fio, struct sp** spisok)
{
	int i, NC;
	FILE *in; // �� ��������� ������ ������������ �������� �����
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	struct sp *nov,*nt,*z=0;
	for(nt=*spisok; nt!=0 && strcmp(nt->fio,fio)<0; z=nt, nt=nt->sled);
	if(nt && strcmp(nt->fio,fio)==0) return;
	nov=(struct sp *) malloc(sizeof(struct sp));
	strcpy(nov->fio,fio);
	nov->sled=nt;
	nov->pred=z;
	nov->points=0;
	for(i=0;i<NC;i++)
		if(strcmp(swimmers[i].name,fio)==0) nov->points=swimmers[i].points;
	if(!z) *spisok=nov;
	else z->sled=nov;
	if(nt) nt->pred=nov;
	fclose(in);
	return;
}

// ������� ���������� ���������
void diagram(struct z *swimmers, struct sp* spisok)
{
	struct sp *nt;
	int len, i, NColor;
	int ochki = 0, NC;
	FILE *in; // �� ��������� ������ ������������ �������� �����
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	char str1[20];
	char str2[20];
	System::ConsoleColor Color;
	Console::ForegroundColor=ConsoleColor::Black;
	Console::BackgroundColor=ConsoleColor::White;
	Console::Clear();
	for(i=0;i<NC;i++) ochki = ochki + swimmers[i].points;
	if(!spisok)
		for(i=0;i<NC;i++) vstavka(swimmers, swimmers[i].name, &spisok);
	Color=ConsoleColor::Black; NColor=0;
	for(nt=spisok,i=0; nt!=0; nt=nt->sled,i++)
	{
		sprintf(str1,"%s",nt->fio);
		sprintf(str2,"%3.1f%%",(nt->points*100./ochki));
		Console::ForegroundColor=ConsoleColor::Black;
		Console::BackgroundColor=ConsoleColor::White;
		Console::CursorLeft=5; Console::CursorTop=i+1;
		printf(str1);
		Console::CursorLeft=20;
		printf("  %s ||",str2);
		Console::BackgroundColor=++Color; NColor++;
		Console::CursorLeft=30;
		for(len=0; len<nt->points*100/ochki; len++) printf(" ");
		if(NColor==14)
		{ Color=ConsoleColor::Black; NColor=0; }
	}
	getch();
	fclose(in);
	return ;
}

// ������� ���������� ���������� �� ������������ ���������
void best_on_dist(struct z *swimmers)
{
	int NC;
	int i; float fastest_time; char name_of_fastest[20] = "";
	char swimmer_is_found_flag = 0;
	int meters; char style[7];
	FILE *in; // �� ��������� ������ ������������ �������� �����
	if((in=fopen("results.dat","r"))==NULL) //������� ������� ����
	{
		printf("\n���� results.dat �� ������ !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	Console::ForegroundColor=ConsoleColor::DarkMagenta;
	Console::BackgroundColor=ConsoleColor::Gray;
	Console::CursorLeft=10;
	Console::CursorTop=15;
	printf("������� ��������� � �������: [�����] [�����] ");
	Console::CursorVisible::set(true);
	scanf("%d %s", &meters, style); strcat(style, "\0");
	Console::CursorVisible::set(false);

	fastest_time = 100000;
	for(i=1; i<NC; i++)
		if ((meters==swimmers[i].distant)&&(strcmp(style, swimmers[i].style)==0))
		{
			if(fastest_time>text_to_time(swimmers[i].new_time))
			{
				strcpy(name_of_fastest, swimmers[i].name); strcat(name_of_fastest, "\0");
				fastest_time = text_to_time(swimmers[i].new_time);
				swimmer_is_found_flag = 1;
			}
		}
	Console::CursorLeft=10;
	Console::CursorTop=17;
	if (!swimmer_is_found_flag)
	{
		printf("������, ����� ��������� ����� �� ����.");
		getch();
		return;
	}
	printf("%s �� ��������� %d %s", name_of_fastest, meters, style);
	getch();
	fclose(in);
	return;
}




