#include <stdio.h>
#include <stdlib.h>
#include "listaenc.h"

void criaLista(tLista *lista){
	lista->tamanho = 0;
	lista->comeco = NULL;
	lista->fim = NULL;
}

int vaziaLista(tLista lista){
	if(lista.tamanho == 0){
		return 1;
	}
	return 0;
}

int procuraPosicao(tLista lista, int tipo, int x, int y, int z){
	tNo *no = lista.comeco;
	int pos = 1;
	while(no!=NULL){
		if((no->tipo == tipo) && (no->x == x) && (no->y == y) && (no->z == z)){
			return pos;
		}
		pos++;
		no = no->depois;
	}
	return 0;
}

tNo retornaNo(tLista lista, int pos){
    tNo *no;
    int n = 1;
    no = lista.comeco;
    while(n<pos){
        no = no->depois;
        n++;
    }
    return *no;
}

void exibeLista(tLista lista){
    tNo *no;
    no = lista.comeco;
    if(no == NULL){
        printf("Nao ha objetos na cena\n");
    }
    printf("\n");
    while(no!=NULL){
        if(no->tipo == 1){
            printf("Tipo: %d\n"
                   "Posicao(x, y, z): (%d, %d, %d)\n"
                   "Tamanho: %.3f\n"
                   "Cor(R, G, B): (%.3f, %.3f, %.3f)\n", no->tipo, no->x, no->y, no->z, no->tamObj, no->r, no->g, no->b);
        }
        if(no->tipo == 2){
            printf("Tipo: %d\n"
                   "Posicao(x, y, z): (%d, %d, %d)\n"
                   "Raio: %.3f\nSlice: %d\nStack:%d\n"
                   "Cor(R, G, B): (%.3f, %.3f, %.3f)\n", no->tipo, no->x, no->y, no->z, no->tamObj, no->slice, no->sstack, no->r, no->g, no->b);
        }
        if(no->tipo == 3){
            printf("Tipo: %d\n"
                   "Posicao(x, y, z): (%d, %d, %d)\n"
                   "Raio: %.3f\nAltura: %f\nSlice: %d\nStack:%d\n"
                   "Cor(R, G, B): (%.3f, %.3f, %.3f)\n"
                   "Angulo: X = %.3f, Y = %.3f, Z = %.3f", no->tipo, no->x, no->y, no->z, no->tamObj, no->raio_or_altura, no->slice, no->sstack, no->r, no->g, no->b, no->angx, no->angy, no->angz);
        }
        if(no->tipo == 4){
            printf("Tipo: %d\n"
                   "Posicao(x, y, z): (%d, %d, %d)\n"
                   "Tamanho: %.3f\n"
                   "Cor(R, G, B): (%.3f, %.3f, %.3f)\n", no->tipo, no->x, no->y, no->z, no->tamObj, no->r, no->g, no->b);
        }
        if(no->tipo == 5){
            printf("Tipo: %d\n"
                   "Posicao(x, y, z): (%d, %d, %d)\n"
                   "Raio dentro: %.3f\nRaio fora: %.3f\nSlice: %d\nStack:%d\n"
                   "Cor(R, G, B): (%.f, %.3f, %.3f)\n", no->tipo, no->x, no->y, no->z, no->tamObj, no->raio_or_altura, no->slice, no->sstack, no->r, no->g, no->b);
        }
        no = no->depois;
    }
}

int editaObj(tLista *lista, int pos, int tipo, int x, int y, int z, double tamObj, double ra, int slice, int sstack, double r, double g, double b, int rx, int ry, int rz, double angx, double angy, double angz){
    tNo *no;
    int n = 1;
    if(vaziaLista(*lista) || pos == 0){
        return 0;
    }
    no = lista->comeco;
    while(n<pos && no!=NULL){
        no = no->depois;
        n++;
    }
    no->x = x;
    no->y = y;
    no->z = z;
    no->tamObj = tamObj;
    no->raio_or_altura = ra;
    no->slice = slice;
    no->sstack = sstack;
    no->r = r;
    no->g = g;
    no->b = b;
    no->rx = rx;
    no->ry = ry;
    no->rz = rz;
    no->angx = angx;
    no->angy = angy;
    no->angz = angz;
    return 1;
}

int insere(tLista *lista, int tipo, int x, int y, int z, double tamObj, double ra, int slice, int sstack, double r, double g, double b, int rx, int ry, int rz, double angx, double angy, double angz){
	tNo *no;
	no =(tNo *) malloc(sizeof(tNo));
	if(no == NULL){
		return 0;
	}
	no->tipo = tipo;
	no->x = x;
	no->y = y;
	no->z = z;
	no->tamObj = tamObj;
	no->raio_or_altura = ra;
	no->slice = slice;
	no->sstack = sstack;
	no->r = r;
	no->g = g;
	no->b = b;
    no->rx = rx;
    no->ry = ry;
    no->rz = rz;
    no->angx = angx;
    no->angy = angy;
    no->angz = angz;
	if(vaziaLista(*lista)){
		lista->comeco = no;
		lista->fim = no;
		no->depois = NULL;
		no->antes = NULL;
	}else{
		no->antes = lista->fim;
		no->depois = NULL;
		lista->fim->depois = no;
		lista->fim = no;
	}
	lista->tamanho++;
	return 1;
}

int removeObj(tLista *lista,int tipo, int x, int y, int z){
	tNo *perc, *aux;
	int n = 1, pos;

	if (vaziaLista(*lista)){
		return 0;
	}
	perc = lista->comeco;
	pos = procuraPosicao(*lista,tipo,x,y,z);

	if(pos == 0){
        return 0;
	}

	while((n<pos) && (perc!=NULL)){
	 	aux = perc;
	 	n++;
	 	perc = perc->depois;
	}
	if(pos == 1){
		if(lista->tamanho == 1){
			lista->comeco = NULL;
			lista->fim = NULL;
		}else{
			lista->comeco = perc->depois;
			perc->antes = NULL;
		}
	}
	else if(pos == lista->tamanho){
		aux->depois = NULL;
		lista->fim = aux;
	}else{
		aux->depois = perc->depois;
		perc->depois->antes = aux;
	}

	free(perc);
	lista->tamanho--;
	return 1;
}
