void setup() {
  Serial.begin(9600); // use the same baud-rate as the python side
}
void loop() {
  Serial.println("Hello world from Ardunio!"); // write a string
  delay(1000);
}
