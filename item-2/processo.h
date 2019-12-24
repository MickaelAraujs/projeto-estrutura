//criando TAD para armazenar cada processo
typedef struct processo Processo;

//criando novo processo: retorna ponteiro para um struct processo.
Processo *criaProcesso();

//imprime informa��es contidas no struct processo
void imprimeProcesso(Processo *p);

//libera o processo com o procedimento free e retorna o n�mero identificador do processo
int liberaProcesso(Processo *p);

void addProcesso(Processo *p,int id);
