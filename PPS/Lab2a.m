clear all;
close all;

N =10000;
fp = 10000;
f = 740;
t = [0:1/fp:(N-1)/fp];
x = sin(2*pi*f*t);

figure(1);

subplot(321);
plot(t,x);
xlabel('czas[s]');
ylabel('sinus');

subplot(322);
nbins=51;
hist(x,nbins)
xlabel('wartosci probki');
ylabel('l. probek w przedziale')


y = rand(1,N);
subplot(323);
plot(t,y);
xlabel('czas[s]');
ylabel('Szum równomierny');


subplot(324);
hist(y,nbins);
xlabel('wartosci probki');
ylabel(' 1. próbek w przedziale')

z = randn(1,N);
subplot(325);
plot(t,z);
xlabel('czas[s]');
ylabel('Szum gaussowski');


subplot(326);
hist(z,nbins);
xlabel('czas[s]');
ylabel(' 1. próbek w przedziale');
%%
figure(2);
N2=100;
fp2=100;
t2=0:1/fp2:(N2-1)/fp2;
a=sin(2*pi*2*t2);
stem(t2,a);


