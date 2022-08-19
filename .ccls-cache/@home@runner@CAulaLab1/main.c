#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char Nome[50];
  int Idade;
	float Altura;
}PESSOA;

void leNomeArquivoEntrada(char* nomeArquivo){
  fgets(nomeArquivo, 50, stdin);
  nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;
}

int abreArquivoAEntrada(FILE **Arq, char *nomeArquivo) {
  fprintf(stderr, "File>> %s\n", nomeArquivo);
  (*Arq) = fopen(nomeArquivo, "r");
  if (*Arq == NULL) {
    return 0;
  } else {
    return 1;
  }
}

int leDadosUmaPessoa(FILE *Arq, PESSOA *P) {

  char aux[100];

  if (fgets(P->Nome, 100, Arq)) {
    P->Nome[strcspn(P->Nome, "\n")] = 0;
    fprintf(stderr, "Nome: %s\n", P->Nome);
    fgets(aux, 100, Arq);
    P->Idade = atoi(aux);
    fprintf(stderr, "Idade: %d\n", P->Idade);
    fgets(aux, 100, Arq);
    P->Altura = atof(aux);
    fprintf(stderr, "Altura: %f\n", P->Altura);

    return 1;
  }

  return 0;
}

void fechaArquivo(FILE* pont_arq){
	fclose(pont_arq);
}



void imprimeVetor(PESSOA * Povo, int i){
	int j;
	for(j = 0; j < i; j++){
		fprintf(stderr, "%s\n", Povo[j].Nome);
		fprintf(stderr, "%f\n", Povo[j].Altura);
		fprintf(stderr, "%d\n", Povo[j].Idade);
	}
}

int compare(PESSOA *a, PESSOA *b) {
  if (a->Idade < b->Idade)
    return -1;
  else if (a->Idade > b->Idade)
    return 1;
  else
    return 0;
}

int main()
{
     char S1[50];
     PESSOA Povo[10], P;
     FILE *Arq;
     int i = 0;

     leNomeArquivoEntrada(S1);
     if (abreArquivoAEntrada(&Arq, S1) == 1)
     {
            do{
                    if (leDadosUmaPessoa(Arq, &P) == 1)
                    {
                        Povo[i] = P;
                        i++;
                    }
                    else break;
            } while(1);
            fechaArquivo(Arq);
            qsort((void *)&Povo, i, sizeof(PESSOA), compare);
            imprimeVetor(Povo,i);
    }
    else printf("Erro na abertura do arquivo");
    system("pause");
    return 0;
}