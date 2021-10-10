clear all;
close all;
%%
N=1000;
fp=1000;
t = [0:1/fp:(N-1)/fp];


%%
x=2*sin(2*pi*250*t)+3*sin(2*pi*350*t);%+2*rand(1,N);
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