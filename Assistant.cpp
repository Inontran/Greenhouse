#define NULL (void*)0

Assistant::Assistant()
{

}


float Assistant::get_temperature_air()
{
	return get_temperature( Assistant::pin_termometr_water );
}

float Assistant::get_temperature_water()
{
	return get_temperature( Assistant::pin_termometr_water );
}

float Assistant::get_level_humidity()
{
	return 0;
}


float Assistant::get_temperature(int pin_number)
{ 
  unsigned int B = 3950; // Параметр бетта(B) термистора (из datasheet)
  float r_25 = 4700.0;//сопротивление термистора при 25 градусов Цельсия
  float r_d = 10000.0;//сопротивление резистора делителя напряжения
  float voltage = analogRead(pin_number) * VIN / 1023.0;//напряжение, получаемое с термистора
  float r_t = voltage * r_d / (VIN - voltage);//сопротивление при температуре t
  float temperature = 1. / ( 1. / (B) * log(r_t / r_25) + 1. / (25. + 273.15) ) - 273.15;
  return temperature;
}

int Assistant::get_level_light()
{
	int adc_value = analogRead( Assistant::pin_luxmetr );
    float volt = 5.0 * (adc_value / 1024.0);
    float resistor = (10.0 * 5.0) / volt - 10.0;
    int lx = 223.35 * pow(resistor, -10 / 8);
    return lx;
}