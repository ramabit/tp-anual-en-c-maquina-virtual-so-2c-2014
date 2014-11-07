/*
 * conexiones_cpu.h
 *
 *  Created on: 16/10/2014
 *      Author: utnso
 */

#ifndef CONEXIONES_CPU_H_
#define CONEXIONES_CPU_H_

#include <hu4sockets/sockets.h>

//

typedef struct conexion {
	sock_t* socket;
	uint32_t id;
} conexion_t;

void inicializar_lista_conexiones_cpu();

void* escuchar_conexiones(void*);
void _atender_conexion(sock_t*, sock_t**);
void* _atiendo_hilo_conexion(void* conexion);

void _agregar_conexion(sock_t*, uint32_t);
conexion_t* buscar_conexion_cpu_por_fd(int32_t);
void _recalcular_mayor_fd(int32_t*, int32_t);

void _atiendo_crear_segmento(sock_t*, char*);
void _atiendo_destruir_segmento(sock_t*, char*);
void _atiendo_leer_memoria(sock_t*, char*);
void _atiendo_escribir_memoria(sock_t*, char*);

#endif /* CONEXIONES_CPU_H_ */
