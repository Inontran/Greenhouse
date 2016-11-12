#include <AmperkaKB.h>
#include <U8glib.h>
#include <Menu.h>

U8GLIB_ST7920_128X64_4X u8g(28, 30, 32, 34, 36, 38, 40, 42, 26, 22, 24);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
AmperkaKB KB(13, 12, 11, 10, 7, 6, 5, 4);// создаём объект для работы с матричной клавиатурой

Menu *current_menu;
int current_number_menu_item = 1;
int amount_items = 1;
char **menu_strings = new char *[amount_items];



void setup()
{
	// открываем монитор Serial порта
	Serial.begin(9600);

 	//блок инициализации меню
 	//block of initialization menu
 	{
 		//current menu
 		char *menu_name_items[] = { "actions", "data", "settings" };
 		current_menu = new Menu("main menu", 3, menu_name_items);
 		amount_items = current_menu->get_amount_items();
 		menu_strings = current_menu->get_name_items();

		//submenus

		delete [] menu_name_items;
	}

	// указываем тип клавиатуры
	KB.begin(KB4x4);
}

void loop()
{
	// определяем нажатие кнопки
	if (KB.onPress()) {
    	// печатаем номер кнопки и её символ в последовательный порт
    	Serial.print("Key is press ");
    	Serial.print(KB.getNum);
    	Serial.print(" = \"");
    	Serial.print(KB.getChar);
    	Serial.println("\"");
    	
    	switch (KB.getChar) {
    	    case 'A':
    	    	if(current_number_menu_item == 1) current_number_menu_item = amount_items;
    	    	else current_number_menu_item--;
    	    	break;
    	    case 'B':
    	    	if(current_number_menu_item == amount_items) current_number_menu_item = 1;
    	    	else current_number_menu_item++;
    	     	break;
    	}
	}

	//draw menu and other data
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
	// char **menu_strings = new char *[number_items];
	// menu_strings = current_menu->get_name_items();
	// char *menu_strings[] = { "actions", "data", "settings" };
	for( i = 0; i < amount_items; i++ ) 
	{
		u8g.setDefaultForegroundColor();
		if ( i+1 == current_number_menu_item ) {
			u8g.drawBox(0, (i+1)*h+1, w, h);
			u8g.setDefaultBackgroundColor();
		}
		u8g.drawStr(5, (i+1)*h, menu_strings[i]);
	}
}