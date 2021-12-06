<?php
$marcas = array(1=>"Ford", 2=>"Renault", 5=>"Ferrari");
$provincias = array(1=>"CABA", 7=>"Cordoba", 2=>"Misiones");
$detalles = array(20=>"Aire", 30=>"ABS", 33=>"Gas");

$indistinto = "INDISTINTO";
$autos = array();
$autos[25] = array("marca"=>1, "prov"=>2, "det"=>array(20));
$autos[4] = array("marca"=>2, "prov"=>1, "det"=>array(20,30));
$autos[14] = array("marca"=>1, "prov"=>2, "det"=>array(30));
$autos[1] = array("marca"=>5, "prov"=>7, "det"=>array(20,30,33));

?>


<!DOCTYPE html>
<html>
    <title>Ejercicio 1</title>
</head>
<body>
    <h1>Concecionaria Ejercicios</h1>

    <?php if ( isset($_GET['marcas']) && isset($_GET['provincias']) )  { ?>
    
    <?php if ( $_GET['marcas'] !== $indistinto) { ?>
    <p>La marca es <?= $marcas[ $_GET['marcas'] ]?></p>
    <?php } ?>

    <?php if ( $_GET['provincias'] !== $indistinto) { ?>
    <p>La provincia es <?= $provincias [ $_GET['provincias'] ]?> </p>
    <?php } ?>
    
    
    <?php if ( $_GET['provincias'] !== $indistinto && $_GET['marcas'] !== $indistinto ) { ?>

    <p>Detalles del vehiculo: </p>
    <?php foreach($autos as $clave=>$valor) { ?>

        <?php if($_GET['marcas'] == $autos[$clave]["marca"] && $_GET['provincias'] == $autos[$clave]["prov"])  { ?>    
            <?php $detalles_vehiculo = $autos[$clave]["det"]; ?>
                <?php foreach($detalles_vehiculo as $deta) { ?>
                    <li><?= $detalles[$deta] ?></li> 
                <?php  } ?>
            <?php  } ?>
        <?php } ?>
    <?php } else { ?>

        <?php foreach($autos as $clave=>$valor) { ?>
            <p><?=$marcas[$autos[$clave]["marca"]]?></p>
            <p><?=$provincias[$autos[$clave]["prov"]]?></p>
        <?php } ?>

    <?php } ?>
    
    
    
    
    
    <?php  } else {  ?> <!-- RENDERIZADO FORMULARIO -->

    <form action="" method="get">
        <select name="marcas">
            <?php foreach($marcas as $CM => $M) { ?>
                <option value="<?= $CM ?>"><?= $M ?></option>
            <?php } ?>
            <option value="<?= $indistinto ?>"><?= $indistinto ?></option>
        </select>
        <select name="provincias">
            <?php foreach($provincias as $CP => $P) { ?>
                <option value="<?= $CP ?>"><?= $P ?></option>
            <?php } ?>
                <option value="<?= $indistinto ?>"><?= $indistinto ?></option>
        </select>

        <input type="submit" value="Ver vehiculos"></input>
    </form>


    <?php }  ?>
</body>
</html>






<!-- EJERCICIO 3 -->
<h1>EJERCICIO 3</h1>
<!DOCTYPE html>
<html>
<head>
    <title>ejercicio 3</title>
</head>


<body>

<?php if( isset($_GET['pesos']) || isset($_GET['dolar']) || isset($_GET['tasa'])) { ?>
    
    <?php if( $_GET['pesos'] !== '' && $_GET['dolar'] !== '' )  { ?>
        <?php  $dato_faltante_valor = (int)$_GET['dolar'] / (int)$_GET['pesos'] ?>
        <?php  $dato_faltante = "TASA" ?>
    <?php } ?>

    <?php if( $_GET['pesos'] !== '' && $_GET['tasa'] !== '' )  { ?>
        <?php  $dato_faltante_valor = (int)$_GET['pesos'] * (int)$_GET['tasa']  ?>
        <?php  $dato_faltante = "DOLARES" ?>
    <?php } ?>

    <?php if( $_GET['dolar'] !== '' && $_GET['tasa'] !== '' )  { ?>
        <?php  $dato_faltante_valor = (int)$_GET['dolar'] / (int)$_GET['tasa'] ?>
        <?php  $dato_faltante = "PESOS" ?>
    <?php } ?>


    <p>El dato faltante es: <?= $dato_faltante . ' ' .  $dato_faltante_valor?> </p>

    <?php  } else {  ?> 

        <form action="" method="get">
        <label for="pesos">Pesos: </label>
        <input type="text" name="pesos" /> 

        <label for="dolar">Dolares: </label>
        <input type="text" name="dolar" /> 

        <label for="tasa">Tasa de cambio %: </label>
        <input type="text" name="tasa" /> 

        <input type="submit" value="Ver faltante"></input>

    </form>

    <?php  } ?>
</body>
</html>





<!-- EJERCICIO 4 -->


<h1>EJERCICIO 4</h1>
<!DOCTYPE html>
<html>
<head>
    <title>ejercicio 4</title>
</head>
<body>


<?php  

if (isset($_GET['calculo'])) { 
    if ($_GET['calculo'] === $_GET['valor']) echo "OK";
    else echo "INCORRECTO";
}

$valor1 = rand(0,10);
$valor2 = rand(0,10);
$operador = array('+','-','*','/');
$index = rand(0,3);


switch ($operador[$index]) {
    case '+':
        $resultado = $valor1 + $valor2;
        $signo = '+';
        break;
    case '-':
        $resultado = $valor1 - $valor2;
        $signo = '-';
        break;
    case '*':
        $resultado = $valor1 * $valor2;
        $signo = '*';
        break;
    case '/':
        $resultado = $valor1 / $valor2;
        $signo = '/';
    break;
    }
?>



    <form action="" method="get">
        <p><?= $valor1 . $signo . $valor2 ?></p>

        <input type="text" name="calculo" /> 
        <input type="hidden" name="valor" value="<?= (int)$resultado ?>"/>
        <input type="submit" value="Calcular"></input>
    </form>

</body>
</html>