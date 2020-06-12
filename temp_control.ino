#include 
int reading = 0;
int sensorPin = A0;
int relay =7;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
	// set up the LCD's number of columns and rows: 
	lcd.begin(16, 2);
	pinMode(relay,OUTPUT);
}

void loop() {
	reading = analogRead(sensorPin);
	int celsius = reading/2;
	lcd.setCursor(0, 0);
	lcd.print("Temperature: ");	
	lcd.setCursor(0,1);
	lcd.print(celsius, DEC);
	lcd.print((char)223);
	lcd.print("C");
	if (celsius >35) {
		digitalWrite(7,HIGH);
	} else {
		digitalWrite(7,LOW);
	}
	delay(500);
	lcd.clear();
}