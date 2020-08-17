#include "MyForm.h"

using namespace YSA;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

[STAThreadAttribute]

//Draw Function
Void MyForm::myDrawLine(Graphics^ g, Pen^ p, double *Weights, int xtranslate,int ytranslate)
{
	int y, x, y1 = 0, x1 = 0, y2 = 0, x2 = 0;

	x = pictureBox1->Width / 2;

	y = -Weights[0] * x - Weights[2] / Weights[1];

	if ((pictureBox1->Height / 2) > y && y > (-(pictureBox1->Height)))
	{
		x2 = x; //Right
		y2 = (-(Weights[0] * x2) - Weights[2]) / Weights[1]; //Right
		x1 = -(pictureBox1->Width / 2); //Left
		y1 = (-(Weights[0] * x1) - Weights[2]) / Weights[1]; //Left

		y1 = -y1;
		y2 = -y2;

		x1 += (pictureBox1->Width / 2); //Translate from coordinate plane to picturebox plane
		x2 += (pictureBox1->Width / 2);
		y1 += (pictureBox1->Height / 2);
		y2 += (pictureBox1->Height / 2);

		if (checkBox3->Checked)
			g->DrawLine(p, x1 + xtranslate, y1 - (ytranslate), x2 + xtranslate, y2 - (ytranslate));
		else
			g->DrawLine(p, x1, y1, x2, y2);
	}
	else
	{
		y = pictureBox1->Height / 2;
		y1 = y; //Bottom
		x1 = (-(Weights[1] * y1) - Weights[2]) / Weights[0]; //Bottom
		y2 = -(pictureBox1->Height / 2); //Top
		x2 = (-(Weights[1] * y2) - Weights[2]) / Weights[0]; //Top

		y1 = -y1;
		y2 = -y2;

		x1 += (pictureBox1->Width / 2);
		x2 += (pictureBox1->Width / 2);
		y1 += (pictureBox1->Height / 2);
		y2 += (pictureBox1->Height / 2);

		if (checkBox3->Checked)
			g->DrawLine(p, x1 + xtranslate, y1 - (ytranslate), x2 + xtranslate, y2 - (ytranslate));
		else
			g->DrawLine(p, x1, y1, x2, y2);
	}
}

//Drawing the Coordinate Plane
System::Void MyForm::pictureBox1_Paint(System::Object^sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ obj = e->Graphics;
	Pen^ myPen = gcnew Pen(Color::Black, 4);

	double xPlane[3] = { 1 ,0 ,0 };
	double yPlane[3] = { 0, 1 ,0 };

	myDrawLine(obj, myPen, xPlane, 0, 0);
	myDrawLine(obj, myPen, yPlane, 0, 0);
}

//Marking Points and Getting Coordinate Data
System::Void MyForm::pictureBox1_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	int X, Y;
	X = e->X;
	Y = e->Y;

	if (comboBox1->SelectedIndex == 0 || comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Select Data Set", "Warning");
	}
	else if (comboBox1->SelectedIndex == 1)
	{
		//Mark the Point
		color = Color::Green;
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + j, Y + i, color);

		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + i, Y + j, color);
		//Get the Coordinate Data and Save
		CX[totalCount] = X - (pictureBox1->Width / 2);
		CY[totalCount] = (pictureBox1->Height / 2) - Y;
		CC[totalCount] = comboBox1->SelectedIndex;
		counter1++;
	}
	else if (comboBox1->SelectedIndex == 2)
	{
		color = Color::Red;
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + j, Y + i, color);

		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + i, Y + j, color);

		CX[totalCount] = X - (pictureBox1->Width / 2);
		CY[totalCount] = (pictureBox1->Height / 2) - Y;
		CC[totalCount] = comboBox1->SelectedIndex;
		counter2++;
	}
	else if (comboBox1->SelectedIndex == 3)
	{
		color = Color::Orange;
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + j, Y + i, color);

		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + i, Y + j, color);

		CX[totalCount] = X - (pictureBox1->Width / 2);
		CY[totalCount] = (pictureBox1->Height / 2) - Y;
		CC[totalCount] = comboBox1->SelectedIndex;
		counter3++;
	}
	else if (comboBox1->SelectedIndex == 4)
	{
		color = Color::Purple;
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + j, Y + i, color);
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + i, Y + j, color);
		CX[totalCount] = X - (pictureBox1->Width / 2);
		CY[totalCount] = (pictureBox1->Height / 2) - Y;
		CC[totalCount] = comboBox1->SelectedIndex;
		counter4++;
	}
	else if (comboBox1->SelectedIndex == 5)
	{
		color = Color::Navy;
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + j, Y + i, color);
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + i, Y + j, color);
		CX[totalCount] = X - (pictureBox1->Width / 2);
		CY[totalCount] = (pictureBox1->Height / 2) - Y;
		CC[totalCount] = comboBox1->SelectedIndex;
		counter5++;
	}
	else if (comboBox1->SelectedIndex == 6)
	{
		color = Color::Gray;
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + j, Y + i, color);
		for (int i = -1; i <= 1; i++)
			for (int j = -5; j <= 5; j++)
				picBoxImage->SetPixel(X + i, Y + j, color);
		CX[totalCount] = X - (pictureBox1->Width / 2);
		CY[totalCount] = (pictureBox1->Height / 2) - Y;
		CC[totalCount] = comboBox1->SelectedIndex;
		counter6++;
	}
	totalCount = counter1 + counter2 + counter3 + counter4 + counter5 + counter6;
	label3->Text = "Number of Points : " + totalCount.ToString();
	pictureBox1->Image = picBoxImage;
}

