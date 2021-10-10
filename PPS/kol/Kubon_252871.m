%suits
clear all;
close all;
%%Kubon Piotr 252871
%%
[x_audio,fpx_audio] = audioread('mbi04czep.wav');
N_audio = length(x_audio);                             
% t_audio=(0:N_audio-1)*1/fpx_audio;                

% Nf_audio = 2^nextpow2(N_audio);
% N21_audio = Nf_audio/2 +1;
% f_audio=linspace(0,fpx_audio/2,N21_audio);
% wid_audio = fft(x_audio,Nf_audio);
% mod_wid_audio=abs(wid_audio);

dr = 4;                                        
y_decim = decimate(x_audio,dr);
Ny_decim = length(y_decim);
fpy_decim = fpx_audio/dr;
t_decim = (0:Ny_decim-1)*1/fpy_decim;

Nfy_decim = 2^nextpow2(Ny_decim);
N21y_decim = Nfy_decim/2 +1;
fy_decim=linspace(0,fpy_decim/2,N21y_decim);
wid_decim = fft(y_decim,Nfy_decim);
mod_wid_decim=abs(wid_decim);

figure(1);
subplot(421);
plot(t_decim,y_decim);
xlabel('czas[s]');
ylabel('sygnal po decymacji');

subplot(422);
plot(fy_decim,mod_wid_decim(1:N21y_decim));
xlabel('czestotliwosc[Hz]');
ylabel('modul widma po decymacji');

%%  korelacja - do poprawy!
kmax = 230;                     
tr= -kmax/fpx_audio : 1/fpx_audio : kmax/fpx_audio;   
korel=xcorr(x_audio,x_audio,kmax); 

subplot(423);
plot(tr,korel);
xlabel('przesunięcie [s]');
ylabel('korelacja');
%%

                                   
                                   
% t_ftr = (0:N_ftr-1)*1/fp_ftr;                      

% 

% N21_ftr = Nf_ftr/2+1;                               
% widmo_ftr = fft(x_ftr,Nf_ftr);
% mod_wid_ftr = abs(widmo_ftr);
% f_ftr = linspace(0,fp_ftr/2,N21_ftr); 



N_ftr = N_audio;  
x_ftr = x_audio;
f_doWyc = 900; 
fp_ftr = fpx_audio;    
fgu = f_doWyc/(fp_ftr/2); 
M = 101;   
odp_impuls = fir1(M-1,fgu);
Nf_ftr = 2^nextpow2(N_ftr);
widmo_filtra = fft(odp_impuls,Nf_ftr/2+1);
mod_widmo_filtra = abs(widmo_filtra);
widmo_syg_wyciete = fft(x_poWycieciu,Nf_ftr);
mod_widma_syg_wyciete = abs(widmo_syg_wyciete);
fh_filtra = linspace(0,fp_ftr/2,N21h_filtra);



                                       
                                                 %f. unormowana (od 0 do 1)
                   %dolno-przepustowy - przepuszcza do pewnej f. !!! fgu - liczba nie przedział

t_ftr_2 = (0:M-1)*1/fp_ftr;

Nfh_filtra = 256;
N21h_filtra = Nfh_filtra/2+1;
           %rozdzielczość widma - co ile będzie kolejna próbka widma - start, krok, ilość


x_poWycieciu = filter(odp_impuls,1,x_ftr);        %liczenie splotu - nałożenie funkcji filtra na funkcje sygnału


subplot(423);
plot(t_ftr_2,odp_impuls);
xlabel('czas [s]');
ylabel('odpowiedz impulsowa');

subplot(424);
plot(fh_filtra,mod_widmo_filtra(1:N21h_filtra));
xlabel('czestotliwosc [Hz]');
ylabel('modul transmitancji filtru');

subplot(425);
plot(fh_filtra,mod_widma_syg_wyciete(1:N21h_filtra));

xlabel('czestotliwosc [Hz]');
ylabel('widmo amp. sygnału po filtracji');

subplot(426);
%plot(fh_filtra,mod_widma_syg_wyciete(1:N21h_filtra));
plot(fy_decim,mod_wid_decim(1:N21y_decim));
xlabel('czas[s]');
ylabel('widmo amp. sygnału po filtracji');

%poleam w garniturach






