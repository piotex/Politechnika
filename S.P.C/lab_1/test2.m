clear;
close all;

s = tf('s');
% ODPOWIEDZI NA SKOK - ROZNE ROZMIESZCZENIE BIEGUNOW
B_Array = [3, 6, 1, -1];
C_Array = [2, -1, 10, 10];

b = 3;
c = 2;
    
    K = (1/(s^2+b*s+c));
    sys_txt = sprintf('$\\frac{1}{s^2 %+.ds %+.d}$', b, c);
    
    
    figure(1);
    [y,t] = step(K);
    plot(t, squeeze(y), 'b' , 'LineWidth',1.3  );
    grid on;
    title(['K(s) = ', sys_txt], 'FontSize', 14, 'interpreter', 'latex');
    xlabel('Czas [s]');
    ylabel('Amplituda');
