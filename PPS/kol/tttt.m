clear all
close all



[x,fp] = audioread('mbi04czep.wav');


N=length(x);
dr=4;
y=decimate(x,dr);
fpx=fp/dr;
Nx=length(y);
Nf=2^nextpow2(N);
N21=Nf/2+1;
f=linspace(0,fpx/2,N21);
wx=fft(y,Nf);
wx=abs(wx);
tx=0:1/fpx:(Nx-1)/fpx;

subplot(621);
plot(tx,y);
xlabel('czas[s]');

subplot(622);
plot(f,wx(1:N21));


fg=900;
fp2=fp/2;
fgu=fg/fp2;
M=101;
h=fir1(M-1,fgu);
Mf=2^nextpow2(M);
M21=Mf/2+1;
hx=fft(h,Mf);
hx=abs(hx);
f2=linspace(0,fp/2,M21);
t=0:1/fp:(M-1)/fp;


subplot(624);
plot(t,h);
xlabel('czas[s]');
ylabel('odpowiedz impulsowa filtru');
subplot(625);
plot(f2,hx(1:M21));
xlabel('czestotliwosc[hz]');
ylabel('modul transmitancji');


x2=filter(h,1,x);
N=length(x);
Nf=2^nextpow2(N);
N21=Nf/2+1;
f=linspace(0,fp/2,N21);
vx2=fft(x2,Nf);
vx2=abs(vx2);
subplot(626);
plot(f,vx2(1:N21));
xlabel('czestotliwosc[hz]');
ylabel('widmo amplitudowe');