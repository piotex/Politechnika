clear all;
close all;


Ttt = 20;


figure(1);
hold on;
grid on;


    kp = 2.22;
    ki = 0.63;
    kd = 0.63;
    
    sim('simu3_pid.slx');
    txt = ['kp = ',num2str(kp),'ki = ',num2str(ki),'kd = ',num2str(kd)];
    plot(mtim, y, 'LineWidth', 2,'DisplayName',txt); 

legend('show');
xlabel('t') 
ylabel('y');   


















