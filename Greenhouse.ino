#include <AmperkaKB.h>
#include <U8glib.h>
#include <Menu.h>

U8GLIB_ST7920_128X64_4X u8g(28, 30, 32, 34, 36, 38, 40, 42, 26, 22, 24);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
AmperkaKB KB(13, 12, 11, 10, 7, 6, 5, 4);// создаём объект для работы с матричной клавиатурой
Menu *current_menu;
int current_menu_item = 1;

void setup()
{
	// открываем монитор Serial порта
 	Serial.begin(9600);


	char *menu_strings[] = { "actions", "data", "settings" };
	current_menu = new Menu("main menu", menu_strings);
	// current_menu = new Menu();
	// current_menu->set_name_menu("main menu");

	// Serial.println(current_menu->get_name_menu());
	Serial.println( sizeof(current_menu->get_name_items() ) );
	// menu_strings = current_menu->get_name_items();

	delete [] menu_strings;
}

void loop()
{
 	u8g.firstPage();  
  	do {
    	drawMenu();
  	} while( u8g.nextPage() );
}





void drawMenu()
{
	uint8_t i, h;
  	u8g_uint_t w, d;

  	u8g.setFont(u8g_font_6x13);
  	u8g.setFontRefHeightText();
  	u8g.setFontPosTop();
  
  	h = u8g.getFontAscent()-u8g.getFontDescent();
  	w = u8g.getWidth();

	//print name menu on the top LCD
	//печать вверху дисплея названия меню
	d = (w-u8g.getStrWidth(current_menu->get_name_menu()))/2;
	u8g.setDefaultForegroundColor();
	u8g.drawStr(d, 0, current_menu->get_name_menu());

	//print menu items on LCD
	//печать на дисплей пунктов меню
	char **menu_strings = new char *[sizeof(current_menu->get_name_items())/2];
	menu_strings = current_menu->get_name_items();
	// char *menu_strings[] = { "actions", "data", "settings" };
  	for( i = 0; i < sizeof( menu_strings ) /2; i++ ) 
  	{
    	u8g.setDefaultForegroundColor();
    	if ( i+1 == current_menu_item ) {
      	u8g.drawBox(0, (i+1)*h+1, w, h);
      	u8g.setDefaultBackgroundColor();
    	}
    	u8g.drawStr(5, (i+1)*h, menu_strings[i]);
  	}
}