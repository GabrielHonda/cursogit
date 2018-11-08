#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_inserir, ArvoreVaziaInsereNaRaiz)
{
	struct arvbin arv, arv_depois;
	int temp_depois[1] = { 1 };
	int* dados_depois[1] = { &temp_depois[0] };
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 1 };

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreUmElementoInsereNaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[1] = { 1 };
	int temp_depois[2] = { 1, 0 };
	int* dados[1] = { &temp[0] };
	int* dados_depois[2] = { &temp_depois[0], &temp_depois[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 0 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreUmElementoInsereNaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[1] = { 1 };
	int temp_depois[2] = { 1, 2 };
	int* dados[1] = { &temp[0] };
	int* dados_depois[3] = { &temp_depois[0], NULL, &temp_depois[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 2 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreDoisElementosRaizEsquerdaInsereNaEsquerdaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[2] = { 2, 1 };
	int temp_depois[3] = { 2, 1, 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	int* dados_depois[4] = { &temp_depois[0], &temp_depois[1], NULL, &temp_depois[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 0 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreDoisElementosRaizEsquerdaInsereNaEsquerdaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[2] = { 2, 0 };
	int temp_depois[3] = { 2, 0, 1 };
	int* dados[2] = { &temp[0], &temp[1] };
	int* dados_depois[5] = { &temp_depois[0], &temp_depois[1], NULL, NULL, &temp_depois[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 1 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreDoisElementosRaizDireitaInsereNaDireitaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[2] = { 1, 2 };
	int temp_depois[3] = { 1, 2, 3 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	int* dados_depois[7] = { &temp_depois[0], NULL, &temp_depois[1], NULL, NULL, NULL, &temp_depois[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 3 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreDoisElementosRaizDireitaInsereNaDireitaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[2] = { 1, 3 };
	int temp_depois[3] = { 1, 3, 2 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	int* dados_depois[6] = { &temp_depois[0], NULL, &temp_depois[1], NULL, NULL, &temp_depois[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 2 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaDireitaInsereNaEsquerdaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 2, 1, 3 };
	int temp_depois[4] = { 2, 1, 3, 0 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	int* dados_depois[4] = { &temp_depois[0], &temp_depois[1], &temp_depois[2], &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 0 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaDireitaInsereNaEsquerdaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 3, 1, 4 };
	int temp_depois[4] = { 3, 1, 4, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	int* dados_depois[5] = { &temp_depois[0], &temp_depois[1], &temp_depois[2], NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 2 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaDireitaInsereNaDireitaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 1, 0, 2 };
	int temp_depois[4] = { 1, 0, 2, 3 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	int* dados_depois[7] = { &temp_depois[0], &temp_depois[1], &temp_depois[2], NULL, NULL, NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 3 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaDireitaInsereNaDireitaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 1, 0, 3 };
	int temp_depois[4] = { 1, 0, 3, 2 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	int* dados_depois[6] = { &temp_depois[0], &temp_depois[1], &temp_depois[2], NULL, NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 2 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaEsquerdaInsereNaEsquerdaEsquerdaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 3, 2, 1 };
	int temp_depois[4] = { 3, 2, 1, 0 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	int* dados_depois[8] = { &temp_depois[0], &temp_depois[1], NULL, &temp_depois[2], NULL, NULL, NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 0 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaEsquerdaInsereNaEsquerdaEsquerdaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 3, 2, 0 };
	int temp_depois[4] = { 3, 2, 0, 1 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	int* dados_depois[9] = { &temp_depois[0], &temp_depois[1], NULL, &temp_depois[2], NULL, NULL, NULL, NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 1 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaEsquerdaInsereNaEsquerdaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 3, 1, 0 };
	int temp_depois[4] = { 3, 1, 0, 2 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	int* dados_depois[9] = { &temp_depois[0], &temp_depois[1], NULL, &temp_depois[2], &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 2 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizEsquerdaEsquerdaInsereNaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 2, 1, 0 };
	int temp_depois[4] = { 2, 1, 3, 0 };
	int* dados[4] = { &temp[0], &temp[1], NULL, &temp[2] };
	int* dados_depois[9] = { &temp_depois[0], &temp_depois[1], &temp_depois[2], &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 3 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizDireitaDireitaInsereNaDireitaDireitaDireita)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 0, 1, 2 };
	int temp_depois[4] = { 0, 1, 2, 3 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	int* dados_depois[15] = { &temp_depois[0], NULL, &temp_depois[1], NULL, NULL, NULL, &temp_depois[2], NULL, NULL, NULL, NULL, NULL, NULL, NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 3 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizDireitaDireitaInsereNaDireitaDireitaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 0, 1, 3 };
	int temp_depois[4] = { 0, 1, 3, 2 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	int* dados_depois[14] = { &temp_depois[0], NULL, &temp_depois[1], NULL, NULL, NULL, &temp_depois[2], NULL, NULL, NULL, NULL, NULL, NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 2 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizDireitaDireitaInsereNaDireitaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 0, 2, 3 };
	int temp_depois[4] = { 0, 2, 1, 3 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	int* dados_depois[7] = { &temp_depois[0], NULL, &temp_depois[1], NULL, NULL, &temp_depois[2], &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 1 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_inserir, ArvoreTresElementosRaizDireitaDiretaInsereNaEsquerda)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 1, 2, 3 };
	int temp_depois[4] = { 1, 0, 2, 3 };
	int* dados[7] = { &temp[0], NULL, &temp[1], NULL, NULL, NULL, &temp[2] };
	int* dados_depois[7] = { &temp_depois[0], &temp_depois[1], &temp_depois[2], NULL, NULL, NULL, &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];
	int a_inserir[1] = { 0 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_inserir(&arv, &a_inserir[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);

	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}
