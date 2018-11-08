#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_remover, ArvoreVaziaRemoverNull)
{
	struct arvbin arv, arv_depois;

	aux_arvbin_preencher(&arv, intcmp, NULL, 0, NULL);

	arvbin_remover(&arv, NULL);

	aux_arvbin_preencher(&arv_depois, intcmp, NULL, 0, NULL);
	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_remover, ArvoreUmElemento)
{
	struct arvbin arv, arv_depois;
	int temp[1] = { 0 };
	int* dados[1] = { &temp[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_remover(&arv, nos[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, NULL, 0, NULL);
	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));
	ASSERT_NE(0, memoria_foi_liberada(nos[0], sizeof(struct arvbin_no)));

	_CrtSetDbgFlag(tmpFlagOld);

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_remover, ArvoreDoisElementosRaizEsquerdaRemoveRaiz)
{
	struct arvbin arv, arv_depois;
	int temp[2] = { 1, 0 }, temp_depois[1] = { 0 };
	int* dados[2] = { &temp[0], &temp[1] };
	int* dados_depois[1] = { &temp_depois[0] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_remover(&arv, nos[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);
	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));
	ASSERT_NE(0, memoria_foi_liberada(nos[0], sizeof(struct arvbin_no)));

	_CrtSetDbgFlag(tmpFlagOld);

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_remover, ArvoreTresElementosRaizEsquerdaDireitaRemoveRaiz)
{
	struct arvbin arv, arv_depois;
	int temp[3] = { 1, 0, 2 }, temp_depois[2] = { 2, 0 };
	int* dados[3] = { &temp[0], &temp[1], &temp[2] };
	int* dados_depois[2] = { &temp_depois[0], &temp_depois[1] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_remover(&arv, nos[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);
	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));
	ASSERT_NE(0, memoria_foi_liberada(nos[0], sizeof(struct arvbin_no)));

	_CrtSetDbgFlag(tmpFlagOld);

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_remover, ArvoreQuatroElementosRemoveRaiz)
{
	struct arvbin arv, arv_depois;
	int temp[4] = { 1, 0, 3, 2 }, temp_depois[3] = { 2, 0, 3 };
	int* dados[6] = { &temp[0], &temp[1], &temp[2], NULL, NULL, &temp[3] };
	int* dados_depois[3] = { &temp_depois[0], &temp_depois[1], &temp_depois[2] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_remover(&arv, nos[0]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);
	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));
	ASSERT_NE(0, memoria_foi_liberada(nos[0], sizeof(struct arvbin_no)));

	_CrtSetDbgFlag(tmpFlagOld);

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}

TEST(arvbin_remover, ArvoreCincoElementosRemoveDireita)
{
	struct arvbin arv, arv_depois;
	int temp[5] = { 0, 2, 1, 4, 3 }, temp_depois[4] = { 0, 3, 1, 4 };
	int* dados[14] = { &temp[0], NULL, &temp[1], NULL, NULL, &temp[2], &temp[3], NULL, NULL, NULL, NULL, NULL, NULL, &temp[4] };
	int* dados_depois[7] = { &temp_depois[0], NULL, &temp_depois[1], NULL, NULL, &temp_depois[2], &temp_depois[3] };
	struct arvbin_no* nos[sizeof(dados)/sizeof(int*)];
	struct arvbin_no* nos_depois[sizeof(dados_depois)/sizeof(int*)];

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	int tmpFlagOld = tmpFlag;
	tmpFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	aux_arvbin_preencher(&arv, intcmp, dados, sizeof(dados)/sizeof(int*), nos);

	arvbin_remover(&arv, nos[2]);

	aux_arvbin_preencher(&arv_depois, intcmp, dados_depois, sizeof(dados_depois)/sizeof(int*), nos_depois);
	ASSERT_NE(0, aux_arvbin_iguais(&arv, &arv_depois));
	ASSERT_NE(0, memoria_foi_liberada(nos[2], sizeof(struct arvbin_no)));

	_CrtSetDbgFlag(tmpFlagOld);

	aux_arvbin_limpar(&arv);
	aux_arvbin_limpar(&arv_depois);
}
