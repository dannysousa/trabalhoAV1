#include <stdio.h>
#include <stdlib.h>

// Declaração de váriaves como globais, para facilitar o acesso em todos os métodos
FILE *l, *e;
int valor, escolhido, i, j, k = 0, num = 0, min, aux;

//Declaração do método Insertion
void Insertion()
{
	
	//abertura dos documentos para leitura do vetor numérico e para escrita do mesmo ordenado
	l = fopen ("OrdenarNumeros.txt", "r");
	
	e = fopen ("NumerosOrdenados.txt", "w");
	
	//cláusula while para descobrir a quantidade de elementos no vetor
	while(!feof(l)) {
		fscanf(l, "%i", &valor);
		num++;
	}
	
	//variável contadora menos 1 para o tamanho correto do vetor, já que o primeiro índice é 0
	num = num - 1;
	
	//declaração do vetor com a capacidade correta de armazenamento
	int vet[num];
	
	//fechamento do arquivo de leitura para evitar possíveis erros
	fclose(l);
	
	//reabertura do arquivo para leitura das variáveis
	l = fopen ("OrdenarNumeros.txt", "r");
	
	//clausula while para receber os valores do vetor
    while(!feof(l))
    {
    	fscanf(l, "%i", &valor);
    	
    	vet[k] = valor;
    	k++;
	}
	
	//iniciando a ordenação do vetor pelo método Insertion
	for (i = 1; i < num; i++)
	{
		//elemento seleciodado para verificação
		escolhido = vet[i];
		
		//váriavel para verificação
		j = i - 1;
		
		//clausila para verificar os elementos anteriores ao elento selecionado
		while ((j >= 0) && (vet[j] > escolhido))
		{
			//enquanto os elementos anteriores forem maiores que o comparado, vai sendo buscado um valor inferior
			vet[j + 1] = vet[j];
			j--;
		}
		
		//elemento sendo adcionado em seu devido local com o vetor em ordem crescente
		vet[j + 1] = escolhido;	
	}
	
	
	//escrita no novo documento do vetor totalmente odenado juntamente com o algoritmo a ser utilizado
	for (i = 0; i < num; i++)
    {
    	fprintf(e, "%i ", vet[i]);
	}
		
	fprintf(e, "\nEste vetor foi ordenado utilizando o Insertion Sort.");

	//apenas mostrando para o usuário o vetor em ordem crescente
	for (i = 0; i < num; i++)
    {
    	printf("%i ", vet[i]);
	}
	
	
	//salvando e fechando os arquivos aberto para leitura e escrita
	fclose(l);
	fclose(e);
}

//Declaração do método Selection
void Selection()
{	
	//abertura dos documentos para leitura do vetor numérico e para escrita do mesmo ordenado
	l = fopen ("OrdenarNumeros.txt", "r");
	
	e = fopen ("NumerosOrdenados.txt", "w");
	
	//cláusula while para descobrir a quantidade de elementos no vetor
	while(!feof(l)) {
		fscanf(l, "%i", &valor);
		num++;
	}
	
	//variável contadora menos 1 para o tamanho correto do vetor, já que o primeiro índice é 0
	num = num - 1;
	
	//declaração do vetor com a capacidade correta de armazenamento
	int vet[num];
	
	//fechamento do arquivo de leitura para evitar possíveis erros
	fclose(l);
	
	//reabertura do arquivo para leitura das variáveis
	l = fopen ("OrdenarNumeros.txt", "r");
	
	//clausula while para receber os valores do vetor
    while(!feof(l))
    {
    	fscanf(l, "%i", &valor);
    	
    	vet[k] = valor;
    	k++;
	}
  	
  	//inicio da organização pelo método Selection
 	for (i = 0; i < (num-1); i++) 
	{
		//posição que será atualizada
		min = i;
		
		//verificação de todos os os elementos para descobrir qual o menor a seguir
		for (j = (i+1); j < num; j++)
		{
			//sempre que aparecer algum novo menor, será armazenada o valor dessa posição
			if(vet[j] < vet[min])
			{
				min = j;
			}
	    }
	    //inserção do menor valor na posição caso não esteja na posição correta
	    if (vet[i] != vet[min])
		{
			aux = vet[i];
	    	vet[i] = vet[min];
	    	vet[min] = aux;
 		}
 		
 	}
 	
	//escrita no novo documento do vetor totalmente odenado juntamente com o algoritmo a ser utilizado
	for (i = 0; i < num; i++)
    {
    	fprintf(e, "%i ", vet[i]);
	}
		
	fprintf(e, "\nEste vetor foi ordenado utilizando o Selection Sort.");

	//apenas mostrando para o usuário o vetor em ordem crescente
	for (i = 0; i < num; i++)
    {
    	printf("%i ", vet[i]);
	}
	
	
	//salvando e fechando os arquivos aberto para leitura e escrita
	fclose(l);
	fclose(e);
}

