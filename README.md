# TCS3200-sensor-de-color-con-LED-RGB
Detector de colores mediante sensor de color TCS3200 con RGB LED para visualizar resultados


Este proyecto esta protegido por la licencia de software libre con copyleft "GNU General Public License (GPL) 3.0" y ha sido desarrollado parcialmente por principiantes por lo que no se ofrece garantía alguna y su uso queda bajo la responsabilidad única de sus usuarios.

Circuito:
 
  1 Arduino Uno u otras placas base compatibles
  1 sensor de color TCS3200
  1 led RGB
    
  Lista de componentes conectados a entradas:
      Sensor de color TCS3200 : Pines S0, S1, S2,S3
                
    
  Lista de componentes conectados a salidas:
     
       Sensor de color TCS3200: Pin OUT
       LED RGB: pines R,G,B
  
  
  Desarrollo del proyecto:

La idea sería seguir desarrollando el proyecto para conseguir unos colores en el led mas acordes a los resultados de las lectura de las frecuencias. Por el momento el led solo indica rojo, verde o azul dependiendo de si el escaneo del color tiene una frecuencia mas cercana a uno de esos tres colores, es decir si predomina la frencuencia roja entonces se enciende solo el led rojo, si predomina la verde se enciende led verde y si predomina la azul se enciende el led azul pero no se mezclan colores en el led RGB. Para ello habria que desarrollar el código para que mezclen los colores.Ahí lo dejo de momento.

  FECHA :16/02/2020
  AUTOR José María Mejuto
  
