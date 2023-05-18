# Parcial 1 SPD: Parte Domiciliaria 
![](https://hackmd.io/_uploads/Hyw-EgQr2.png)

## :space_invader: Alumno:
### Famozo, Luca

## :blue_book: Descripción
El proyecto consiste en una simulación de un montacargas en Arduino para Tinkercad. El mismo presenta *tres botones*, el *superior* se encarga de elevar un piso cada vez que es presionado; el botón *inferior* se encarga de descender un piso cuando cada vez que se es presionado; y el *central* cuando se es presionado anula la funcionalidad de los otros dos botones hasta que se vuelva a presionar. Además, dos *LEDs* se encargan de indicar el estado del montacargas. Si el encendido es el *verde*, significa que se está en movimiento. En cambio si el encendido es el *rojo*, el montacargas se encuentra detenido. Por último, un *display de siete segmentos* indica el piso en el que se encuentra el montacargas.

## :memo: Inicialización de datos y variables
```c
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
```

## :file_folder: Funciones
La función *'loop()'* utiliza dos funciones: *'saber_si_detenerse()'* determina si el usuario presionó el botón que impide el movimiento del montacargas, y si se encuentra con que no fue así, la función *'saber_si_subir_o_bajar()'* determina si el montacargas descenderá o ascenderá.
```c
void loop() {
  saber_si_detenerse();
  if (!detenerse) {
    saber_si_subir_o_bajar();
  }
}

```
*'saber_si_detenerse()'*, en el caso de que el estado del botón de detener el montacargas sea *true*, indicará esto mismo por consola y encenderá el led rojo, a la vez que asignará a la variable *'detenerse'* como una negación de sí misma con el fin de que si el botón vuelve a ser presionado, se desactive.
```c
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
```
*'saber_si_detenerse()'* utiliza un *if* y un *else if* para evaluar si debe utilizarse la función *'subir()'* o la función *'bajar()'*. Además, llama a la función *'mostrar_piso()'*, la cual se encarga de indicar tanto por el display como por consola el piso en el que se encuentra el montacargas actualmente. 
```c
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
```
Se utilizará la función *'subir()'* para explicar el funcionamiento de las funciones de movimiento (la función de descenso es similar, solo que se cambiaría la línea *'piso_actual++'* por un *'piso_actual- -'*). Aquí lo que se hace es sumar un uno al piso en el que se encuentre actualmente el montacargas, a la vez que se indicará por consola que se encuentra en movimiento y se enciende el led verde.
```c
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
```

La función *'mostrar_piso()'* evalúa si el piso actual es disntinto al piso anterior con el fin de que solo se ejecute si esta condición es verdadera. con un *switch* analiza los distintos casos que pueden darse (del 0 al 9) para mostrar ese número por el display e indicarlo por consola. Además, fuera del *if* asigna el valor del piso actual a la variable *piso_anterior*.
```c
void mostrar_piso()
{
  if (piso_actual != piso_anterior){
    switch (piso_actual){
     case 1: //encendido del display
      Serial.println("El montacargas se encuentra en el piso 1");
     //resto de casos (pisos)
      break;
    }
    piso_anterior = piso_actual;
  }
}
```
# :link: Link al proyecto
[Proyecto](https://www.tinkercad.com/things/8s21LzDo4V2)
