/*
 * operaciones-con-bits.h
 *
 *  Created on: 17/10/2014
 *      Author: utnso
 */

#ifndef INSTRUCCIONES_H_
#define INSTRUCCIONES_H_

typedef char instruccion_t[5];

#include <commons/collections/dictionary.h>

#include "ansisop.h"
#include "sockets.h"
#include "tcb-funciones.h"

/*
 * 	@DESC: Crea el diccionario de instrucciones y le carga todas las instrucciones
 * 	@RETURN:
 */
void inicializar_dic_de_instrucciones();

/*
 * 	@DESC: Destruye el diccionario de instrucciones
 * 	@RETURN:
 */
void liberar_dic_de_instrucciones();

/*
 * 	@DESC: Ejecuta la instruccion
 * 	@RETURN:
 * 		OK si salio bien
 *		ERROR_EN_EJECUCION si algo fallo en la instruccion o no habia instruccion a ejecutar
 */
resultado_t ejecutar_siguiente_instruccion(tcb_t* tcb);

#endif /* INSTRUCCIONES_H_ */
