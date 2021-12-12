<?php
/*
$tramite = array(44 => "Inscripcion", 45 => "Vacaciones", 20 => "Licencias");

$horarios = array();
$horarios[44] = array(1=>"8 a 16", 2=>"8 a 16", 3=>"8 a 16", 4=>"8 a 16", 5=>"8 a 10"); //la clave es el día de la semana (1=lunes)
$horarios[45] = array(1=>"10 a 18", 2=>"10 a 18", 3=>"10 a 18", 4=>"10 a 18");
$horarios[20] = array(1=>"9 a 13", 3=>"9 a 16", 5=>"9 a 13");
/*
Yo, --SU NOMBRE--, declaro que el código desarrollado aquí abajo es de mi autoría 

Según estos datos, el trámite 45 no se realiza los viernes, mientras que el trámite 20 sólo se realiza lunes, miércoles y viernes.

Se desea presentarle al usuario un formulario con un select para seleccionar el nombre de un trámite.
El usuario hará submit y en el siguiente formulario elegirá el día de la semana (lunes, martes, miércoles, jueves, viernes) de otro select.
Al hacer submit nuevamente el sistema informará en qué horarios ese trámite se realiza en el día seleccionado, o bien mostrará un mensaje de "Trámite no disponible ese día".
Al mostrar los resultados se debe colocar un enlace para volver a realizar la consulta.

Se debe resolver todo el problema en un solo archivo fuente PHP.

<p>El tramite <?= $_GET["tramites"] ?> El dia <?= $_GET["dias"] ?> tiene el siguiente hoario disponible  <?= $horarios_disponibles[$_GET["dias"]] ?> </p>

*/


$tramite = array(44 => "Inscripcion", 45 => "Vacaciones", 20 => "Licencias");

$horarios = array();
$horarios[44] = array(1=>"8 a 16", 2=>"8 a 16", 3=>"8 a 16", 4=>"8 a 16", 5=>"8 a 10"); //la clave es el día de la semana (1=lunes)
$horarios[45] = array(1=>"10 a 18", 2=>"10 a 18", 3=>"10 a 18", 4=>"10 a 18");
$horarios[20] = array(1=>"9 a 13", 3=>"9 a 16", 5=>"9 a 13");

?>


<?php if(isset($_GET["dias"])) { ?>

    <p>El horario disponible para el tramite "<?= $tramite[$_GET["valor"]] ?>" es de : <?= $horarios[$_GET["valor"]][$_GET["dias"]]  ?> </p>

    <?php } else { ?>

<?php if(isset($_GET["tramites"])) { ?>


    <form action="" method="get">
        
        <label for="dias" name="dias" >Dias: </label>
        <select name="dias">
        <?php $horarios_disponibles = $horarios[$_GET["tramites"]] ?>
            <?php foreach($horarios_disponibles as $CM => $M) { ?>
                <option value="<?= $CM ?>"><?= $CM ?></option>
            <?php } ?>
        </select>
        <input type="hidden" name="valor" value="<?= (int)$_GET["tramites"] ?>"/>
		<br>
		<br>
		<br>

		<input type="submit" value="Elegir dia de la semana"></input>
	</form>

    <?php } else { ?>
    
    <form action="" method="get">
        
        <label for="tramites" name="tramites" >Tramites: </label>
        <select name="tramites">
            <?php foreach($tramite as $CM => $M) { ?>
                <option value="<?= $CM ?>"><?= $M ?></option>
            <?php } ?>
        </select>
        
		<br>
		<br>
		<br>

		<input type="submit" value="Elegir tramite"></input>
	</form>

        <?php } ?> 
    <?php } ?>