/* is_released.ino
 * Author Diego Perez (http://hotboards.org)
 * toggle led on pin 13 when the button on pin 5 is released
 */

#include <Arduino.h>
#include <Hotboards_buttons.h>

// create a single button object, when the button is pressed it gives you a LOW value
// because it work with pull-ups.
Hotboards_buttons btn( 5 );
// if your buton gives you a HIGH value when is pressed, then we need to create the button
// object with an extra parameter: Hotboards_buttons btn( 5, HIGH );
// in any case the functions will return a '1' value any time the button is released

void setup( void )
{
    // to ilustrate our example we use the led on pin 13
    pinMode( 13, OUTPUT );
}

void loop( void )
{
    // the moment when the button is released the function will return a '1'
    // it doesn't matter if our button is configured with pull-ups(LOW) or pull-downs(HIGH)
    if( btn.isReleased( ) )
    {
        // toggle led on pin 13
        digitalWrite( 13, !digitalRead( 13 ) );
    }
}
