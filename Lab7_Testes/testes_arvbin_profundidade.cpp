#include <string.h>
#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_profundidade, ArvoreVazia)
{
	struct arvbin arv;

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	ASSERT_EQ(0, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreUmElemento)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(1, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreDoisElementosRaizEsquerda)
{
	struct arvbin arv;
	int temp[2] = { 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(2, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreDoisElementosRaizDireita)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(2, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreTresElementosRaizEsquerdaDireita)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(2, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreProfundidadeTresCaso1)
{
	struct arvbin arv;
	int temp[4] = { 2, 1, 3, 0 };
	int* dados[4] = { &temp[0], &temp[1], &temp[2], &temp[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(3, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreProfundidadeTresCaso2)
{
	struct arvbin arv;
	int temp[5] = { 3, 1, 4, 0, 2 };
	int* dados[5] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(3, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreProfundidadeTresCaso3)
{
	struct arvbin arv;
	int temp[6] = { 3, 2, 5, 0, 1, 4 };
	int* dados[6] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(3, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreProfundidadeTresCaso4)
{
	struct arvbin arv;
	int temp[7] = { 3, 2, 5, 0, 1, 4, 6 };
	int* dados[7] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(3, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreProfundidadeQuatro)
{
	struct arvbin arv;
	int temp[8] = { 4, 2, 6, 1, 3, 5, 7, 0 };
	int* dados[8] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6], &temp[7] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(4, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_profundidade, ArvoreProfundidadeCinco)
{
	struct arvbin arv;
	int temp[7] = { 4, 3, 5, 2, 6, 1, 0 };
	int* dados[16] = { &temp[0], &temp[1], &temp[2], &temp[3], NULL, NULL, &temp[4], &temp[5], NULL, NULL, NULL, NULL, NULL, NULL, NULL, &temp[6] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(5, arvbin_profundidade(&arv));

	aux_arvbin_limpar(&arv);
}
