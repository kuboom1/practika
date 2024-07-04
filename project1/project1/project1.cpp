// ConsoleApplication1.cpp : main project file.
#include "stdafx.h" // Подключение библиотек
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <clocale>

using namespace std; // Подключения пространств имён
using namespace System;
using namespace System::IO;

#define ENTER 13 // Обозначение кнопок
#define ESC 27
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79

int menu(int); // указание шаблонов используемых функций
void maxim(struct z*);
float text_to_time(char *);
void kolvo(struct z*);
void match(struct z*);
void alfalist(struct z*, struct sp*);
void vstavka(struct z*, char*,  struct sp**);
void best_on_dist(struct z*);
void diagram(struct z*, struct sp*);

struct z {
	char name[20]; // ФИО спортсмена
	int year; // Год рождения спортсмена
	char style[7]; // Стиль плавания
	int distant; // Дистанция
	char new_time[10]; // Показанное время
	char prev_time[10]; // Заявленное время
	int points; //Количество очков
	char city[10]; // Город
}; // шаблон структуры для исходных данных

struct sp {
	char fio[20];
	int points;
	struct sp* pred;
	struct sp* sled;
} *spisok; // шаблон структуры данных | глобальное описание структуры двустореннего списка 
 
int main(array<System::String ^> ^args)
{
	int i, n, NC;
	char dan[7][55] = { 
 "Какой пловец набрал больше всего очков?               ",
 "Есть ли пловцы, набравшие одинаковое количество очков?",
 "Сколько пловцов улучшили свои результаты?             ",
 "Кто стал лучшим на дистанции:                         ",
 "Алфавитный список участников соревнований             ",
 "Диаграмма по набранным очкам в процентном соотношении ",
 "Выход                                                 "}; 
    // Массив из пробелов для оформления
    char BlankLine[] = "                                                        "; 
	FILE *in; // на локальном уровне осуществляем открытие файла
	struct z *swimmers; // считываем данные из файла в выделенную память
	//setlocale(LC_CTYPE, "Russian");
	system("chcp 1251>nul"); // установление кодировки 1251
	Console::CursorVisible::set(false); //отключаем видимость курсора
	Console::WindowWidth = 112; // устанавливаем ширину консольного окна
	Console::WindowHeight = 31; // устанавливаем высоту консольного окна
	Console::BufferHeight = Console::WindowHeight; //установка размера буфера по высоте
	Console::BufferWidth = Console::WindowWidth; //установка размера буфера по ширине
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	swimmers = (struct z*)malloc(NC*sizeof(struct z)); // выделяем память
	for(i=0;i<NC;i++) // цикл для считывания данных из файла
	{
		fscanf(in ,"%s%d%s%d%s%s%d%s", swimmers[i].name, &swimmers[i].year, swimmers[i].style, 
      &swimmers[i].distant, swimmers[i].new_time, swimmers[i].prev_time, &swimmers[i].points, swimmers[i].city);
	}
	printf("\n\t\t+%-20s %-5s %-6s %-9s %-11s %-12s %-4s %-7s+\n", "ФИО", "Год", "Стиль", "Дистанция", "Новое время", "Старое время", "Очки", "Город");
	printf("\t\t|---------------------------------------------------------------------------------|");
	for(i=0;i<NC;i++) // цикл для вывода данных на экран
	{
		printf("\n\t\t|%-20s %-5d %-6s %-9d %-11s %-12s %-4d %-7s|", swimmers[i].name, swimmers[i].year, swimmers[i].style, 
			swimmers[i].distant, swimmers[i].new_time, swimmers[i].prev_time, swimmers[i].points, swimmers[i].city);
	}
	getch();

	while (1) //в цикле создаем область для вопросов и окрашиваем её в цвета
	{
		Console::BackgroundColor = ConsoleColor::Gray; // устанавливаем фоновый цвет серый
		Console::Clear(); // Очищаем консоль (красим её в серый цвет)
		Console::ForegroundColor = ConsoleColor::Yellow; // устанавливаем цвет текста желтый
		Console::BackgroundColor = ConsoleColor::DarkMagenta; // устанавливаем фоновый цвет фиолетовый
		Console::CursorLeft = 10;
		Console::CursorTop = 4; //первая точка, откуда будем закрашивать область меню
		printf(BlankLine);
		for(i = 0; i < 7; i++) //размещение вопросов
		{
			Console::CursorLeft = 10;
			Console::CursorTop = i + 5;
			printf(" %s ", dan[i]);
		}
		Console::CursorLeft = 10;
		Console::CursorTop = 12; //последняя точка, где будет заканчиваться выделенная область под меню
		printf(BlankLine);
		n = menu(7);
		switch (n) //выбор вопроса в меню
		{
		case 1: maxim(swimmers); break;
		case 2: match(swimmers); break;
		case 3: kolvo(swimmers); break;
		case 4: best_on_dist(swimmers); break;
		case 5: alfalist(swimmers, spisok); break;
		case 6: diagram(swimmers, spisok); break;
		case 7: exit(0);
		}
	} // конец while(1)...
	return 0;
} // конец main()
  
