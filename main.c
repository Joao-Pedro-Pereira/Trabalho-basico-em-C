#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utente.h"

 void GuardarUtentes(NodeU *lista){
    FILE *fp;
    NodeU *aux;
    aux = lista;
    fp = fopen("utente.txt", "w");
    if(fp == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    while(aux != NULL){
        fprintf(fp, "%s %d %d\n", aux->pessoa.nome, aux->pessoa.codigoU, aux->pessoa.codigoM);
        aux = aux->next;
    }
    fclose(fp);
    printf("Dados dos utentes foram guardados no arquivo .\n");
}

int main() {
	
	
	int escolha;
	Utente dadosU;
	NodeU *listaU=NULL;
	do{
		printf("\n         Menu principal         ");
		printf("\n 1. Inserir um novo utente");  
		printf("\n 2. Editar dados de um utente"); 
		printf("\n 3. Consultar dados de um utente");
		printf("\n 4. Consultar dados de todos os utentes");
		printf("\n 5. Remover um utente");
		printf("\n 6. Registar a entrade de um utente");
		
		printf("\n\n 7. Inserir um novo medico");  
		printf("\n 8. Editar dados de um medico");  
		printf("\n 9. Consultar dados de um medico");  
		printf("\n 10. Consultar dados de todos os medicos");  
		printf("\n 11. Remover um medico");
		printf("\n 0. Sair\n");
		printf("\nEscolha a sua opcao\n");
		scanf("%d",&escolha);
		fflush(stdin);
		
		switch(escolha){
			case 1:{
				InserirDadosU(&dadosU);
				InserirNaListaU(&listaU,dadosU);
				break;
			}
			case 2:{
				EditarUtente(&listaU);
				break;
			}
			case 3:{
				EncontraUtente(listaU);
				break;
			}
			case 4:{
				ListarUtentes(listaU);
				break;
			}
			case 5:{
				RemoverUtente(&listaU);
				break;
			}
			case 6:{
				EncontraUtente(listaU);
				break;
			}
			case 7:{
			
				break;
			}
			case 8:{
				RemoverUtente(&listaU);
				break;
			}
			case 9:{
			
				break;
			}
			case 10:{
				ListarUtentes(listaU);
				break;
			}
			
			case 11:{
			
				break;
			}
			case 0:{
				GuardarUtentes(listaU);
				printf("\n\n\t Volte sempre\n");
				break;
			}
			
		
		}
		
	}while(escolha!=0);
	
	return 0;
}
