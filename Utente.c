#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utente.h"
void InserirDadosU(Utente *dados){
	printf("\n-----------------Inserir Utente------------ \n");
	printf ("Qual e o nome do utente? \n");
	fflush(stdin);
	gets(dados->nome);
	printf ("Qual e o codigo do utente? \n");
	fflush(stdin);
	scanf("%d",&dados->codigoU);
	printf ("Qual e o codigo do medico? \n");
	scanf("%d",&dados->codigoM);	
}

void InserirNaListaU(NodeU **lista, Utente dados){
    NodeU *novoNode;
    NodeU *aux;

    novoNode = (NodeU*)malloc(sizeof(NodeU));
    novoNode->pessoa = dados;
    novoNode->next = NULL;

    if (*lista == NULL){
        *lista = novoNode;
    }
    else {
        aux = *lista;
        while (aux->next != NULL){
            aux = aux->next;
        }   
        aux->next = novoNode;
    }
}


void ListarUtentes(NodeU *lista){
	NodeU *aux;
	aux= lista;
	while(aux!=NULL){
	printf("\nCodigo do Utente: %d \n",aux->pessoa.codigoU);
	printf("Nome do utente: %s \n",aux->pessoa.nome);
	printf("Codigo do Medico: %d \n",aux->pessoa.codigoM);
	aux=aux->next;
	}
	free(aux);
}

void EncontraUtente(NodeU *lista){
	NodeU *aux;
	aux= lista;
	int codigo;
	printf("\n Insira o codigo do Utente que pertende encontrar \n\n");
	scanf("%d",&codigo);
	while(aux!=NULL){
		if(aux->pessoa.codigoU==codigo){
			printf("\nCodigo do Utente: %d \n",aux->pessoa.codigoU);
			printf("Nome do utente: %s \n",aux->pessoa.nome);
			printf("Codigo do Medico: %d \n",aux->pessoa.codigoM);
		}
	aux=aux->next;
	}
	free(aux);
}

void EditarUtente(NodeU **lista){
	NodeU *aux;
	aux= *lista;
	int codM,codU;
	char nomeu[51];
	printf("\n Insira o codigo do Utente que pertende editar \n\n");
	scanf("%d",&codU);
	printf("\n Insira o novo nome \n\n");
	fflush(stdin);
	gets(nomeu);
	printf("\n Insira o novo codigo do medico \n\n");
	scanf("%d",&codM);
	while(aux!=NULL){
		if(aux->pessoa.codigoU==codU){
			aux->pessoa.codigoM= codM;
			strcpy(aux->pessoa.nome, nomeu);
		}
	aux=aux->next;
	}
}

void RemoverUtente(NodeU **lista){
	NodeU *aux, *ant;
	aux = *lista;
	ant = *lista;
	int cod, encontrou=0;
	printf("\n Qual o codigo do utente que pertende remover? \n");
	scanf("%d",&cod);
	while (!encontrou && aux != NULL){
		if(cod== aux->pessoa.codigoU){ /* função a implementar */
			encontrou = 1;
		}else{
			ant = aux;
			aux=aux->next;
		}
	}
	if (encontrou){

		if (ant == aux && aux == *lista){
			*lista = aux->next;
		}else{
			ant->next=aux->next;
		}
		free(aux);
		aux = NULL;
	}
}
