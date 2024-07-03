#pragma once

#include "Form2.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
//#include <clocale>

//int _CRT_SECURE_NO_WARNINGS;
using namespace System::Runtime::InteropServices;

int NC;

float text_to_time(char *);

struct z {
	char name[20];
	int year;
	char style[7];
	int distant;
	char new_time[10];
	char prev_time[10];
	int points;
	char city[10];
};

struct sp {
	char fio[20];
	int points;
	struct sp* pred;
	struct sp* sled;
} *spisok;

struct z *swimmers;

void vstavka(struct z* swimmers, char* fio)
{
	int i;
	struct sp *nov, *nt, *z=0;
	for(nt=spisok; nt!=0 && strcmp(nt->fio,fio)<0; z=nt, nt=nt->sled);
	if(nt && strcmp(nt->fio,fio)==0) return;
	nov =(struct sp *) malloc(sizeof(struct sp));
	strcpy(nov->fio,fio);
	nov->sled=nt;
	nov->pred=z;
	nov->points=0;
	for(i=0;i<NC;i++)
		if(strcmp(swimmers[i].name,fio)==0) nov->points=swimmers[i].points;
	if (!z) spisok=nov;
	else z->sled=nov;
	if (nt) nt->pred=nov;
	return;
}

void best_on_dist_form(char* name, int meters, char* style, struct z* swimmers)
{
	float fastest_time; char name_of_fastest[20] = "";
	char swimmer_is_found_flag = 0;

	fastest_time = text_to_time(swimmers[0].new_time);
	for(int i=1; i<NC; i++)
	{
		if ((((meters==swimmers[i].distant)&&(strcmp(style, swimmers[i].style)==0))&&(fastest_time>text_to_time(swimmers[i].new_time))))
		{
			strcpy(name_of_fastest, swimmers[i].name);
			fastest_time = text_to_time(swimmers[i].new_time);
			swimmer_is_found_flag = 1;
		}
	}
	if (!swimmer_is_found_flag) return;
	strcpy(name, name_of_fastest);
	return;
}

