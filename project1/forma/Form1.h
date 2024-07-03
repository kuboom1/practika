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
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������������������������������������ToolStripMenuItem;
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
		/// ��������� ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->����ToolStripMenuItem, 
				this->�������ToolStripMenuItem, this->�����ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(764, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�������ToolStripMenuItem, 
				this->���������ToolStripMenuItem});
			this->����ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"����ToolStripMenuItem.Image")));
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"���������ToolStripMenuItem.Image")));
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->�ToolStripMenuItem, 
				this->����������������������������������������������ToolStripMenuItem, this->������������������������������������ToolStripMenuItem, 
				this->������������������������ToolStripMenuItem, this->��������������������������������������ToolStripMenuItem, this->�����������������������������������������������ToolStripMenuItem});
			this->�������ToolStripMenuItem->Enabled = false;
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �ToolStripMenuItem
			// 
			this->�ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�ToolStripMenuItem.Image")));
			this->�ToolStripMenuItem->Name = L"�ToolStripMenuItem";
			this->�ToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->�ToolStripMenuItem->Text = L"����� ������ ������ ������ ����� �����\?               ";
			this->�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�ToolStripMenuItem_Click);
			// 
			// ����������������������������������������������ToolStripMenuItem
			// 
			this->����������������������������������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"����������������������������������������������ToolStripMenuItem.Image")));
			this->����������������������������������������������ToolStripMenuItem->Name = L"����������������������������������������������ToolStripMenuItem";
			this->����������������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->����������������������������������������������ToolStripMenuItem->Text = L"���� �� ������, ��������� ���������� ���������� �����\?";
			this->����������������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������������������������������������������ToolStripMenuItem_Click);
			// 
			// ������������������������������������ToolStripMenuItem
			// 
			this->������������������������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"������������������������������������ToolStripMenuItem.Image")));
			this->������������������������������������ToolStripMenuItem->Name = L"������������������������������������ToolStripMenuItem";
			this->������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->������������������������������������ToolStripMenuItem->Text = L"������� ������� �������� ���� ����������\?";
			this->������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::������������������������������������ToolStripMenuItem_Click);
			// 
			// ������������������������ToolStripMenuItem
			// 
			this->������������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"������������������������ToolStripMenuItem.Image")));
			this->������������������������ToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->������������������������ToolStripMenuItem->Name = L"������������������������ToolStripMenuItem";
			this->������������������������ToolStripMenuItem->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->������������������������ToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->������������������������ToolStripMenuItem->Text = L"��� ���� ������ �� ���������";
			this->������������������������ToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::������������������������ToolStripMenuItem_Click);
			// 
			// ��������������������������������������ToolStripMenuItem
			// 
			this->��������������������������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"��������������������������������������ToolStripMenuItem.Image")));
			this->��������������������������������������ToolStripMenuItem->Name = L"��������������������������������������ToolStripMenuItem";
			this->��������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->��������������������������������������ToolStripMenuItem->Text = L"���������� ������ ���������� ������������";
			this->��������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��������������������������������������ToolStripMenuItem_Click);
			// 
			// �����������������������������������������������ToolStripMenuItem
			// 
			this->�����������������������������������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�����������������������������������������������ToolStripMenuItem.Image")));
			this->�����������������������������������������������ToolStripMenuItem->Name = L"�����������������������������������������������ToolStripMenuItem";
			this->�����������������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(421, 22);
			this->�����������������������������������������������ToolStripMenuItem->Text = L"��������� �� ��������� ����� � ���������� �����������";
			this->�����������������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����������������������������������������������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�����ToolStripMenuItem.Image")));
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ToolStripMenuItem_Click);
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
			this->tabPage1->Text = L"������� ������";
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
			this->tabPage2->Text = L"������";
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
			this->tabPage3->Text = L"���������";
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
			this->Text = L"��������";
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
private: System::Void �ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
				 sprintf(ss,"%s �������\n%ld �����", best.name, best.points);
				 s = gcnew String(ss);
				 MessageBox::Show(s,"���������� ������������ � ����� ������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
					 MessageBox::Show("���� �� ������!","������!",
						 MessageBoxButtons::OK,MessageBoxIcon::Error);
					 Marshal::FreeHGlobal(IntPtr((void*)str_tmp));
					 return;
				 }
				 Marshal::FreeHGlobal(IntPtr((void *)str_tmp));
			 }
			 else return;
			 �������ToolStripMenuItem->Enabled=true;
			 DataTable ^Table1;
			 Table1 = gcnew DataTable();
			 this->dataGridView1->DataSource = Table1;
			 //this->dataGridView1->AllowUserToAddRows=false;
			 //this->dataGridView1->AllowUserToDeleteRows=false;
			 //this->dataGridView1->ReadOnly=true;
			 Table1->Columns->Add("���");
			 Table1->Columns->Add("���");
			 Table1->Columns->Add("�����");
			 Table1->Columns->Add("���������");
			 Table1->Columns->Add("����� �����");
			 Table1->Columns->Add("������ �����");
			 Table1->Columns->Add("����");
			 Table1->Columns->Add("�����");
			 fscanf(in,"%d",&NC);
			 swimmers = new z[NC];
			 for(i=0;i<NC;i++)
			 {
				 fscanf(in ,"%s%d%s%d%s%s%d%s", swimmers[i].name, &swimmers[i].year, swimmers[i].style, 
					 &swimmers[i].distant, swimmers[i].new_time, swimmers[i].prev_time, &swimmers[i].points, swimmers[i].city);
				 Table1->Rows->Add();

				 s = gcnew String(swimmers[i].name);
				 Table1->Rows[i][0] = s; // ��� Table1->Rows[i]["���"] = s;

				 Table1->Rows[i][1] = swimmers[i].year; // ��� Table1->Rows[i]["���"] = swimmers[i].year;

				 s = gcnew String(swimmers[i].style);
				 Table1->Rows[i][2] = s; // ��� Table1->Rows[i]["�����"] = s;

				 Table1->Rows[i][3] = swimmers[i].distant; // ��� Table1->Rows[i]["���������"] = swimmers[i].distant;

				 s = gcnew String(swimmers[i].new_time);
				 Table1->Rows[i][4] = s; // ��� Table1->Rows[i]["����� �����"] = s;

				 s = gcnew String(swimmers[i].prev_time);
				 Table1->Rows[i][5] = s; // ��� Table1->Rows[i]["������ �����"] = s;

				 Table1->Rows[i][6] = swimmers[i].points; // ��� Table1->Rows[i]["���"] = swimmers[i].points;

				 s = gcnew String(swimmers[i].city);
				 Table1->Rows[i][7] = s; // ��� Table1->Rows[i]["�����"] = s;
			 }
			 fclose(in);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ����������������������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
			 sprintf(ss, "%s � %s ������� �� %d �����", examp.name, name_of_match, examp.points);
			 s = gcnew String(ss);
			 MessageBox::Show(s, "������, ��������� ���������� ���-�� �����:", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
private: System::Void ������������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
			 sprintf(ss, "%d ������� �� %d", k, NC);
			 s = gcnew String(ss);
			 MessageBox::Show(s, "���������� ����������, ��������� ����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
private: System::Void ������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ c;
			 char best_name[80] = "";
			 char ss[80];
			 String^ s;
			 Form2 ^F2 = gcnew Form2();
			 F2->ShowDialog();
			 c = F2->a + " ������ " + F2->b;
			 MessageBox::Show(c, "�� �����");
			 int meters = Int32::Parse(F2->a);
			 char* style = (char*)(void*)Marshal::StringToHGlobalAnsi(F2->b);
			 Marshal::FreeHGlobal(IntPtr((void*)style));
			 best_on_dist_form(best_name, meters, style, swimmers);
			 if (strcmp(best_name, "")==0)
			 {
				 MessageBox::Show("����� ��������� ����� �� ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
			 else
			 {
				 sprintf(ss, "%s �� ��������� %s", best_name, c);
				 s = gcnew String(ss);
				 MessageBox::Show(s, "������ �� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
			 }
		 }
private: System::Void ��������������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i;
			 struct sp* nt, *z;
			 char ss[80];
			 String ^s;
			 tabControl1->SelectTab(1); // ��������� �� ������� "������"
			 if(!spisok)
				 for(i=0;i<NC;i++)
					 vstavka(swimmers,swimmers[i].name);
			 richTextBox1->ReadOnly=1;
			 richTextBox1->Clear();
			 richTextBox1->Text ="\t���������� ������\n ================";
			 for(nt=spisok; nt!=0; nt=nt->sled)
			 {
				 sprintf(ss," %-20s %6d",nt->fio,nt->points);
				 s = gcnew String(ss,0,31);
				 richTextBox1->Text = richTextBox1->Text+"\n"+s;
			 }
			 richTextBox2->ReadOnly=1;
			 richTextBox2->Clear();
			 richTextBox2->Text ="\t�������� ���������� ������\n ================";
			 for(nt = spisok; nt != 0; z = nt, nt=nt->sled);
			 for(nt = z; nt != 0; nt=nt->pred)
			 {
				 sprintf(ss," %-20s %6d",nt->fio,nt->points);
				 s = gcnew String(ss, 0, 31);
				 richTextBox2->Text = richTextBox2->Text+"\n"+s;
			 }
		 }
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void tabPage3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void �����������������������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 tabControl1->SelectTab(2); // ��������� �� ������� ����������"
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
				 g->FillPie(myBrush, 25, 25, 185, 185, aStart, aEnd-aStart); // ���������� ������ ���������
				 if (i > NC/2)
				 {
					 g->FillRectangle(myBrush, 440, (55+(i-1)*20)%(280), 20, 20); // ��������� ��������� ������� ����� �������� �������
				 }
				 else
				 {
					 g->FillRectangle(myBrush, 300, 50+(i-1)*20, 20, 20); // ��������� ��������� ������� ����� �������� �������
				 }
				 //g->FillRectangle(myBrush, 300, 50+(i-1)*20, 20, 20); // ��������� ��������� ������� ����� �������� �������
				 myBrush->Color::set(Color::FromArgb(196, 0, 0, 0));
				 xPos = 30+(185-25)/2+(185-25)/1.5*Math::Cos(Math::PI*(aStart+aEnd)/360);
				 yPos = 30+(185-25)/2+(185-25)/1.5*Math::Sin(Math::PI*(aStart+aEnd)/360);
				 if (i > NC/2)
				 {
					 g->DrawString(gcnew String(nt->fio), myFont, myBrush, 460, (55+(i-1)*20)%(280)); // ������� ������ �������
				 }
				 else
				 {
					 g->DrawString(gcnew String(nt->fio), myFont, myBrush, 320, 55+(i-1)*20); // ������� ������ �������
				 }
				 g->DrawString(Convert::ToString(nt->points*100/ochki)+"%", myFont, myBrush, xPos, yPos);
			 } //����� ����� for�
		 } // ����� �������

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