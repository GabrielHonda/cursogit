#include <string.h>
#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_altura_elemento, ArvoreUmElemento)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(1, arvbin_altura_elemento(&arv, nos[0]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_altura_elemento, ArvoreDoisElementosRaizEsquerda)
{
	struct arvbin arv;
	int temp[2] = { 3, 1 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(1, arvbin_altura_elemento(&arv, nos[0]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[1]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_altura_elemento, ArvoreDoisElementosRaizDireita)
{
	struct arvbin arv;
	int temp[2] = { 1, 3 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(1, arvbin_altura_elemento(&arv, nos[0]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[2]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_altura_elemento, ArvoreTresElementosRaizEsquerdaDireita)
{
	struct arvbin arv;
	int temp[3] = { 3, 1, 5 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(1, arvbin_altura_elemento(&arv, nos[0]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[1]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[2]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_altura_elemento, ArvoreProfundidadeQuatro)
{
	struct arvbin arv;
	int temp[8] = { 4, 2, 6, 1, 3, 5, 7, 0 };
	int* dados[8] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6], &temp[7] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(1, arvbin_altura_elemento(&arv, nos[0]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[1]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[2]));
	ASSERT_EQ(3, arvbin_altura_elemento(&arv, nos[3]));
	ASSERT_EQ(3, arvbin_altura_elemento(&arv, nos[4]));
	ASSERT_EQ(3, arvbin_altura_elemento(&arv, nos[5]));
	ASSERT_EQ(3, arvbin_altura_elemento(&arv, nos[6]));
	ASSERT_EQ(4, arvbin_altura_elemento(&arv, nos[7]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_altura_elemento, ArvoreProfundidadeCinco)
{
	struct arvbin arv;
	int temp[7] = { 4, 3, 5, 2, 6, 1, 0 };
	int* dados[16] = { &temp[0], &temp[1], &temp[2], &temp[3], NULL, NULL, &temp[4], &temp[5], NULL, NULL, NULL, NULL, NULL, NULL, NULL, &temp[6] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(1, arvbin_altura_elemento(&arv, nos[0]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[1]));
	ASSERT_EQ(2, arvbin_altura_elemento(&arv, nos[2]));
	ASSERT_EQ(3, arvbin_altura_elemento(&arv, nos[3]));
	ASSERT_EQ(3, arvbin_altura_elemento(&arv, nos[6]));
	ASSERT_EQ(4, arvbin_altura_elemento(&arv, nos[7]));
	ASSERT_EQ(5, arvbin_altura_elemento(&arv, nos[15]));

	aux_arvbin_limpar(&arv);
}
