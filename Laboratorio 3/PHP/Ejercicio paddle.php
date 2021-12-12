
<?php
/*
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
*/


$canchas = array(4=>"Cancha grande", 3=>"Cancha de atrás", 2=>"Cancha nueva");

$reservas = array(
	array("cancha"=>4, "dia"=>"27", "desde"=>9, "hasta"=>10),
	array("cancha"=>4, "dia"=>"27", "desde"=>10, "hasta"=>11),
	array("cancha"=>2, "dia"=>"27", "desde"=>15, "hasta"=>17),
	array("cancha"=>3, "dia"=>"27", "desde"=>18, "hasta"=>22)
);
?>


<?php if(isset($_GET["canchas"]) && isset($_GET["dia"]) && isset($_GET["horas"]) && isset($_GET["inicio"])) { ?>


	<?php foreach($reservas as $CM => $M) {  ?>
		
		<?php if( ($M["cancha"] == $_GET["canchas"]) && ($M["dia"] == $_GET["dia"])) {  ?>
			<p>La cancha no esta disponible</p>
		
			<?php } else { ?>
		
			<p>La canchas disponibles son: <?= $canchas[$M["cancha"]] ?> </p>
				<?php } ?>
			<?php } ?>


	<?php } else { ?>
<form action="" method="get">
        
        <label for="canchas" name="canchas" >Canchas: </label>
        <select name="canchas">
            <?php foreach($canchas as $CM => $M) { ?>
                <option value="<?= $CM ?>"><?= $M ?></option>
            <?php } ?>
        </select>
        
		<br>
		<br>
		<br>
		
		<label for="dia" name="dia" >Dia: </label>
		<select name="dia">
		<?php for($i=1 ; $i <= 31; $i++) { ?>
                <option value="<?= $i ?>"><?= $i ?></option>
            <?php } ?>
        </select>
        
        <br>
		<br>
		<br>

		<label for="inicio" name="inicio" >Inicio: </label>
		<select name="inicio">
		    <?php foreach($reservas as $CM => $M) { ?>
                <option value="<?= $M["desde"]  ?>"><?= $M["desde"] ?></option>
            <?php } ?>
        </select>

		<br>
		<br>
		<br>

		<label for="horas" name="horas" >Horas: </label>
		<select name="horas">
            <?php for($i=1 ; $i <= 12; $i++) { ?>
                <option value="<?= $i ?>"><?= $i ?></option>
            <?php } ?>
        </select>

		<br>
		<br>
		<br>

		<input type="submit" value="Ver canchas disponibles"></input>
	</form>

	<?php } ?> 