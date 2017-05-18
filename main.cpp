#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include "listaenc.c"

/**Variáveis*/
tLista listaObj;
int rotacao = 0;



void exibeMenu(){
    printf("Digite um numero para desenhar o objeto\n\t1-Cubo\n\t2-Esfera\n\t3-Cone\n\t4-Pote\n\t5-Torus\n"
           "Digite uma letra para fazer editar a cena\n\tr-Remover um objeto\n\te-Editar um objeto\n"
           "\tg-Girar a cena\n\tm-Mostra os detalhes de cada objeto\n\tq-Para fechar\n");
}

void eixos(){
    glColor3d(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3d(20, 20, -20);
        glVertex3d(40, 20, -20);
    glEnd();

    glColor3d(0, 1, 0);
    glBegin(GL_LINES);
        glVertex3d(20, 20, -20);
        glVertex3d(20, 40, -20);
    glEnd();

    glColor3d(0, 0, 1);
    glBegin(GL_LINES);
        glVertex3d(20, 20, -20);
        glVertex3d(20, 20, -40);
    glEnd();
}

void desenhaObjetos(){
    tNo *no;
    no = listaObj.comeco;
    int i;
    for(i=0; i<listaObj.tamanho; i++){
        glPushMatrix();
        if(no->tipo == 1){
            glTranslated(no->x, 0, 0);
            glTranslated(0, no->y, 0);
            glTranslated(0, 0, no->z);
            if(no->rx == 1){
                glRotated(no->angx, no->rx, 0, 0);
            }
            if(no->ry == 1){
                glRotated(no->angy, 0, no->ry, 0);
            }
            if(no->rz == 1){
                glRotated(no->angz, 0, 0, no->rz);
            }
            glColor3d(no->r, no->g, no->b);
            glutSolidCube(no->tamObj);
        }
        if(no->tipo == 2){
            glTranslated(no->x, 0, 0);
            glTranslated(0, no->y, 0);
            glTranslated(0, 0, no->z);
            if(no->rx == 1){
                glRotated(no->angx, no->rx, 0, 0);
            }
            if(no->ry == 1){
                glRotated(no->angy, 0, no->ry, 0);
            }
            if(no->rz == 1){
                glRotated(no->angz, 0, 0, no->rz);
            }
            glColor3d(no->r, no->g, no->b);
            glutSolidSphere(no->tamObj, no->slice, no->sstack);
        }
        if(no->tipo == 3){
            glTranslated(no->x, 0, 0);
            glTranslated(0, no->y, 0);
            glTranslated(0, 0, no->z);
            if(no->rx == 1){
                glRotated(no->angx, no->rx, 0, 0);
            }
            if(no->ry == 1){
                glRotated(no->angy, 0, no->ry, 0);
            }
            if(no->rz == 1){
                glRotated(no->angz, 0, 0, no->rz);
            }
            glColor3d(no->r, no->g, no->b);
            glutSolidCone(no->tamObj, no->raio_or_altura, no->slice, no->sstack);
        }
        if(no->tipo == 4){
            glTranslated(no->x, 0, 0);
            glTranslated(0, no->y, 0);
            glTranslated(0, 0, no->z);
            if(no->rx == 1){
                glRotated(no->angx, no->rx, 0, 0);
            }
            if(no->ry == 1){
                glRotated(no->angy, 0, no->ry, 0);
            }
            if(no->rz == 1){
                glRotated(no->angz, 0, 0, no->rz);
            }
            glColor3d(no->r, no->g, no->b);
            glutSolidTeapot(no->tamObj);
        }
        if(no->tipo == 5){
            glTranslated(no->x, 0, 0);
            glTranslated(0, no->y, 0);
            glTranslated(0, 0, no->z);
            if(no->rx == 1){
                glRotated(no->angx, no->rx, 0, 0);
            }
            if(no->ry == 1){
                glRotated(no->angy, 0, no->ry, 0);
            }
            if(no->rz == 1){
                glRotated(no->angz, 0, 0, no->rz);
            }
            glColor3d(no->r, no->g, no->b);
            glutSolidTorus(no->tamObj, no->raio_or_altura, no->slice, no->sstack);
        }
        glPopMatrix();
        no = no->depois;
    }
}

void Inicializa (void)
{
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
	GLfloat posicaoLuz0[4]={0.0, 50.0, 0.0, 1.0};//luz frente
	GLfloat posicaoLuz2[4]={-50.0, 50.0, 0.0, 1.0};//luz esquerda

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz0 );

	// Define os parâmetros da luz de número 2
	glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuz2 );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);

	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);

	// Habilita a luz
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT2);

	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

}

