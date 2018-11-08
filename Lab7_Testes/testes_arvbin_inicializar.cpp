#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "arvbin.h"
}

TEST(arvbin_inicializar, Inicializar)
{
	struct arvbin arv;

	arvbin_inicializar(&arv, intcmp);

	ASSERT_EQ(NULL, arv.raiz);
	ASSERT_EQ(&intcmp, arv.compar);

	aux_arvbin_limpar(&arv);
}
