clear all;
close all;
%% sinus
N=1000;      %ilosc probek
fp=2500;    %f. probkowania
Tp=1/fp;    %okres probkowania
A=1;        %amplituda
f=20;        %f. sinusa
fi=0.4;     %przesuniecie fazowe


t=[0:(1/fp):(N-1)/fp];      %wektor czasu

x=A*sin(2*pi*f*t+fi);
y=rand(1,N);            %szum równomierny
z=randn(1,N);           %szum gałsowski

%% chirp
N=1000;                 %ilosc probek
fp=2500;                %f. probkowania
f0 = 10;                %f.początkowa
f1 = 150;               %f.końcowa
t1 = (N-1)/fp;          %koniec wektora czasu
v=chirp(t,f0,t1,f1);

%% korelacja
kmax = 400;                      %przesunięcie sygnału o 400 próbek w prawo i 400 pr. w lewo - maksymalne opóźnienie sygnału (w próbkach)
tr= -kmax/fp : 1/fp : kmax/fp;   %przesunięcie sygnału w czasie
korel=xcorr(x,x,kmax); 
%autokorelacja
koler_auto=xcorr(y,y,kmax);

%% histogram - słupki - statystyka sprawdzająca liczność wartości w danym podprzedziale wartości
nbins=51;                        %liczba przedziałów

%% histogram - widmo sygnału - wykres w dziedzinie częstotliwości
%DFT - dyskretna transformata Fouriera
%FFT - szybka transformata Fouriera - wymaga Nf jako potęgi 2
%motylek - transformata dwupunktowa
%widmo amplitudowe - moduł widma
%widmo fazowe      - argument - kąt przy liczbie zesp
Nf = 1024;                               %długość transf. Fouriera - potęga 2 większa od N - doklejanie zer jesli są różne - przeciek widma
wid_fft = fft(x,Nf);
mod_wid_fft = abs(wid_fft);

%poprawne widmo sygnału - połowa - bo reszta to lustrzane odbicie i trzeba usuwać
N21 = (Nf/2)+1;
rozd_widm = linspace(0,fp/2,N21);            %rozdzielczość widma - co ile będzie kolejna próbka widma - start, krok, ilość

%% zabawa z plikiem dźwiękowym
[x_audio,fpx_audio] = audioread('mbi04osiem.wav');
N_audio = length(x_audio);                              %długość nagrania
t_audio=(0:N_audio-1)*1/fpx_audio;                  %fpx - czestotliwość próbkowania - trzeba odczytać z nagrania

Nf_audio = 2^nextpow2(N_audio);
N21_audio = Nf_audio/2 +1;
f_audio=linspace(0,fpx_audio/2,N21_audio);
wid_audio = fft(x_audio,Nf_audio);
mod_wid_audio=abs(wid_audio);

%decymacja - pozbywanie się zbędnych (redundantnych) informacji  - dużo rzeczysię zmienia 
dr = 4;                                         %rząd decymacji - co którą próbkę bierzemy - UWAGA - trzeba uważać na f_syg < 2*f_próbkowania
y_decim = decimate(x_audio,dr);
Ny_decim = length(y_decim);
fpy_decim = fpx_audio/dr;
t_decim = (0:Ny_decim-1)*1/fpy_decim;

Nfy_decim = 2^nextpow2(Ny_decim);
N21y_decim = Nfy_decim/2 +1;
fy_decim=linspace(0,fpy_decim/2,N21y_decim);
wid_decim = fft(y_decim,Nfy_decim);
mod_wid_decim=abs(wid_decim);

% aliasing       - jeżeli f_próbkowania  nie jest większa od 2x częstotliwość sygnału - WIDMA się psują
% przeciek widma - jeżeli rozdzielczość widma (fp/Nf) nie jest wielokrotnością częstotliwości sygnału (f)
%                - dodatkowo jeżeli długość transf. Fouriera  (Nf) =/= długość sygnału (N)
%% spektogram - pokazuje jak widmo zmieniało się w czasie

N_spec=5000;
fp_spec=2000;
t_spec=0:1/fp_spec:(N_spec-1)/fp_spec;
x_spec=chirp(t_spec,100,2.5,900,'q');

%% filtracja !!!

N_ftr = 5000;                                       %dł. sygnału
fp_ftr = 4000;                                      %f. próbkowania
t_ftr = (0:N_ftr-1)*1/fp_ftr;                       %wektor czasu
x_ftr = chirp(t_ftr,200,(N_ftr-1)/fp_ftr,1200);     %sygnał - w.czasu, f.pocz., koniec w.czasu, f.końcowa