int gravaArquivo(FILE *arq){
tNo *no;
//no = listaObj.comeco;
//if(no == NULL){
  //  return 0;
//}
    printf("Arquivo Criado!");
  //  while(no!=NULL){
        fwrite(&no,1,sizeof(tNo),arq);
    //    no = no->depois;
    //}
        fclose(arq);
        return 1;
}

int leArquivo(FILE *arq){

tNo *noo;

if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo");
        return 0;
        }

  fread(&noo,1,sizeof(tNo),arq);
  insere(&listaObj, noo->tipo, noo->x, noo->y, noo->z, noo->tamObj,noo->ra, noo->slice, noo->sstack, noo->r, noo->g, noo->b, noo->rx, noo->ry, noo->rz, noo->angx, noo->angy, noo->angz);



        printf("Leitura Realizada!");

        return 1;
}

int pega;
 int Arquivo(){

int op;
 char nomearq[15];

 printf("1 - Novo Arquivo \n2- Abrir Arquivo\n");
    scanf("%i",&op);
    if(op==1){
        printf("________NOVO ARQUIVO_________\n");
            printf("Digite o nome do arquivo a ser criado(.txt):\n");
            scanf("%s\n",nomearq);

            FILE* arquivo = fopen(nomearq,"wb");
            if(arquivo==NULL){
            printf("Não foi possível abrir o arquivo");
            return 0;
        }
        gravaArquivo(arquivo);
    }
     else if(op==2){
        printf("_________ABRIR ARQUIVO_________\n");
        printf("Digite o nome do arquivo para ser aberto(.txt):\n");
        scanf("%s\n",nomearq);

           FILE* arquiv = fopen(nomearq,"rb");
            if(arquiv==NULL){
            printf("Não foi possível abrir o arquivo");
            return 0;
        }
         leArquivo(arquiv);
         fclose(arquiv);
     }
     else{
        printf("OPCAO INVALIDA\n");

        return 0;
    }

return 1;

}




/*int Arquivo(){
    //tNo no;
    FILE *arquivo;
    //int op;
    char nomearq[20];

  printf("1 - Novo Arquivo \n2- Abrir Arquivo");
    scanf("%i",&op);
    if(op==1){
        printf("________NOVO ARQUIVO_________\n");
        printf("Digite o nome do novo arquivo:");
        scanf("%s",nomearq);

        arquivo = fopen("teste.txt","wb");
        if (arquivo == NULL){
            printf("Não foi possível abrir o arquivo");
            return 0;}


        fwrite(&no,sizeof(tNo),1,arquivo);
        fclose(arquivo);
        return 1;

    }

    else if(op==2){

        tNo *no;
        printf("_________ABRIR ARQUIVO_________\n");
        printf("Digite o nome do arquivo a ser aberto:");
        scanf("%s",nomearq);

        arquivo = fopen("teste.txt","rb");
        if(arquivo == NULL){
            printf("Nao foi possivel abrir o arquivo");
            return 0;
        }

        do{
        fread(&no,sizeof(tNo),1,arquivo);
        insere(&listaObj, no->tipo, no->x, no->y, no->z, no->tamObj,no->ra, no->slice, no->sstack, no->r, no->g, no->b, no->rx, no->ry, no->rz, no->angx, no->angy, no->angz);
        }
        while(!feof(arquivo));
        fclose(arquivo);
        return 1;
    }
    else{
        printf("OPCAO INVALIDA");
        return 0;
    }
    return 1;
}*/


