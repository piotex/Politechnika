clear all;
close all;
t=0:0.1:10;
h=(dirac(t)- exp(-2*t));
plot(t,h);
grid;
title('Wykres funkcji y(t)');
xlabel('t');
ylabel('y');