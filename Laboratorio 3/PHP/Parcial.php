
<?php
$prestamos = array(8 => "Linea Joven 2021", 11 => "Linea Tradicional", 2 => "ANSES");

$detalle = array();
$detalle[8] = array('tasa' => 31.8, 'gracia' => 1, 'maximo' => 40000);
$detalle[11] = array('tasa' => 55.7, 'gracia' => 3, 'maximo' => 999000);
$detalle[2] = array('tasa' => 22, 'gracia' => 2, 'maximo' => 10000);

$meses = array(1 => "Enero", 2=>"Febrero", 3=>"Marzo", 4=>"Abril", 5=>"Mayo", 6=>"Junio", 7=>"Julio", 8=>"Agosto", 9=>"Septiembre", 10=>"Octubre", 11=>"Noviembre", 12=>"Diciembre");

/*
Yo, --MARTIN--, declaro que el código desarrollado aquí abajo es de mi autoría 
*/

?>

<?php if(isset($_GET["linea_value"])) { ?>
    
    <?php if( $_GET["monto"] > $detalle[$_GET["linea_value"]]['maximo']) { ?>

        <?php echo("La linea de credito no es apta") ?>
        
        <?php } else {  ?>    

            <?php  $tasa_a_cobrar = ($_GET["monto"] * $detalle[$_GET["linea_value"]]['tasa']) / 100 ?>
            <?php  $monto_total = $_GET["monto"] + $tasa_a_cobrar ?>
            <?php $mes_a_devolver = $_GET["meses"] + $detalle[$_GET["linea_value"]]['gracia'] + 1?>

            

            <?php if( $mes_a_devolver > 12) { ?>
                <?php  $mes_a_devolver =  ($detalle[$_GET["linea_value"]]['gracia'] - (12 - $_GET["meses"])) + 1 ?>
            <?php } ?>

            <?php if( $mes_a_devolver == 13) { ?>
                <?php  $mes_a_devolver =  1 ?>
            <?php } ?>

            <p>El monto a devolver es: <?= $monto_total ?></p>
            <p>Debera comenzar a pagar en el mes de:  <?= $meses[$mes_a_devolver] ?></p>

        <?php } ?>

        <br>
		<br>
		<br>
        
        <a href="Parcial.php">Volver a cargar el tramite</a>
<?php } ?>




<?php if(!isset($_GET["linea_value"])) { ?>

<form action="" method="get">
        
        <label for="linea" name="linea" >Linea de credito: </label>
        <select name="linea">
            <?php foreach($prestamos as $CM => $M) { ?>
                <option value="<?= $CM ?>"><?= $M ?></option>
            <?php } ?>
        </select>

        <br>
		<br>
		<br>

		<input type="submit" value="Elegir linea de credito"></input>
</form>

<?php } ?>

<?php if(isset($_GET["linea"])) { ?>
    <form action="" method="get">
        
        <label for="monto" name="monto" >Monto: </label>
        <input type="text" name="monto"></input>
        
		<br>
		<br>
		<br>
        <input type="hidden" name="linea_value" value="<?= $_GET["linea"] ?>"/>
        <label for="meses" name="meses" >Elija mes: </label>
        <select name="meses">
            <?php foreach($meses as $CM => $M) { ?>
                <option value="<?= $CM ?>"><?= $M ?></option>
            <?php } ?>
        </select>


        <br>
		<br>
		<br>

		<input type="submit" value="Confirmar"></input>
</form>
    
    <?php } ?>

