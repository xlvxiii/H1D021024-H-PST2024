#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int trigPin = D0;
int echoPin = D1;
int led_merah = D5;;
int led_ijo = D4;
int SDA_pin = D3;
int SCL_pin = D2;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(D6);
  pinMode(led_ijo, OUTPUT);
  pinMode(led_merah, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Wire.begin(SDA_pin, SCL_pin);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = 0.034*duration/2;
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.println(" cm");

  if (distance <= 10)
  {
    digitalWrite(led_ijo, HIGH);
    digitalWrite(led_merah, LOW);

    myservo.write(90);
    delay(5);
  
  } else {
    digitalWrite(led_merah, HIGH);
    digitalWrite(led_ijo, LOW);
    
    myservo.write(0);
    delay(5);
  }

  delay(1000);
  
 
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}