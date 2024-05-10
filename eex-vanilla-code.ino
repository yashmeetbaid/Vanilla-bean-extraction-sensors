#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
#define LED_PIN 13       // Define the pin for the LED
#define BUZZER_PIN 6     // Define the pin for the buzzer
#define RELAY_PIN 27     // Define the pin for the relay module
#define TEMPERATURE_THRESHOLD 65 // Define the temperature threshold
#define BLINK_INTERVAL 500       // Define the blink interval in milliseconds

bool ledState = LOW; // Initial state of the LED

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Temperature:");
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT); // Set relay pin as output
}

void loop()
{
  float temperatureC = 70; // Simulated temperature value (change as needed)

  lcd.setCursor(0, 1);
  lcd.print("     ");        // Clear previous temperature
  lcd.setCursor(0, 1);
  lcd.print(temperatureC); // Display temperature on LCD

  if (temperatureC > TEMPERATURE_THRESHOLD)
  {
    digitalWrite(LED_PIN, HIGH);    // Turn on LED if temperature is above threshold
    digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
    digitalWrite(RELAY_PIN, HIGH);  // Turn on relay
    // Blink the LED and synchronize with the buzzer
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    delay(BLINK_INTERVAL / 2); // Half of the blink interval
    digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
  }
  else
  {
    digitalWrite(LED_PIN, LOW);    // Turn off LED if temperature is below threshold
    digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
    digitalWrite(RELAY_PIN, LOW);  // Turn off relay
  }

  delay(BLINK_INTERVAL / 2); // Adjust delay time as needed for smoother blinking
}