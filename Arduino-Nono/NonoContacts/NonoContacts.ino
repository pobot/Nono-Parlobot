

void setup()
{
  Serial.begin(9600);
  Serial.println("Nono test contacts");

  // led 13
  pinMode(13,OUTPUT);

  // les contacts 
  pinMode(2,INPUT);

  pinMode(3,INPUT);

  attachInterrupt(1,contactGauche,CHANGE);
  attachInterrupt(0,contactDroite,CHANGE);

  // le moteur du cou

  pinMode(7,OUTPUT); // la direction
  pinMode(6,OUTPUT); // la vitesse

  digitalWrite(6,HIGH);
  digitalWrite(7,LOW); // on débute dans le sens horaire

  Serial.println("Pret...");
}

void contactDroite()
{
  Serial.println("Droite");
  if (digitalRead(2) == HIGH) {
    digitalWrite(13,LOW);
    lumiere_off();
  } 
  else {
    digitalWrite(13,HIGH);
    lumiere_on();
    // change la direction --> horaire
    digitalWrite(7,HIGH);
  }  
  delay(200);
}

void contactGauche()
{
  Serial.println("Gauche");
  if (digitalRead(3) == HIGH) {
    digitalWrite(13,LOW);
    lumiere_off();
  } 
  else {
    digitalWrite(13,HIGH);
    lumiere_on();
    // change la direction --> antihoraire
    digitalWrite(7,LOW);
  }  
  delay(200);
}

void loop()
{

  if (Serial.available())
  {
    bouche_off();
    delay(100); 
    bouche_on(Serial.read());
    delay(100);
    bouche_off();
    delay(100); 
  }

}


void lumiere_on()
{

  digitalWrite(16,HIGH);
  digitalWrite(17,HIGH);
  digitalWrite(18,HIGH);
  digitalWrite(19,HIGH); 
}


void lumiere_off()
{
  digitalWrite(16,LOW);
  digitalWrite(17,LOW);
  digitalWrite(18,LOW);
  digitalWrite(19,LOW); 

}

void bouche_off()
{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW); 
}

void bouche_on(int num)
{  
  digitalWrite(9,HIGH);
  if (num == 1) return;
  digitalWrite(10,HIGH);
  if (num == 2) return;
  digitalWrite(11,HIGH);
  if (num == 3) return;
  digitalWrite(12,HIGH);
  if (num == 4) return;
  digitalWrite(13,HIGH);  
}