int menu(int n)
{
	char dan[7][55] = { 
 "Какой пловец набрал больше всего очков?               ",
 "Есть ли пловцы, набравшие одинаковое количество очков?",
 "Сколько пловцов улучшили свои результаты?             ",
 "Кто стал лучшим на дистанции:                         ",
 "Алфавитный список участников соревнований             ",
 "Диаграмма по набранным очкам в процентном соотношении ",
 "Выход                                                 "}; 
 // Массив из пробелов для оформления
    char BlankLine[]="                                                        "; 
    int y1 = 0, y2 = n - 1; //устанавливаем выделение для строчки
	char c = 1;
	while (c != ESC) //при нажатии кнопки ESC, меню закроется
	{
		switch (c)
		{
		case DOWN: y2 = y1; y1++; break; // кнопка DOWN позволяет перемещаться вниз
		case UP: y2 = y1; y1--; break; // кнопка UP позволяет перемещаться вверх
		case HOME: y2 = y1; y1 = 0; break; // кнопка HOME позволяет перемещаться в самый верх
		case END: y2 = y1, y1 = n-1; break; // кнопка END позволяет перемещаться в самый низ
		case ENTER: return y1 + 1; // кнопка ENTER позволяет выбрать вопрос
		}
		if (y1 > n - 1) { y2 = n - 1; y1 = 0; } //условие,когда срабатывает кнопка DOWN
		if (y1 < 0) { y2 = 0; y1 = n - 1; } //условие,когда срабатывает кнопка UP
		Console::ForegroundColor = ConsoleColor::White; //при выборе вопроса
														//буквы окрашиваются в белый цвет
		Console::BackgroundColor = ConsoleColor::Magenta; //при выборе вопроса,
														//план за буквами подсвечивается розовым
		Console::CursorLeft = 11;
		Console::CursorTop = y1 + 5;
		printf("%s", dan[y1]);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::BackgroundColor = ConsoleColor::DarkMagenta;
		Console::CursorLeft = 11;
		Console::CursorTop = y2 + 5;
		printf("%s", dan[y2]);
		c = getch();
	} // конец while(c!=ESC)...
	exit(0);
}