//Initialize Weights
System::Void MyForm::InitializeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
		Graphics^ obj;
		obj = pictureBox1->CreateGraphics();
		Pen^ myPen = gcnew Pen(Color::Blue, 2);
		Pen^ greenPen = gcnew Pen(Color::Green, 2);
		Pen^ redPen = gcnew Pen(Color::Red, 2);
		Pen^ orangePen = gcnew Pen(Color::Orange, 2);
		Pen^ purplePen = gcnew Pen(Color::Purple, 2);
		Pen^ navyPen = gcnew Pen(Color::Navy, 2);
		Pen^ grayPen = gcnew Pen(Color::Gray, 2);

		int temp[6] = { 0, 0, 0, 0, 0, 0 };
		double tempWeights[3];

		//Counting how many classes there are
		for (int i = 0; i <= totalCount; i++)
		{
			if (temp[CC[i] - 1] != 1)
				temp[CC[i] - 1] = 1;
		}
		NumberOfClasses = temp[0] + temp[1] + temp[2] + temp[3] + temp[4] + temp[5];

		label2->Text = "Number of Classes : " + NumberOfClasses.ToString();

		colorIndex = new int[NumberOfClasses];
		for (int i = 0; i < NumberOfClasses; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (temp[j] == 1)
				{
					colorIndex[i] = j;
					temp[j] = 0;
					break;
				}
			}
		}

		if (NumberOfClasses == 0)
		{
			MessageBox::Show("You didnt select any points.", "Warning");
		}
		else if (NumberOfClasses == 1)
		{
			MessageBox::Show("Cant categorize 1 class with a line.", "Warning");
		}
		else if (NumberOfClasses == 2)
		{
			W[0] = -1, W[1] = 1, W[2] = 0;

			myDrawLine(obj, myPen, W, 0, 0);
			NumberOfNeurons = 1;
		}
		else
		{
			NumberOfNeurons = NumberOfClasses;
			for (int i = 0; i <= (NumberOfClasses * 3) - 3; i += 3)
			{
				W[i] = -1; W[i + 1] = 1; W[i + 2] = 0;
				tempWeights[0] = W[i];	tempWeights[1] = W[i + 1];	tempWeights[2] = W[i + 2];

				if (colorIndex[i / 3] == 1)
					myPen = greenPen;
				else if (colorIndex[i / 3] == 2)
					myPen = redPen;
				else if (colorIndex[i / 3] == 3)
					myPen = orangePen;
				else if (colorIndex[i / 3] == 4)
					myPen = purplePen;
				else if (colorIndex[i / 3] == 5)
					myPen = navyPen;
				else if (colorIndex[i / 3] == 6)
					myPen = grayPen;

				myDrawLine(obj, myPen, tempWeights, 0, 0);
			}
		}
}

