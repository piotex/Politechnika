clear;
close all;

s = tf('s');

a=0.8;
b=4;

K = (1/(s^2+a*s+b));
sys_txt = sprintf('$\\frac{1}{s^2 %+.ds %+.d}$', a,b);
    
figure(1);
[y,t] = step(K);
plot(t, squeeze(y), 'b' , 'LineWidth',1.3  );
grid on;
%axis([0 10 -0 0.14]);

hold on;
title(['K(s) = ', sys_txt], 'FontSize', 14, 'interpreter', 'latex');
xlabel('Czas [s]');
ylabel('Amplituda');

TF = islocalmax(y);                 %TF - to są indeksy, gdzie 1 informuje o tym, że jest tam max lokalne

expo_x = [0,0,0,0,0,0,0];
expo_y = [0,0,0,0,0,0,0];
counter = 1;

for i = 1:1:length(TF)              %tutaj pobieram współrzędne max lokal
   if TF(i) == 1
       expo_x(counter) = t(i);
       expo_y(counter) = y(i);
       counter = counter+1;
   end
end

expo_x = nonzeros(expo_x);      %muszą być co najmniej 3 punkty!
expo_y = nonzeros(expo_y);

plot(expo_x,expo_y,'r*');

%teraz trzeba odpalić: APPS -> Curve Fitting -> wybrać exponente, x i y
%oraz zczytać wartości

a = 0.25;
b = 0.3977;                  % a transmitancji = 2*b
c = 0.25;                    % b transmitancji = 1/c

expp = a*exp(-b*t)+c;
plot(t, expp,'Color',[0,0,0]);

