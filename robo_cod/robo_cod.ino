
//Carrega a biblioteca do sensor ultrassonico
 #include <Ultrasonic.h> 
  #define motor1  9 // motor da direita / define a velocidade porta IN2  
  #define dire1 8 //Pino_Direção do motor 1 porta IN1 

  #define motor2  11 // motor da esquerda / define a velocidade porta IN4 
  #define dire2 10 //Pino_Direção do motor 2 porta IN3 

  //Define os pinos para o trigger e echo
  #define pino_trigger 4
  #define pino_echo 5

  #define S1 3 // sensor da roda direita 
  #define S2 2 // sensor da roda esquerda 

  int velocidade = 100; // velocidade dos motores
  float distancia;

// essas variaveis guarda o valor dos sensores de linha 
  bool Sensor1 = 0;
  bool Sensor2 = 0;

  //Inicializa o sensor nos pinos definidos acima
  Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(dire1, OUTPUT);
  pinMode(dire2, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);

  digitalWrite(dire1, LOW); // low pra frente high pra tras
  digitalWrite(dire2, LOW);// low pra tras high pra frente 

  Serial.begin(9600);
  


}

void loop() {
  Sensor1 = digitalRead(S1);
  Sensor2 = digitalRead(S2);
  long microsec = ultrasonic.timing();
  distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(distancia);


  //Le as informacoes do sensor, em cm e pol
if(distancia <= 10){

    analogWrite(motor1, 0);
    analogWrite(motor2, 0);
    Serial.println("funciona");

    }
  if((Sensor1 == 0) && (Sensor2 == 0)){ // Se detectar na extremidade das faixas duas cores brancas
    
    analogWrite(motor1, velocidade); 
    analogWrite(motor2, velocidade);
        Serial.println("anda");

  }
  else if ((Sensor1 == 1) && (Sensor2 == 0)){ // Se detectar um lado preto e o outro branco

    analogWrite(motor1, 0); // O motor 1 desliga
    analogWrite(motor2, velocidade); // O motor 2 fica ligado, fazendo assim o carrinho virar
            Serial.println("anda");

  }

  else if((Sensor1 == 0) && (Sensor2 == 1)){ // Se detectar um lado branco e o outro preto
    analogWrite(motor1, velocidade); //O motor 1 fica ligado
    analogWrite(motor2, 0); // O motor 2 desliga, fazendo assim o carrinho virar no outro sentido
            Serial.println("anda");

  }

  
}
 
