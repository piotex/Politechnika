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
qkN = 18000;
%% wyliczenia 
fkN = qkN/(cpN*ppN*(TkzN-Tw2N));
ks1 = (cpN*ppN*fkN*(TkzN-Tw2N))/(Tw1N-2*TzewN+Tw2N);
ks2 = ks1;
k0 = ((cpN*ppN*fkN)*(TkzN-Tw1N)-ks1*(Tw1N-TzewN))/(Tw1N-Tw2N);
%% parametry dynmiczne 
Cv1 = cpN*ppN*V1N;
Cv2 = cpN*ppN*V2N;

%% II część
%% warunki początkowe - zmienne wejścia
Tzew0 = TzewN;
fk0 = fkN *0.7;
Tkz0 = TkzN*0.7;
%% stan równowagi - zmienne wyjścia
%Tw10 = Tw1N;
%Tw20 = Tw2N;
%% III część
%% 
T = 100.0; 
t0 = 50.0;
dTzew = 0.0;
dfkz = 0.0;
dTkz = 2.0;

%% Tw10 i Tw20
%%
a_1 = cpN*ppN*fk0;
b_1 = ks1+a_1+k0;

Tw10 = ( (a_1*b_1*Tkz0)+ks1*(ks1+a_1+2*k0)*Tzew0 )/( (b_1^2)-(k0*(k0+a_1)) );
Tw20 = ( (k0+a_1)*Tw10+ks1*Tzew0 )/( k0+a_1+ks1 );

%%

figure(1);
subplot(1,2,1);
hold on;
grid on;
sim('Kubon_lab10_sim');
plot(ans.tout ,ans.Tw1_out);
subplot(1,2,2);
xlabel('aaa');
ylabel('Tw1');

hold on;
grid on;
plot(ans.tout ,ans.Tw2_out);
xlabel('');
ylabel('Tw2');
title('');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%transmitancja%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

a_1 = cpN*ppN*fk0;
M1_ = [Cv1 , a_1+ks1+k0];
M2_ = [Cv2 , a_1+ks2+k0];

L1 = [(Cv2*a_1) (a_1*(ks2+a_1+k0))];                                %Tkz
L2 = [(Cv2*ks1) ((k0*ks2)+(ks1*(a_1+ks2+k0)))];                     %Tzew
L3 = (k0*a_1+a_1*a_1);                                              %Tkz
L4 = [(Cv1+ks2) (k0*ks1+(a_1*ks1)+(ks2*(a_1+ks1+k0)))];             %Tzew


M1 = [(Cv1*Cv2) (Cv1*a_1+Cv1*ks2+Cv1*k0+Cv2*a_1+Cv2*ks1+Cv2*k0) (a_1^2+a_1*ks2+a_1*k0  +a_1*ks1+ks1*ks2+ks1*k0    +k0*ks2)];
M2 = M1;
M3 = M2;
M4 = M3;



%%
figure(2);
subplot(1,2,1);
hold on;
grid on;
sim('Kubon_lab10_2_sim');
plot(ans.tout ,ans.Tw1_out_tr);
subplot(1,2,2);
hold on;
grid on;
plot(ans.tout ,ans.Tw2_out_tr);
xlabel('');
ylabel('');
title('transmitancja');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%rownania stanu%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Tw0_w = [Tw10,Tw20];
A = [ (-cpN*ppN*fk0-ks1-k0)/(Cv1) , k0/Cv1 ; (k0+cpN*ppN*fk0)/(Cv2) , (-k0-cpN*ppN*fk0-ks2)/(Cv2)  ];
B = [(cpN*ppN*fk0)/(Cv1) , ks2/Cv1 ; 0 , ks2/Cv2 ];
C = eye(2);
D = zeros(2);



figure(3);
subplot(1,2,1);
hold on;
grid on;
sim('Kubon_lab10_3_sim');
plot(ans.tout ,ans.Tw1_out_rs);
subplot(1,2,2);
hold on;
grid on;
plot(ans.tout ,ans.Tw2_out_rs);
xlabel('');
ylabel('');
title('r stanu');


