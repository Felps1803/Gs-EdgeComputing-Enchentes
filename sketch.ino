#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9
#define ECHO_PIN 8

#define LED_VERDE 4
#define LED_AMARELO 3
#define LED_VERMELHO 2
#define BUZZER 5

#define PINO_CHUVA A0
#define PINO_VENTO A1

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();
}

float medirNivelAgua() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);
  float distancia_cm = duracao * 0.034 / 2.0;
  return distancia_cm;
}

void mostrarAlerta(float nivel) {
  if (nivel < 20.0) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, LOW);
    lcd.clear();
    lcd.print("Nivel OK");
    lcd.setCursor(0,1);
    lcd.print("Sem risco");
  } else if (nivel >= 20.0 && nivel <= 30.0) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, LOW);
    lcd.clear();
    lcd.print("Atencao!");
    lcd.setCursor(0,1);
    lcd.print("Monitorar!");
  } else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.clear();
    lcd.print("Risco de");
    lcd.setCursor(0,1);
    lcd.print("enchente!");
  }
}

void loop() {
  float nivel = medirNivelAgua();
  int chuva = analogRead(PINO_CHUVA);     // 0 a 1023
  int vento = analogRead(PINO_VENTO);     // 0 a 1023

  mostrarAlerta(nivel);

  String risco;
  if (nivel < 20.0) risco = "baixo";
  else if (nivel <= 30.0) risco = "moderado";
  else risco = "alto";

  Serial.print("{\"chuva\": ");
  Serial.print(chuva);
  Serial.print(", \"vento\": ");
  Serial.print(vento);
  Serial.print(", \"nivel_agua_cm\": ");
  Serial.print(nivel, 1);
  Serial.print(", \"risco\": \"");
  Serial.print(risco);
  Serial.println("\"}");

  delay(2000);
}