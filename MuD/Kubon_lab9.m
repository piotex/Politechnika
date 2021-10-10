% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: miniprojekt

%%
%zmienne wejściowe:  Tzew, Tkz, fk
%zmienne wyjściowe:  Tw1, Tw2

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
Tzew0 = TzewN + 0;
Tkz0 = TkzN;
fk0 = fkN;
%% stan równowagi - zmienne wyjścia
Tw10 = Tw1N;
Tw20 = Tw2N;
%% III część
%% 
T = 100.0; 
t0 = 5.0;
dTzew = 0.0;
dTkz = 0.0;
dfkz = 0.0;


















