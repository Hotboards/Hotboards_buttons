/*
  Hotboards_buttons.cpp - Driver to control buttons
  Hotboards buttons board (http://hotboards.org)
  Created by Diego Perez, January 16, 2016.
  Released into the public domain.
*/
#include "Hotboards_buttons.h"

Hotboards_buttons::Hotboards_buttons( int pin, bool active )
{
    _pin = pin;
    _lastButtonState = 0;
    _pressed = active;
    _isPressed = 0;
    _isReleased = 0;
    pinMode( pin, INPUT );
}

bool Hotboards_buttons::isPressed( void )
{
    bool isPressed;
    poll( );
    isPressed = _isPressed;
    _isPressed = 0;
    return isPressed;
}

bool Hotboards_buttons::isReleased( void )
{
    bool isReleased;
    poll( );
    isReleased = _isReleased;
    _isReleased = 0;
    return isReleased;
}

bool Hotboards_buttons::status( void )
{
    if( digitalRead( _pin ) == _pressed ) return 1;
    else return 0;
}

void Hotboards_buttons::poll( void )
{
    bool buttonState;
    // leemos el boton de la tarjeta
    buttonState = status( );

    // comparemos el estado actual con la anterior lectura
    if( buttonState != _lastButtonState )
    {
        // si el estado cambio esque recien se presiono
        if( buttonState )
        {
            // regresamos un uno si el boton cambio a presionado
            _isPressed = 1;
        }
        else
        {
            // si no es que fue soltado
            _isReleased = 1;
        }
    }
    // respaldamos el esatdo actual para compararlo la sigentoie
    // vez que preguntemos
    _lastButtonState = buttonState;
}
