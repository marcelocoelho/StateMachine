



// STATE MACHINE
////////////////////////////////////////////////////////////////////////////////
enum State {
   WAITING,
   PLAYING,
   DEBUG
};

int globalState = WAITING;

volatile unsigned char displayFramerateDivider;

#define FPS_15  0x0F  // 0x0F means 66 miliseconds in between frames, so 15 frames a second
#define FPS_30  0x07  // 0x07 means 33 miliseconds in between frames, 30 frames a second
#define FPS_60  0x03  // 0x03 means 16 or 17 miliseconds in between frames so 60 frames a second

long countdownFrames = 0;




/*////////////////////////////////////////////////////////////////////////////////

  MAIN SOFTWARE STARTS HERE

////////////////////////////////////////////////////////////////////////////////*/


void setup() {

  
}



/*//////////////////////////////////////////////////////////////////////////////////
    TIMER INTERRUPT AND MAIN ROUTINES
    Time gets called repeatedly, every 4 ms.
    This replaces loop()
//////////////////////////////////////////////////////////////////////////////////*/
ISR(TIMER1_OVF_vect) {

  // Go get input
  getInput();

  // Execute/change state
  changeState();

  // Then deal with output
  displayFramerateDivider = (++displayFramerateDivider) & FPS_30; // this counts from 0 incrementally by 1

  if(displayFramerateDivider == 0)   // this counts frames
  {
    if (countdownFrames > 0) {            // If there is a time, count down to zero
      countdownFrames--;
    } else if (countdownFrames == 0) {   // When it gets to 0, then play animation
      setDisplay();
    } else if (countdownFrames < 0) {   // But if it's -1, then ignore this animation and don't play anything
      // do nothing
    }

  }

}


void getInput() {
  
}


void changeState() {

  
}


void setDisplay() {

}




/*//////////////////////////////////////////////////////////////////////////////////
    TIMER INTERRUPTS
//////////////////////////////////////////////////////////////////////////////////*/

//
// displayStartFrameInterrupt() : Sets up the microcontroller to interrupt when Timer1 overflows.
//
void displayStartFrameInterrupt()
{
   TIMSK1 = _BV(TOIE1);
   //sei();
   TCCR1B |= 0x02;

   sei();
}


//
// displayStopFrameInterrupt() : Keeps the microcontroller from interrupting on Timer1 overflow.
//
void displayStopFrameInterrupt()
{
   TIMSK1 = ~_BV(TOIE1);
}



/*//////////////////////////////////////////////////////////////////////////////////
    LOOP
//////////////////////////////////////////////////////////////////////////////////*/
void loop()
{
  // does nothing

}
