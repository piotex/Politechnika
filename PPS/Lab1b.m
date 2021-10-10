clear all;
close all;

N=4000;
fp=10000;
t=0:1/fp:(N-1)/fp;
x=sin(2*pi*350*t);
subplot(321);
plot(t,x);
xlabel('czas');
ylabel('sinus');

kmax=1000;
rx=xcorr(x,x,kmax);
tr= -kmax/fp : 1/fp : kmax/fp;
subplot(322);
plot(tr,rx);
xlabel('przesunięcie [s]');
ylabel('autokorelacja');

%wykres 3 - szum równomierny 
subplot(323);
%v=x+rand(1,N);
v=rand(1,N);
plot(t,v);
xlabel('czas [s]');
ylabel('sinus z szumem');

%wykres 4- autokorelacja
subplot(324);
rv=xcorr(v,v,kmax);
plot(tr,rv);
xlabel('przesunięcie [s]');
ylabel('autokorelacja');

%wykres 5- szum gaussoski
subplot(325);
%vG=x+randn(1,N);
vG=randn(1,N);
plot(t,vG);
xlabel('czas [s]');
ylabel('sinus z szumem gaussoskim');

%wykres 6- autokorelacja
subplot(326);
rvG=xcorr(vG,vG,kmax);
plot(tr,rvG);
xlabel('przesunięcie [s]');
ylabel('autokorelacja');

%doczytać: centrowanie sygnału, normowanie sygnału






