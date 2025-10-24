#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Coefficients for temperature formula: T = n1 + n2*V + n3*V^2 + n4*V^3
const float n1 = 475.07068903;
const float n2 = -1692.8886208;
const float n3 = 1695.70287764;
const float n4 = -436.62989088;

const float input_voltage = 1.10; // the voltage to test

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  float v = input_voltage;
  float temperature = n1 + n2 * v + n3 * v * v + n4 * v * v * v;

  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(input_voltage, 3);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature, 2);
  lcd.write(223);
  lcd.print("C");
}
