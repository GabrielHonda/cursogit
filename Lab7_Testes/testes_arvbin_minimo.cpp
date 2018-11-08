#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_minimo, ArvoreVaziaComecaNaRaiz)
{
	struct arvbin arv;

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, arvbin_minimo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreUmElementoComecaNaRaiz)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_minimo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreUmElementoComecaNaEsquerda)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_minimo(&arv, arv.raiz->esq));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreDoisElementosRaizEsquerdaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[2] = { 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[1], arvbin_minimo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreDoisElementosRaizDireitaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_minimo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreTresElementosRaizEsquerdaDireitaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[1], arvbin_minimo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreTresElementosRaizEsquerdaDireitaComecaNaDireita)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[2], arvbin_minimo(&arv, arv.raiz->dir));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreTresElementosRaizEsquerdaEsquerdaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[3] = { 2, 1, 0 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[3], arvbin_minimo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_minimo, ArvoreCincoElementosComecaNaDireita)
{
	struct arvbin arv;
	int temp[5] = { 1, 0, 3, 2, 4 };
	int* dados[7] = { &temp[0], &temp[1], &temp[2], NULL, NULL, &temp[3], &temp[4] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[5], arvbin_minimo(&arv, arv.raiz->dir));

	aux_arvbin_limpar(&arv);
}