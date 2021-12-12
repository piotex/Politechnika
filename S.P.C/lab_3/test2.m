clear all;
close all;

Ttt = 20;
t_kp = [1; 3; 9; 150];

figure(1);
hold on;
grid on;

kp = 1;
ki=0;
    
sim('simu3.slx');
txt = ['kp = ',num2str(kp)];
plot(mtim, y, 'LineWidth', 2,'DisplayName',txt); 
    
legend('show');
xlabel('t') 
ylabel('y');  

Ko = tf([1],[1,3,3,1]); 
Kuar = feedback(1,Ko);

figure;
hold on;
grid on;
step(Ko)
step(Kuar)


