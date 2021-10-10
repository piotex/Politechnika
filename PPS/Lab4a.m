clear all;
close all;

[x,fpx] = audioread('mbi04osiem.wav');
N = length(x);
t=(0:N-1)*1/fpx;
figure(1);
subplot(211);
plot(t,x);
xlabel('czas[s]');
ylabel('nagranie');

Nf = 2^nextpow2(N);
N21 = Nf/2 +1;
f=linspace(0,fpx/2,N21);
vx = fft(x,Nf);
wx=abs(vx);

subplot(212);
plot(f,wx(1:N21));
xlabel('czestotliwosc[Hz]');
ylabel('modul widma');

dr=4;
y=decimate(x,dr);
Ny=length(y);
fpy=fpx/dr;
ty=(0:Ny-1)*1/fpy;
figure(2);
subplot(211);
plot(ty,y);
xlabel('czas[s]');
ylabel('sygnal');

Nfy = 2^nextpow2(Ny);
N21y = Nfy/2 +1;
fy=linspace(0,fpy/2,N21y);
vy = fft(y,Nfy);
wy=abs(vy);

subplot(212);
plot(fy,wy(1:N21y));
xlabel('czestotliwosc[Hz]');
ylabel('modul widma');



