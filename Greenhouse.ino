#include <AmperkaKB.h>
#include <U8glib.h>

U8GLIB_ST7920_128X64_4X u8g(28, 30, 32, 34, 36, 38, 40, 42, 26, 22, 24);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16


void setup()
{
	u8g.drawLine(0, 0, 100, 100);
}

void loop()
{
	
}