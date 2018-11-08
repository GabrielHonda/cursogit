#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_maximo, ArvoreVaziaComecaNaRaiz)
{
	struct arvbin arv;

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, arvbin_maximo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreUmElementoComecaNaRaiz)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_maximo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreUmElementoComecaNaDireita)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_maximo(&arv, arv.raiz->dir));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreDoisElementosRaizDireitaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[2], arvbin_maximo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreDoisElementosRaizEsquerdaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[2] = { 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_maximo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreTresElementosRaizEsquerdaDireitaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[2], arvbin_maximo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreTresElementosRaizEsquerdaDireitaComecaNaEsquerda)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[1], arvbin_maximo(&arv, arv.raiz->esq));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreTresElementosRaizDireitaDireitaComecaNaRaiz)
{
	struct arvbin arv;
	int temp[3] = { 0, 1, 2 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[6], arvbin_maximo(&arv, arv.raiz));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_maximo, ArvoreCincoElementosComecaNaEsquerda)
{
	struct arvbin arv;
	int temp[5] = { 3, 1, 4, 0, 2 };
	int* dados[5] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[4], arvbin_maximo(&arv, arv.raiz->esq));

	aux_arvbin_limpar(&arv);
}