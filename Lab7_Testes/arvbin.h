#pragma once

struct arvbin_no
{
	void* dado;
	struct arvbin_no* pai;
	struct arvbin_no* esq;
	struct arvbin_no* dir;
};

struct arvbin
{
	struct arvbin_no* raiz;
	int (*compar)(void*, void*);
};

void arvbin_inicializar(struct arvbin* arv, int(*compar)(void*, void*));
void arvbin_inserir(struct arvbin* arv, void* dado);
void arvbin_visitar_em_ordem_rec(struct arvbin_no* no, void(*func_visita)(struct arvbin_no*));
void arvbin_visitar_em_ordem(struct arvbin* arv, void(*func_visita)(struct arvbin_no*));
struct arvbin_no* arvbin_minimo(struct arvbin* arv, struct arvbin_no* no);
struct arvbin_no* arvbin_maximo(struct arvbin* arv, struct arvbin_no* no);
struct arvbin_no* arvbin_predecessor(struct arvbin* arv, struct arvbin_no* no);
struct arvbin_no* arvbin_sucessor(struct arvbin* arv, struct arvbin_no* no);
void arvbin_remover(struct arvbin* arv, struct arvbin_no* no);
struct arvbin_no* arvbin_buscar(struct arvbin* arv, void* dado);
int arvbin_contar_elementos(struct arvbin* arv);
int arvbin_altura_elemento(struct arvbin* arv, struct arvbin_no* no);
int arvbin_profundidade(struct arvbin* arv);
void arvbin_visitar_em_ordem_inversa(struct arvbin* arv,	void(*func_visita)(struct arvbin_no*));
