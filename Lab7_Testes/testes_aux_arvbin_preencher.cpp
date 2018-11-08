#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(aux_arvbin_preencher, ArvoreVazia)
{
	struct arvbin arv;

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreUmElemento)
{
	struct arvbin arv;
	int temp[1] = { 1 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(NULL, arv.raiz->esq);
	ASSERT_EQ(NULL, arv.raiz->dir);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreDoisElementosRaizEsquerda)
{
	struct arvbin arv;
	int temp[2] = { 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(nos[1], arv.raiz->esq);
	ASSERT_EQ(NULL, arv.raiz->dir);

	ASSERT_EQ(&temp[1], arv.raiz->esq->dado);
	ASSERT_EQ(nos[0], arv.raiz->esq->pai);
	ASSERT_EQ(NULL, arv.raiz->esq->esq);
	ASSERT_EQ(NULL, arv.raiz->esq->dir);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreDoisElementosRaizDireita)
{
	struct arvbin arv;
	int temp[2] = { 1, 2 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(NULL, arv.raiz->esq);
	ASSERT_EQ(nos[2], arv.raiz->dir);

	ASSERT_EQ(&temp[1], arv.raiz->dir->dado);
	ASSERT_EQ(nos[0], arv.raiz->dir->pai);
	ASSERT_EQ(NULL, arv.raiz->dir->esq);
	ASSERT_EQ(NULL, arv.raiz->dir->dir);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreTresElementos1)
{
	struct arvbin arv;
	int temp[3] = { 1, 0, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(nos[1], arv.raiz->esq);
	ASSERT_EQ(nos[2], arv.raiz->dir);

	ASSERT_EQ(&temp[1], arv.raiz->esq->dado);
	ASSERT_EQ(nos[0], arv.raiz->esq->pai);
	ASSERT_EQ(NULL, arv.raiz->esq->esq);
	ASSERT_EQ(NULL, arv.raiz->esq->dir);

	ASSERT_EQ(&temp[2], arv.raiz->dir->dado);
	ASSERT_EQ(nos[0], arv.raiz->dir->pai);
	ASSERT_EQ(NULL, arv.raiz->dir->esq);
	ASSERT_EQ(NULL, arv.raiz->dir->dir);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreTresElementos2)
{
	struct arvbin arv;
	int temp[3] = { 2, 1, 0 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(nos[1], arv.raiz->esq);
	ASSERT_EQ(NULL, arv.raiz->dir);

	ASSERT_EQ(&temp[1], arv.raiz->esq->dado);
	ASSERT_EQ(nos[0], arv.raiz->esq->pai);
	ASSERT_EQ(nos[3], arv.raiz->esq->esq);
	ASSERT_EQ(NULL, arv.raiz->esq->dir);

	ASSERT_EQ(&temp[2], arv.raiz->esq->esq->dado);
	ASSERT_EQ(nos[1], arv.raiz->esq->esq->pai);
	ASSERT_EQ(NULL, arv.raiz->esq->esq->esq);
	ASSERT_EQ(NULL, arv.raiz->esq->esq->dir);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreTresElementos3)
{
	struct arvbin arv;
	int temp[3] = { 0, 1, 2 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(NULL, arv.raiz->esq);
	ASSERT_EQ(nos[2], arv.raiz->dir);

	ASSERT_EQ(&temp[1], arv.raiz->dir->dado);
	ASSERT_EQ(nos[0], arv.raiz->dir->pai);
	ASSERT_EQ(NULL, arv.raiz->dir->esq);
	ASSERT_EQ(nos[6], arv.raiz->dir->dir);

	ASSERT_EQ(&temp[2], arv.raiz->dir->dir->dado);
	ASSERT_EQ(nos[2], arv.raiz->dir->dir->pai);
	ASSERT_EQ(NULL, arv.raiz->dir->dir->esq);
	ASSERT_EQ(NULL, arv.raiz->dir->dir->dir);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreTresElementos4)
{
	struct arvbin arv;
	int temp[3] = { 2, 0, 1 };
	int* dados[5] = { &temp[0], &temp[1], NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(nos[1], arv.raiz->esq);
	ASSERT_EQ(NULL, arv.raiz->dir);

	ASSERT_EQ(&temp[1], arv.raiz->esq->dado);
	ASSERT_EQ(nos[0], arv.raiz->esq->pai);
	ASSERT_EQ(NULL, arv.raiz->esq->esq);
	ASSERT_EQ(nos[4], arv.raiz->esq->dir);

	ASSERT_EQ(&temp[2], arv.raiz->esq->dir->dado);
	ASSERT_EQ(nos[1], arv.raiz->esq->dir->pai);
	ASSERT_EQ(NULL, arv.raiz->esq->dir->esq);
	ASSERT_EQ(NULL, arv.raiz->esq->dir->dir);

	aux_arvbin_limpar(&arv);
}

TEST(aux_arvbin_preencher, ArvoreTresElementos5)
{
	struct arvbin arv;
	int temp[3] = { 0, 2, 1 };
	int* dados[6] = { &temp[0], NULL, &temp[1], NULL, NULL, &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	ASSERT_EQ(&temp[0], arv.raiz->dado);
	ASSERT_EQ(NULL, arv.raiz->pai);
	ASSERT_EQ(NULL, arv.raiz->esq);
	ASSERT_EQ(nos[2], arv.raiz->dir);

	ASSERT_EQ(&temp[1], arv.raiz->dir->dado);
	ASSERT_EQ(nos[0], arv.raiz->dir->pai);
	ASSERT_EQ(nos[5], arv.raiz->dir->esq);
	ASSERT_EQ(NULL, arv.raiz->dir->dir);

	ASSERT_EQ(&temp[2], arv.raiz->dir->esq->dado);
	ASSERT_EQ(nos[2], arv.raiz->dir->esq->pai);
	ASSERT_EQ(NULL, arv.raiz->dir->esq->esq);
	ASSERT_EQ(NULL, arv.raiz->dir->esq->dir);

	aux_arvbin_limpar(&arv);
}
