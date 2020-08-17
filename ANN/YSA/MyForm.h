#pragma once
#include "Artificial_Neural_Networks.h"

namespace YSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	double CX[50], CY[50];//Noktalarýn X Y ve Hangi Data setine ait olduðu CC dizisinde
	int CC[50];
	int NumberOfNeurons;
	int NumberOfClasses = 0;
	int *colorIndex;
	double W[18];//Aðýrlýk dizisi

	int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, totalCount = 0;//Data Setler için ayrý sayaç

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Bitmap^ picBoxImage;
		Color color;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			color = Color::White;
			picBoxImage = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = picBoxImage;
			for (int i = 0; i < pictureBox1->Height; i++)
				for (int j = 0; j < pictureBox1->Width; j++)
					picBoxImage->SetPixel(j, i, color);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ýnitializeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  binaryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  continiousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  multiCategoryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  binaryToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  continiousToolStripMenuItem1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//Draw line function
		Void myDrawLine(Graphics^ g, Pen^ p, double *Weights, int xtranslate,int ytranslate);
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ýnitializeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continiousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiCategoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continiousToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(979, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ýnitializeToolStripMenuItem,
					this->trainingToolStripMenuItem, this->multiCategoryToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 22);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// ýnitializeToolStripMenuItem
			// 
			this->ýnitializeToolStripMenuItem->Name = L"ýnitializeToolStripMenuItem";
			this->ýnitializeToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->ýnitializeToolStripMenuItem->Text = L"Initialize";
			this->ýnitializeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::InitializeToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binaryToolStripMenuItem,
					this->continiousToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// binaryToolStripMenuItem
			// 
			this->binaryToolStripMenuItem->Name = L"binaryToolStripMenuItem";
			this->binaryToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->binaryToolStripMenuItem->Text = L"Binary";
			this->binaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::binaryToolStripMenuItem_Click);
			// 
			// continiousToolStripMenuItem
			// 
			this->continiousToolStripMenuItem->Name = L"continiousToolStripMenuItem";
			this->continiousToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->continiousToolStripMenuItem->Text = L"Continious";
			this->continiousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continiousToolStripMenuItem_Click);
			// 
			// multiCategoryToolStripMenuItem
			// 
			this->multiCategoryToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binaryToolStripMenuItem1,
					this->continiousToolStripMenuItem1
			});
			this->multiCategoryToolStripMenuItem->Name = L"multiCategoryToolStripMenuItem";
			this->multiCategoryToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->multiCategoryToolStripMenuItem->Text = L"MultiCategoryTraining";
			// 
			// binaryToolStripMenuItem1
			// 
			this->binaryToolStripMenuItem1->Name = L"binaryToolStripMenuItem1";
			this->binaryToolStripMenuItem1->Size = System::Drawing::Size(132, 22);
			this->binaryToolStripMenuItem1->Text = L"Binary";
			this->binaryToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::binaryToolStripMenuItem1_Click);
			// 
			// continiousToolStripMenuItem1
			// 
			this->continiousToolStripMenuItem1->Name = L"continiousToolStripMenuItem1";
			this->continiousToolStripMenuItem1->Size = System::Drawing::Size(132, 22);
			this->continiousToolStripMenuItem1->Text = L"Continious";
			this->continiousToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::continiousToolStripMenuItem1_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox1->Location = System::Drawing::Point(8, 23);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(797, 41);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(72, 17);
			this->checkBox3->TabIndex = 4;
			this->checkBox3->Text = L"Normalize";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(512, 510);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Cycle : 0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(676, 317);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(82, 32);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Choose", L"Data Set 1", L"Data Set 2", L"Data Set 3",
					L"Data Set 4", L"Data Set 5", L"Data Set 6"
			});
			this->comboBox1->Location = System::Drawing::Point(676, 39);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(82, 21);
			this->comboBox1->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(513, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Number of Classes : 0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(512, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Number of Points : 0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 558);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Koordinat Düzlemi Çizme
	private: System::Void MyForm::pictureBox1_Paint(System::Object^sender, System::Windows::Forms::PaintEventArgs^ e);

	//Initialize Doðru çizme
	private: System::Void MyForm::InitializeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	//Noktalarý alma
	private: System::Void MyForm::pictureBox1_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	
	//Reset
	private: System::Void MyForm::button1_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	 //Exit
	private: System::Void MyForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	//Binary Perceptron
	private: System::Void MyForm::binaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	//Continous Perceptron
	private: System::Void MyForm::continiousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	//Binary MultiCategory Perceptron
	private: System::Void binaryToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);

	//Continious MultiCategory Perceptron
	private: System::Void continiousToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
};
}