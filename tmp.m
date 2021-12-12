clear;
close all;

%H = tf([1],[1 3 2]);
%H = tf([1],[1 2 0]);    %K2-g2

s = zpk('s');
H = 2* (exp(-1*s))+1;   %K2-g1

%H = (s-2)/(s+1)^2
%H = (s+1)/((s)*(s^2+3*s+50))

nyquist(H)
%grid on;