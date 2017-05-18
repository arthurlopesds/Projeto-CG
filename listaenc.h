#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED

typedef struct no{
	int x, y, z, tipo, slice, sstack, rx, ry, rz;
	double r, g, b, tamObj, raio_or_altura, angx, angy, angz,ra;
	struct no *antes;
	struct no *depois;
}tNo;

typedef struct lista{
	int tamanho;
	tNo *comeco;
	tNo *fim;
}tLista;

void criaLista(tLista *lista);
int vaziaLista(tLista lista);
int procuraPosicao(tLista lista, int tipo, int x, int y, int z);
tNo retornaNo(tLista lista, int pos);
int insere(tLista *lista, int tipo, int x, int y, int z, double tamObj, double ra, int slice, int sstack, double r, double g, double b, int rx, int ry, int rz, double angx, double angy, double angz);
void exibeLista(tLista lista);
int editaObj(tLista *lista, int pos, int tipo, int x, int y, int z, double tamObj, double ra, int slice, int sstack, double r, double g, double b, int rx, int ry, int rz, double angx, double angy, double angz);
int removeObj(tLista *lista, int tipo, int x, int y, int z);

#endif // LISTAENC_H_INCLUDED
