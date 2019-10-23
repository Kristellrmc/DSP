# DSP
En el siguiente archivo podrá encontrar el código de convolución y DFT para una señal tanto como clase como librería. 
La convolución es una forma matemática para combinar dos señales en una tercera señal, en esta ocasión utilizamos como primera señal un archivo .DAT y como segunda señal una “señal de impulso”.  
El algoritmo calcula la convolución mediante una sumatoria representada en un ciclo for. Donde se representa el tamaño de la señal de entrada, el tamaño de la señal de la respuesta al impulso y y[n] representa la señal de salida obteniendo así un archivo “output_signal.DAT”.

Para el uso de un archivo externo (.DAT) es necesario pegar el texto dentro del archivo waveform.cpp

Por otro lado, la transformada discreta de Fourier nos facilita el manejo de las señales al poder expresarla como una combinación lineal de términos permitiéndonos ver la distribución de frecuencias de la señal permitiendo tener valores para cada tiempo determinado.
Dentro de este archivo se cuenta con una clase definida de la transformada discreta de Fourier donde se hace uso de una señal de entrada y mediante una sumatoria se obtiene como salida tanto la parte real como imaginaria de la transformada discreta de Fourier. 
A su vez se cuenta con las funciones para el calculo de la magnitud, fase y transformada discreta inversa de Fourier para poder así observar frecuencias y composición y descomposición de señales.
