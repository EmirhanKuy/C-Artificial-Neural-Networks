#include "Artificial_Neural_Networks.h"

using namespace System;

Artificial_Neural_Networks::Artificial_Neural_Networks() {};

double Artificial_Neural_Networks::zScoreNormalize(double *X, int size)
{
	int avg, temp = 0, temp2 = 0, temp3 = 0, temp4 = 0;
	double standardDeviation;

	for (int i = 0; i < size; i++)
		temp += X[i];

	avg = temp / size;

	for (int i = 0; i < size; i++)
	{
		temp2 = X[i] - avg;
		temp3 += Math::Pow(temp2, 2);
	}

	temp4 = temp3 / size - 1;
	standardDeviation = Math::Sqrt(temp4);

	for (int i = 0; i < size; i++)
		X[i] = (X[i] - avg) / standardDeviation;

	return *X;
}

void Artificial_Neural_Networks::singleLayerSingleNeuronDiscretePerceptron()
{
	//double sign, net, c = 0.1, y1, y2, X1, X2;
	//float d, d1 = 1, d2 = -1; //Beklenen deðer
	//int error = 1, cycle = 0;
}

double	Artificial_Neural_Networks::getWeights2D()
{
	return 0;
}

void	Artificial_Neural_Networks::initializeWeights()
{
	
}
