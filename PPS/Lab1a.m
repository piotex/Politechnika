clear all;
close all;
%%
N=1000;
fp=2500;
Tp=1/fp;
A=1;
f=3;
fi=0.4;
t=[0:(1/fp):(N-1)/fp];

x=A*sin(2*pi*f*t+fi);
y=rand(1,N);
z=randn(1,N);

f0 = 10;
f1 = 150;
t1 = (N-1)/fp;
v=chirp(t,f0,t1,f1);
%%
figure(1);

subplot(221);
plot(t,x);
xlabel('czas[s]');
ylabel('sinus');

subplot(222);
plot(t,y);
xlabel('czas[s]');
ylabel('szum równomierny');

subplot(223);
plot(t,z);
xlabel('czas[s]');
ylabel('szum normalny');

subplot(224);
plot(t,v);
ylabel('czas[s]');
xlabel('ćwirk');
%%
w=6*sin(2*pi*10*t)+3*sin(2*pi*20*t)+2*rand(1,N);

%%
figure(2);
plot(t,w);
xlabel('czas[s]');
ylabel('sygnal');






%q=[1:1:10];
%plot(q,sin(q));