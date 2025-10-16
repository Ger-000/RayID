int UVPin = 2;
int LEDPin =3;

void setup() {
pinMode(UVPin, OUTPUT);
pinMode(LEDPin, OUTPUT);
analogWrite(UVPin, 165); //Maximum is always 165!!!
delay(10000); //Adjust this to whatever the sensor takes
analogWrite(UVPin, 0); 
analogWrite(LEDPin, 120);
delay(10000); //Adjust this to whatever the sensor takes
analogWrite(LEDPin, 0);
}

void loop() {


}
