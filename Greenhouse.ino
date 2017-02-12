#include <AmperkaKB.h>
#include <U8glib.h>
#include <Menu.h>
#include <DS1302.h>
#include <Assistant.h>

#define NULL (void*)0


U8GLIB_ST7920_128X64_4X u8g(28, 30, 32, 34, 36, 38, 40, 42, 26, 22, 24);   // 8Bit Com: D0..D7, en, di, rw
// U8GLIB_ST7920_128X64_4X u8g(34, 36, 38);	// SPI Com: SCK = en = 6, MOSI = rw = 5, CS = di = 4

AmperkaKB KB(14, 15, 16, 17, 18, 19, 20, 21);// создаём объект для работы с матричной клавиатурой
// Init the DS1302
DS1302 rtc(27, 25, 23);

Menu *current_menu;
int current_number_menu_item = 1;
int amount_items;

/* 
luxmetr, termometr_water, termometr_air, sensor_mist, sensor_level_water;
mistmaker, phytolamp, ventilation, heating_air;
*/
// Assistant assistant();


void setup()
{
	// открываем монитор Serial порта
	Serial.begin(9600);

	//инициализация меню дисплея
	init_menu();

	// указываем тип клавиатуры
	KB.begin(KB4x4);

	// Set the clock to run-mode, and disable the write protection
    rtc.halt(false);
    rtc.writeProtect(false);

    // rtc.setDOW(WEDNESDAY);        // Set Day-of-Week to FRIDAY
    // rtc.setTime(23, 07, 00);     // Set the time to 12:00:00 (24hr format)
    // rtc.setDate(1, 02, 2017);   // Set the date to August 6th, 201
}

void loop()
{
	// определяем нажатие кнопки
	if (KB.onPress()) {
    	switch (KB.getChar) {
    	    //вверх
    	    case 'A':
    	    	if(current_number_menu_item == 1) current_number_menu_item = amount_items;
    	    	else current_number_menu_item--;
    	    	break;
    	    //вниз
    	    case 'B':
    	    	if(current_number_menu_item == amount_items) current_number_menu_item = 1;
    	    	else current_number_menu_item++;
    	     	break;
    	     //отмена или назад
    	    case 'C' :
    	    	if(current_menu->get_parent_menu() != NULL){
    	    		current_menu = current_menu->get_parent_menu();
    	    		amount_items = current_menu->get_amount_items();
    	    		current_number_menu_item = 1;
    	    	} else{} //отмена изменения значений
    	    	break;
    	    //ок
    	    case 'D' :
    	    	if(current_menu->get_submenu(current_number_menu_item) != NULL){
    	    		current_menu = current_menu->get_submenu(current_number_menu_item);
    	    		amount_items = current_menu->get_amount_items();
    	    		current_number_menu_item = 1;
    	    	} else{}//включение чего-либо или изменение настроек/значенией
    	    	break;
    	}
	}

	update_menu();

	//печать меню и данных на дисплее
	u8g.firstPage();  
	do {
		drawMenu();
	} while( u8g.nextPage() );
}

//инициализация меню
void init_menu()
{
	String **menu_name_items;
	String **menu_value_items;
	Menu *submenu;
 	//главное меню
 	amount_items = 3;
 	menu_name_items = new String *[amount_items];
 	menu_name_items[0] = new String("actions");
 	menu_name_items[1] = new String("data");
 	menu_name_items[2] = new String("settings");
 	current_menu = new Menu( new String("main menu"), amount_items, menu_name_items);


	//остальные подменю
	amount_items = 2;
	menu_name_items = new String *[amount_items];
	menu_name_items[0] = new String("mist maker");
	menu_name_items[1] = new String("lightning");
	//здесь будет инициализация значений
	menu_value_items = new String *[amount_items];
	menu_value_items[0] = new String("off");
	menu_value_items[1] = new String("off");
	submenu = new Menu( new String("actions"), amount_items, menu_name_items, menu_value_items);
	current_menu->add_submenu(submenu, 1);
	
	amount_items = 3;
	menu_name_items = new String *[amount_items];
	menu_name_items[0] = new String("time");
	menu_name_items[1] = new String("date");
	menu_name_items[2] = new String("DoW");
	// menu_value_items = new char *[amount_items];
	// menu_value_items[0] = rtc.getTimeStr();
	// menu_value_items[1] = rtc.getDateStr();
	// menu_value_items[0] = rtc.getTimeStr();
	// menu_value_items[2] = rtc.getDOWStr();
	submenu = new Menu( new String("data"), amount_items, menu_name_items);
	current_menu->add_submenu(submenu, 2);


	amount_items = current_menu->get_amount_items();
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

	//печать вверху дисплея названия меню
	String str = *current_menu->get_name_menu();
	char *array_char = new char;
	str.toCharArray(array_char, str.length()+1);
	d = ( w-u8g.getStrWidth( array_char )  )/2;
	u8g.setDefaultForegroundColor();
	u8g.drawStr(d, 0, array_char );
	delete array_char;

	//печать на дисплей пунктов меню
	for( i = 0; i < amount_items; i++ ) 
	{
		u8g.setDefaultForegroundColor();
		if ( i+1 == current_number_menu_item ) {
			u8g.drawBox(0, (i+1)*h+1, w, h);
			u8g.setDefaultBackgroundColor();
		}

		str = *current_menu->get_name_items()[i];
		array_char = new char;
		str.toCharArray( array_char, str.length()+1 );
		u8g.drawStr(5, (i+1)*h, array_char );
		delete array_char;

		str = *current_menu->get_value_items()[i];
		array_char = new char;
		str.toCharArray( array_char, str.length()+1 );
		u8g.drawStr(w - u8g.getStrWidth( array_char ), (i+1)*h, array_char );
		delete array_char;
	}
}

void update_menu()
{
	if(current_menu->get_name_menu()->equals("actions") ){
		// String *str = new String("ON");
		// current_menu->set_value_items( new String("on"), 1);
		// delete str;
	}
	if(current_menu->get_name_menu()->equals("data") ){
		String *str = new String(rtc.getTimeStr());
		current_menu->set_value_items( str, 1);
		delete str;
		str = new String(rtc.getDateStr());
		current_menu->set_value_items( str, 2);
		delete str;
		str = new String(rtc.getDOWStr());
		current_menu->set_value_items( str, 3);
		delete str;
	}
	
}