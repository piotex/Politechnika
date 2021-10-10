% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: miniprojekt

%%
%zmienne wejściowe:  Tzew, Tkz, fk
%zmienne wyjściowe:  Tw1, Tw2
clear all;
close all;

T_stop = 300;

k1 = 1;
k2 = 7;
k3 = 8;

%% I część
%% wartości nominalne 
TzewN = -20;
Tw1N = 20;
Tw2N = 15;
TkzN = 30;
V1N = k1*k2*2.5;
V2N = V1N*0.7;
cpN = 1000;
ppN = 1.2;
%qkN = 18000;
qkN=[10000:1000:20000];
Twew_2=qkN*2;


    figure(1);
    hold on;
    grid on;

    plot(qkN,Twew_2,'-o');
    xlabel("Q[W]"); 
    ylabel("Twew [C]"); 

