#include <string.h>
#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

static int** array_visitas;
static int tam_array_visitas;
static int cont_visitas;

static void func_visita(struct arvbin_no* no)
{
	if (cont_visitas < tam_array_visitas)
	{
		array_visitas[cont_visitas] = (int*)no->dado;
	}

	cont_visitas++;
}

TEST(arvbin_visitar_em_ordem, ArvoreVazia)
{
	struct arvbin arv;

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	array_visitas = NULL;
	tam_array_visitas = 0;
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreUmElemento)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[1] = { &temp[0] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreDoisElementosRaizEsquerda)
{
	struct arvbin arv;
	int temp[2] = { 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[2] = { &temp[1], &temp[0] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreDoisElementosRaizDireita)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[2] = { &temp[0], &temp[1] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreTresElementosRaizEsquerdaDireita)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[3] = { &temp[1], &temp[0], &temp[2] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreTresElementosRaizEsquerdaEsquerda)
{
	struct arvbin arv;
	int temp[3] = { 2, 1, 0 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[3] = { &temp[2], &temp[1], &temp[0] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreTresElementosRaizEsquerdaDireita2)
{
	struct arvbin arv;
	int temp[3] = { 2, 0, 1 };
	int* dados[5] = { &temp[0], &temp[1], NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[3] = { &temp[1], &temp[2], &temp[0] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreTresElementosRaizDireitaDireita)
{
	struct arvbin arv;
	int temp[3] = { 0, 1, 2 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[3] = { &temp[0], &temp[1], &temp[2] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_visitar_em_ordem, ArvoreTresElementosRaizDireitaEsquerda)
{
	struct arvbin arv;
	int temp[3] = { 0, 2, 1 };
	int* dados[6] = { &temp[0], NULL, &temp[1], NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int* visitas[3] = { &temp[0], &temp[2], &temp[1] };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	array_visitas = (int**)malloc(sizeof(temp)/sizeof(int)*sizeof(int*));
	tam_array_visitas = sizeof(temp)/sizeof(int);
	cont_visitas = 0;

	arvbin_visitar_em_ordem(&arv, func_visita);

	ASSERT_EQ(sizeof(visitas)/sizeof(int*), cont_visitas);
	ASSERT_EQ(0, memcmp(array_visitas, visitas, sizeof(visitas)));

	aux_arvbin_limpar(&arv);
}