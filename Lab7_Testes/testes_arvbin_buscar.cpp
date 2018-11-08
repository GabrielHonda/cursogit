#include <string.h>
#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_buscar, ArvoreVazia)
{
	struct arvbin arv;
	int buscado = 0;

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscado));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreUmElementoBuscadoExiste)
{
	struct arvbin arv;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscado[1] = { 0 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_buscar(&arv, &buscado[0]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreUmElementoBuscadosNaoExistem)
{
	struct arvbin arv;
	int temp[1] = { 1 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[2] = { 0, 2 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[1]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreDoisElementosRaizEsquerdaBuscadosExistem)
{
	struct arvbin arv;
	int temp[2] = { 3, 1 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[2] = { 3, 1 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(nos[1], arvbin_buscar(&arv, &buscados[1]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreDoisElementosRaizEsquerdaBuscadosNaoExistem)
{
	struct arvbin arv;
	int temp[2] = { 3, 1 };
	int* dados[2] = { &temp[0], &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[3] = { 0, 2, 4 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[2]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreDoisElementosRaizDireitaBuscadosExistem)
{
	struct arvbin arv;
	int temp[2] = { 1, 3 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[2] = { 1, 3 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(nos[2], arvbin_buscar(&arv, &buscados[1]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreDoisElementosRaizDireitaBuscadosNaoExistem)
{
	struct arvbin arv;
	int temp[2] = { 1, 3 };
	int* dados[3] = { &temp[0], NULL, &temp[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[3] = { 0, 2, 4 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[2]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreTresElementosRaizEsquerdaDireitaBuscadosExistem)
{
	struct arvbin arv;
	int temp[3] = { 3, 1, 5 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[3] = { 3, 1, 5 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(nos[1], arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(nos[2], arvbin_buscar(&arv, &buscados[2]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreTresElementosRaizEsquerdaDireitaBuscadosNaoExistem)
{
	struct arvbin arv;
	int temp[3] = { 3, 1, 5 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[4] = { 0, 2, 4, 6 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[2]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[3]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreQuatroElementosBuscadosExistem)
{
	struct arvbin arv;
	int temp[4] = { 5, 3, 7, 1 };
	int* dados[4] = { &temp[0], &temp[1], &temp[2], &temp[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[4] = { 5, 3, 7, 1 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(nos[1], arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(nos[2], arvbin_buscar(&arv, &buscados[2]));
	ASSERT_EQ(nos[3], arvbin_buscar(&arv, &buscados[3]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreQuatroElementosBuscadosNaoExistem)
{
	struct arvbin arv;
	int temp[4] = { 5, 3, 7, 1 };
	int* dados[4] = { &temp[0], &temp[1], &temp[2], &temp[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[5] = { 0, 2, 4, 6, 8 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[2]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[3]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[4]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreOitoElementosBuscadosExistem)
{
	struct arvbin arv;
	int temp[8] = { 9, 5, 13, 3, 7, 11, 15, 1 };
	int* dados[8] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6], &temp[7] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[8] = { 9, 5, 13, 3, 7, 11, 15, 1 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(nos[0], arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(nos[1], arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(nos[2], arvbin_buscar(&arv, &buscados[2]));
	ASSERT_EQ(nos[3], arvbin_buscar(&arv, &buscados[3]));
	ASSERT_EQ(nos[4], arvbin_buscar(&arv, &buscados[4]));
	ASSERT_EQ(nos[5], arvbin_buscar(&arv, &buscados[5]));
	ASSERT_EQ(nos[6], arvbin_buscar(&arv, &buscados[6]));
	ASSERT_EQ(nos[7], arvbin_buscar(&arv, &buscados[7]));

	aux_arvbin_limpar(&arv);
}

TEST(arvbin_buscar, ArvoreOitoElementosBuscadosNaoExistem)
{
	struct arvbin arv;
	int temp[8] = { 9, 5, 13, 3, 7, 11, 15, 1 };
	int* dados[8] = { &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6], &temp[7] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	int buscados[9] = { 0, 2, 4, 6, 8, 10, 12, 14, 16 };

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[0]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[1]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[2]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[3]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[4]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[5]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[6]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[7]));
	ASSERT_EQ(NULL, arvbin_buscar(&arv, &buscados[8]));

	aux_arvbin_limpar(&arv);
}