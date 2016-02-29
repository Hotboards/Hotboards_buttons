Hotboards_buttons
=================

Genial libreria de proposito general para leer botones mecanicos, puedes saber cuando han sido presionados o soltados, ademas de saber su estado en todo momento. Descarga la libreria en formato [**zip**](https://github.com/Hotboards/Hotboards_buttons/archive/master.zip), renombra el archivo ( _solo quita el **-master**_ ) e importala a tu Arduino IDE com dice [aqui](http://developer.mbed.org/cookbook/Working-with-Libraries).

API
---

**Hotboards_buttons( int pin, bool active=LOW )**

Constructor para inicializar botones. unicamnete se puede crear un solo boton por instancia. Se puede indicar el nivel de voltaje que el boton presenta cuando este se presiona, un valor LOW indica que los botones funcionan con pull-ups, mientras que un valor HIGH indica pull-downs.

``` cpp
/* creamos un boton en el pin 5 (por default funciona con pull-ups) */
Hotboards_buttons btn( 5 );
/* creamos un boton en el pin 9 que funciona con pull-downs */
Hotboards_buttons btn2( 9, HIGH );
```

**bool isPressed( void )**

Regresa un valor de **1** cuando el boton se presiona. Una vez leido el valor, este no volvera a indicar que el boton se presiono hasta que sea soltado y presionado de nuevo. No importa si se ha configurado el boton con pull-ups o pull-downs, la funcion regresa el mismo valor

``` cpp
// creamos un boton en pin 7
Hotboards_buttons btn( 7 );
// preguntamos cuando este se presione
if( btn.isPressed( ) ){
    // se presiono el boton
}
```

**bool isReleased( void )**

Regresa un valor de **1** cuando el boton se suelta. Una vez leido el valor, este no volvera a indicar que el boton se solto hasta que sea presionado y soltado de nuevo. No importa si se ha configurado el boton con pull-ups o pull-downs, la funcion regresa el mismo valor

``` cpp
// creamos un boton en pin 7
Hotboards_buttons btn( 7 );
// preguntamos cuando este se suelte despues de presionado
if( btn.isRleased( ) ){
    // se solto el boton
}
```

**bool status( void )**

Regresa un valor de **1** cuando el boton esta presionado un **0** cuando no lo esta.

``` cpp
// creamos un boton en pin 7
Hotboards_buttons btn( 7 );
// preguntamos si el boton esta o no presionado
if( btn.status( ) ){
    // el boton esta presionado
}
else {
    // el boton no esta presionado
}
```

Ejemplos
--------

- [Leyendo estado de un boton](https://github.com/Hotboards/Hotboards_buttons/tree/master/examples/button/button.ino)
- [Preguntando si se presiono el boton](https://github.com/Hotboards/Hotboards_buttons/tree/master/examples/is_pressed/is_pressed.ino)
- [Preguntando si se solto el boton](https://github.com/Hotboards/Hotboards_buttons/tree/master/examples/is_released/is_released.ino)
- [Leyendo un dos botones cuando se presionan](https://github.com/Hotboards/Hotboards_buttons/tree/master/examples/buttons/buttons.ino)
