clear all;
close all;
N=4000;
fp=3000;
t=(0:N-1)*1/fp;
x=chirp(t,200,(N-1)/fp,1000);
figure(1)
subplot(321)
plot(t,x)
xlabel('czas [s]')
ylabel('sygnal')
Nf=2^nextpow2(N);
N21=Nf/2+1;
f=linspace(0,fp/2,N21);
v=fft(x,Nf);
w=abs(v);
subplot(322)
plot(f,w(1:N21))
xlabel('czestotliwosc [Hz]');
ylabel('modul widma');
M=201;
ff=[600 800]/(fp/2);
h=fir1(M-1,ff,'stop');
th=(0:M-1)*1/fp;
subplot(323)
plot(th,h)
xlabel('czas [s]');
ylabel('odp impulsowa');
v2=abs(fft(h,Nf));
subplot(324)
plot(f,v2(1:N21));
xlabel('czestotliwosc[Hz]');
ylabel('modul transmitancji');
y=filter(h,1,x);
subplot(325)
plot(t,y)
xlabel('czas');
ylabel('sygnał po filtrze');
vy=fft(y,Nf);
wy=abs(vy);
subplot(326)
plot(f,wy(1:N21));
xlabel('czestotliwosci');
ylabel('modul widma');