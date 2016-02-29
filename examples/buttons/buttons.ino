/* button.ino
 * Author Diego Perez (http://hotboards.org)
 * turn on a led on pin 13 when the button on pin 5 is pressed and then turn it off
 * when the button on pin 6 is pressed
 */

#include <Arduino.h>
#include <Hotboards_buttons.h>

// create a single button object, when the button is pressed it gives you a LOW value
// because it work with pull-ups.
Hotboards_buttons btn1( 5 );
Hotboards_buttons btn2( 6 );
// if your buton gives you a HIGH value when is pressed, then we need to create the button
// object with an extra parameter: Hotboards_buttons btn( 5, HIGH );
// in any case the functions will return a '1' value any time the button is pressed

void setup( void )
{
    // to ilustrate our example we use the led on pin 13
    pinMode( 13, OUTPUT );
}

void loop( void )
{
    // the moment when the button is pressed the function will return a '1'
    // it doesn't matter if our button is configured with pull-ups(LOW) or pull-downs(HIGH)

    // turn on the led when button 1 is pressed
    if( btn1.isPressed( ) )
    {
        digitalWrite( 13, HIGH );
    }

    // turn off the led when button 2 is pressed
    if( btn2.isPressed( ) )
    {
        digitalWrite( 13, LOW );
    }
}
