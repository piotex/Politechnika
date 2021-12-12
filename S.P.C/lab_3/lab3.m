clear all;
close all;


Ttt = 20;
t_kp = [1; 3; 9; 150];

figure(1);
hold on;
grid on;

for i=1:1:size(t_kp)
    kp = t_kp(i);
    
    sim('simu3.slx');
    txt = ['kp = ',num2str(kp)];
    plot(mtim, y, 'LineWidth', 2,'DisplayName',txt); 
end
legend('show');
xlabel('t') 
ylabel('y');   

%--------------------%--------------------%--------------------%--------------------%--------------------%--------------------

figure(2);
hold on;
grid on;

for i=1:1:size(t_kp)
    kp = t_kp(i);
    
    sim('simu3.slx');
    txt = ['kp = ',num2str(kp)];
    plot(mtim, uchyb, 'LineWidth', 2,'DisplayName',txt); 
end
legend('show');
xlabel('t') 
ylabel('uchyb');


















