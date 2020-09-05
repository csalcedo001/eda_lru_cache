# LRU Cache: Analisis de complejidad

## Estructuras utilizadas

Se construyo el LRU cache con un unordered\_map y un deque porque ambos forman parte de la libreria estandar de C++. El map asocia un key al iterador de un deque para poder acceder al pair de key-value. El deque esta ordenado segun el uso de cada key, lo que quiere decir que el ultimo elemento key en ser utilizado estara al inicio del deque.

## Complejidad temporal

### insertKeyValuePair

Esta funcion se ejecuta en O(1). Al insertar un key-value pair el unordered\_map puede agregar el key en O(1) porque es un hash table. De la misma manera, como el key insertado es el ultimo en utilizar, se agrega al inicio del deque en O(1).

### getValueFromKey

Hallar el value dado un key es una operacion que se realiza en O(1). Esto de debe a que el unordered\_map accede al value del key en O(1). El deque es actualizado porque el valor accedido es ahora el ultimo en utilizarse. Esto tambien se consigue en O(1) porque en el deque puedes mover los punteros del nodo a apuntar al inicio de la lista, de forma independiente al numero de elementos en lista.

### getMostRecentKey

Esta operacion se realiza en O(1) porque es el primer elemento en el dequeue. Obtener este elemento toma O(1).


## Complejidad espacial

La estructura requiere un espacio de O(n), ya que tanto el deque como el hash table tienen una longitud que crece de forma lineal con el numero de elementos en el cache.
