
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum
{
    PERGUNTA,
    ANIMAL
} tipoNo;
struct arv
{
    tipoNo tipo;
    char texto[100];
    struct arv *sim;
    struct arv *nao;
};

typedef struct arv Arv;

void run(Arv *a, Arv *raiz);
void processaPergunta(Arv *a, Arv *raiz);
void processaAnimal(Arv *a, Arv *raiz);

Arv *inicializa(void)
{
    return NULL;
}

int vazia(Arv *a)
{
    return a == NULL;
}

Arv *cria(const char *c, Arv *sae, Arv *sad, tipoNo tipo)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));
    strcpy(p->texto, c);
    p->sim = sae;
    p->nao = sad;
    p->tipo = tipo;
    return p;
}

void imprime(Arv *a, int nivel)
{
    if(a == NULL)
        return;

    for(int i = 0; i < nivel; i++)
    {
        printf("   ");
    }

    printf("|-- %s\n", a->texto);
    printf("\n");
    imprime(a->sim, nivel + 1);
    imprime(a->nao, nivel + 1);
}
void preOrder(Arv *a)
{
    if (a != NULL)
    {
        printf("| %s | \n", a->texto);
        preOrder(a->sim);
        preOrder(a->nao);
    }
}

void processaAnimal(Arv *a, Arv *raiz)
{
    char respostaFinal;
    char novaPergunta[100];
    char animalCorreto[100];
    char animalAntigo[100];
    strcpy(animalAntigo, a->texto);
    printf("Reposta final >>>> %s \n", a->texto);
    printf("\n");
    printf("Esse era seu animal? Responda com s ou n \n");
    scanf(" %c", &respostaFinal);
    getchar();
    if (respostaFinal == 's')
    {
        printf("Animal adivinhado com sucesso, parando arvore \n ");
    }
    else if (respostaFinal == 'n')
    {
        printf("Qual o animal correto? \n");
        fgets(animalCorreto, 100, stdin);

        printf("Qual pergunta difere o animal que voce pensou pro animal que foi respondido? \n");
        fgets(novaPergunta, 100, stdin);
        printf("\n");
        printf("O sistema aprendeu uma nova diferenciacao ! Voltando para o comeco \n");
        printf("\n");
        animalCorreto[strcspn(animalCorreto, "\n")] = '\0';
        novaPergunta[strcspn(novaPergunta, "\n")] = '\0';
        strcpy(a->texto, novaPergunta);

        a->nao = cria(animalAntigo, inicializa(), inicializa(), ANIMAL);
        a->sim = cria(animalCorreto, inicializa(), inicializa(), ANIMAL);
        a->tipo = PERGUNTA;
        printf("A sequequencia em pre order == \n");
        preOrder(raiz);
        run(raiz, raiz);
    }
}

void processaPergunta(Arv *a, Arv *raiz)
{
    char resposta;
    printf("Pensando . . . | %s \n", a->texto);

    scanf(" %c", &resposta);

    if (resposta == 's')
    {
        run(a->sim, raiz);
    }
    else if (resposta == 'n')
    {
        run(a->nao, raiz);
    }
    else
    {
        printf("Resposta invalida, responda apenas com s ou n \n");
        printf("Voltando para a pergunta \n");
        run(a, raiz);
    }
}
void run(Arv *a, Arv *raiz)
{
    if (a->tipo == PERGUNTA)
    {
        processaPergunta(a, raiz);
    }
    else if (a->tipo == ANIMAL)
    {
        processaAnimal(a, raiz);
    }
}
Arv *libera(Arv *a)
{
    if (!vazia(a))
    {
        libera(a->sim);
        libera(a->nao);
        free(a);
    }
    return NULL;
}

int main()
{


    Arv *r1 = cria("Pomba", inicializa(), inicializa(), ANIMAL);
    Arv *r2 = cria("Mosca", inicializa(), inicializa(), ANIMAL);
    Arv *r3 = cria("Cachorro", inicializa(), inicializa(), ANIMAL);
    Arv *r4 = cria("Tartaruga", inicializa(), inicializa(), ANIMAL);
    Arv *a3 = cria("E um mamifero?", r3, r4, PERGUNTA);
    Arv *a2 = cria("E uma ave?", r1, r2, PERGUNTA);
    Arv *a1 = cria("Ele voa?", a2, a3, PERGUNTA);
    
    run(a1, a1);

    return 0;
}