void sort(int vetor[], int comeco, int meio, int fim)
{
	//criação de variáveis para suporte na organização do vetor
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

	//inicio da organização do vetor como um todo
    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

	//Caso ainda haja elementos na primeira metade
    while(com1 <= meio)
	{
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

	//Caso ainda haja elementos na segunda metade
    while(com2 <= fim) 
	{
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

	//Move os elementos de volta para o vetor original
    for(comAux = comeco; comAux <= fim; comAux++)
	{
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    //limpa o vetor auxiliar para reutilização
    free(vetAux);
}

//iniciando a organização do vetor em forma crescente
void mergeSort(int vetor[], int comeco, int fim)
{
	//como o método consiste em dividir o vetor em duas partes, é necessário saber o meio do vetor
	int meio;
	
	//método para organização enquanto não estiver com vetores unitários
    if (comeco < fim)
	{
       	meio = (fim+comeco)/2;
       	mergeSort(vetor, comeco, meio);
       	mergeSort(vetor, meio+1, fim);
       	sort(vetor, comeco, meio, fim);
    }

}

//Declaração do método Merge
void Merge()
{
	
	//abertura dos documentos para leitura do vetor numérico e para escrita do mesmo ordenado
	l = fopen ("OrdenarNumeros.txt", "r");
	
	e = fopen ("NumerosOrdenados.txt", "w");
	
	//cláusula while para descobrir a quantidade de elementos no vetor
	while(!feof(l)) {
		fscanf(l, "%i", &valor);
		num++;
	}
	
	//variável contadora menos 1 para o tamanho correto do vetor, já que o primeiro índice é 0
	num = num - 1;
	
	//declaração do vetor com a capacidade correta de armazenamento
	int vet[num];
	
	//fechamento do arquivo de leitura para evitar possíveis erros
	fclose(l);
	
	//reabertura do arquivo para leitura das variáveis
	l = fopen ("OrdenarNumeros.txt", "r");
	
	//clausula while para receber os valores do vetor
    while(!feof(l))
    {
    	fscanf(l, "%i", &valor);
    	
    	vet[k] = valor;
    	k++;
	}

	//iniciando a organização do vetor
	mergeSort(vet, 0, num-1);
	
		
	//escrita no novo documento do vetor totalmente odenado juntamente com o algoritmo a ser utilizado
	for (i = 0; i < num; i++)
    {
    	fprintf(e, "%i ", vet[i]);
	}
		
	fprintf(e, "\nEste vetor foi ordenado utilizando o Merge Sort.");

	//apenas mostrando para o usuário o vetor em ordem crescente
	for (i = 0; i < num; i++)
    {
    	printf("%i ", vet[i]);
	}
	
	
	//salvando e fechando os arquivos aberto para leitura e escrita
	fclose(l);
	fclose(e);
	
}

int main()
{
	char escolha = 1;
	
	while (escolha != '0')
	{
		
		printf("Qual dos seguintes algoritmos deseja utilizar???\n");
		printf("1 - Insertion Sort\n");
		printf("2 - Merge Sort\n");
		printf("3 - Selection Sort\n");
		printf("0 - Sair\n");
		
		gets(&escolha);
		
		switch(escolha)
		{
			case '0':
				printf("Obrigado por utilizar o programa ^_^!!!\n");
				break;
				
			case '1':
				printf("\n");
				Insertion();
				printf("\n\n");
				printf("Vetor organizado com sucesso!!!\n");
				while (escolha != '0')
				{
					printf("Por gentileza, digite 0 para encerrar o programa:\n");
					gets(&escolha);
				}
				break;
				
			case '2':
				printf("\n");
				Merge();
				printf("\n\n");
				printf("Vetor organizado com sucesso!!!\n");
				while (escolha != '0')
				{
					printf("Por gentileza, digite 0 para encerrar o programa:\n");
					gets(&escolha);
				}
				break;
			
			case '3':
				printf("\n");
				Selection();
				printf("\n\n");
				printf("Vetor organizado com sucesso!!!\n");
				while (escolha != '0')
				{
					printf("Por gentileza, digite 0 para encerrar o programa:\n");
					gets(&escolha);
				}
				break;
				
			default:
				system("cls");
				printf("Por favor, apenas uma das op%c%ces do Menu.\n", 135, 228);
				break;
		}
	}
	
	system("pause");
	
}
