clear;
close all;

s = tf('s');
% ODPOWIEDZI NA SKOK - ROZNE ROZMIESZCZENIE BIEGUNOW
B_Array = [3, 6, 1, -1];
C_Array = [2, -1, 10, 10];

for i = 1:4
    
    b = B_Array(i);
    c = C_Array(i);
    K = (1/(s^2+b*s+c));
    sys_txt = sprintf('$\\frac{1}{s^2 %+.ds %+.d}$', b, c);
    
    figure(i);
    [y,t] = step(K);
    plot(t, squeeze(y), 'b' , 'LineWidth',1.3  );
    grid on;
    title(['K(s) = ', sys_txt], 'FontSize', 14, 'interpreter', 'latex');
    xlabel('Czas [s]');
    ylabel('Amplituda'); z
    %if i==3 
    %    hold on;
    %    plot(t, 0.09982*exp(-0.9785*t)+0.09966 );
    %end

end

