/*
Assuming the protocol we are adding is for the (imaginary) manufacturer:  Shuzu

Our fantasy protocol is a standard protocol, so we can use this standard
template without too much work. Some protocols are quite unique and will require
considerably more work in this file! It is way beyond the scope of this text to
explain how to reverse engineer "unusual" IR protocols. But, unless you own an
oscilloscope, the starting point is probably to use the rawDump.ino sketch and
try to spot the pattern!

Before you start, make sure the IR library is working OK:
  # Open up the Arduino IDE
  # Load up the rawDump.ino example sketch
  # Run it

Now we can start to add our new protocol...

1. Copy this file to : ir_Shuzu.cpp

2. Replace all occurrences of "Shuzu" with the name of your protocol.

3. Tweak the #defines to suit your protocol.

4. If you're lucky, tweaking the #defines will make the default send() function
   work.

5. Again, if you're lucky, tweaking the #defines will have made the default
   decode() function work.

You have written the code to support your new protocol!

Now you must do a few things to add it to the IRremote system:

1. Open IRremote.h and make the following changes:
   REMEMEBER to change occurences of "SHUZU" with the name of your protocol

   A. At the top, in the section "Supported Protocols", add:
      #define DECODE_SHUZU  1
      #define SEND_SHUZU    1

   B. In the section "enumerated list of all supported formats", add:
      SHUZU,
      to the end of the list (notice there is a comma after the protocol name)

   C. Further down in "Main class for receiving IR", add:
      //......................................................................
      #if DECODE_SHUZU
          bool  decodeShuzu (decode_results *results) ;
      #endif

   D. Further down in "Main class for sending IR", add:
      //......................................................................
      #if SEND_SHUZU
          void  sendShuzu (unsigned long data,  int nbits) ;
      #endif

   E. Save your changes and close the file

2. Now open irRecv.cpp and make the following change:

   A. In the function IRrecv::decode(), add:
      #ifdef DECODE_NEC
          DBG_PRINTLN("Attempting Shuzu decode");
          if (decodeShuzu(results))  return true ;
      #endif

   B. Save your changes and close the file

You will probably want to add your new protocol to the example sketch

3. Open MyDocuments\Arduino\libraries\IRremote\examples\IRrecvDumpV2.ino

   A. In the encoding() function, add:
      case SHUZU:    Serial.print("SHUZU");     break ;

Now open the Arduino IDE, load up the rawDump.ino sketch, and run it.
Hopefully it will compile and upload.
If it doesn't, you've done something wrong. Check your work.
If you can't get it to work - seek help from somewhere.

If you get this far, I will assume you have successfully added your new protocol
There is one last thing to do.

1. Delete this giant instructional comment.

2. Send a copy of your work to us so we can include it in the library and
   others may benefit from your hard work and maybe even write a song about how
   great you are for helping them! :)

Regards,
  BlueChip
*/

#include "IRremote.h"
#include "IRremoteInt.h"

//==============================================================================
//
//
//                              S H U Z U
//
//
//==============================================================================

#define BITS          16  // The number of bits in the command

#define HDR_MARK    5800  // The length of the Header:Mark
#define HDR_SPACE   1200  // The lenght of the Header:Space

#define BIT_MARK    550  // The length of a Bit:Mark
#define ONE_SPACE   1200  // The length of a Bit:Space for 1's
#define ZERO_SPACE  550  // The length of a Bit:Space for 0's
#define TOPBIT 0x8000

//+=============================================================================
//
#if SEND_SKYHDTV
void  IRsend::sendSKYhdtv (unsigned short data,  int nbits)
{

        int toggle;
	// Set IR carrier frequency
	enableIROut(36);

	// Header
	mark(HDR_MARK);
	space(HDR_SPACE);

        toggle = 0;


	// Data
	for (int i = 0; i < nbits; i++) {
           toggle = !toggle;
           if (data & TOPBIT) {
   
            if(toggle){
              mark(ONE_SPACE);
            }
            else{
              space(ONE_SPACE);
            }

           }
           else{ 
             
            if(toggle){
              mark(ZERO_SPACE);
            }
            else{
              space(ZERO_SPACE);
            }
             
               }
      data <<= 1;


        }
	// Footer
	mark(BIT_MARK);
    space(0);  // Always end with the LED off
}
#endif