//Discrete Perceptron
System::Void MyForm::binaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	double sign, net, d, d1 = 1, d2 = -1;
	double c = 0.1;
	int distance = 0, avgx = 0, avgy = 0;
	int cycle = 0;
	bool error = true;

	Artificial_Neural_Networks ANN;
	Graphics^ obj;
	obj = pictureBox1->CreateGraphics();
	Pen^ bluePen = gcnew Pen(Color::Blue, 2);


	if (checkBox3->Checked)
	{
		//Calculating translation distance
		double temp = 0, temp2 = 0;
		for (int i = 0; i < counter1 + counter2; i++)
			temp += CX[i];

		avgx = temp / (counter1 + counter2);

		for (int i = 0; i < counter1 + counter2; i++)
			temp2 += CY[i];

		avgy = temp2 / (counter1 + counter2);

		//Call normalization function
		ANN.zScoreNormalize(CX, counter1 + counter2);
		ANN.zScoreNormalize(CY, counter1 + counter2);
	}

	//for(int i = 0; i < counter1 + counter2 ; i++)
	//	MessageBox::Show("  " + CX[i] + "  " + CY[i] + "  " /*+ counter1 + "  " + W[0] + "  " + W[1] + "  " + W[2]*/ ); //TEST 

	while (error)
	{
		error = false;
		cycle++;
		for (int i = 0; i < counter1 + counter2; i++)
		{
			CC[i] == 1 ? d = d1 : d = d2;

			//net1 =w1^t * x1
			net = (W[0] * CX[i]) + (W[1] * CY[i]) + (W[2] * 1);

			//sign
			net > 0 ? sign = 1.0 : sign = -1.0;

			if (d != sign)
			{
				error = true;
				//w2 = w1 + c ( d - sign)x1
				W[0] += (c * (d - sign)) * CX[i];
				W[1] += (c * (d - sign)) * CY[i];
				W[2] += (c * (d - sign)) * 1;
			}

			pictureBox1->Refresh();

			myDrawLine(obj, bluePen, W, avgx, avgy);

			//obj->DrawLine(bluePen, 0.0, (pictureBox1->Height / 2) - y1, (float)pictureBox1->Width, (pictureBox1->Height / 2) - y2);
			//MessageBox::Show("  " + W[0] + " " + W[1] + " " + W[2]); //TEST
		}
		label1->Text = "Number of Cycles : " + cycle.ToString();
	}
}

//Continious Perceptron
System::Void MyForm::continiousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	double net, fnet, fnetDer, bias = 1, lambda = 1, c = 0.1, error = 1, maxError = 0.1; //Delta algorithm variables
	double d, d1 = 1, d2 = -1; //Expected values

	int cycle = 0; // How many times did the algorithm loop
	int distance = 0, avgx = 0, avgy = 0; //Translation value of the line after normalization
	
	Artificial_Neural_Networks ANN;
	Graphics^ obj;
	Pen^ bluePen = gcnew Pen(Color::Blue, 2);
	obj = pictureBox1->CreateGraphics();

	if (checkBox3->Checked)
	{
		//Calculating translation distance
		double temp = 0, temp2 = 0;

		for (int i = 0; i < counter1 + counter2; i++)
			temp += CX[i];

		avgx = temp / (counter1 + counter2);

		for (int i = 0; i < counter1 + counter2; i++)
			temp2 += CY[i];

		avgy = temp2 / (counter1 + counter2);

		//Call normalization function
		ANN.zScoreNormalize(CX, counter1 + counter2);
		ANN.zScoreNormalize(CY, counter1 + counter2);
	}

	while (error > maxError)
	{
		error = 0;
		cycle++;
		for (int i = 0; i < counter1 + counter2; i++)
		{
			CC[i] == 1 ? d = d1 : d = d2;

			//net1 =w1^t * x1
			net = (W[0] * CX[i]) + (W[1] * CY[i]) + (W[2] * bias);

			//f(net) = (2 / 1 + e^(-net*lambda)) - 1;
			fnet = (2 / (1 + Math::Exp(-net*lambda))) - bias;

			//F'(net) = (1-o*o) / 2
			fnetDer = 0.5 * (1 - fnet*fnet);

			//w2 = w1 + 0.5c (d - fnet) (1 - fnettürev)x1
			W[0] += 0.5 * c * (d - fnet) * fnetDer * CX[i];
			W[1] += 0.5 * c * (d - fnet) * fnetDer * CY[i];
			W[2] += 0.5 * c * (d - fnet) * fnetDer * 1;

			//Square error minimization = Error = 1/2(d-fnet)^2
			error += (Math::Pow((d - fnet), 2)) / 2.0;

			pictureBox1->Refresh();

			myDrawLine(obj, bluePen, W, avgx, avgy);
		}
		label1->Text = "Number of Cycles : " + cycle.ToString();
	}
}

