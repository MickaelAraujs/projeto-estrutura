//criando TAD para armazenar cada processo
typedef struct processo Processo;

//criando novo processo: retorna ponteiro para um struct processo.
Processo *criaProcesso();

//imprime informações contidas no struct processo
void imprimeProcesso();

//libera o processo com o procedimento free e retorna o número identificador do processo
int liberaProcesso();
