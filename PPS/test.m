clear all;
close all;

fpx=3600;
x = sin(2*pi*500) + sin(2*pi*1200);
N = length(x);
t=(0:N-1)*1/fpx;
figure(1);

Nf = 2^nextpow2(N);
N21 = Nf/2 +1;
f=linspace(0,fpx/2,N21);
vx = fft(x,Nf);
wx=abs(vx);

dr=2;
y=decimate(x,dr);
Ny=length(y);
fpy=fpx/dr;
ty=(0:Ny-1)*1/fpy;
figure(2);
subplot(211);
plot(ty,y);
xlabel('czas[s]');
ylabel('sygnal');






















