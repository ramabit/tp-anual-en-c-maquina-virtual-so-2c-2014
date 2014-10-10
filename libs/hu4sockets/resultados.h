/*
 * resultados.h
 *
 *  Created on: 27/09/2014
 *      Author: utnso
 */

#ifndef RESULTADOS_H_
#define RESULTADOS_H_

typedef enum {
	OK,
	FALLO,
	PRUEBA,
	TERMINO,

	// FALLOS EN CPU: 101 -> 130
	FALLO_CONEXION = 102,
	FALLO_COMUNICACION = 103,
	FALLO_PEDIDO_DE_TCB = 104,
	FALLO_CREACION_DE_SEGMENTO = 105,
	FALLO_DESTRUCCION_DE_SEGMENTO = 106,
	FALLO_LECTURA_DE_MEMORIA = 107,
	FALLO_ESCRITURA_EN_MEMORIA = 108,

	// EXCEPCIONES EN CPU: 131 -> 150
	EXCEPCION_NO_ENCONTRO_EL_REGISTRO = 131,
	EXCEPCION_DIVISION_POR_CERO = 132,
	EXCEPCION_POR_INTERRUPCION = 133,
} resultado_t;

#endif /* RESULTADOS_H_ */
