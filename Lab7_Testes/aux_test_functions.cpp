#include <cstddef>
#include <cstdlib>

extern "C"
{
#include "arvbin.h"
}

#include "aux_test_functions.h"

int intcmp(void* arg1, void* arg2)
{
	int* a1 = (int*)arg1;
	int* a2 = (int*)arg2;

	return *a1 - *a2;
}

static void aux_arvbin_preencher_rec(struct arvbin_no* no, struct arvbin_no* pai, int indice_no, int* dados[], int tam_lista, struct arvbin_no* nos[])
{
	int indice_prox;

	no->pai = pai;
	no->dado = dados[indice_no];

	indice_prox = 2*indice_no + 1;
	if (indice_prox < tam_lista && dados[indice_prox] != NULL)
	{
		nos[indice_prox] = (struct arvbin_no*)malloc(sizeof(struct arvbin_no));
		no->esq = nos[indice_prox];
		aux_arvbin_preencher_rec(no->esq, no, indice_prox, dados, tam_lista, nos);
	}
	else
	{
		no->esq = NULL;
	}

	indice_prox = 2*indice_no + 2;
	if (indice_prox < tam_lista && dados[indice_prox] != NULL)
	{
		nos[indice_prox] = (struct arvbin_no*)malloc(sizeof(struct arvbin_no));
		no->dir = nos[indice_prox];
		aux_arvbin_preencher_rec(no->dir, no, indice_prox, dados, tam_lista, nos);
	}
	else
	{
		no->dir = NULL;
	}
}

void aux_arvbin_preencher(struct arvbin* arv, int(*compar)(void*, void*), int* dados[], int tam_lista, struct arvbin_no* nos[])
{
	arv->compar = compar;

	if (tam_lista == 0)
	{
		arv->raiz = NULL;
	}
	else
	{
		nos[0] = (struct arvbin_no*)malloc(sizeof(struct arvbin_no));
		arv->raiz = nos[0];
		aux_arvbin_preencher_rec(arv->raiz, NULL, 0, dados, tam_lista, nos);
	}
}

static int aux_arvbin_iguais_rec(struct arvbin_no* no1, struct arvbin_no* no2, int(*compar)(void*, void*))
{
	if (no1 == NULL && no2 == NULL)
	{
		return 1;
	}
	else if ((no1 == NULL && no2 != NULL) || (no1 != NULL && no2 == NULL))
	{
		return 0;
	}
	else
	{
		if (compar(no1->dado, no2->dado) != 0)
		{
			return 0;
		}
		else
		{
			return aux_arvbin_iguais_rec(no1->esq, no2->esq, compar) && aux_arvbin_iguais_rec(no1->dir, no2->dir, compar);
		}
	}
}

int aux_arvbin_iguais(struct arvbin* arv1, struct arvbin* arv2)
{
	if (arv1->compar != arv2->compar)
	{
		return 0;
	}
	else
	{
		return aux_arvbin_iguais_rec(arv1->raiz, arv2->raiz, arv1->compar);
	}
}

static void aux_arvbin_limpar_rec(struct arvbin_no* no)
{
	if (no != NULL)
	{
		aux_arvbin_limpar_rec(no->esq);
		aux_arvbin_limpar_rec(no->dir);
	}

	free(no);
}

void aux_arvbin_limpar(struct arvbin* arv)
{
	aux_arvbin_limpar_rec(arv->raiz);
}

int memoria_foi_liberada(void* arg, int tam)
{
	int i;
	unsigned char* arg_char = (unsigned char*)arg;
	for (i = 0; i < tam; i++)
	{
		if (arg_char[i] != 0xDD)
		{
			return 0;
		}
	}

	return 1;
}