namespace forma {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// —водка дл€ Form1
	///
	/// ¬нимание! ѕри изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") дл€ средства компил€ции управл€емого ресурса,
	///          св€занного со всеми файлами с расширением .resx, от которых зависит данный класс. ¬ противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  завершитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  вопросыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  аToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  кто—талЋучшимЌаƒистанцииToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  алфавитный—писок”частников—оревнованийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->завершитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вопросыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->аToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->алфавитный—писок”частников—оревнованийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->файлToolStripMenuItem, 
				this->вопросыToolStripMenuItem, this->выходToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(764, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->открытьToolStripMenuItem, 
				this->завершитьToolStripMenuItem});
			this->файлToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"файлToolStripMenuItem.Image")));
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->файлToolStripMenuItem->Text = L"‘айл";
			this->файлToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::файлToolStripMenuItem_Click);
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"открытьToolStripMenuItem.Image")));
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->открытьToolStripMenuItem->Text = L"ќткрыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открытьToolStripMenuItem_Click);
			// 
			// завершитьToolStripMenuItem
			// 
			this->завершитьToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"завершитьToolStripMenuItem.Image")));
			this->завершитьToolStripMenuItem->Name = L"завершитьToolStripMenuItem";
			this->завершитьToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->завершитьToolStripMenuItem->Text = L"«авершить";
			this->завершитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::завершитьToolStripMenuItem_Click);
			// 
			// вопросыToolStripMenuItem
			// 
			this->вопросыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->аToolStripMenuItem, 
				this->естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem, this->сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem, 
				this->кто—талЋучшимЌаƒистанцииToolStripMenuItem, this->алфавитный—писок”частников—оревнованийToolStripMenuItem, this->диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem});
			this->вопросыToolStripMenuItem->Enabled = false;
			this->вопросыToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"вопросыToolStripMenuItem.Image")));
			this->вопросыToolStripMenuItem->Name = L"вопросыToolStripMenuItem";
			this->вопросыToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->вопросыToolStripMenuItem->Text = L"¬опросы";
			// 
			// аToolStripMenuItem
			// 
			this->аToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"аToolStripMenuItem.Image")));
			this->аToolStripMenuItem->Name = L"аToolStripMenuItem";
			this->аToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->аToolStripMenuItem->Text = L" акой пловец набрал больше всего очков\?               ";
			this->аToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::аToolStripMenuItem_Click);
			// 
			// естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem
			// 
			this->естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem.Image")));
			this->естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem->Name = L"естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem";
			this->естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem->Text = L"≈сть ли пловцы, набравшие одинаковое количество очков\?";
			this->естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem_Click);
			// 
			// сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem
			// 
			this->сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem.Image")));
			this->сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem->Name = L"сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem";
			this->сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem->Text = L"—колько пловцов улучшили свои результаты\?";
			this->сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem_Click);
			// 
			// кто—талЋучшимЌаƒистанцииToolStripMenuItem
			// 
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"кто—талЋучшимЌаƒистанцииToolStripMenuItem.Image")));
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->Name = L"кто—талЋучшимЌаƒистанцииToolStripMenuItem";
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->Text = L" то стал лучшим на дистанции";
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->кто—талЋучшимЌаƒистанцииToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::кто—талЋучшимЌаƒистанцииToolStripMenuItem_Click);
			// 
			// алфавитный—писок”частников—оревнованийToolStripMenuItem
			// 
			this->алфавитный—писок”частников—оревнованийToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"алфавитный—писок”частников—оревнованийToolStripMenuItem.Image")));
			this->алфавитный—писок”частников—оревнованийToolStripMenuItem->Name = L"алфавитный—писок”частников—оревнованийToolStripMenuItem";
			this->алфавитный—писок”частников—оревнованийToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->алфавитный—писок”частников—оревнованийToolStripMenuItem->Text = L"јлфавитный список участников соревнований";
			this->алфавитный—писок”частников—оревнованийToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::алфавитный—писок”частников—оревнованийToolStripMenuItem_Click);
			// 
			// диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem
			// 
			this->диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem.Image")));
			this->диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem->Name = L"диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem";
			this->диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem->Text = L"ƒиаграмма по набранным очкам в процентном соотношении";
			this->диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"выходToolStripMenuItem.Image")));
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->выходToolStripMenuItem->Text = L"¬ыход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 28);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(764, 508);
			this->tabControl1->TabIndex = 1;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(756, 482);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"¬ходные данные";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(750, 476);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox2);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(756, 482);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"—писок";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->richTextBox2->Location = System::Drawing::Point(375, 0);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(381, 482);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(353, 482);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(756, 482);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"ƒиаграмма";
			this->tabPage3->UseVisualStyleBackColor = true;
			this->tabPage3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage3_Paint);
			this->tabPage3->Click += gcnew System::EventHandler(this, &Form1::tabPage3_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"results";
			this->openFileDialog1->Filter = L"Data Files (*.dat) | *.dat";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(764, 534);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" урсова€";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void аToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i;
			 struct z best;
			 char ss[100];
			 String ^s;

			 strcpy(best.name,swimmers[0].name);
			 best.points=swimmers[0].points;
			 for(i=1;i<NC;i++)
				 if (swimmers[i].points > best.points)
				 {
					 strcpy(best.name,swimmers[i].name);
					 best.points = swimmers[i].points;
				 }
				 sprintf(ss,"%s получил\n%ld очков", best.name, best.points);
				 s = gcnew String(ss);
				 MessageBox::Show(s,"ѕобедитель соревнований в общем зачете", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void завершитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FILE *in;
			 int i;
			 char ctemp[90];
			 String ^s;
			 if (openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK)
			 {
				 s = openFileDialog1->FileName;
				 char *str_tmp=(char*)(void*)Marshal::StringToHGlobalAnsi(s);
				 if ((in=fopen(str_tmp,"r"))==NULL)
				 {
					 MessageBox::Show("‘айл не открыт!","ќшибка!",
						 MessageBoxButtons::OK,MessageBoxIcon::Error);
					 Marshal::FreeHGlobal(IntPtr((void*)str_tmp));
					 return;
				 }
				 Marshal::FreeHGlobal(IntPtr((void *)str_tmp));
			 }
			 else return;
			 вопросыToolStripMenuItem->Enabled=true;
			 DataTable ^Table1;
			 Table1 = gcnew DataTable();
			 this->dataGridView1->DataSource = Table1;
			 //this->dataGridView1->AllowUserToAddRows=false;
			 //this->dataGridView1->AllowUserToDeleteRows=false;
			 //this->dataGridView1->ReadOnly=true;
			 Table1->Columns->Add("‘»ќ");
			 Table1->Columns->Add("√од");
			 Table1->Columns->Add("—тиль");
			 Table1->Columns->Add("ƒистанци€");
			 Table1->Columns->Add("Ќовое врем€");
			 Table1->Columns->Add("—тарое врем€");
			 Table1->Columns->Add("ќчки");
			 Table1->Columns->Add("√ород");
			 fscanf(in,"%d",&NC);
			 swimmers = new z[NC];
			 for(i=0;i<NC;i++)
			 {
				 fscanf(in ,"%s%d%s%d%s%s%d%s", swimmers[i].name, &swimmers[i].year, swimmers[i].style, 
					 &swimmers[i].distant, swimmers[i].new_time, swimmers[i].prev_time, &swimmers[i].points, swimmers[i].city);
				 Table1->Rows->Add();

				 s = gcnew String(swimmers[i].name);
				 Table1->Rows[i][0] = s; // или Table1->Rows[i]["‘»ќ"] = s;

				 Table1->Rows[i][1] = swimmers[i].year; // или Table1->Rows[i]["√од"] = swimmers[i].year;

				 s = gcnew String(swimmers[i].style);
				 Table1->Rows[i][2] = s; // или Table1->Rows[i]["—тиль"] = s;

				 Table1->Rows[i][3] = swimmers[i].distant; // или Table1->Rows[i]["ƒистанци€"] = swimmers[i].distant;

				 s = gcnew String(swimmers[i].new_time);
				 Table1->Rows[i][4] = s; // или Table1->Rows[i]["Ќовое врем€"] = s;

				 s = gcnew String(swimmers[i].prev_time);
				 Table1->Rows[i][5] = s; // или Table1->Rows[i]["—тарое врем€"] = s;

				 Table1->Rows[i][6] = swimmers[i].points; // или Table1->Rows[i]["√од"] = swimmers[i].points;

				 s = gcnew String(swimmers[i].city);
				 Table1->Rows[i][7] = s; // или Table1->Rows[i]["√ород"] = s;
			 }
			 fclose(in);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void естьЋиѕловцыЌабравшиеќдинаковое оличествоќчковToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i, j;
			 char name_of_match[20] = "";
			 char ss[80];
			 String ^s;
			 struct z examp;
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
			 sprintf(ss, "%s и %s набрали по %d очков", examp.name, name_of_match, examp.points);
			 s = gcnew String(ss);
			 MessageBox::Show(s, "ѕловцы, набравшие одинаковое кол-во очков:", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
private: System::Void сколькоѕловцов”лучшили—вои–езультатыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i, k=0;
			 float prev_res, new_res;
			 char ss[80];
			 String ^s;
			 for(i=0;i<NC;i++)
			 {
				 prev_res = text_to_time(swimmers[i].prev_time);
				 new_res = text_to_time(swimmers[i].new_time);
				 if ((prev_res - new_res) > 0) k++;
			 }
			 sprintf(ss, "%d пловцов из %d", k, NC);
			 s = gcnew String(ss);
			 MessageBox::Show(s, " оличество участников, улучивших результаты", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
private: System::Void кто—талЋучшимЌаƒистанцииToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ c;
			 char best_name[80] = "";
			 char ss[80];
			 String^ s;
			 Form2 ^F2 = gcnew Form2();
			 F2->ShowDialog();
			 c = F2->a + " метров " + F2->b;
			 MessageBox::Show(c, "¬ы ввели");
			 int meters = Int32::Parse(F2->a);
			 char* style = (char*)(void*)Marshal::StringToHGlobalAnsi(F2->b);
			 Marshal::FreeHGlobal(IntPtr((void*)style));
			 best_on_dist_form(best_name, meters, style, swimmers);
			 if (strcmp(best_name, "")==0)
			 {
				 MessageBox::Show("“акую дистанцию никто не плыл", "ќшибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
			 else
			 {
				 sprintf(ss, "%s на дистанции %s", best_name, c);
				 s = gcnew String(ss);
				 MessageBox::Show(s, "Ћучший на дистанции", MessageBoxButtons::OK, MessageBoxIcon::Information);
			 }
		 }
private: System::Void алфавитный—писок”частников—оревнованийToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i;
			 struct sp* nt, *z;
			 char ss[80];
			 String ^s;
			 tabControl1->SelectTab(1); // переходим на вкладку "—ѕ»—ќ "
			 if(!spisok)
				 for(i=0;i<NC;i++)
					 vstavka(swimmers,swimmers[i].name);
			 richTextBox1->ReadOnly=1;
			 richTextBox1->Clear();
			 richTextBox1->Text ="\tјЋ‘ј¬»“Ќџ… —ѕ»—ќ \n ================";
			 for(nt=spisok; nt!=0; nt=nt->sled)
			 {
				 sprintf(ss," %-20s %6d",nt->fio,nt->points);
				 s = gcnew String(ss,0,31);
				 richTextBox1->Text = richTextBox1->Text+"\n"+s;
			 }
			 richTextBox2->ReadOnly=1;
			 richTextBox2->Clear();
			 richTextBox2->Text ="\tќЅ–ј“Ќџ… јЋ‘ј¬»“Ќџ… —ѕ»—ќ \n ================";
			 for(nt = spisok; nt != 0; z = nt, nt=nt->sled);
			 for(nt = z; nt != 0; nt=nt->pred)
			 {
				 sprintf(ss," %-20s %6d",nt->fio,nt->points);
				 s = gcnew String(ss, 0, 31);
				 richTextBox2->Text = richTextBox2->Text+"\n"+s;
			 }
		 }
private: System::Void файлToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void tabPage3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void диаграммаѕоЌабраннымќчкам¬ѕроцентном—оотношенииToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 tabControl1->SelectTab(2); // переходим на вкладку Ђƒ»ј√–јћћј"
		 }
private: System::Void tabPage3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			 Pen ^myPen = gcnew Pen(System::Drawing::Color::Black, 3);
			 SolidBrush ^myBrush = gcnew SolidBrush(Color::FromArgb(196, 0, 0, 0));
			 System::Drawing::Font^ myFont = gcnew System::Drawing::Font("Arial", 8);
			 int i, K;
			 int iRed, iGreen, iBlue;
			 int aStart, aEnd;
			 int ochki;
			 float xPos, yPos;
			 struct sp *nt;
			 Graphics ^g = tabPage3->CreateGraphics();
			 g->Clear(System::Drawing::Color::White);
			 if (!spisok)
				 for(i=0;i<NC;i++)
					 vstavka(swimmers,swimmers[i].name);
			 K = 0; ochki = 0;
			 for(nt=spisok; nt!=0; nt=nt->sled)
			 {
				 K++;
				 ochki += nt->points;
			 }
			 g->DrawEllipse(myPen,25,25,185,185);
			 aEnd = 0;
			 for(nt=spisok, i=0; nt!=0; nt=nt->sled, i++)
			 {
				 iRed = (((i+1)&4)>0)*255 / (i/8+1);
				 iGreen = (((i+1)&2)>0)*255 / (i/8+1);
				 iBlue = (((i+1)&1)>0)*255 / (i/8+1);
				 aStart = aEnd;
				 aEnd += nt->points*360 / ochki;
				 if(i == K-1) aEnd = 360;
				 myBrush->Color::set(Color::FromArgb(196, iRed, iGreen, iBlue));
				 g->FillPie(myBrush, 25, 25, 185, 185, aStart, aEnd-aStart); // заполнение цветом сегментов
				 if (i > NC/2)
				 {
					 g->FillRectangle(myBrush, 440, (55+(i-1)*20)%(280), 20, 20); // рисование квадратов разного цвета напротив фамилий
				 }
				 else
				 {
					 g->FillRectangle(myBrush, 300, 50+(i-1)*20, 20, 20); // рисование квадратов разного цвета напротив фамилий
				 }
				 //g->FillRectangle(myBrush, 300, 50+(i-1)*20, 20, 20); // рисование квадратов разного цвета напротив фамилий
				 myBrush->Color::set(Color::FromArgb(196, 0, 0, 0));
				 xPos = 30+(185-25)/2+(185-25)/1.5*Math::Cos(Math::PI*(aStart+aEnd)/360);
				 yPos = 30+(185-25)/2+(185-25)/1.5*Math::Sin(Math::PI*(aStart+aEnd)/360);
				 if (i > NC/2)
				 {
					 g->DrawString(gcnew String(nt->fio), myFont, myBrush, 460, (55+(i-1)*20)%(280)); // фамилии первый столбец
				 }
				 else
				 {
					 g->DrawString(gcnew String(nt->fio), myFont, myBrush, 320, 55+(i-1)*20); // фамилии второй столбец
				 }
				 g->DrawString(Convert::ToString(nt->points*100/ochki)+"%", myFont, myBrush, xPos, yPos);
			 } //конец цикла forЕ
		 } // конец функции

};
}

float text_to_time(char *time) // char 1:14:06 -> int 74.06 s
{
	float res;
	char temp[3];
	res = (float)atoi(time+5); res /= 100.0;
	strncpy(temp, time+2, 2); temp[2] = 0; res += atoi(temp);
	strncpy(temp, time, 1); temp[1] = 0; res += atoi(temp)*60;
	return res;
}