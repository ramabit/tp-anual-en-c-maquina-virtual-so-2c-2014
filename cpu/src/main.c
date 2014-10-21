#include "instrucciones.h"

int32_t main(int32_t argc, char** argv)
{

	setvbuf(stdout, NULL, _IONBF, 0); // funcion necesiaria para imprimir en pantalla en eclipse

	// TODO descomentar (solamente comentado para pruebas)
//	if (conectar_con_memoria() == FALLO_CONEXION
//		|| conectar_con_kernel() == FALLO_CONEXION) { // TODO cambiar a log
//		printf("ERROR FALTAL: Fallo la conexion\n");
//		return 0;
//	}

	if (cargar_configuraciones() == FALLO_CARGA_DE_CONFIGURACIONES) {
		printf("ERROR FALTAL: al cargar configuraciones");
		return 0;
	}

	// TODO eliminar (solamente para pruebas)
	if (conectar_con_kernel() == FALLO_CONEXION) {
		printf("ERROR FALTAL");
		return 0;
	}

	// TODO cambiar a log
	printf("Se pudo conectar a memoria y kernel\n");

	tcb_t tcb;
	t_dictionary* dic_instrucciones = dictionary_create();
	resultado_t (*funcion)(tcb_t*);
	resultado_t resultado = OK;
	int32_t quantum;
	instruccion_t instruccion;

	cargar_diccionario_de_instrucciones(dic_instrucciones);

	// TODO eliminar (solo para pruebas)
	cerrar_puertos();

	// TODO eliminar (solo para pruebas)
	return 0;

	while (1) {
		// TODO preguntar que pasa si no puedo obtener un TCB
		if (pedir_tcb(&tcb, &quantum) == FALLO_PEDIDO_DE_TCB)
			resultado = ERROR_EN_EJECUCION;

		// TODO eliminar (no es mas necesario)
		/*
		 dictionary_destroy(dic_instrucciones);
		 cerrar_puertos();
		 printf("ERROR FALTAL: Fallo pedido de tcb\n");
		 return 0;
		 */

		printf("%d\n", quantum); // TODO eliminar (solamente para pruebas)
		printf("%d\n", tcb.a); // TODO eliminar (solamente para pruebas)

		break; // TODO eliminar (solamente para pruebas)

		if ((quantum <= 0) && !tcb.km)
			resultado = ERROR_EN_EJECUCION;

		// TODO eliminar (no es mas necesario)
		/*
		 dictionary_destroy(dic_instrucciones);
		 cerrar_puertos();
		 printf("ERROR FALTAL: Quantum invalido. Aborto\n");
		 break;
		 */

		while ((quantum > 0 || tcb.km) && resultado == OK) {
			obtener_instruccion(&tcb, instruccion);
			funcion = dictionary_get(dic_instrucciones, instruccion);
			resultado = funcion(&tcb);
			quantum--;
		}

		if (resultado == OK)
			resultado = FIN_QUANTUM;

		// TODO preguntar que pasa si esto falla
		informar_a_kernel_de_finalizacion(tcb, resultado);
	}

	dictionary_destroy(dic_instrucciones);

	cerrar_puertos();

	return 0;
}
