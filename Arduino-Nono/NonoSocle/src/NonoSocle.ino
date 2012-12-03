// Test du socle bougeant de Nono

void setup()
{
  
}

void loop()
{

	// changer le sens
	digitalWrite(4,LOW);

	// mettre en marche
	digitalWrite(5,HIGH);
  	delay(1000);

  	// arrêter 
	digitalWrite(5,LOW);
  	delay(1000);


  	// changer le sens
	digitalWrite(4,HIGH);

	// mettre en marche
	digitalWrite(5,HIGH);
  	delay(1000);

  	// arrêter 
	digitalWrite(5,LOW);
  	delay(1000);
}
