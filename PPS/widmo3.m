
clear;
f1=100;	% czestotliwosc pierwszej sinosoidy
A1=2;		% amplituda pierwszej sinusoidy
phi1=0.4;	% faza pierwszej sinusoidy

f2=350;	% czestotliwosc drugiej sinosoidy
A2=1;		% amplituda drugiej sinusoidy
phi2=0.8;	% faza drugiej sinusoidy

fp=2000;	% czestotliwosc probkowania
N1=1600;	% dlugosc sygnalu
Nf=1600;

% generuj os czasu
t1=0:1/fp:(N1-1)/fp;

% generuj sygnal i wykres
syg=A1*sin(2*pi*f1*t1+phi1) + A2*sin(2*pi*f2*t1+phi2);
subplot(221);
plot(t1,syg);
xlabel('czas [s]');
ylabel('x(t)');

% wyznacz widmo
widmo=fft(syg,Nf)/Nf;
wid1=abs(widmo);
subplot (222);
N21 = Nf/2 + 1;
f1 = linspace (0, fp/2, N21);
plot (f1, wid1(1:N21));
xlabel ('czest. [Hz]');
ylabel ('|X(f)|');

% --------------  zmiana Nf
Nf = 2048;
wid2 = abs (fft(syg,Nf)/Nf);
N21 = Nf/2 + 1;
f2 = linspace (0, fp/2, N21);
subplot (223);
plot (f2, wid2(1:N21));
xlabel ('czest. [Hz]');
ylabel ('|X(f)|');

% --------------  zmiana Nf
Nf = 2^13;
wid3 = abs (fft(syg,Nf)/Nf);
N21 = Nf/2 + 1;
f2 = linspace (0, fp/2, N21);
subplot (224);
plot (f2, wid3(1:N21));
xlabel ('czest. [Hz]');
ylabel ('|X(f)|');

set (gcf,'Position',[50 50 1000 700]);