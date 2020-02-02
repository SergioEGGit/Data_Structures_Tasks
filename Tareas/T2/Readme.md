#  Especificación Informal TDA

   * ___Moneda:___  InsertarMoneda, ImprimirLista, BuscarMoneda, ModificarMonedero.
   * ___Descripción:___ Los valores del son enteros, cadena de texto y TDA Anidados.
   * ___Operaciones:___
      * InsertarMoneda(ListaMoneda:TDA, idM:entero, nombreM:cadena de texto, cantidadM:entero) devuelve(void)
          * requerimientos: idM,cantidadM > 0 y nombreM <> NULL.
          *	efecto: Inserta.	  
      * ImprimirLista(ListaMoneda:TDA) devuelve(void)
          * efecto: muestra.
      * BuscarMoneda(ListaMoneda:TDA, nombreM:cadena de texto) devuelve(entero)
	      * requerimientos: nombreM <> NULL.
		  * efecto: Buscar.
      * ModificarMonedero(ListaMoneda:TDA, nombreM:cadena de texto, CantiadRes:entero) devuelve(void)
          * requerimientos: _nombreM <> NULL y CantidadRes > 0.
          * efecto: Modificar.		  
