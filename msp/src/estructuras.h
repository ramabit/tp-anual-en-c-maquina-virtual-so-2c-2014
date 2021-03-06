/*
 * estructuras.h
 *
 *  Created on: 15/09/2014
 *      Author: utnso
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#include <stdint.h>
#include <commons/collections/list.h>
#include <pthread.h>

typedef uint32_t direccion;

typedef struct pagina {
	uint16_t id;
	bool tiene_marco;
	bool en_disco;
	uint32_t marco;
	uint64_t id_en_indice;
	uint8_t max_modificable;
	int bit_referencia;
} pagina_t;

typedef struct segmento {
	uint16_t id;
	uint32_t tamanio;
	t_list* paginas;
} segmento_t;

typedef struct proceso_msp{
	uint32_t pid;
	t_list* segmentos;
	pthread_rwlock_t semaforo_rw;
}proceso_msp_t;

typedef struct marco{
	uint32_t id;
	bool ocupado;
	char* datos;
	uint32_t id_proceso;
}marco_t;

#endif /* ESTRUCTURAS_H_ */
