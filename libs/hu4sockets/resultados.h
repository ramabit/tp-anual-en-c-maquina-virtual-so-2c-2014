/*
 * resultados.h
 *
 *  Created on: 27/09/2014
 *      Author: utnso
 */

#ifndef RESULTADOS_H_
#define RESULTADOS_H_

typedef enum {

	OK = 1,

//	TODO eliminar (ya no se necesitan mas)
//	FALLO = 2,
//	PRUEBA = 3,
//	TERMINO = 4,

	// FALLOS EN CPU: 101 -> 130
	FALLO_CONEXION = 102,
	FALLO_COMUNICACION = 103,
	FALLO_PEDIDO_DE_TCB = 104,
	FALLO_CREACION_DE_SEGMENTO = 105,
	FALLO_DESTRUCCION_DE_SEGMENTO = 106,
	FALLO_LECTURA_DE_MEMORIA = 107,
	FALLO_ESCRITURA_EN_MEMORIA = 108,
	FALLO_INFORME_A_KERNEL = 109,
	FALLO_CARGA_DE_CONFIGURACIONES = 110,
	FALLO_ENTRADA_ESTANDAR		= 111,

	FALLO_SYSCALL = 112,

	// EXCEPCIONES EN CPU: 131 -> 150
	EXCEPCION_NO_ENCONTRO_EL_REGISTRO = 131,
	// TODO eliminar (no se necesita mas)
//	EXCEPCION_DIVISION_POR_CERO = 132,
	EXCEPCION_POR_INTERRUPCION = 133,
	// TODO eliminar (no se necesitan mas)
//	EXCEPCION_POR_INGRESO_TEXTO = 134,
//	EXCEPCION_POR_INGRESO_TEXTO_CON_TAMANO = 135,
//	EXCEPCION_POR_IMPRIMIR_TEXTO = 136,
//	EXCEPCION_POR_IMPRIMIR_TEXTO_CON_TAMANO = 137,
//	EXCEPCION_POR_JOIN = 138,
//	EXCEPCION_POR_BLOQUEO = 139,
//	EXCEPCION_POR_DESBLOQUEO = 140,
	EXCEPCION_POR_POSICION_DE_STACK_INVALIDA = 141,

	// RESULTADOS DEL CPU AL KERNEL 151 -> 200
	FIN_QUANTUM = 151,
	FIN_EJECUCION = 152,
	DESCONEXION_CPU = 153,
	ERROR_EN_EJECUCION = 154,
//	FIN_INTERRUPCION = 155,

	// RESULTADO DE MEMORIA AL MUNDO 201 -> 250
	RESULTADO_OK = 201,
	ERROR_DE_MEMORIA_LLENA = 202,
	ERROR_NO_ENCUENTRO_SEGMENTO = 203,
	SEGMENTATION_FAULT = 204,

	// RESULTADOS DEL KERNEL AL CPU 251 -> 300
	COMPLETADO_OK = 5,

} resultado_t;

#endif /* RESULTADOS_H_ */
