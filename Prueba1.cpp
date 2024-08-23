#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

#define TAM 5

typedef struct pila 
{
    int elem[TAM];
    int tope;
};

void inicializar(pila *);
int vacia(pila);
int llena(pila);
void poner(pila *, int);
void quitar(pila *, int *);
int sumarElementos(pila);
bool buscarElemento(pila, int);

int main() {
    pila p, t;
    int x, opc, flag = 0;
    system("cls");
    inicializar(&p);
    do {
        system("cls");
        printf("\nMENU DE PILAS");
        printf("\n\n1-> INSERTAR ELEMENTO ");
        printf("\n2-> ELIMINAR ELEMENTO ");
        printf("\n3-> MOSTRAR ELEMENTOS ");
        printf("\n4-> SUMAR ELEMENTOS ");
        printf("\n5-> BUSCAR ELEMENTO ");
        printf("\n6-> SALIR");
        printf("\n");
        printf("\nDE SU OPCION : ");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                if (!llena(p)) {
                    printf("\nDE EL ELEMENTO A INSERTAR : ");
                    scanf("%d", &x);
                    poner(&p, x);
                } else {
                    printf("\nLA PILA ESTA LLENA");
                }
                break;
            case 2:
                if (!vacia(p)) {
                    quitar(&p, &x);
                    printf("\nEL ELEMENTO ELIMINADO ES: %d", x);
                } else {
                    printf("\nLA PILA ESTA VACIA");
                }
                break;
            case 3:
                if (!vacia(p)) {
                    printf("\nELMENTOS DE LA PILA");
                    printf("\n");
                    t.tope = -1;
                    do {
                        quitar(&p, &x);
                        printf("\n%4d", x);
                        poner(&t, x);
                    } while (!vacia(p));
                    do {
                        quitar(&t, &x);
                        poner(&p, x);
                    } while (!vacia(t));
                } else {
                    printf("\nLA PILA ESTA VACIA\n");
                }
                break;
            case 4:
                if (!vacia(p)) {
                    int suma = sumarElementos(p);
                    printf("\nLA SUMA DE LOS ELEMENTOS EN LA PILA ES: %d", suma);
                } else {
                    printf("\nLA PILA ESTA VACIA");
                }
                break;
            case 5:
                if (!vacia(p)) {
                    printf("\nINGRESE EL ELEMENTO A BUSCAR: ");
                    scanf("%d", &x);
                    if (buscarElemento(p, x)) {
                        printf("\nEL ELEMENTO %d SE ENCUENTRA EN LA PILA.", x);
                    } else {
                        printf("\nEL ELEMENTO %d NO SE ENCUENTRA EN LA PILA.", x);
                    }
                } else {
                    printf("\nLA PILA ESTA VACIA");
                }
                break;
            case 6:
                flag = 1;
                break;
            default:
                printf("\nOPCION NO VALIDA...");
        }
        if (!flag) {
            printf("\n\n");
            system("pause");
        }

    } while (!flag);
    printf("\nHA FINALIZADO EL PROGRAMA\n");
    system("pause");
}

void inicializar(pila *p) {
    (*p).tope = -1;
}

int vacia(pila p) {
    return ((p.tope) == -1);
}

int llena(pila p) {
    return ((p.tope) == (TAM - 1));
}

void poner(pila *p, int x) {
    if (!llena(*p)) {
        (*p).tope++;
        (*p).elem[(*p).tope] = x;
    } else {
        printf("\nSOBREFLUJO");
    }
    return;
}

void quitar(pila *p, int *x) {
    if (!vacia(*p)) {
        *x = (*p).elem[(*p).tope];
        (*p).tope--;
    } else {
        printf("\nBAJOFLUJO");
    }
    return;
}

int sumarElementos(pila p) {
    int suma = 0;
    while (!vacia(p)) {
        int elem;
        quitar(&p, &elem);
        suma += elem;
        poner(&p, elem); 
    }
    return suma;
}

bool buscarElemento(pila p, int valor) {
    bool encontrado = false;
    while (!vacia(p)) {
        int elem;
        quitar(&p, &elem);
        if (elem == valor) {
            encontrado = true;
        }
        poner(&p, elem); 
    }
    return encontrado;
}
