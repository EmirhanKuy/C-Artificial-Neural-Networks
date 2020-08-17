#pragma once
#include <windows.h>

class Artificial_Neural_Networks 
{
private:
	double Weightss[3] = {0,0,0};
public:
			Artificial_Neural_Networks();
	double	getWeights2D();
	void	initializeWeights();
	void	singleLayerSingleNeuronDiscretePerceptron();
	double	zScoreNormalize(double *X, int size);
};

//Aðýrlýklar initialize fonsiyonu