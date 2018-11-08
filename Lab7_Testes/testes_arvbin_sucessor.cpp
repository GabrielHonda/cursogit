#include <string.h>
#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_sucessor, ArvoreUmElemento)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_sucessor(&arv, nos[0]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_sucessor, ArvoreDoisElementosRaizEsquerda)
{
	struct arvbin arv;
	int temp[2] = { 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_sucessor(&arv, nos[0]));
	ASSERT_EQ(nos[0], arvbin_sucessor(&arv, nos[1]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_sucessor, ArvoreDoisElementosRaizDireita)
{
	struct arvbin arv;
	int temp[2] = { 0, 1 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[2], arvbin_sucessor(&arv, nos[0]));
	ASSERT_EQ(NULL, arvbin_sucessor(&arv, nos[2]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_sucessor, ArvoreTresElementosRaizEsquerdaDireita)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[2], arvbin_sucessor(&arv, nos[0]));
	ASSERT_EQ(nos[0], arvbin_sucessor(&arv, nos[1]));
	ASSERT_EQ(NULL, arvbin_sucessor(&arv, nos[2]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_sucessor, ArvoreOitoElementos)
{
	struct arvbin arv;
	int temp[8] = { 4, 2, 6, 1, 3, 5, 7, 0 };
	int* dados[8] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6], &temp[7] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[5], arvbin_sucessor(&arv, nos[0]));
	ASSERT_EQ(nos[4], arvbin_sucessor(&arv, nos[1]));
	ASSERT_EQ(nos[6], arvbin_sucessor(&arv, nos[2]));
	ASSERT_EQ(nos[1], arvbin_sucessor(&arv, nos[3]));
	ASSERT_EQ(nos[0], arvbin_sucessor(&arv, nos[4]));
	ASSERT_EQ(nos[2], arvbin_sucessor(&arv, nos[5]));
	ASSERT_EQ(NULL, arvbin_sucessor(&arv, nos[6]));
	ASSERT_EQ(nos[3], arvbin_sucessor(&arv, nos[7]));

	aux_arvbin_limpar(&arv);
}