clear;
close all;

s = tf('s');

%S1_Array = [1+1/2i, 1+2i, 1+10i];
%S2_Array = [1-1/2i, 1-2i, 1-10i];

S1_Array = [(1+1/2i), (1+3i), (1+10i)];
S2_Array = [(1-1/2i), (1-3i), (1-10i)];

opis = ["","",""];

figure;
grid on;
hold on;
axis([0 8 -10 10]);
for i = 1:1:3
   
    
    s1 = S1_Array(i);
    s2 = S2_Array(i);
    K = (1/((s-s1)*(s-s2)));
    sys_txt = sprintf('$\\frac{1}{(s-%.2f+%.2fj)*(s-%.2f+%.2fj)}$', real(s1),imag(s1),real(s2),imag(s2));
    opis(i)=sys_txt;
    
    [y,t] = step(K);
    plot(t, squeeze(y) );
    hold on;
    %title(['K(s) = ', sys_txt], 'FontSize', 14, 'interpreter', 'latex');
    
end

xlabel('Czas [s]');
ylabel('Amplituda'); 
legend(opis, 'FontSize', 14, 'interpreter', 'latex');
