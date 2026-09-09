#include "stdio.h"
#define MAX_SENSORES 10

struct sensor
{
	int canal;
	double ganho;
	double offset;
	double medida;
};

//medida corrigida = ganho*medida + offset

void mostrar_medidas(struct sensor *valores, int n);
void calibrar(struct sensor* valores, int n);
double calcular_media(struct sensor* valores, int n);
int indice_maior(struct sensor* valores, int n);
void calcular_media_canais(struct sensor* valores, int n, double* media_canal);

int main() {

	struct sensor sensores[MAX_SENSORES];
	int n;

	//LIMITA A QUANT DE SENSORES

	do {
		printf("Entre com a quantidade de sensores (entre 1 e MAX_SENSORES) n = ");
		scanf_s("%d", &n);
	} while (n < 1 || n > MAX_SENSORES);

	//fazer as n leituras do sensor

	for (int i = 0; i < n; i++) {

		//ler e limitar o canal entre 0 e 1
		printf("leitura: %d\n", i + 1);
		do {
			printf("entre com o canal(0 ou 1) :");
			scanf_s("%d", &(sensores[i].canal));

		} while (sensores[i].canal < 0 || sensores[i].canal > 1);

		//ler e limitar o ganho entre 10.0v e 10.4v
		do {
			printf("entre com o ganho entre (10.0v e 10.4v) :");
			scanf_s("%lf", &(sensores[i].ganho));

		} while (sensores[i].ganho < 10.0 || sensores[i].ganho > 10.4);

		//ler e limitar o offset entre -1.0v e 1.0v
		do {
			printf("entre com o offset entre (-1.0v e 1.0v) :");
			scanf_s("%lf", &(sensores[i].offset));

		} while (sensores[i].offset < -1.0 || sensores[i].offset> 1.0);

		//ler e limitar a medida do sensor entre 0.0v e 1.0v
		do {
			printf("entre com a medida entre (0.0v e 1.0v) :");
			scanf_s("%lf", &(sensores[i].medida));

		} while (sensores[i].medida < 0.0 || sensores[i].medida> 1.0);

	}
	printf("Medidas sem calibraçao\n");
	mostrar_medidas(sensores, n);
	calibrar(&sensores[0], n);
	printf("Medidas com calibraçao\n");
	mostrar_medidas(sensores, n);
	printf("Media global das medidas calibradas = %0.2lf\n",
		calcular_media(sensores, n));

	int imaior = indice_maior(sensores, n);
	printf("Maior valor medido = %0.2lf \t Canal = %d \n",
		sensores[imaior].medida, sensores[imaior].canal);

	double vet_media_canal[2];
	calcular_media_canais(sensores, n, vet_media_canal);

	printf("Media canal 0: %0.2lf\t Media canal 1: %0.2lf\n",
		vet_media_canal[0], vet_media_canal[1]);

	return 0;
}

void mostrar_medidas(struct sensor* valores, int n) {

	for (int i = 0; i < n; i++) {
		//imprimir todos os campo de valores[i]

		printf("Amostra: %d\t", i + 1);
		printf("Canal: %d\t", valores[i].canal);
		printf("Ganho: %0.2lf\t", valores[i].ganho);
		printf("Offset: %0.2lf\t", valores[i].offset);
		printf("Medida: %0.2lf\n", valores[i].medida);
}
}
void calibrar(struct sensor* valores, int n) {

	for (int i = 0; i < n; i++) {
		valores[i].medida = valores[i].ganho * valores[i].medida + valores[i].offset;
	}	
}
double calcular_media(struct sensor* valores, int n) {

	double soma = 0.0;
	for (int i = 0; i < n; i++) {
		soma += valores[i].medida;
	}
	return soma / n;
}
int indice_maior(struct sensor* valores, int n) {

	int imaior = 0;
	double maior = valores[imaior].medida;
	for (int i = 1; i < n; i++) {
		if (valores[i].medida > maior) {
			maior = valores[i].medida;
			imaior = i;
		}
	}
	return imaior;
}
void calcular_media_canais(struct sensor* valores, int n, double* media_canal) {

}