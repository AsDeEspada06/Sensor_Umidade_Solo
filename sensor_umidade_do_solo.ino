//Código Criado por: Adson Selton
//Sistema de Irrigação automática com Arduino 
//Simulado utilizando Tinkercad
//Robótica Educacional 

//Definir pinos 
#define sensor 2 //sensor digital
#define rele 5 //Relé

void setup()
{
  pinMode (5, rele);
  pinMode(3, OUTPUT); //LED VERMELHO
  pinMode(4, OUTPUT); //LED VERDE
  Serial.begin(9600); // INICIAR A COMUNICAÇÃO SERIAL
  
}

void loop()
{
  Serial.print("Sistema: "); //MOSTRAR NO MONITOR SERIAL
  if (digitalRead(sensor) == 1){ //LEITURA DO SENSOR DIGITAL
    Serial.print("Terra Umida, ");
    digitalWrite(3, LOW);// DESLIGA LED
    digitalWrite(4, HIGH);// LIGA LED
  }
  else if (digitalRead(sensor) == 0){ //LEITURA DO SENSOR DIGITAL
    Serial.print("Terra Seca, ");
  digitalWrite(3, HIGH);// LIGA LED
    digitalWrite(4, LOW);// DESLIGA LED
  }
    // PODE SER QUE AO MONTAR O CIRCUITO SEJA NECESSÁRIO INVERTER A LEITURA DO SENSOR DIGITAL DE 1 PARA 0 E VICE-VERSA
  
  if (analogRead(A0) < 600){ //LEITURA SENSOR ANALÓGICO
    Serial.println("Bomba ligada");
    digitalWrite(rele, LOW); //ACIONA O RELÉ E LIGA A BOMBA
  }
  else if(analogRead(A0) > 600){//LEITURA SENSOR ANALÓGICO
    Serial.println("Bomba desligada");
    digitalWrite(rele, HIGH); // DESLIGA O RELÉ E A BOMBA
  }
}
