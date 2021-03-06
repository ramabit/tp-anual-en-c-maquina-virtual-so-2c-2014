/*
 * pagina.c
 *
 *  Created on: 15/09/2014
 *      Author: utnso
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "pagina.h"
#include "segmento.h"
#include "configuraciones.h"
#include "swapping.h"
#include "semaforos.h"
#include "logs.h"

#include <commons/collections/list.h>

void crear_pagina(segmento_t *segmento, uint32_t bytes){
	pagina_t *pagina = malloc(sizeof(pagina_t));
	pagina->tiene_marco = false;
	pagina->en_disco = false;

	agregar_pagina_a_segmento(segmento,pagina);
	pagina->id = list_size(segmento->paginas)-1;

	pagina->bit_referencia = 0;

	if(bytes >= 256){
		pagina->max_modificable = 255;
	}else{
		pagina->max_modificable = bytes - 1;
	}

	// agrego pagina a indice de paginas
	//lock_lista_indice_paginas();
	list_add(get_indice_paginas(), pagina);
	pagina->id_en_indice = list_size(get_indice_paginas()) - 1;
	//unlock_lista_indice_paginas();
}

void agregar_pagina_a_segmento(segmento_t *segmento, pagina_t *pagina){
	list_add(segmento->paginas, pagina);
}

direccion direccion_virtual_segmento_base_pagina(uint16_t id_segmento, uint16_t id_pagina)
{
	uint32_t base_segmento=direccion_virtual_base_de_segmento(id_segmento);
	return base_segmento | (id_pagina<<8);
}

pagina_t* buscar_pagina_segun_id_en_lista_paginas(uint16_t id_pagina, t_list* lista_paginas){
	bool _es_pagina(pagina_t* pagina) {
		return pagina->id==id_pagina;
	}
	pagina_t* pagina_requerida =(pagina_t*)list_find(lista_paginas, (void*) _es_pagina);
	return pagina_requerida;
}

void asignar_marco(pagina_t* * pagina, segmento_t** segmento, uint32_t pid){
	marco_t* marco=NULL;
	marco = buscar_marco_libre();

	//Si no hay ningun marco libre, swappeo
	//Si hay un marco libre, se lo asigno a la pagina
	if((*pagina)->en_disco){
		swap_out(pid, (*segmento)->id, pagina);
	}else{
		if(marco == NULL){
			swap_in(pagina, (*segmento)->id, pid);
		}else{
			(*pagina)->marco=marco->id;
			(*pagina)->tiene_marco= true;
			marco->id_proceso = pid;
			marco->ocupado= true;

			loggear_trace("Se asigno el marco %d a la pagina %d del segmento %d del proceso %d.",
					marco->id, (*pagina)->id, (*segmento)->id, pid);

			if(cantidad_marcos_libre() == 0){
				loggear_info("Espacio de memoria principal lleno");
			}
		}
	}
}

bool hay_siguiente_pagina(uint16_t id_pagina, t_list* lista_paginas, pagina_t* * encontro_pagina)
{
	*encontro_pagina=list_get(lista_paginas, (id_pagina)+1);
	if((*encontro_pagina)==NULL)
	{
		return false;
	}

	return true;
}

pagina_t* siguiente_pagina(uint16_t id_pagina, t_list* lista_paginas)
{
	return buscar_pagina_segun_id_en_lista_paginas(id_pagina, lista_paginas);
}

