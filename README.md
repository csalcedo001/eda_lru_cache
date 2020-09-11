# LRU Cache: Analisis de complejidad

## Estructuras utilizadas

Se construyo el LRU cache con un unordered\_map (hash table) y un doubly linked list porque permiten realizar las operaciones insertKeyValuePair, getValueFromKey y getMostRecentKey en O(1). El map asocia un key al nodo de la lista para poder acceder al tanto al key como al value. La lista esta ordenada segun el ultimo uso de cada key, lo que quiere decir que el ultimo key en ser utilizado estara al inicio de la lista, mientras que el elemento menos usado se encontrara al final.

## Complejidad temporal

### insertKeyValuePair

Esta funcion se ejecuta en O(1). Al insertar un key-value pair el unordered\_map puede agregar el key un tiempo estimado de O(1) por tratarse de un hash table. De la misma manera, como el key insertado es el ultimo en haberse utilizado, se agrega al inicio de la lista en O(1) con solo actualizar los punteros de los nodos involucrados.

### getValueFromKey

Hallar el value dado un key es una operacion que se realiza en O(1). Esto de debe a que el unordered\_map accede al value del key en un tiempo de acceso estimado de O(1). La lista es actualizada porque el valor accedido es ahora el ultimo en utilizarse. Esto tambien se consigue en O(1) porque en la lista puedes extraer un nodo del medio de la lista y moverlo al inicio con solo actualizar los punteros de las posiciones que han sido modificadas, de forma independiente al numero de elementos en lista.

### getMostRecentKey

Esta operacion se realiza en O(1) porque el elemento mas reciente es el primer elemento en la lista, lo cual solo requiere ver el puntero al primer nodo en la lista.


## Complejidad espacial

La estructura requiere un espacio de O(m) con m la cantidad de elementos especificados al iniciar el cache. Si basamos el analisis de complejidad en el costo por realizar n operaciones sobre el cache, se puede observar que se ocupa un espacio de O(1), ya que tanto el hash table como la lista doblemente enlazada tienen una longitud que crece de forma lineal con el numero de elementos en el cache hasta llegar a la longitud maxima m. Al alcanzar el tope, el cache no crecera incluso al realizar mas operaciones.
