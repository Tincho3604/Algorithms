# EJERCICIOS PHP (LABORATORIO 3)

## Ejercicio paddle

Una empresa se dedica al alquiler de canchas de paddle por horas.
Dados los siguientes arrays:

$canchas = array(4=>"Cancha grande", 3=>"Cancha de atrás", 2=>"Cancha nueva");

$reservas = array(
	array("cancha"=>4, "dia"=>"27", "desde"=>9, "hasta"=>10),
	array("cancha"=>4, "dia"=>"27", "desde"=>10, "hasta"=>11),
	array("cancha"=>2, "dia"=>"27", "desde"=>15, "hasta"=>17),
	array("cancha"=>3, "dia"=>"27", "desde"=>18, "hasta"=>22)
);

Realice un formulario que permita seleccionar un día (select), 
elegir una cancha (select), la hora de inicio de la reserva
y la cantidad de horas (select con números del 1 al 12).
 
El select de canchas debe armarse a partir del array de datos, de 
manera que si cambiaran los datos, el select se modifica 
automáticamente al ejecutar el programa.

Al hacer submit se debe mostrar si la cancha está disponible
ese día en esa cantidad de horas. El array reservas contiene las reservas
confirmadas, es decir, cuándo la cancha NO está disponible.

Si NO estuviera disponible pero SI hubiera OTRA/s cancha/s disponible/s 
debe indicarse al usuario (el nombre de la otra/s cancha).

El programa solamente debe indicar la disponibilidad, allí termina el proceso.


## Ejercicios libro "Programacion WEB para programadores"
![image](https://user-images.githubusercontent.com/62455807/144778680-5f7f246a-f6e3-4bfe-af14-6d84087cc1dc.png)
