clear all;
close all;

ab=25;
cd=28;
ef=71;

N=7100;
Nf=7100;

fp=2528;
t = [0:1/fp:(N-1)/fp];

x = sin(2*pi*ab*t)+ sin(2*pi*cd*t)+ sin(2*pi*ef*t)   ;
subplot(211);
plot(t,x);
xlabel('czas[s]');
ylabel('x(t)');

%%
f=linspace(0,fp,Nf);
v=fft(x,Nf);
w=abs(v);

subplot(212);

N21=Nf/2+1;
f=linspace(0,fp/2,N21);
vy=fft(x,Nf);
wy=abs(vy); 
plot(f,wy(1:N21));
xlabel('częstotliwość [Hz]')
ylabel('widmo')













