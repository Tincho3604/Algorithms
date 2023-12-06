-- PUNTO 3: Agregar el artículo cuyo código sea el siguiente en la secuencia, el nombre es ALTAVOCES, su precio $7000.
INSERT INTO PRODUCTOS (COD_PRODUCTO, DESCRIPCION, PRECIO_UNITARIO) VALUES ('P0011', 'ALTAVOCES', 7000);

-- PUNTO 4: Cambiar el nombre del producto cuyo código termina en 8 por ‘Impresora Láser’.
UPDATE PRODUCTOS SET DESCRIPCION = 'Impresora Láser' WHERE COD_PRODUCTO LIKE '%8';

-- PUNTO 5: Aplicar un 10 % de descuento a todos los precios de los productos.
UPDATE PRODUCTOS SET PRECIO_UNITARIO = PRECIO_UNITARIO - (PRECIO_UNITARIO * 1.10);

-- PUNTO 6: Obtener la descripción de todos los productos de la tienda.
SELECT DESCRIPCION FROM  PRODUCTOS;

-- PUNTO 7: Obtener el código y descripción de los artículos de la tienda cuyo precio sea menor a $2000.
SELECT COD_PRODUCTO, DESCRIPCION FROM PRODUCTOS WHERE PRECIO_UNITARIO < 2000;

-- PUNTO 8: Obtener todos los datos de los productos de la tienda cuyo precio esté entre $600 y $1200.
SELECT * FROM PRODUCTOS WHERE PRECIO_UNITARIO BETWEEN 1200 AND 600;

-- PUNTO 9: Aplicar un descuento de $150 a todos los productos cuyos precios no sean superiores o iguales a $1200.
UPDATE PRODUCTOS SET PRECIO_UNITARIO = PRECIO_UNITARIO - (PRECIO_UNITARIO * 1.150) WHERE PRECIO_UNITARIO <= 1200 ;

-- PUNTO 10: Obtener la descripción y el precio en dólares de todos los productos de la tienda (considere que el dólar está a $450).
SELECT DESCRIPCION, TRUNC(PRECIO_UNITARIO/450, 2) PRECIO_DOLAR FROM PRODUCTOS; 

-- PUNTO 11: Obtener la descripción y el precio en dólares de los productos de la tienda 
-- cuyo precio sea superior o igual a $1800 ordenados en forma descendente por precio y ascendentemente por nombre.
SELECT DESCRIPCION, ROUND(PRECIO_UNITARIO/450, 2) AS PRECIO_DOLAR
FROM PRODUCTOS
WHERE PRECIO_UNITARIO >= 1800
ORDER BY PRECIO_UNITARIO DESC, DESCRIPCION ASC;







