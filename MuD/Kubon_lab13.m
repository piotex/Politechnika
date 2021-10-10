clear all
close all

k = 2;
T1 = 10;
T2 = 20;
s = tf('s');
G=k/((T1*s+1)*(T2*s+1));
figure(1);
hold on;
grid on;
step(G);
%%
T0 = 3.68;
Tk = 45.1-T0;

G12 = (k*exp(-s*T0))/(Tk*s+1)
grid on;
step(G12);
%%
k1 = 1;
k2 = 7;
k3 = 8;
TzewN = -20;
Tw1N = 20;
Tw2N = 15;
TkzN = 30;
V1N = k1*k2*2.5;
V2N = V1N*0.7;
cpN = 1000;
ppN = 1.2;
qkN = 18000;
fkN = qkN/(cpN*ppN*(TkzN-Tw2N));
fk0 = fkN;
ks1 = (cpN*ppN*fkN*(TkzN-Tw2N))/(Tw1N-2*TzewN+Tw2N);
ks2 = ks1;
k0 = ((cpN*ppN*fkN)*(TkzN-Tw1N)-ks1*(Tw1N-TzewN))/(Tw1N-Tw2N);
Cv1 = cpN*ppN*V1N;
Cv2 = cpN*ppN*V2N;
a_1 = cpN*ppN*fk0;

a=a_1;
b = Cv1*Cv2;
c = (Cv1*a_1+Cv1*ks2+Cv1*k0+Cv2*a_1+Cv2*ks1+Cv2*k0);
d = (a_1^2+a_1*ks2+a_1*k0  +a_1*ks1+ks1*ks2+ks1*k0    +k0*ks2);

Kk2 = (4*b*a*(k0+a))/(c^2);
T01 = (2*b)/(c);

figure(2);
hold on;
G13 = (Kk2)/((T01*s+1)^2);
%G13 = (k0*a+a*a)/(b*s^2+c*s+d);
bode(G13);                           
%model_K = (Kk/KT*s+1)*exp(-s*Kt0);

%1/t1 = 1/0,0508 = 19,68
%1/t2 = 1/0,243  =  4,115

%sprawdzenie - charakterystyka czerwona i niebieska pokrywają się, a więc
%dobrze odczytano parametry 
% G14 = (0.622)/(((1/0.0508)*s+1)*((1/0.243)*s+1));
% bode(G14);

grid on;







