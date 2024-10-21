
const int pino = 7; 
void setup() {
  
  pinMode(pino, OUTPUT);
}


void loop() {
  digitalWrite(pino, HIGH);   
  delay(500);                
  digitalWrite(pino, LOW);    
  delay(500);                
}
