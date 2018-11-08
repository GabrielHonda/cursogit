#include <stddef.h>
#include <stdlib.h>
#include "arvbin.h"

void arvbin_inicializar(struct arvbin* arv, int(*compar)(void*, void*))
{
	// Insira aqui o codigo da sua solucao do exercicio 1
}

void arvbin_inserir(struct arvbin* arv, void* dado)
{
	// Insira aqui o codigo da sua solucao do exercicio 2
}

struct arvbin_no* arvbin_minimo(struct arvbin* arv, struct arvbin_no* no)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 3
	return NULL;
}

struct arvbin_no* arvbin_maximo(struct arvbin* arv, struct arvbin_no* no)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 4
	return NULL;
}

struct arvbin_no* arvbin_predecessor(struct arvbin* arv, struct arvbin_no* no)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 5
	return NULL;
}

struct arvbin_no* arvbin_sucessor(struct arvbin* arv, struct arvbin_no* no)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 6
	return NULL;
}

void arvbin_remover(struct arvbin* arv, struct arvbin_no* no)
{
	// Insira aqui o codigo da sua solucao do exercicio 7
}

struct arvbin_no* arvbin_buscar(struct arvbin* arv, void* dado)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 8
	return NULL;
}

void arvbin_visitar_em_ordem(struct arvbin* arv, void(*func_visita)(struct arvbin_no*))
{
	// Insira aqui o codigo da sua solucao do exercicio 9
}

void arvbin_visitar_em_ordem_inversa(struct arvbin* arv, void(*func_visita)(struct arvbin_no*))
{
	// Insira aqui o codigo da sua solucao do exercicio 10
}

int arvbin_contar_elementos(struct arvbin* arv)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 11
	return -1;
}

int arvbin_altura_elemento(struct arvbin* arv, struct arvbin_no* no)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 12
	return -1;
}

int arvbin_profundidade(struct arvbin* arv)
{
	// Substitua o codigo abaixo pela sua solucao do exercicio 13
	return -1;
}
