#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typed struct{
    float x;
    float y;
}Ponto;

/*declaração da funçaõ que calcula a area*/
float AreaTriangulo(Ponto A, Ponto B, Ponto C);

/*declaração das variaveis e abertura do arquivo para leitura*/
int main(){
    Ponto ponto [100];
    FILE *arquivo = fopen("calculoarea.txt", "r");
    int vertice, quatPontos = 0;
    float area, areaTri;

/*verificar se houve erro ao abrir o arquivo*/
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }

    system("cls");

    fscanf(arquivo, "%d", &vertice);

/*leitura do numero de vertices*/
    while(quatPontos, < vertice){
        quantPontos++;
        fscanf(arquivo, "%f %f", &ponto [quantPontos].X, &ponto[quantPontos].Y);
    }

/*poligono impresso em duas casas decimais*/
    if(vertice < 3){
        printf("Nao ha vertices suficientes para formartar o poligono!");
    }else if(vertice == 3){
        area = AreaTriangulo(ponto[1], ponto[2], ponto[3]);
        printf("A area do poligono é igual a: %.2f.", area);
    }else{
        for(int i = 2; i <= vertice; i++){
            areaTri = AreaTriangulo(ponto[1], ponto[i - 1], ponto[i]);
            area += areaTri;
        }
        printf("A area do e igual a: %.2f", area);
    }

    fclose(arquivo);
    
}

float AreaTriangulo(Ponto A, Ponto B, Ponto C){
    float area, det;

    det = (A.X * B.Y + A.Y * C.X + B.X * C.Y) - (B.Y * C.X + A.X * C.Y + A.Y * B.X);
    area = fabs(det)/2;

    return area;
}