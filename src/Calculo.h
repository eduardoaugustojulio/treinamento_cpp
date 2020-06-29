#include <iostream>

class Calculo 
{
    public:
        Calculo(int inicio = 0, unsigned int tamanho = 0);
        virtual ~Calculo();

        virtual void calcula();

        virtual void limpaCalculo();
        
        virtual unsigned int numeroResultados();

        virtual int resultado(unsigned int indice);
        
        virtual std::string nome() const;

        virtual std::string toString(char sep);

    protected:
        int inicio;
        int tamanho;    
};
