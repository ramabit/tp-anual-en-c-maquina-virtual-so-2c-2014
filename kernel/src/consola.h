/*
 * consola.h
 *
 *  Created on: 25/9/2014
 *      Author: matias
 */

#ifndef CONSOLA_H_
#define CONSOLA_H_

#include "estructuras.h"

/**
 * recibe por parámetro el identificador de tipo y retorna un puntero a lo que leyó por consola.
 */
//void* leer(uint16_t identificador_tipo);

/*
 * retorna los numeros leidos por consola
 */
int leer_int();

/*
 * retorna la cadena leida por consola.
 */
char* leer_cadena();


void escribir(uint16_t identificador_tipo);

#endif /* CONSOLA_H_ */