//Binary MultiCategory Perceptron
System::Void MyForm::binaryToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Artificial_Neural_Networks ANN;
	Graphics^ obj;
	obj = pictureBox1->CreateGraphics();
	Pen^ myPen = gcnew Pen(Color::Blue, 2);
	Pen^ greenPen = gcnew Pen(Color::Green, 2);
	Pen^ redPen = gcnew Pen(Color::Red, 2);
	Pen^ orangePen = gcnew Pen(Color::Orange, 2);
	Pen^ purplePen = gcnew Pen(Color::Purple, 2);
	Pen^ navyPen = gcnew Pen(Color::Navy, 2);
	Pen^ grayPen = gcnew Pen(Color::Gray, 2);

	double sign, net, d, bias = 1;
	double c = 0.1;
	int cycle = 0;
	bool totalError = true; 
	double tempWeights[3] = {0, 0, 0};

	int tempx = 0, tempy = 0, counterx = 1, countery = 1;
	int translatex[6];
	int translatey[6];

	if (checkBox3->Checked)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < totalCount; j++)
			{
				if (CC[j] == (colorIndex[i] + 1))
				{
					tempx += CX[j];
					counterx += 1;
					tempy += CY[j];
					countery += 1;
				}
			}
			translatex[i] = tempx / counterx;
			translatey[i] = tempy / countery;
			counterx = 1;
			countery = 1;
			tempx = 1;
			tempy = 1;
		}

		//Call normalization function
		ANN.zScoreNormalize(CX, totalCount);
		ANN.zScoreNormalize(CY, totalCount);
	}

	while (totalError)
	{
		totalError = false;
		cycle++;

		for (int i = 0; i < totalCount; i++)
		{
			for (int j = 0; j <= (NumberOfNeurons * 3) - 3; j += 3)
			{
				//net1 =w1^t * x1
				net = (W[j] * CX[i]) + (W[j + 1] * CY[i]) + (W[j + 2] * bias);
				//Sign
				net > 0 ? sign = 1.0 : sign = -1.0;
				//Expected Value
				//CC[i] == (j / 3) + 1 ? d = 1.0 : d = -1.0;
				CC[i] == colorIndex[(j / 3)] ? d = 1.0 : d = -1.0;
				if (d != sign)
				{
					totalError = true;
					//w2 = w1 + c ( d - sign)x1
					W[j] += (c * (d - sign)) * CX[i];
					W[j + 1] += (c * (d - sign)) * CY[i];
					W[j + 2] += (c * (d - sign)) * bias;
				}
			}

			pictureBox1->Refresh();

			for (int k = 0; k <= (NumberOfNeurons * 3) - 3; k += 3)
			{
				tempWeights[0] = W[k];
				tempWeights[1] = W[k + 1];
				tempWeights[2] = W[k + 2];
				
				if (colorIndex[k / 3] == 0)
					myPen = greenPen;
				else if (colorIndex[k / 3] == 1)
					myPen = redPen;
				else if (colorIndex[k / 3] == 2)
					myPen = orangePen;
				else if (colorIndex[k / 3] == 3)
					myPen = purplePen;
				else if (colorIndex[k / 3] == 4)
					myPen = navyPen;
				else if (colorIndex[k / 3] == 5)
					myPen = grayPen;

				myDrawLine(obj, myPen, tempWeights, translatex[k / 3], translatey[k / 3]);
			}
		}
		label1->Text = "Number of Cycles : " + cycle.ToString();
	}
}