// Какой пловец набрал больше всего очков?
// Функция поиска максимума
void maxim(struct z* swimmers){
	int i=0, NC; struct z best;
	FILE *in; // на локальном уровне осуществляем открытие файла
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	strcpy(best.name,swimmers[0].name);
	best.points = swimmers[0].points; //в переменную структуры записываем нулевой элемент
	for(i=1;i<NC;i++)
		if (swimmers[i].points>best.points) // сравниваем встретивщийся элемент с имеющимся
		{
			strcpy(best.name,swimmers[i].name); // запоминаем имя победителя в переменную best.name
			best.points=swimmers[i].points; // запоминаем очки победителя в переменную best.points
		}
		Console::ForegroundColor=ConsoleColor::DarkMagenta;
		Console::BackgroundColor=ConsoleColor::Gray;
		Console::CursorLeft=10; //задаем область, где будет выведено имя
		Console::CursorTop=15;
		printf("Победитель соревнований в общем зачете %s",best.name); //Вывод имени
		Console::CursorLeft=10;
		Console::CursorTop=16; //задаем область, где будет выведено макс.количество
		printf("имеет в сумме %d очков!",best.points); // Вывод максимального количества
		getch();
		fclose(in);
}
// вспомогательная функция преобразования времени из строки в число
float text_to_time(char *time) // char 1:14:06 -> int 74.06 s
{
	float res;
	char temp[3];
	res = (float)atoi(time+5); res /= 100.0;
	strncpy(temp, time+2, 2); temp[2] = 0; res += atoi(temp);
	strncpy(temp, time, 1); temp[1] = 0; res += atoi(temp)*60;
	return res;
}
// Количество учатсников, улучшивших результат
// Функция подсчета количества
void kolvo(struct z *swimmers)
{
	int i, k=0, NC;
	float prev_res, new_res;
	FILE *in; // на локальном уровне осуществляем открытие файла
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
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
	printf("%d из 27 участников улучшили свой результат.", k);
	getch();
	fclose(in);
}

// Найти спортсменов, набравших одинаковое количество очков
// Функция нахождения совпадания
void match(struct z *swimmers)
{
	char name_of_match[20] = "";
	int i, j, NC;
	struct z examp;
	FILE *in; // на локальном уровне осуществляем открытие файла
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
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
	printf("Равное количество очков - %d", examp.points);
	Console::CursorLeft=10;
	Console::CursorTop=16;
	printf("набрали %s и %s", examp.name, name_of_match);
	getch();
	fclose(in);
}

// Функция вывода алфавитного и обратного списка
void alfalist(struct z* swimmers, struct sp* spisok)
{
	int i, x=3, NC;
	struct sp* nt, *z;
	FILE *in; // на локальном уровне осуществляем открытие файла
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	Console::ForegroundColor=ConsoleColor::DarkMagenta;
	Console::BackgroundColor=ConsoleColor::Gray;
	if(!spisok)
		for(i=0;i<NC;i++) vstavka(swimmers, swimmers[i].name, &spisok);
	Console::Clear();
	printf("\n Алфавитный список участников:\n");
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
	printf("  Обратный список участников: ");
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

// Функция вставки элемента в связный список
void vstavka(struct z* swimmers, char* fio, struct sp** spisok)
{
	int i, NC;
	FILE *in; // на локальном уровне осуществляем открытие файла
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
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

// Функция построения диаграммы
void diagram(struct z *swimmers, struct sp* spisok)
{
	struct sp *nt;
	int len, i, NColor;
	int ochki = 0, NC;
	FILE *in; // на локальном уровне осуществляем открытие файла
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
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

// Функция нахождения победителя на определенной дистанции
void best_on_dist(struct z *swimmers)
{
	int NC;
	int i; float fastest_time; char name_of_fastest[20] = "";
	char swimmer_is_found_flag = 0;
	int meters; char style[7];
	FILE *in; // на локальном уровне осуществляем открытие файла
	if((in=fopen("results.dat","r"))==NULL) //попытка открыть файл
	{
		printf("\nФайл results.dat не открыт !");
		getch(); exit(1);
	}
	fscanf(in, "%d", &NC);
	Console::ForegroundColor=ConsoleColor::DarkMagenta;
	Console::BackgroundColor=ConsoleColor::Gray;
	Console::CursorLeft=10;
	Console::CursorTop=15;
	printf("Введите дистанцию в формате: [метры] [стиль] ");
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
		printf("Ошибка, такую дистанцию никто не плыл.");
		getch();
		return;
	}
	printf("%s на дистанции %d %s", name_of_fastest, meters, style);
	getch();
	fclose(in);
	return;
}




