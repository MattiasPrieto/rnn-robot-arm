//Tercera prueba de mover los motores a la vez, a traves de angulos
///////////////ARRAY de angulos///////////////////
String cadena = "";
uint8_t Ary[4];
uint8_t i=0, j=0;
////////////////Cosas necesarias para mover los motores///////////////////////////////
int vel = 5;                    //Tiempo de retardo (milisegundos) = Velocidad del motor
int angulo;     
int angulo1; 
int angulo2; //Valor recibido en grados (-90° a 90°, -90° a 90°, 0 a 90°)
int numero_pasos = 0;
int numero_pasos1 = 0;
int numero_pasos2 = 0;          //Valor en grados donde se encuentra el motor
////////////////////Trucazo////////////////////////////////////////////////////////
int F = 0;
void setup() {
  Serial.begin(9600);
//////Motor 1//////////////  
  pinMode(2,OUTPUT);  //IN1
  pinMode(3,OUTPUT);  //IN2
  pinMode(4,OUTPUT);  //IN3
  pinMode(5,OUTPUT);  //IN4
//////Motor 2//////////////    
  pinMode(6,OUTPUT);  //IN1
  pinMode(7,OUTPUT);  //IN2
  pinMode(8,OUTPUT);  //IN3
  pinMode(9,OUTPUT);  //IN4
//////Motor 3//////////////  
  pinMode(10,OUTPUT);  //IN1
  pinMode(11,OUTPUT);  //IN2
  pinMode(12,OUTPUT);  //IN3
  pinMode(13,OUTPUT);  //IN4
  
}

void loop() {
while (Serial.available()>0){    //Lee el valor enviado por el Puerto serial
    delay(vel);
    char c =Serial.read();      //Lee los caracteres
    cadena +=c; 
  }

Serial.print(cadena);
while (j < cadena.length()){
    if (cadena.charAt(j) == ',')
    {
      i++;
    }
    else
    {
      Ary[i] = Ary[i] * 10;
      }
      if ((cadena.charAt(j) < '0') || (cadena.charAt(j) > '9'))
      {
        Ary[i] = 0;
      }
      else
      {
        Ary[i] = Ary[i] + (cadena.charAt(j) - '0');
      }
    
    j++;
  }
if (cadena.length()>0){
  cadena = "";
}
if (Ary[4]!= 000){
  Serial.print(Ary[0]);
  delay(1000);
  Serial.print(Ary[1]);
  delay(1000);
  Serial.println(Ary[2]);
  delay(1000);
}

  if (Ary[4]!=0){
    angulo = Ary[0]; //Convierte cadena de caracteres a Enteros
      Serial.print(angulo);       //Envia valor en Grados
      Serial.println(" Grados");
    delay(vel);
    angulo = (angulo * 21)/40;     //Ajuste de relación
    angulo = (angulo * 5.661111111); // Ajuste de 2038 pasos por revolucion a 360 
    F=F+1; 
  }
  while(angulo>numero_pasos){     //Giro hacia la izquierda en grados
    paso_izq(); 
    numero_pasos = numero_pasos +1;
  }  
  while(angulo<numero_pasos){     //Giro hacia la derecha en grados
    paso_der(); 
    numero_pasos = numero_pasos -1;
  }
  
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);                     //Se apaga el motor 1

  if (Ary[4]!= 0){
    angulo1 = Ary[1]; //Convierte cadena de caracteres a Enteros
      Serial.print(angulo1);       //Envia valor en Grados
      Serial.println(" Grados");
    delay(vel);
    angulo1 = (angulo1 * 5)/12;     //Ajuste de relación
    angulo1 = (angulo1 * 5.661111111); // Ajuste de 2038 pasos por revolucion a 360  
    F=F+1;
  }
  while(angulo1>numero_pasos1){     //Giro hacia la izquierda en grados
    paso_izq1(); 
    numero_pasos1 = numero_pasos1 +1;
    
  }  
  while(angulo1<numero_pasos1){     //Giro hacia la derecha en grados
    paso_der1(); 
    numero_pasos1 = numero_pasos1 -1;
   
  }
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);                     //Se apaga el motor 2
  
  if (Ary[4]!=0){
    angulo2= Ary[2]; //Convierte cadena de caracteres a Enteros
      Serial.print(angulo2);       //Envia valor en Grados
      Serial.println(" Grados");
    delay(vel);
    angulo2 = (angulo2 * 5)/12;     //Ajuste de relación
    angulo2 = (angulo2 * 5.661111111); // Ajuste de 2038 pasos por revolucion a 360  
    F=F+1;
  }
  while(angulo2>numero_pasos2){     //Giro hacia la izquierda en grados
    paso_izq2(); 
    numero_pasos2 = numero_pasos2 +1;
    
  }  
  while(angulo2<numero_pasos2){     //Giro hacia la derecha en grados
    paso_der2(); 
    numero_pasos2 = numero_pasos2 -1;
  }
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);                     //Se apaga el motor 3
  if (F==3){
  F=0;
  i=0;
  j=0;
  fin();
  Ary[0]=0;
  Ary[1]=0;
  Ary[2]=0;
  }
}
////////////////////Funcion Fin(volviendo a 0)//////////////////////////////////////////
void fin(){
  Serial.println("Esperando");
  delay(vel);
}
///////////////////Funciones Motor 1////////////////////////////////////////////////////////
void paso_der(){            //pasos a la derecha motor 1
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  delay(vel);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  delay(vel);
}
void paso_izq(){            //pasos a la izquierda motor 1
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  delay(vel);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  delay(vel);
}
///////////////////Funciones Motor 2////////////////////////////////////////////////////////
void paso_der1(){            //pasos a la derecha Motor 2
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(vel);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(vel);
}
void paso_izq1(){            //pasos a la izquierda Motor 2
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(vel);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(vel);
}
///////////////////Funciones Motor 3 ////////////////////////////////////////////////////////
void paso_der2(){            //pasos a la derecha Motor 3
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(vel);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(vel);
}
void paso_izq2(){            //pasos a la izquierda Motor 3
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(vel);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(vel);
}
