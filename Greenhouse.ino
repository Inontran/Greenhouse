#include <AmperkaKB.h>
#include <U8glib.h>
#include <Menu.h>

#define NULL (void*)0

U8GLIB_ST7920_128X64_4X u8g(28, 30, 32, 34, 36, 38, 40, 42, 26, 22, 24);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
AmperkaKB KB(13, 12, 11, 10, 7, 6, 5, 4);// создаём объект для работы с матричной клавиатурой

Menu *current_menu;
int current_number_menu_item = 1;
int amount_items;


void setup()
{
	// открываем монитор Serial порта
	Serial.begin(9600);
	init_menu();

	// указываем тип клавиатуры
	KB.begin(KB4x4);
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
    	    	if(current_menu->get_submenu()[current_number_menu_item] != NULL){
    	    		current_menu = current_menu->get_submenu()[current_number_menu_item-1];
    	    		amount_items = current_menu->get_amount_items();
    	    		current_number_menu_item = 1;
    	    	} else{}//включение чего-либо или изменение настроек/значенией
    	    	break;
    	}
	}

	//печать меню и данных на дисплее
	u8g.firstPage();  
	do {
		drawMenu();
	} while( u8g.nextPage() );
}

//инициализация меню
void init_menu()
{
	char **menu_name_items;
	char **menu_value_items;
	Menu *submenu;
 	//главное меню
 	amount_items = 3;
 	menu_name_items = new char *[amount_items];
 	menu_name_items[0] = "actions";
 	menu_name_items[1] = "data";
 	menu_name_items[2] = "settings";
 	current_menu = new Menu("main menu", amount_items, menu_name_items);
 	delete [] menu_name_items;


	//остальные подменю
	amount_items = 2;
	menu_name_items = new char *[amount_items];
	menu_name_items[0] = "mist maker";
	menu_name_items[1] = "lightning";
	menu_value_items = new char *[amount_items];
	//здесь будет инициализация значений
	menu_value_items[0] = "off";
	menu_value_items[1] = "off";
	submenu = new Menu("actions", amount_items, menu_name_items, menu_value_items);
	submenu->set_parent_menu(current_menu);
	current_menu->add_submenu(submenu, 1);
	delete [] menu_name_items;
	delete [] menu_value_items;
	delete submenu;

	amount_items = 2;
	menu_name_items = new char *[amount_items];
	menu_name_items[0] = "t1";
	menu_name_items[1] = "t2";
	menu_value_items = new char *[amount_items];
	menu_value_items[0] = "20";
	menu_value_items[1] = "22";
	submenu = new Menu("data", amount_items, menu_name_items, menu_value_items);
	submenu->set_parent_menu(current_menu);
	current_menu->add_submenu(submenu, 2);
	delete [] menu_name_items;
	delete [] menu_value_items;
	delete submenu;

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
	d = (w-u8g.getStrWidth(current_menu->get_name_menu()))/2;
	u8g.setDefaultForegroundColor();
	u8g.drawStr(d, 0, current_menu->get_name_menu());

	//печать на дисплей пунктов меню
	for( i = 0; i < amount_items; i++ ) 
	{
		u8g.setDefaultForegroundColor();
		if ( i+1 == current_number_menu_item ) {
			u8g.drawBox(0, (i+1)*h+1, w, h);
			u8g.setDefaultBackgroundColor();
		}
		u8g.drawStr(5, (i+1)*h, current_menu->get_name_items()[i]);
		u8g.drawStr(w - u8g.getStrWidth(current_menu->get_value_items()[i]), (i+1)*h, current_menu->get_value_items()[i]);
	}
}