void escolheObj(unsigned char tecla, int x1, int y1){

    int x, y, z, slice, sstack, rx, ry, rz, cont;
    double tam, r, g, b, ra, angx, angy, angz;
    char op, opcoord;
    switch(tecla){
        case '1':

            cont = 0;
            rx = 0;
            ry = 0;
            rz = 0;
            angx = 0;
            angy = 0;
            angz = 0;
            printf("\nDesenhando um Cubo\n");
            printf("Digite as coordenadas do Cubo\nX: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            printf("Z: ");
            scanf("%d", &z);
            printf("Tamanho do Cubo: ");
            scanf("%lf", &tam);
            printf("Digite a cor do cubo usando o sistema RGB\nR = ");
            scanf("%lf", &r);
            printf("G = ");
            scanf("%lf", &g);
            printf("B = ");
            scanf("%lf", &b);

            while(1){
                fflush(stdin);
                printf("Deseja rotacionar o objeto?(s/n) ");
                scanf("%c", &op);
                if(op == 'n' || cont == 3){
                    break;
                }
                if(op == 's'){
                    fflush(stdin);
                    printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                    scanf("%c", &opcoord);
                    if(opcoord == 'x'){
                        rx = 1;
                        printf("Digite o angulo que deseja rotacionar em x: ");
                        scanf("%lf", &angx);
                        cont++;
                    }
                    if(opcoord == 'y'){
                        ry = 1;
                        printf("Digite o angulo que deseja rotacionar em y: ");
                        scanf("%lf", &angy);
                        cont++;
                    }
                    if(opcoord == 'z'){
                        rz = 1;
                        printf("Digite o angulo que deseja rotacionar em z: ");
                        scanf("%lf", &angz);
                        cont++;
                    }
                }
            }
            insere(&listaObj, 1, x, y, z, tam, 0, 0, 0, r, g, b, rx, ry, rz, angx, angy, angz);
            break;
        case '2':
            cont=0;
            rx = 0;
            ry = 0;
            rz = 0;
            angx = 0;
            angy = 0;
            angz = 0;
            printf("\nDesenhando uma Esfera\n");
            printf("Digite as coordenadas da Esfera\nX: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            printf("Z: ");
            scanf("%d", &z);
            printf("Raio da Esfera: ");
            scanf("%lf", &tam);
            printf("Face: ");
            scanf("%d", &slice);
            printf("Stack: ");
            scanf("%d",&sstack);
            printf("Digite a cor da esfera usando o sistema RGB\nR: ");
            scanf("%lf", &r);
            printf("G: ");
            scanf("%lf", &g);
            printf("B: ");
            scanf("%lf", &b);

            while(1){
                fflush(stdin);
                printf("Deseja rotacionar o objeto?(s/n) ");
                scanf("%c", &op);
                if(op == 'n' || cont == 3){
                    break;
                }
                if(op == 's'){
                    fflush(stdin);
                    printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                    scanf("%c", &opcoord);
                    if(opcoord == 'x'){
                        rx = 1;
                        printf("Digite o angulo que deseja rotacionar em x: ");
                        scanf("%lf", &angx);
                        cont++;
                    }
                    if(opcoord == 'y'){
                        ry = 1;
                        printf("Digite o angulo que deseja rotacionar em y: ");
                        scanf("%lf", &angy);
                        cont++;
                    }
                    if(opcoord == 'z'){
                        rz = 1;
                        printf("Digite o angulo que deseja rotacionar em z: ");
                        scanf("%lf", &angz);
                        cont++;
                    }
                }
            }
            insere(&listaObj, 2, x, y, z, tam, 0, slice, sstack, r, g, b, rx, ry, rz, angx, angy, angz);
            break;
        case '3':
            cont = 0;
            rx = 0;
            ry = 0;
            rz = 0;
            angx = 0;
            angy = 0;
            angz = 0;
            printf("\nDesenhando um Cone\n");
            printf("Digite as coordenadas do Cone\nX: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            printf("Z: ");
            scanf("%d", &z);
            printf("Raio: ");
            scanf("%lf", &tam);
            printf("Altura do Cone: ");
            scanf("%lf", &ra);
            printf("Face: ");
            scanf("%d", &slice);
            printf("Stack: ");
            scanf("%d",&sstack);
            printf("Digite a cor do cone usando o sistema RGB\nR: ");
            scanf("%lf", &r);
            printf("G: ");
            scanf("%lf", &g);
            printf("B: ");
            scanf("%lf", &b);

            while(1){
                fflush(stdin);
                printf("Deseja rotacionar o objeto?(s/n) ");
                scanf("%c", &op);
                if(op == 'n' || cont == 3){
                    break;
                }
                if(op == 's'){
                    fflush(stdin);
                    printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                    scanf("%c", &opcoord);
                    if(opcoord == 'x'){
                        rx = 1;
                        printf("Digite o angulo que deseja rotacionar em x: ");
                        scanf("%lf", &angx);
                        cont++;
                    }
                    if(opcoord == 'y'){
                        ry = 1;
                        printf("Digite o angulo que deseja rotacionar em y: ");
                        scanf("%lf", &angy);
                        cont++;
                    }
                    if(opcoord == 'z'){
                        rz = 1;
                        printf("Digite o angulo que deseja rotacionar em z: ");
                        scanf("%lf", &angz);
                        cont++;
                    }
                }
            }
            insere(&listaObj, 3, x, y, z, tam, ra, slice, sstack, r, g, b, rx, ry, rz, angx, angy, angz);
            break;
        case '4':
            cont = 0;
            rx = 0;
            ry = 0;
            rz = 0;
            angx = 0;
            angy = 0;
            angz = 0;
            printf("\nDesenhando um Pote\n");
            printf("Digite as coordenadas do Pote\nX: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            printf("Z: ");
            scanf("%d", &z);
            printf("Tamanho do pote: ");
            scanf("%lf", &tam);
            printf("Digite a cor do pote usando o sistema RGB\nR: ");
            scanf("%lf", &r);
            printf("G: ");
            scanf("%lf", &g);
            printf("B: ");
            scanf("%lf", &b);

            while(1){
                fflush(stdin);
                printf("Deseja rotacionar o objeto?(s/n) ");
                scanf("%c", &op);
                if(op == 'n' || cont == 3){
                    break;
                }
                if(op == 's'){
                    fflush(stdin);
                    printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                    scanf("%c", &opcoord);
                    if(opcoord == 'x'){
                        rx = 1;
                        printf("Digite o angulo que deseja rotacionar em x: ");
                        scanf("%lf", &angx);
                        cont++;
                    }
                    if(opcoord == 'y'){
                        ry = 1;
                        printf("Digite o angulo que deseja rotacionar em y: ");
                        scanf("%lf", &angy);
                        cont++;
                    }
                    if(opcoord == 'z'){
                        rz = 1;
                        printf("Digite o angulo que deseja rotacionar em z: ");
                        scanf("%lf", &angz);
                        cont++;
                    }
                }
            }
            insere(&listaObj, 4, x, y, z, tam, 0, 0, 0, r, g, b, rx, ry, rz, angx, angy, angz);
            break;
        case '5':
            cont = 0;
            rx = 0;
            ry = 0;
            rz = 0;
            angx = 0;
            angy = 0;
            angz = 0;
            printf("\nDesenhando um Torus\n");
            printf("Digite as coordenadas do Torus\nX: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            printf("Z: ");
            scanf("%d", &z);
            printf("Raio de Dentro do Torus: ");
            scanf("%lf", &tam);
            printf("Raio de Fora do Torus: ");
            scanf("%lf", &ra);
            printf("Sides do Torus: ");
            scanf("%d", &slice);
            printf("Rings do Torus: ");
            scanf("%d",&sstack);
            printf("Digite a cor do torus usando o sistema RGB\nR: ");
            scanf("%lf", &r);
            printf("G: ");
            scanf("%lf", &g);
            printf("B: ");
            scanf("%lf", &b);

            while(1){
                fflush(stdin);
                printf("Deseja rotacionar o objeto?(s/n) ");
                scanf("%c", &op);
                if(op == 'n' || cont == 3){
                    break;
                }
                if(op == 's'){
                    fflush(stdin);
                    printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                    scanf("%c", &opcoord);
                    if(opcoord == 'x'){
                        rx = 1;
                        printf("Digite o angulo que deseja rotacionar em x: ");
                        scanf("%lf", &angx);
                        cont++;
                    }
                    if(opcoord == 'y'){
                        ry = 1;
                        printf("Digite o angulo que deseja rotacionar em y: ");
                        scanf("%lf", &angy);
                        cont++;
                    }
                    if(opcoord == 'z'){
                        rz = 1;
                        printf("Digite o angulo que deseja rotacionar em z: ");
                        scanf("%lf", &angz);
                        cont++;
                    }
                }
            }
            insere(&listaObj, 5, x, y, z, tam, ra, slice, sstack, r, g, b, rx, ry, rz, angx, angy, angz);
            break;
        case 'e':
            int pos, tipo;
            tNo backupNo;
            cont = 0;
            printf("\nDigite os parametros do objeto que quer procurar:\n");
            printf("Tipo: ");
            scanf("%d", &tipo);
            printf("X = ");
            scanf("%d", &x);
            printf("Y = ");
            scanf("%d", &y);
            printf("Z = ");
            scanf("%d", &z);
            pos = procuraPosicao(listaObj, tipo, x, y, z);
            if(pos == 0){
                printf("Objeto nao encontrado\n");
                break;
            }
            backupNo = retornaNo(listaObj, pos);
            printf("\t[Editando]\nDigite os novos parametros do objeto\n");
            if(tipo == 1){
                printf("\nEditando um Cubo\n");
                printf("Digite as coordenadas do Cubo\nX: ");
                scanf("%d", &x);
                printf("Y: ");
                scanf("%d", &y);
                printf("Z: ");
                scanf("%d", &z);
                printf("Tamanho do Cubo: ");
                scanf("%lf", &tam);
                printf("Digite a cor do cubo usando o sistema RGB\nR = ");
                scanf("%lf", &r);
                printf("G = ");
                scanf("%lf", &g);
                printf("B = ");
                scanf("%lf", &b);

                while(1){
                    fflush(stdin);
                    printf("Deseja rotacionar o objeto?(s/n) ");
                    scanf("%c", &op);
                    if(op == 'n' || cont == 3){
                        rx = backupNo.rx;
                        ry = backupNo.ry;
                        rz = backupNo.rz;
                        angx = backupNo.angx;
                        angy = backupNo.angy;
                        angz = backupNo.angz;
                        break;
                    }
                    if(op == 's'){
                        fflush(stdin);
                        printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                        scanf("%c", &opcoord);
                        if(opcoord == 'x'){
                            rx = 1;
                            printf("Digite o angulo que deseja rotacionar em x: ");
                            scanf("%lf", &angx);
                            cont++;
                        }
                        if(opcoord == 'y'){
                            ry = 1;
                            printf("Digite o angulo que deseja rotacionar em y: ");
                            scanf("%lf", &angy);
                            cont++;
                        }
                        if(opcoord == 'z'){
                            rz = 1;
                            printf("Digite o angulo que deseja rotacionar em z: ");
                            scanf("%lf", &angz);
                            cont++;
                        }
                    }
                }
                editaObj(&listaObj, pos, tipo, x, y, z, tam, 0, 0, 0, r, g, b, rx, ry, rz, angx, angy, angz);
            }
            if(tipo == 2){
                printf("\nEditando a Esfera\n");
                printf("Digite as coordenadas da Esfera\nX: ");
                scanf("%d", &x);
                printf("Y: ");
                scanf("%d", &y);
                printf("Z: ");
                scanf("%d", &z);
                printf("Raio da Esfera: ");
                scanf("%lf", &tam);
                printf("Face: ");
                scanf("%d", &slice);
                printf("Stack: ");
                scanf("%d",&sstack);
                printf("Digite a cor da esfera usando o sistema RGB\nR: ");
                scanf("%lf", &r);
                printf("G: ");
                scanf("%lf", &g);
                printf("B: ");
                scanf("%lf", &b);

            while(1){
                fflush(stdin);
                printf("Deseja rotacionar o objeto?(s/n) ");
                scanf("%c", &op);
                if(op == 'n' || cont == 3){
                    rx = backupNo.rx;
                    ry = backupNo.ry;
                    rz = backupNo.rz;
                    angx = backupNo.angx;
                    angy = backupNo.angy;
                    angz = backupNo.angz;
                    break;
                }
                if(op == 's'){
                    fflush(stdin);
                    printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                    scanf("%c", &opcoord);
                    if(opcoord == 'x'){
                        rx = 1;
                        printf("Digite o angulo que deseja rotacionar em x: ");
                        scanf("%lf", &angx);
                        cont++;
                    }
                    if(opcoord == 'y'){
                        ry = 1;
                        printf("Digite o angulo que deseja rotacionar em y: ");
                        scanf("%lf", &angy);
                        cont++;
                    }
                    if(opcoord == 'z'){
                        rz = 1;
                        printf("Digite o angulo que deseja rotacionar em z: ");
                        scanf("%lf", &angz);
                        cont++;
                    }
                }
            }
                editaObj(&listaObj, pos, tipo, x, y, z, tam, 0, slice, sstack, r, g, b, rx, ry, rz, angx, angy, angz);
            }
            if(tipo == 3){
                printf("\nEditando o Cone\n");
                printf("Digite as coordenadas do Cone\nX: ");
                scanf("%d", &x);
                printf("Y: ");
                scanf("%d", &y);
                printf("Z: ");
                scanf("%d", &z);
                printf("Raio: ");
                scanf("%lf", &tam);
                printf("Altura do Cone: ");
                scanf("%lf", &ra);
                printf("Face: ");
                scanf("%d", &slice);
                printf("Stack: ");
                scanf("%d",&sstack);
                printf("Digite a cor do cone usando o sistema RGB\nR: ");
                scanf("%lf", &r);
                printf("G: ");
                scanf("%lf", &g);
                printf("B: ");
                scanf("%lf", &b);

            while(1){
                fflush(stdin);
                printf("Deseja rotacionar o objeto?(s/n) ");
                scanf("%c", &op);
                if(op == 'n' || cont == 3){
                    rx = backupNo.rx;
                    ry = backupNo.ry;
                    rz = backupNo.rz;
                    angx = backupNo.angx;
                    angy = backupNo.angy;
                    angz = backupNo.angz;
                    break;
                }
                if(op == 's'){
                    fflush(stdin);
                    printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                    scanf("%c", &opcoord);
                    if(opcoord == 'x'){
                        rx = 1;
                        printf("Digite o angulo que deseja rotacionar em x: ");
                        scanf("%lf", &angx);
                        cont++;
                    }
                    if(opcoord == 'y'){
                        ry = 1;
                        printf("Digite o angulo que deseja rotacionar em y: ");
                        scanf("%lf", &angy);
                        cont++;
                    }
                    if(opcoord == 'z'){
                        rz = 1;
                        printf("Digite o angulo que deseja rotacionar em z: ");
                        scanf("%lf", &angz);
                        cont++;
                    }
                }
            }
                editaObj(&listaObj, pos, tipo, x, y, z, tam, ra, slice, sstack, r, g, b, rx, ry, rz, angx, angy, angz);
            }
            if(tipo == 4){
                printf("\nEditando o Pote\n");
                printf("Digite as coordenadas do Pote\nX: ");
                scanf("%d", &x);
                printf("Y: ");
                scanf("%d", &y);
                printf("Z: ");
                scanf("%d", &z);
                printf("Tamanho do pote: ");
                scanf("%lf", &tam);
                printf("Digite a cor do pote usando o sistema RGB\nR: ");
                scanf("%lf", &r);
                printf("G: ");
                scanf("%lf", &g);
                printf("B: ");
                scanf("%lf", &b);
                while(1){
                    fflush(stdin);
                    printf("Deseja rotacionar o objeto?(s/n) ");
                    scanf("%c", &op);
                    if(op == 'n' || cont == 3){
                        rx = backupNo.rx;
                        ry = backupNo.ry;
                        rz = backupNo.rz;
                        angx = backupNo.angx;
                        angy = backupNo.angy;
                        angz = backupNo.angz;
                        break;
                    }
                    if(op == 's'){
                        fflush(stdin);
                        printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                        scanf("%c", &opcoord);
                        if(opcoord == 'x'){
                            rx = 1;
                            printf("Digite o angulo que deseja rotacionar em x: ");
                            scanf("%lf", &angx);
                            cont++;
                        }
                        if(opcoord == 'y'){
                            ry = 1;
                            printf("Digite o angulo que deseja rotacionar em y: ");
                            scanf("%lf", &angy);
                            cont++;
                        }
                        if(opcoord == 'z'){
                            rz = 1;
                            printf("Digite o angulo que deseja rotacionar em z: ");
                            scanf("%lf", &angz);
                            cont++;
                        }
                    }
                }
                editaObj(&listaObj, pos, tipo, x, y, z, tam, 0, 0, 0, r, g, b, rx, ry, rz, angx, angy, angz);
            }
            if(tipo == 5){
                printf("\nEditando o Torus\n");
                printf("Digite as coordenadas do Torus\nX: ");
                scanf("%d", &x);
                printf("Y: ");
                scanf("%d", &y);
                printf("Z: ");
                scanf("%d", &z);
                printf("Raio de Dentro do Torus: ");
                scanf("%lf", &tam);
                printf("Raio de Fora do Torus: ");
                scanf("%lf", &ra);
                printf("Sides do Torus: ");
                scanf("%d", &slice);
                printf("Rings do Torus: ");
                scanf("%d",&sstack);
                printf("Digite a cor do torus usando o sistema RGB\nR: ");
                scanf("%lf", &r);
                printf("G: ");
                scanf("%lf", &g);
                printf("B: ");
                scanf("%lf", &b);
                while(1){
                    fflush(stdin);
                    printf("Deseja rotacionar o objeto?(s/n) ");
                    scanf("%c", &op);
                    if(op == 'n' || cont == 3){
                        rx = backupNo.rx;
                        ry = backupNo.ry;
                        rz = backupNo.rz;
                        angx = backupNo.angx;
                        angy = backupNo.angy;
                        angz = backupNo.angz;
                        break;
                    }
                    if(op == 's'){
                        fflush(stdin);
                        printf("Em qual eixo deseja rotacionar (x, y ou z)? ");
                        scanf("%c", &opcoord);
                        if(opcoord == 'x'){
                            rx = 1;
                            printf("Digite o angulo que deseja rotacionar em x: ");
                            scanf("%lf", &angx);
                            cont++;
                        }
                        if(opcoord == 'y'){
                            ry = 1;
                            printf("Digite o angulo que deseja rotacionar em y: ");
                            scanf("%lf", &angy);
                            cont++;
                        }
                        if(opcoord == 'z'){
                            rz = 1;
                            printf("Digite o angulo que deseja rotacionar em z: ");
                            scanf("%lf", &angz);
                            cont++;
                        }
                    }
                }
                editaObj(&listaObj, pos, tipo, x, y, z, tam, ra, slice, sstack, r, g, b, rx, ry, rz, angx, angy, angz);
            }
            printf("Objeto editado\n");
            break;
        case 'r':
            int apagou;
            printf("\nDigite os parametros do objeto que quer procurar para apagar:\n");
            printf("Tipo do objeto: ");
            scanf("%d", &tipo);
            printf("Digite as coordenadas\nX: ");
            scanf("%d", &x);
            printf("Y: ");
            scanf("%d", &y);
            printf("Z: ");
            scanf("%d", &z);
            apagou = removeObj(&listaObj, tipo, x, y, z);
            if(apagou){
                printf("Objeto removido\n");
            }else{
                printf("Objeto nao foi removido ou nao foi encontrado!\n");
            }
            break;
        case 'm':
            exibeLista(listaObj);
            break;
        case 'g':
            rotacao+=5;
            if(rotacao >360){
                rotacao = 0;
            }
            break;
        case 'q':
            exit(1);
            break;
    }
    glutPostRedisplay();
}

void display(){
    glDrawBuffer(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /**Viewport para os eixos */
    glViewport(0, 0, 20, 20);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 40, 0, 40, 0, 40);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotated(rotacao, 1, 0, 0);
    glRotated(rotacao, 0, 1, 0);

    eixos();

    /** Fim Viewport para os eixos*/

    glViewport(0, 0, 800, 600);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotated(rotacao, 1, 0, 0);
    glRotated(rotacao, 0, 1, 0);

    if(!vaziaLista(listaObj))
        desenhaObjetos();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    criaLista(&listaObj);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(550, 40);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mini Blender");
    Arquivo();
    glutDisplayFunc(display);
    glutKeyboardFunc(escolheObj);
    Inicializa();
    exibeMenu();
    glutMainLoop();
}
