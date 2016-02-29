/*
  Hotboards_buttons.h - Driver to control buttons
  Hotboards buttons board (http://hotboards.org)
  Created by Diego Perez, January 16, 2016.
  Released into the public domain.
*/
#ifndef Hotboards_buttons_h
#define Hotboards_buttons_h

#include <Arduino.h>

/** Hotboards_buttons class.
 *  Used to read mechanical buttons
 *
 * Example:
 * @code
 * #include "Hotboards_buttons.h"
 *
 * Hotboards_buttons btn( 5 );
 *
 * int main( void )
 * {
 *     for(;;){
 *         if( btn.isPressed( ) )
 *             // do something
 *     }
 * }
 * @endcode
 */
class Hotboards_buttons
{
    public :
        /** Create Hotboards_buttons instance
          * @param pin pin where the button will be read it
          * @param active logic level that gives you when the button is pressed
          *
          * Example:
          * @code
          *   // instance one button on pin 5
          *   Hotboards_buttons btn( 5 );
          * @endcode
          */
        Hotboards_buttons( int pin, bool active=LOW );

        /** Tells you if a button has been pressed (only once)
          * @return '1' if the buttons has been pressed
          *
          * Example:
          * @code
          *   // instance one button on pin 5
          *   Hotboards_buttons btn( 5 );
          *   if( btn.isPressed( ) )
          *       // do something
          * @endcode
          */
        bool isPressed( void );

        /** Tells you if a button has been Released (only once)
          * @return '1' if the buttons has been Released
          *
          * Example:
          * @code
          *   // instance one button on pin 5
          *   Hotboards_buttons btn( 5 );
          *   if( btn.isReleased( ) )
          *       // do something
          * @endcode
          */
        bool isReleased( void );

        /** Tells you the button state
          * @return '1' if the buttons is pressed
          *
          * Example:
          * @code
          *   // instance one button on pin 5
          *   Hotboards_buttons btn( 5 );
          *   if( btn.istatus( ) )
          *       // button pressed
          *   else
          *       // button not pressed
          * @endcode
          */
        bool status( void );

    private :
        void poll( void );
        int  _pin;
        bool _pressed;
        bool _lastButtonState;
        bool _isPressed;
        bool _isReleased;
};

#endif
