/* button_status.ino
 * Author Diego Perez (http://hotboards.org)
 * The most simple program, read a single button on pin 5
 */

#include <Arduino.h>
#include <Hotboards_buttons.h>

// create a single button object, when the button is pressed it gives you a LOW value
// because it work with pull-ups.
Hotboards_buttons btn( 5 );
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
    // when the button is pressed the function will return a '1'
    // it doesn't matter if our button is configured with pull-ups(LOW) or pull-downs(HIGH)
    if( btn.status( ) )
    {
        // button is pressed
        digitalWrite( 13, HIGH );
    }
    else
    {
        // button is not pressed
        digitalWrite( 13, LOW );
    }
    // just to poll not so often
    delay( 50 );
}
