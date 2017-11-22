typedef struct {
	int real;
	int img;
} NumeroComplexo ;

NumeroComplexo Inicializa(int, int);
void Imprime(NumeroComplexo);
void Copia(NumeroComplexo*, NumeroComplexo);
NumeroComplexo Soma(NumeroComplexo, NumeroComplexo);
int EhReal(NumeroComplexo);