Nf_ftr = 2^nextpow2(N_ftr);
N21_ftr = Nf_ftr/2+1;                               %dł. transf. Fouriera
widmo_ftr = fft(x_ftr,Nf_ftr);
mod_wid_ftr = abs(widmo_ftr);
f_ftr = linspace(0,fp_ftr/2,N21_ftr);               %rozdzielczość widma - co ile będzie kolejna próbka widma - start, krok, ilość

M = 201;                                          %długość filtra
f_doWyc = [600,800];                              %f. graniczne
fgu = f_doWyc/(fp_ftr/2);                         %f. unormowana (od 0 do 1)
odp_impuls = fir1(M-1,fgu,'stop');              %pasmowo-zaporowy  - wycina pewne f.
% odp_impuls = fir1(M-1,fgu);                   %dolno-przepustowy - przepuszcza do pewnej f. !!! fgu - liczba nie przedział
% odp_impuls = fir1(M-1,fgu,'high');            %górn-przepustowy  - przepuszcza od pewnej f. !!! fgu - liczba nie przedział
% odp_impuls = fir1(M-1,fgu);                   %pasmowo-przepustowy - przepuszcza do pewnej f.
t_ftr_2 = (0:M-1)*1/fp_ftr;

Nfh_filtra = 256;
N21h_filtra = Nfh_filtra/2+1;
fh_filtra = linspace(0,fp/2,N21h_filtra);           %rozdzielczość widma - co ile będzie kolejna próbka widma - start, krok, ilość
widmo_filtra = fft(odp_impuls,Nfh_filtra);
mod_widmo_filtra = abs(widmo_filtra);

x_poWycieciu = filter(odp_impuls,1,x_ftr);        %liczenie splotu - nałożenie funkcji filtra na funkcje sygnału

widmo_syg_wyciete = fft(x_poWycieciu,Nf_ftr);
mod_widma_syg_wyciete = abs(widmo_syg_wyciete);




%%
%%
%%
figure(1);
subplot(421);
plot(t,x);
xlabel('czas[s]');
ylabel('sygnał');

subplot(422);
plot(t,v);
xlabel('czas[s]');
ylabel('chirp');

subplot(423);
plot(tr,korel);
xlabel('przesunięcie [s]');
ylabel('korelacja');

subplot(424);
plot(tr,koler_auto);
xlabel('przesunięcie [s]');
ylabel('autokorelacja');

subplot(425);
hist(x,nbins);
xlabel('wartosci probki');
ylabel('l. probek w przedziale')

subplot(426);
stem(t,x);                                  %stem - nie łączy poszczególnych próbek
xlabel('czas[s]');
ylabel('sygnał');

subplot(427);
plot(rozd_widm, mod_wid_fft(1:N21));                                  
xlabel('częstotliwość[Hz]');
ylabel('widmo sygnału');

figure(2);
subplot(421);
plot(t_audio,x_audio);
xlabel('czas[s]');
ylabel('nagranie');

subplot(422);
plot(f_audio,mod_wid_audio(1:N21_audio));
xlabel('czestotliwosc[Hz]');
ylabel('modul widma');

subplot(423);
plot(t_decim,y_decim);
xlabel('czas[s]');
ylabel('sygnal po decymacji');

subplot(424);
plot(fy_decim,mod_wid_decim(1:N21y_decim));
xlabel('czestotliwosc[Hz]');
ylabel('modul widma po decymacji');

subplot(425);
plot(t_spec,x_spec);
xlabel('czas');
ylabel('x_spec');

subplot(426);
spectrogram(x_spec,512,128,512,fp_spec);        
%sygnał, 
%dł.okna czasowego, 
%liczba próbek które na siebie nachodzą, 
%dł.transf.Fouriera
%częstotliwość próbkowania

% mniejsza szerokość okna - lepsza rozdzielczość w czasie
% duża dł.trans.Four.     - lepsza rozdzielczość widmowa
set(gcf,'Position',[50 50 1200 700]);

figure(3);
subplot(421);
plot(t_ftr,x_ftr);
xlabel('czas[s]');
ylabel('sygnal');

subplot(422);
plot(f_ftr,mod_wid_ftr(1:N21_ftr));
xlabel('czestotliwosc[Hz]');
ylabel('modul widma');

subplot(423);
plot(t_ftr_2,odp_impuls);
xlabel('czas');
ylabel('odpowiedz impulsowa');

subplot(424);
plot(fh_filtra,mod_widmo_filtra(1:N21h_filtra));
xlabel('czestotliwosc');
ylabel('modul transmitancji');

subplot(425);
plot(t_ftr,x_poWycieciu);
xlabel('czas');
ylabel('sygnal');

subplot(426);
plot(f_ftr,mod_widma_syg_wyciete(1:N21_ftr));
xlabel('czest');
ylabel('modul widma');




