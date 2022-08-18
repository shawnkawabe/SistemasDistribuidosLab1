#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Nome;
    int Idade;
	float Altura;
}PESSOA;

void leNomeArquivoEntrada(char* nomeArquivo){
	printf("Digite o nome do arquivo\n");
	scanf("%s", nomeArquivo);
}

int abreArquivoAEntrada(FILE* pont_arq, char* nomeArquivo){
    pont_arq = fopen(nomeArquivo, "r");

  //testando se o arquivo foi realmente criado
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
		return 0;
	}
	return 1;
}

int leDadosUmaPessoa(PESSOA P){
	return 1;
/*
	char c;
	do
	{
		//faz a leitura do caracter no arquivo apontado por pont_arq
		c = fgetc(pont_arq);

		//exibe o caracter lido na tela
		printf("%c" , c);
	}while (c != EOF);//enquanto não for final de arquivo
*/
}

void fechaArquivo(FILE* pont_arq){
	
}

void ordenaVetor(PESSOA Povo, int i){
	
}

void imprimeVetor(PESSOA Povo, int i){
	
}

int main()
{
     char S1[50];
     PESSOA Povo[10], P;
     FILE *Arq;
     int i;

     leNomeArquivoEntrada(S1);
     if (abreArquivoAEntrada(Arq, S1) == 1)
     {
            do{
                    if (leDadosUmaPessoa(P)== 1)
                    {
                        Povo[i] = P;
                        i++;
                    }
                    else break;
            } while(1);
            fechaArquivo(Arq);
            ordenaVetor(Povo, i);
            imprimeVetor(Povo,i);
    }
    else printf("Erro na abertura do arquivo");
     return 0;

}