//Continious MultiCategory Perceptron
System::Void MyForm::continiousToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Artificial_Neural_Networks ANN;
	Graphics^ obj;
	obj = pictureBox1->CreateGraphics();
	Pen^ myPen = gcnew Pen(Color::Blue, 2);
	Pen^ greenPen = gcnew Pen(Color::Green, 2);
	Pen^ redPen = gcnew Pen(Color::Red, 2);
	Pen^ orangePen = gcnew Pen(Color::Orange, 2);
	Pen^ purplePen = gcnew Pen(Color::Purple, 2);
	Pen^ navyPen = gcnew Pen(Color::Navy, 2);
	Pen^ grayPen = gcnew Pen(Color::Gray, 2);

	double fnetDer, fnet, net, d, bias = 1, lambda = 1, error = 1, c = 0.5, maxError = 0.1;
	int cycle = 0;
	double tempWeights[3] = { 0, 0, 0 };

	int tempx = 0, tempy = 0, counterx = 1, countery = 1;
	int translatex[6];
	int translatey[6];

	if (checkBox3->Checked)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < totalCount; j++)
			{
				if (CC[j] == (colorIndex[i] + 1))
				{
					tempx += CX[j];
					counterx += 1;
					tempy += CY[j];
					countery += 1;
				}
			}
			translatex[i] = tempx / counterx;
			translatey[i] = tempy / countery;
			counterx = 1;
			countery = 1;
			tempx = 1;
			tempy = 1;
		}
		//Call normalization function
		ANN.zScoreNormalize(CX, totalCount);
		ANN.zScoreNormalize(CY, totalCount);
	}

	while (error > maxError)
	{
		error = 0;
		cycle++;

		for (int i = 0; i < totalCount; i++)
		{
			for (int j = 0; j <= (NumberOfNeurons * 3) - 3; j += 3)
			{
				//net1 =w1^t * x1
				net = (W[j] * CX[i]) + (W[j + 1] * CY[i]) + (W[j + 2] * bias);
				//f(net) = (2 / 1 + e^(-net*lambda)) - 1;
				fnet = (2 / (1 + Math::Exp(-net))) - 1;
				//F'(net) = (1-o*o) / 2
				fnetDer = (1 - Math::Pow(fnet, 2));
				//Expected Value
				CC[i] == colorIndex[(j / 3)] ? d = 1.0 : d = -1.0;
				//CC[i] == (j / 3) + 1 ? d = 1.0 : d = -1.0;
				//CC[colorIndex[(i / 3)]] == colorIndex[(j / 3)] ? d = 1.0 : d = -1.0;

				W[j] += 0.5 * c * (d - fnet) * fnetDer * CX[i];
				W[j + 1] += 0.5 * c * (d - fnet) * fnetDer * CY[i];
				W[j + 2] += 0.5 * c * (d - fnet) * fnetDer * bias;

				//Square error minimization = Error = 1/2(d-fnet)^2
				error += 0.5 * (Math::Pow((d - fnet), 2));
			}

			pictureBox1->Refresh();

			for (int k = 0; k <= (NumberOfNeurons * 3) - 3; k += 3)
			{
				tempWeights[0] = W[k];
				tempWeights[1] = W[k + 1];
				tempWeights[2] = W[k + 2];

				if (colorIndex[k / 3] == 0)
					myPen = greenPen;
				else if (colorIndex[k / 3] == 1)
					myPen = redPen;
				else if (colorIndex[k / 3] == 2)
					myPen = orangePen;
				else if (colorIndex[k / 3] == 3)
					myPen = purplePen;
				else if (colorIndex[k / 3] == 4)
					myPen = navyPen;
				else if (colorIndex[k / 3] == 5)
					myPen = grayPen;

				myDrawLine(obj, myPen, tempWeights, translatex[k / 3], translatey[k / 3]);
			}
		}
		label1->Text = "Number of Cycles : " + cycle.ToString();
	}
}

//Reset
System::Void MyForm::button1_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	System::Windows::Forms::Application::Restart();
}

//Exit
System::Void MyForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::Application::Exit();
}

int main()
{
	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::Run(gcnew YSA::MyForm());
	return 0;
}