#include <iostream>
#include "Calculo.h"

Calculo::Calculo(int inicio, unsigned int tamanho) 
{
    this->inicio = inicio;
    this->tamanho = tamanho;
}

Calculo::~Calculo()
{
	this->inicio = 0;
}

void Calculo::calcula() 
{
}

void Calculo::limpaCalculo()
{
}

unsigned int Calculo::numeroResultados()
{
	return 0;
}

int Calculo::resultado(unsigned int indice)
{
	return 0;
}

std::string Calculo::toString(char sep)
{
	return "";
}

std::string Calculo::nome() const
{
	return "Calculo vazio";
}
