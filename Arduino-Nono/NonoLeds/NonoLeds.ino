void setup()
{
  Serial.begin(9600);
  Serial.println("Nono test leds");

  // la bouche
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(20,OUTPUT);
  pinMode(21,OUTPUT);


  lumiere_on(0);
  bouche_on(0);
  delay(500);  
  lumiere_off(0);
  bouche_off(0);
  delay(2000);  


  Serial.println("Pret...");
}

void loop()
{

  lumiere_on();
  delay(1000);
  bouche_on();
  delay(1000);
  lumiere_off();
  delay(1000);
  bouche_off();
  delay(1000);

}

void lumiere_on()
{
 lumiere_on(200); 
}
void bouche_on()
{
 bouche_on(200); 
}
void lumiere_off()
{
 lumiere_off(200); 
}
void bouche_off()
{
 bouche_off(200); 
}

void lumiere_on(int tempo)
{
 
 digitalWrite(16,HIGH);
  delay(tempo);
 digitalWrite(17,HIGH);
  delay(tempo);
 digitalWrite(18,HIGH);
  delay(tempo);
 digitalWrite(19,HIGH); 
  delay(tempo);
}


void lumiere_off(int tempo)
{
 digitalWrite(16,LOW);
  delay(tempo);
 digitalWrite(17,LOW);
  delay(tempo);
 digitalWrite(18,LOW);
  delay(tempo);
 digitalWrite(19,LOW); 
  delay(tempo);
  
}

void bouche_off(int tempo)
{
  digitalWrite(10,LOW);
  delay(tempo);
  digitalWrite(9,LOW);
  delay(tempo);
  digitalWrite(11,LOW);
  delay(tempo);
  digitalWrite(12,LOW);
  delay(tempo);
  digitalWrite(13,LOW); 
  delay(tempo);
}

void bouche_on(int tempo)
{
  digitalWrite(10,HIGH);
  delay(tempo);
  digitalWrite(9,HIGH);
  delay(tempo);
  digitalWrite(11,HIGH);
  delay(tempo);
  digitalWrite(12,HIGH);
  delay(tempo);
  digitalWrite(13,HIGH);  
  delay(tempo);
}


