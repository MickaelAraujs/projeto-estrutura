//criando TAD para armazenar cada processo
typedef struct processo Processo;

//criando novo processo: retorna ponteiro para um struct processo.
Processo *criaProcesso();

//imprime informações contidas no struct processo
void imprimeProcesso(Processo *p);

//libera o processo com o procedimento free e retorna o número identificador do processo
int liberaProcesso(Processo *p);

void addProcesso(Processo *p,int id,int espera);

int tempoEspera(Processo *p);

int tempoExe(Processo *p);

//preenche um vetor com números aleatórios
void gerarNumeros(int vet[]);

//busca o indice de um vetor e retorna o valor contido nele
int buscaIndice(int i,int vet[]);
