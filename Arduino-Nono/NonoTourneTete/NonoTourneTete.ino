
volatile boolean troploin = false;

boolean inactif = true;
long last_actif;

void setup()
{
  Serial.begin(115200);
  Serial.println("Robot Nono pret !");
  
  // led 13 à 9, la bouche
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  // les contacts 
  pinMode(2,INPUT);
  pinMode(3,INPUT);

  attachInterrupt(1,contactGauche,CHANGE);
  attachInterrupt(0,contactDroite,CHANGE);

  // le moteur du cou

  pinMode(7,OUTPUT); // la direction
  pinMode(6,OUTPUT); // la vitesse

  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH); // on débute dans le sens horaire

  // les capteurs des oreilles
  pinMode(14,INPUT);
  pinMode(15,INPUT);



  // le moteur du bas

  pinMode(4,OUTPUT); // la direction
  pinMode(5,OUTPUT); // la vitesse


}

void contactDroite()
{
  if (digitalRead(2) == HIGH) {
    digitalWrite(13,LOW);
  } 
  else {
    digitalWrite(13,HIGH);
    troploin = true;
  }  
}

void contactGauche()
{
  if (digitalRead(3) == HIGH) {
    digitalWrite(13,LOW);
  } 
  else {
    digitalWrite(13,HIGH);
    troploin = true;
  } 
}

void loop()
{
  // si on vient d'etre en blocage
  if (troploin) {
    if (digitalRead(3) == HIGH) {
        Serial.println("Tourner à gauche");
      // change la direction --> antihoraire
      digitalWrite(7,LOW);
    } 
    if (digitalRead(2) == HIGH) {
        Serial.println("Tourner à droite");
      // change la direction --> horaire
      digitalWrite(7,HIGH);
    }
    digitalWrite(6,HIGH);
    delay(6000);
    digitalWrite(6,LOW);
    troploin = false;
  } 


  // si les deux capteurs captent : on s'arrete
  if (digitalRead(14) == digitalRead(15))
  {
    digitalWrite(6,LOW); 
    digitalWrite(9,LOW);
    digitalWrite(17,LOW);
    digitalWrite(16,LOW);
  } 
  else {
    inactif = false;
    // il faut tourner
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    // on détermine le sens 
    if (digitalRead(15) == HIGH) {
      digitalWrite(16,HIGH);
      digitalWrite(7,HIGH);
    } 
    else {
      digitalWrite(17,HIGH);
      digitalWrite(7,LOW);
    }

  }

  // détecte une inactivité
  if (! inactif) {
    last_actif = millis(); 
  } 
  else {

    // que fait-on quand on est inactif ? on allume les leds

    if (millis()%2000<1000) 
    {
      lumiere_off();
      bouche_on();
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH); // on tourne dans le sens horaire
    } 
    else {
      bouche_off(); 
      lumiere_on();
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW); // on tourne dans le sens antihoraire
    }

  }

  if (millis()-last_actif > 5000) {
    inactif = true;    
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

void bouche_on()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);  
}









