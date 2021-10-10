clear all;
close all;

N=5000;
fp=4000;
t=(0:N-1)*1/fp;
x=chirp(t,200,(N-1)/fp,1200);

figure(1);
subplot(321);
plot(t,x);
xlabel('czas[s]');
ylabel('sygnal');

Nf=2^nextpow2(N);
N21=Nf/2+1;
v=fft(x,Nf);
w=abs(v);
f=linspace(0,fp/2,N21);
subplot(322);
plot(f,w(1:N21));
xlabel('czestotliwosc[Hz]');
ylabel('modul widma');

M=201;
fg=[600,800];
fgu=fg/(fp/2);
h=fir1(M-1,fgu,'stop');
th=(0:M-1)*1/fp;
subplot(323);
plot(th,h);
xlabel('czas');
ylabel('odpowiedz impulsowa');

Nfh=256;
N21h=Nfh/2+1;
fh=linspace(0,fp/2,N21h);
vh=fft(h,Nfh);
wh=abs(vh);
subplot(324);
plot(fh,wh(1:N21h));
xlabel('czestotliwosc');
ylabel('modul transmitancji');

y=filter(h,1,x);
subplot(325);
plot(t,y);
xlabel('czas');
ylabel('sygnal');

vy=fft(y,Nf);
wy=abs(vy);
subplot(326);
plot(f,wy(1:N21));
xlabel('czest');
ylabel('modul widma');






