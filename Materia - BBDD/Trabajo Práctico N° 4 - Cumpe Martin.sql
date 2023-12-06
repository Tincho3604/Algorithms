/*  PUNTO 2: En la Tabla Libro agregar dos columnas: Fecha_Alta cuyo valor predeterminado sea ‘01/04/2010’ y Cantidad */

ALTER TABLE LIBRO
ADD (
    Fecha_alta DATE DEFAULT TO_DATE('01/04/2010', 'DD/MM/YYYY'),
    Cantidad NUMBER(10,0)
);

/* 
    PUNTO 3: En la tabla de CARRERAS se han encontrado que la carrera de ‘INGENIERIA QUIMICA’ 
    está repetida, identificar el 
    código de una de ellas para luego eliminar uno de los registros en función de su código.
*/
SELECT ID FROM CARRERA WHERE NOMBRE = 'INGENIERIA QUIMICA' AND ROWNUM = 1;
DELETE FROM CARRERA WHERE id = 5;

/* PUNTO 4: Eliminar de la tabla de materias la que lleva como nombre ‘INGLES III’ por no existir. */
DELETE FROM MATERIA WHERE NOMBRE LIKE '%INGLES III%'

/* PUNTO 5: La carrera ingeniería Civil lleva por error el nombre de ingeniería CIVICA, realizar el cambio de nombre. */
UPDATE CARRERA SET NOMBRE = 'INGENIERIA CIVIL' 
WHERE NOMBRE LIKE upper('INGENIERIA CIVICA');  

/* PUNTO 6: Indicar cuántos alumnos hay inscriptos en cada uno de los cursos activos. */
SELECT ALM.NOMBRE, COUNT(ALM.LEGAJO) AS CANTIDAD_ALUMNOS_EN_CURSO_ACTIVO 
FROM ALUMNO ALM
INNER JOIN CARRERA CAR 
ON ALM.CARRERA = CAR.ID 
INNER JOIN MATRICULA MAT
ON ALM.LEGAJO = MAT.ID
INNER JOIN CURSO CUR
ON MAT.CURSO = CUR.ID
GROUP BY ALM.NOMBRE;

-- PUNTO 7: Listar todos los datos del alumno junto con el nombre de la carrera que sigue.
SELECT ALM.LEGAJO,
ALM.APELLIDO,
ALM.NOMBRE, 
ALM.FECHA_NACIMIENTO, 
ALM.MAIL, 
ALM.CARRERA, 
CAR.NOMBRE AS CARRERA_QUE_SIGUEN FROM ALUMNO ALM 
INNER JOIN CARRERA CAR 
ON ALM.CARRERA = CAR.ID;

-- PUNTO 8: Listar los datos de los alumnos que no están inscriptos en ninguna materia.
SELECT ALM.legajo, ALM.APELLIDO, ALM.NOMBRE, ALM.FECHA_NACIMIENTO, ALM.MAIL, ALM.CARRERA
FROM ALUMNO ALM
LEFT JOIN MATRICULA MAT
ON MAT.ALUMNO = ALM.LEGAJO
WHERE MAT.ALUMNO is null;

-- PUNTO 9: Listar los nombres de las materias que no tienen alumnos inscriptos.
SELECT MATE.NOMBRE
FROM MATERIA MATE
full outer join CURSO ON MATE.ID = CURSO.MATERIA
WHERE CURSO.MATERIA IS NULL;

-- PUNTO 10: Armar un listado de cada curso mostrando el nombre de la materia y los alumnos con su apellido, nombre, legajo, 
-- y condición ante la materia: P – ‘PROMOCIONADO’, R – ‘REGULAR’, L – ‘LIBRE’, A – ‘ABANDONO’.

SELECT
    A.NOMBRE,
    A.APELLIDO,
    A.LEGAJO,
    MA.NOMBRE AS MATERIA,
    CASE
        WHEN M.PROMOCIONA = 'P' 
            THEN 'PROMOCIONADO'
        WHEN M.PROMOCIONA = 'R' 
            THEN 'REGULAR'
        WHEN M.PROMOCIONA = 'L' 
            THEN 'LIBRE'
        WHEN M.PROMOCIONA = 'A' 
            THEN 'ABANDONO'
        END as CONDICION
FROM
     ALUMNO A
INNER JOIN
    MATRICULA M ON A.LEGAJO = M.ALUMNO
INNER JOIN CURSO C 
    ON C.ID = M.ALUMNO
INNER JOIN MATERIA MA
ON MA.ID = C.MATERIA;


-- PUNTO 11: No debe existir ningún libro cuyo precio supere los $13500. Controlarlos y si es necesario modificar esos registros.

