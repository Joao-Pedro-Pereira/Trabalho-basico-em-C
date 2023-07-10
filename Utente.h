
//definição da lista
typedef struct utente{
	char nome[51];
	int codigoU, codigoM;
}Utente;

typedef struct nodeU{
	Utente pessoa;
	struct nodeU *next;
}NodeU;

void InserirDadosU(Utente *dados);
void InserirNaListaU(NodeU **lista, Utente dados);
void ListarUtentes(NodeU *lista);
void EncontraUtente(NodeU *lista);
void EditarUtente(NodeU **lista);
void RemoverUtente(NodeU **lista);
