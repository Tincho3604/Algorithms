/*
                              IMPRESION POR CONSOLA
                              
Marca: Peugeot // Modelo: 206 // Puertas: 4 // Precio: $200.000,00
Marca: Honda // Modelo: Titan // Cilindrada: 125cc // Precio: $60.000,00
Marca: Peugeot // Modelo: 208 // Puertas: 5 // Precio: $250.000,00
Marca: Yamaha // Modelo: YBR // Cilindrada: 160cc // Precio: $80.500,50
=============================
Vehículo más caro: Peugeot 208
Vehículo más barato: Honda Titan
Vehículo que contiene en el modelo la letra ‘Y’: Yamaha YBR $80.500,50
=============================
Vehículos ordenados por precio de mayor a menor:
Peugeot 208
Peugeot 206
Yamaha YBR
Honda Titan
*/


class Vehiculo {
  constructor(marca,modelo,puertas,precio){
    this.marca = marca;
    this.modelo = modelo;
    this.puertas = puertas;
    this.precio = precio;  
}
mostrar(){
  return  `Marca: ${this.marca} // Modelo: ${this.modelo} // Puertas: ${this.puertas} // Precio: $${this.precio}`;
 }
}



class Flota extends Vehiculo{
constructor(marca,modelo,precio){
super(marca,modelo,precio)
}

  cambiarFormato(str){
  let value = str.replace(".", "");
  value = value.replace(",",".")
  return parseFloat(value)
  }

 calcularAutoCaro(arr){
  let value
  for(let i=0; i < arr.length-1; i++){
    if(this.cambiarFormato(arr[i].precio) > this.cambiarFormato(arr[i+1].precio)){
           value = arr[i]
    }
 }
  return `Vehículo más caro: ${value.marca} ${value.modelo}`
}


calcularAutoBarato(arr){
 let value
 for(let i=0; i < arr.length-1; i++){
     if(this.cambiarFormato(arr[i].precio) < this.cambiarFormato(arr[i+1].precio)){
            value = arr[i]
     }
  }
return `Vehículo más barato: ${value.marca} ${value.modelo}`
}


vehiculoLetraY(arr){
  let value
  for(let i=0; i<arr.length; i++){
    for(let j=0; j<arr[i].modelo.split("").length; j++){
   if(arr[i].modelo.split("")[j] === "Y"){
       value = arr[i]
    }
  }
}
 return `Vehículo que contiene en el modelo la letra ‘Y’:${value.marca} ${value.modelo} $${value.precio}`
  
  }
  
  ordenar(arr){
  arr.sort((a,b)=> {
   if(this.cambiarFormato(a.precio) > this.cambiarFormato(b.precio)){
   return -1
   }
   if(this.cambiarFormato(a.precio) < this.cambiarFormato(b.precio)){
   return 1
   }
   return 0
});  
for(let i=0; i<arr.length; i++){
   console.log(arr[i].marca,arr[i].modelo ) 
    }
  }
}





class Moto extends Vehiculo{

   constructor(marca,modelo,cilindrada,precio){
   super(marca,modelo,cilindrada,precio)
   this.cilindrada = cilindrada
}
mostrar(){
  return  `Marca: ${this.marca} // Modelo: ${this.modelo} // Cilindrada: ${this.cilindrada}cc // Precio: $${this.precio}`;
}
}



const Ve1 = new Vehiculo("Peugeot",'206',4,'200.000,00');
const Ve2 = new Moto("Honda", 'Titan',125,'60.000,00');
const Ve3 = new Vehiculo("Peugeot",'208',5,'250.000,00');
const Ve4 = new Moto("Yamaha",'YBR',160,'80.500,50');
 console.log('=======================================================================================')
 console.log(Ve1.mostrar())
 console.log(Ve2.mostrar())
 console.log(Ve3.mostrar())
 console.log(Ve4.mostrar())
 console.log('=======================================================================================')

const arrFlota = [Ve1,Ve2,Ve3,Ve4]
const flota = new Flota()

console.log(flota.calcularAutoCaro(arrFlota))
console.log(flota.calcularAutoBarato(arrFlota))
console.log(flota.vehiculoLetraY(arrFlota)) 
console.log("Vehículos ordenados por precio de mayor a menor:")
console.log(flota.ordenar(arrFlota))

