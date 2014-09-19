/*
 * tcb-funciones.c
 *
 *  Created on: 16/09/2014
 *      Author: utnso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "estructuras.h"
#include "resultados.h"

tcb_t* crear_tcb() {
	return malloc(sizeof(tcb_t));
}

int32_t actualizar_valor_en_registro1(tcb_t* tcb, char* registro, int32_t numero) {
	if (strcmp(registro, "a") == 0) {
		tcb->a = numero;
		return OK;
	}
	if (strcmp(registro, "b") == 0) {
		tcb->b = numero;
		return OK;
	}
	if (strcmp(registro, "c") == 0) {
		tcb->c = numero;
		return OK;
	}
	if (strcmp(registro, "d") == 0) {
		tcb->d = numero;
		return OK;
	}
	if (strcmp(registro, "e") == 0) {
		tcb->e = numero;
		return OK;
	}
	return FALLO;
}

int32_t actualizar_valor_en_registro(tcb_t* tcb, char registro, int32_t numero) {
	if ('a' == registro) {
		tcb->a = numero;
		return OK;
	}
	if ('b' == registro) {
		tcb->a = numero;
		return OK;
	}
	if ('c' == registro) {
		tcb->a = numero;
		return OK;
	}
	if ('d' == registro) {
		tcb->a = numero;
		return OK;
	}
	if ('e' == registro) {
		tcb->a = numero;
		return OK;
	}
	return FALLO;
}

int32_t obtener_valor_de_registro1(tcb_t* tcb, char* registro) {
	if (strcmp(registro, "a") == 0) {
		return tcb->a;
	}
	if (strcmp(registro, "b") == 0) {
		return tcb->b;
	}
	if (strcmp(registro, "c") == 0) {
		return tcb->c;
	}
	if (strcmp(registro, "d") == 0) {
		return tcb->d;
	}
	if (strcmp(registro, "e") == 0) {
		return tcb->e;
	}
	return FALLO;
}

int32_t obtener_valor_de_registro(tcb_t* tcb, char registro) {
	if ('a' == registro) {
		return tcb->a;
	}
	if ('b' == registro) {
		return tcb->b;
	}
	if ('c' == registro) {
		return tcb->c;
	}
	if ('d' == registro) {
		return tcb->d;
	}
	if ('e' == registro) {
		return tcb->e;
	}
	return FALLO;
}

int32_t actualizar_pc(tcb_t* tcb, int32_t valor) {
	tcb->pc = valor;
	return OK;
}

int32_t obtener_pc(tcb_t* tcb) {
	return tcb->pc;
}

direccion obtener_base_de_codigo(tcb_t* tcb) {
	return tcb->base_codigo;
}
