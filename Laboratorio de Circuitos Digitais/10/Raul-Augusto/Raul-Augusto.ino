//Raul Alexandre Gonzalez Augusto RA: 211023698

//declaração dos pinos
#define tempPin A0
#define motorPin 3
#define a 2
#define b 4
#define c 5
#define d 6
#define e 7
#define f 8
#define g 9
#define centPin 10
#define dezPin 11
#define uniPin 12
#define deciPin 13

//tempo de espera do delay em milesegundos
#define esperar 25

//declaração das variaveis
int tempVolts, tempInt, cent, dez, uni, deci;
double temp, tempVar;



void setup() {
  //inicia os pins
  pinMode(motorPin, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(centPin, OUTPUT);
  pinMode(dezPin, OUTPUT);
  pinMode(uniPin, OUTPUT);
  pinMode(deciPin, OUTPUT);
  //inicia o serial
  Serial.begin(9600);
}

//conforme o numero manda sinais 0, 1 para os pins do display para escrever o numero
void numeros(int n) {
if (n == -1)
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
} else if (n == 0) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  } else if (n == 1) 
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  } else if (n == 2) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  } else if (n == 3) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  } else if (n == 4) 
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  } else if (n == 5) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  } else if (n == 6) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  } else if (n == 7) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  } else if (n == 8) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else if (n == 9) 
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
}

void loop() {  
  tempVolts = analogRead(tempPin); // recebe temp em volts
  temp = (tempVolts / 1024.0 * 5 - 0.5) * 100; // converte temp em celsius
  
  if (temp > 0)
  {
    analogWrite(motorPin, temp/(125.0/255.0)); //formula para converter de temp para um valor entre 0-255
  } else
  {
    analogWrite(motorPin, 0); // para zerar frequencia se temp <= 0 
  }
  
  //separa a temp em 1 digito por variavel
  tempInt = abs((int)(temp * 10));
  cent = tempInt / 1000;
  tempInt %= 1000;
  dez = tempInt / 100;
  tempInt %= 100;
  uni = tempInt / 10;
  tempInt %= 10;
  deci = tempInt;
  
  //liga display da centena e desliga os demais e envia os sinais do numero para o display
  if (temp < 0) cent = -1;    
  digitalWrite(centPin, LOW);
  digitalWrite(dezPin, HIGH);
  digitalWrite(uniPin, HIGH);
  digitalWrite(deciPin, HIGH);
  numeros(cent);
  delay(esperar);
  
  //liga display da dezena e desliga os demais e envia os sinais do numero para o display
  digitalWrite(centPin, HIGH);
  digitalWrite(dezPin, LOW);
  digitalWrite(uniPin, HIGH);
  digitalWrite(deciPin, HIGH);
  numeros(dez);  
  delay(esperar);
  
  //liga display da unidade e desliga os demais e envia os sinais do numero para o display
  digitalWrite(centPin, HIGH);
  digitalWrite(dezPin, HIGH);
  digitalWrite(uniPin, LOW);
  digitalWrite(deciPin, HIGH);
  numeros(uni);  
  delay(esperar);
  
  //liga display do decimal e desliga os demais e envia os sinais do numero para o display
  digitalWrite(centPin, HIGH);
  digitalWrite(dezPin, HIGH);
  digitalWrite(uniPin, HIGH);
  digitalWrite(deciPin, LOW);
  numeros(deci);
  delay(esperar);

  //Serial.println(tempVar); // mostra temp no console

}
