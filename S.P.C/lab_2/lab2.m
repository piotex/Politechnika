clear all;
close all;

Ttt = 20;
A = 1;


%sim('simu2.slx');

figure(1);

hold on;
grid on;

%plot(mtim, sin, 'LineWidth', 2);
%plot(mtim, sin1, 'LineWidth', 2);
%plot(mtim, sin2, 'LineWidth', 2);

SSS = 2;
%plot(Re1, Im1, 'LineWidth', 2);

k=4;
sys=tf([k],[1 4 6 4 1]); %zdefiniowanie systemu liniowego
w=0:0.01:10; %warto´sci pulsacji dla których nale˙zy wyznaczy´c K(jw)
r=freqresp(sys,w); %wyznaczenie K(jw) systemu przy pulsacjach w
for i=1:1001 %zabieg techniczny (konwersja)
    rr(i)=r(1,1,i); 
end; %zabieg techniczny (konwersja)
plot(rr); %rysowanie ch-ki (czerwone krzy˙zyki)
grid on; %siatka skalujaca na wykresie ˛
hold on; %mozliwo´s´c umieszczenia wielu wykresów w jednym oknie


















