clear all;
close all;
%%
N=400;
fp=1000;
t = [0:1/fp:(N)/fp];


%%
f1=10;
f2=20;
f3=30;
f4=40;
A1 = 0.25;
A2 = 0.25;
A3 = 0.25;
A4 = 1;
x=A1*sin(2*pi*f1*t)+A2*sin(2*pi*f2*t)+A3*sin(2*pi*f3*t)+A4*sin(2*pi*f4*t) +2;
subplot(211);
plot(t,x);
xlabel('czas[s]');
ylabel('x(t)');

%%
Nf=1024;
f=linspace(0,fp,Nf);
v=fft(x,Nf);
w=abs(v);

subplot(212);
plot(f,w);
xlabel('częstotliwość [Hz]');
ylabel('widmo amplitudowe');