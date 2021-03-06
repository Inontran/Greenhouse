#include <AmperkaKB.h>
#include <U8glib.h>
#include <Menu.h>

U8GLIB_ST7920_128X64_4X u8g(28, 30, 32, 34, 36, 38, 40, 42, 26, 22, 24);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
AmperkaKB KB(13, 12, 11, 10, 7, 6, 5, 4);// создаём объект для работы с матричной клавиатурой
Menu *current_menu;

void setup()
{
	char *menu_strings[] = { "actions", "data", "settings" };
	char *menu_name = "main menu";
	current_menu = new Menu(menu_name, menu_strings);


	delete [] menu_strings;
 	delete menu_name;



	// открываем монитор Serial порта
 	Serial.begin(9600);
 	// указываем тип клавиатуры
 	KB.begin(KB4x4);

 	
}

void loop()
{
	// определяем отпускание кнопки
 	// KB.onRelease()
 	// определяем зажатие кнопки
 	// KB.isPressed()
 	// определяем нажатие кнопки
 	if (KB.onPress()) {
   		// печатаем номер кнопки и её символ в последовательный порт
   		Serial.print("Key is press ");
   		Serial.print(KB.getNum);
   		Serial.print(" = \"");
   		Serial.print(KB.getChar);
   		Serial.println("\"");
 	}

 	u8g.firstPage();  
  	do {
    	drawMenu();
  	} while( u8g.nextPage() );
}





void drawMenu()
{
	uint8_t i, h;
  	u8g_uint_t w, d;

  	Item *items = *current_menu.get_items();

  	u8g.setFont(u8g_font_6x13);
  	u8g.setFontRefHeightText();
  	u8g.setFontPosTop();
  
  	h = u8g.getFontAscent()-u8g.getFontDescent();
  	w = u8g.getWidth();
  	// for( i = 0; i < 3; i++ ) {
   //  	d = (w-u8g.getStrWidth(menu_strings[i]))/2;
   //  	u8g.setDefaultForegroundColor();
   //  	if ( i == menu_current ) {
   //    	u8g.drawBox(0, i*h+1, w, h);
   //    	u8g.setDefaultBackgroundColor();
   //  	}
   //  	u8g.drawStr(d, i*h, menu_strings[i]);
  	// }
}