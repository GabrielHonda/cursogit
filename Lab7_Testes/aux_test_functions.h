#pragma once

extern "C"
{
#include "arvbin.h"

	int intcmp(void* arg1, void* arg2);
}

void aux_arvbin_preencher(struct arvbin* arv, int(*compar)(void*, void*), int* dados[], int tam_lista, struct arvbin_no* nos[]);
int aux_arvbin_iguais(struct arvbin* arv1, struct arvbin* arv2);
void aux_arvbin_limpar(struct arvbin* arv);
int memoria_foi_liberada(void* arg, int tam);
