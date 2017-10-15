# Librería Arduino Debounce Filter
Librería para Arduino que implementa un filtro para eliminar el rebote en dispositivos físicos como pulsadores o encorders. La librería permite fijar un intervalo en milisegundos. Tras un cambio, se ignoran cualquier cambio posterior durante el intervalo, produciéndose el filtrado de los posibles rebotes. 

Más información https://www.luisllamas.es/libreria-arduino-debounce-filter/

## Instrucciones de uso
La clase Debounce Filter dispone de un método AddValue, para introducir el nuevo valor de estado a filtrar. De esta forma podemos usar Debounce Filter con cualquier método de entrada, incluido GPIO, interrupciones, valores calculados, o recibidos por cualquier medio de comunicación.

La librería Debounce Filter permite añadir funciones de callback para los eventos OnRising, OnFalling y OnChanging, por lo que podemos emplear la propia clase Debounce Filter para gestionar el flujo del programa, sin tener que realizar estas tareas desde el bucle principal. 

### Constructor 
El filtro de Debounce Filter se instancia a través de uno de sus constructores.

```c++
DebounceFilter();
DebounceFilter(bool state);
DebounceFilter(unsigned long interval);
DebounceFilter(unsigned long interval, bool state);
```

### Filtrar señal
```c++
// Añadir un nuevo valor al filtro y devolver el valor filtrado
bool AddValue(bool newState);

// Obtener el último estado
bool GetState() const;

// Devuelve true si el ultimo estado ha sido un flanco de bajada
bool IsFalling() const;

// Devuelve true si el último estado ha sido un flanco de subida
bool IsRising() const;

// Cambiar el valor del intervalo
void SetInterval(uint16_t interval);

// Funciones callback
DebounceAction OnChange;
DebounceAction OnFalling;
DebounceAction OnRising;
```

## Ejemplos
La librería Debounce Filter incluye los siguientes ejemplos para ilustrar su uso.
* DebounceFilter: Ejemplo de filtrado y funciones de callback

```c++
#include "DebounceFilterLib.h"

// Datos para simular lectura de un sensor
bool values[] = { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0};
size_t valuesLength = sizeof(values) / sizeof(values[0]);


// Función para simular lectura de un sensor
bool getMeasure()
{
	size_t static index = 0;
	index++;
	return values[index - 1];
}

// Instanciar DebounceFilter
DebounceFilter debouncer;

void setup() 
{
	Serial.begin(9600);
	debouncer.SetInterval(50);
	debouncer.OnFalling = []() {Serial.println("OnFalling");};

	for (size_t index = 0; index < valuesLength; index++)
	{
		bool raw = getMeasure();
		debouncer.AddValue(raw);

		delay(10);
	}
}


void loop() 
{

}
```
