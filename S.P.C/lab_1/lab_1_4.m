clear;
close all;

s = tf('s');

K_Ar = [1/2, 1, 3];
T_Ar = [1/2, 1, 3];

opis = ["","",""];

figure(1);
grid on;
hold on;
axis([0 8 -0.5 5]);
for i = 1:1:3
   
    k = K_Ar(i);
    tt = 1;
    K = (k/(tt*s+1));
    sys_txt = sprintf('$\\frac{%.2f}{%.2fs+1}$', k, tt);
    opis(i)=sys_txt;
    
    [y,t] = step(K);
    plot(t, squeeze(y) );
    hold on;
end

xlabel('Czas [s]');
ylabel('Amplituda'); 
legend(opis, 'FontSize', 14, 'interpreter', 'latex');



figure(2);
grid on;
hold on;
axis([0 8 -0.5 5]);
for i = 1:1:3
   
    k = 1;
    tt = T_Ar(i);
    K = (k/(tt*s+1));
    sys_txt = sprintf('$\\frac{%.2f}{%.2fs+1}$', k, tt);
    opis(i)=sys_txt;
    
    [y,t] = step(K);
    plot(t, squeeze(y) );
    hold on;
end

xlabel('Czas [s]');
ylabel('Amplituda'); 
legend(opis, 'FontSize', 14, 'interpreter', 'latex');