// Progetto di Ivan Cristina
// Catania, 23/03/2018
// Il progetto utilizza un Arduino Uno Rev.3 ed un Adafruit NeoPixel Ring a 24 LEDs.
// Seguire la relazione per tutta la documentazione

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parametro 1 = numero di pixel nell'anello strip
// Parametro 2 = numero pin Arduino (qualunque PWM va bene)
// Parametro 3 = flag del tipo di pixel, vanno aggiunte tutte se necessario:
//   NEO_KHZ800  bitstream a 800 KHz (la maggior parte dei prodotti NeoPixel, tra cui i LED WS2812)
//   NEO_KHZ400  bitstream a 400 KHz (pixel FLORA classic 'v1' (non v2), driver dei LED WS2811)
//   NEO_GRB     Pixel collegati per bitstream di tipo GRB (la maggior parte dei prodotti NeoPixel)
//   NEO_RGB     Pixel collegati per bitstream di tipo RGB (pixel FLORA v1, non v2)
//   NEO_RGBW    Pixel collegati per bitstream di tipo RGBW (prodotti NeoPixel RGBW)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANTE: Per ridurre il rischio di burnout del NeoPixel, è consigliabile aggiungere un
// capacitore da 1000 uF ed una resistenza da 300 - 500 Ohm, minimizzare la distanza tra Arduino e
// la strip. Inoltre connettere la GND prima, se possibile.

void setup() {
  // Necessarie alla scheda Trinket 5V 16MHz, è possibile rimuovere queste righe se non necessarie
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // Fine del codice


  strip.begin();  // Iniziallizza la strip in sè
  strip.show();   // Spegne tutti i pixel (show niente, per cui i pixel vengono spenti)
}

void loop() {
  //cerchio();
  //corsa();
  //colori(20);
  arcobaleno(20);
  //corsa_arcobaleno(50);
}

// Prima funzione principale, accende tutti i pixel uno dietro l'altro con un determinato colore
void assegna_colori(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Seconda funzione principale, le luci si accendono in modo alternato (detto stile "theater-chase")
void funzione_corsa(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  // 10 cicli di inseguimento
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    // Accende ogni terzo pixel
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        // Spegne ogni terzo pixel
      }
    }
  }
}

// Questa funzione mostra un accensione in senso orario, tramite il colore impostato:
void cerchio() {
  assegna_colori(strip.Color(255, 0, 0), 50); // Rosso
  assegna_colori(strip.Color(0, 255, 0), 50); // Verde
  assegna_colori(strip.Color(0, 0, 255), 50); // Blu
  assegna_colori(strip.Color(255, 255, 255), 50); // Bianco
}

// Ricrea l'effetto "chase", ovvero la rincorsa dei pixel:
void corsa() {
  funzione_corsa(strip.Color(127, 127, 127), 50); // Grigio
  funzione_corsa(strip.Color(127, 0, 0), 50); // Rosso
  funzione_corsa(strip.Color(0, 0, 127), 50); // Blu
}

// Applica un colore dinamico a tutti i LEDs
void colori(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Ruota((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Leggermente differente, distribuisce i colori in modo da ricreare un effetto arcobaleno
void arcobaleno(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cicli di tutti i colori a ruota
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Ruota(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Simile alla funzione "corsa", ma con applicatovi l'effetto "arcobaleno"
void corsa_arcobaleno(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // ciclo di 256 colori a ruota
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Ruota( (i+j) % 255));    // Accende ogni terzo pixel
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        // Spegne ogni terzo pixel
      }
    }
  }
}

// Manda un valore da 0 a 255 in modo da assegnare un colore.
// I colori sono una transizione R - G - B, per ricominciare con R.
uint32_t Ruota(byte RuotaPos) {
  RuotaPos = 255 - RuotaPos;
  if(RuotaPos < 85) {
    return strip.Color(255 - RuotaPos * 3, 0, RuotaPos * 3);
  }
  if(RuotaPos < 170) {
    RuotaPos -= 85;
    return strip.Color(0, RuotaPos * 3, 255 - RuotaPos * 3);
  }
  RuotaPos -= 170;
  return strip.Color(RuotaPos * 3, 255 - RuotaPos * 3, 0);
}
