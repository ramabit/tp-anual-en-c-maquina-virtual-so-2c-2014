/*
 * memoria.h
 *
 *  Created on: 15/9/2014
 *      Author: martin
 */

#ifndef MEMORIA22_H_
#define MEMORIA22_H_

#include <hu4sockets/tcb.h>

/**
 * @NAME: crear_segmento
 * @DESC: Solicita la creacion de un segmento a la MSP.
 * 		Deja en direccion la direccion del segmento
 * @RETURNS: Devuelve 0 en caso de exito; -1 en caso de Error de Memoria Llena.
 */
int32_t crear_segmento(uint32_t pid, uint32_t tamanio, direccion* direccion);

/**
 * Destruye el segmento correspondiente
 */
void destruir_segmento(uint32_t pid, direccion base_segmento);

/**
 * Escribe en la memoria los bytes enviados
 *
 * @RETURNS: 0 en caso de exito; -1 si existe Segmentatio Fault
 */
int32_t escribir_memoria(uint32_t pid, direccion base_segmento, char* chorro_bytes, uint32_t len);
#endif /* MEMORIA22_H_ */
