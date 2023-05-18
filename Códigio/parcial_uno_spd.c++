#define boton_subir 3
#define boton_bajar A3
#define boton_parar A4
#define led_verde 4
#define led_rojo 5
#define a 7
#define b 6
#define c A2
#define d A1
#define e A0
#define f 8
#define g 9
int piso_actual = 0;
int piso_anterior = -1;
bool detenerse = false;

void setup() {
  pinMode(boton_subir, INPUT_PULLUP);
  pinMode(boton_bajar, INPUT_PULLUP);
  pinMode(boton_parar, INPUT_PULLUP);
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  saber_si_detenerse();
  if (!detenerse) {
    saber_si_subir_o_bajar();
  }
}

void saber_si_detenerse()
{
  if (digitalRead(boton_parar) == 0)
  {
    detenerse = !detenerse;
    Serial.println("Se ha presionado el pulsador de frenado.");
    digitalWrite(led_verde, 0);
    digitalWrite(led_rojo, 1);
    delay(100);
  }
}

void saber_si_subir_o_bajar()
{
  if (digitalRead(boton_subir)== 0 && piso_actual < 9){
    subir();
  }
  else if (digitalRead(boton_bajar)== 0 && piso_actual > 0){
    bajar();
  }
  mostrar_piso();
}

void subir()
{
  piso_actual++;
  digitalWrite(led_verde, 1);
  digitalWrite(led_rojo, 0);
  Serial.println("En movimiento.");
  delay(3000);
  digitalWrite(led_verde, 0);
  digitalWrite(led_rojo, 0);
}
  
void bajar()
{
  piso_actual--;
  digitalWrite(led_verde, 1);
  digitalWrite(led_rojo, 0);
  Serial.println("En movimiento.");
  delay(3000);
  digitalWrite(led_verde, 0);
  digitalWrite(led_rojo, 0);
}

void mostrar_piso()
{
  if (piso_actual != piso_anterior){
    switch (piso_actual){
     case 0:
      digitalWrite(a, 1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,0);
      Serial.println("El montacargas se encuentra en planta baja");
      break;
     case 1:
      digitalWrite(a, 0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,0);
      Serial.println("El montacargas se encuentra en el piso 1");
      break;
     case 2:
      digitalWrite(a, 1);
      digitalWrite(b,1);
      digitalWrite(c,0);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,0);
      digitalWrite(g,1);
      Serial.println("El montacargas se encuentra en el piso 2");
      break;
     case 3:
      digitalWrite(a, 1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,1);
      Serial.println("El montacargas se encuentra en el piso 3");
      break;
     case 4:
      digitalWrite(a, 0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
      Serial.println("El montacargas se encuentra en el piso 4");
      break;
     case 5:
      digitalWrite(a, 1);
      digitalWrite(b,0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e,0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      Serial.println("El montacargas se encuentra en el piso 5");
      break;
     case 6:
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      Serial.println("El montacargas se encuentra en el piso 6");
      break;
     case 7:
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 0);
      Serial.println("El montacargas se encuentra en el piso 7");
      break;
     case 8:
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      Serial.println("El montacargas se encuentra en el piso 8");
      break;
     case 9:
      digitalWrite(a, 1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
      Serial.println("El montacargas se encuentra en el piso 9");
      break;
      default:
      break;
    }
    piso_anterior = piso_actual;
  }
}
