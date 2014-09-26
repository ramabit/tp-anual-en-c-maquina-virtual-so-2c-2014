/*
 * lstestados.h
 *
 *  Created on: 15/9/2014
 *      Author: martin
 */

#ifndef LSTESTADOS_H_
#define LSTESTADOS_H_

#include <commons/collections/queue.h>
#include "estructuras.h"

/**
 * Inicializa las colas del Planificador
 */
void inicializar_listas_estados_tcb();

/**
 * Agrega un TCB a la cola de Ready
 */
void agregar_a_ready(tcb_t* tcb);

void agregar_a_block(tcb_t* tcb);

void agregar_a_exec(tcb_t* tcb);

void agregar_a_exit(tcb_t* tcb);

void quitar_de_exec(tcb_t* tcb);

void agregar_a_cola_recurso(uint32_t recurso, tcb_t* tcb);

void quitar_primero_de_cola_recurso(uint32_t recurso);

#endif /* LSTESTADOS_H_ */
