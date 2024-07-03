#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace forma {

	/// <summary>
	/// ������ ��� Form2
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::ComboBox^  comboBox1;
	public:
		String^ a;
		String^ b;
		String^ textBox1old;
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(38, 75);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(85, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form2::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(38, 154);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(162, 154);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"����", L"�����", L"�����", L"�����"});
			this->comboBox1->Location = System::Drawing::Point(162, 74);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(85, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form2::comboBox1_SelectedIndexChanged);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"������� ���������";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
				 textBox1->Text = a;
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 a = textBox1->Text->ToString();
				 this->Close();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 a = "���� �������!";
				 this->Close();
			 }
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (comboBox1->SelectedIndex == 0) b = "����";
				 if (comboBox1->SelectedIndex == 1) b = "�����";
				 if (comboBox1->SelectedIndex == 2) b = "�����";
				 if (comboBox1->SelectedIndex == 3) b = "�����";
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->textBox1->Text=="") return;
			 try
			 {
				 System::Int32::Parse(this->textBox1->Text);
			 }
			 catch(...) //catch(Exception ^e)
			 {
				 MessageBox::Show("������� �� �����","������!",
					 System::Windows::Forms::MessageBoxButtons::OK,
					 System::Windows::Forms::MessageBoxIcon::Error);
				 this->textBox1->Text=textBox1old;
				 // String ^textBox1old � ������� ����������, ��� �������� ������� ��������
			 }
			 textBox1old = "";
			 //textBox1old = this->textBox1->Text;
		 }
};
}
