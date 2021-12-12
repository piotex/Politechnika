clear all;
close all;


Ttt = 6;
t_kp = [1; 3; 9];
t_ki = [1; 3; 9];

size_t_kp = 3;


for i=1:1:size(t_kp)
    figure(i);
    hold on;
    grid on;
    for j=1:1:size(t_ki)
        kp = t_kp(i);
        ki = t_ki(j);

        sim('simu3_2.slx');
        txt = ['kp = ',num2str(kp),'  ki = ',num2str(ki)];
        plot(mtim, y, 'LineWidth', 2,'DisplayName',txt); 
    end
    legend('show');
    xlabel('t') 
    ylabel('y'); 
end  

%--------------------%--------------------%--------------------%--------------------%--------------------%--------------------

for i=1:1:size(t_kp)
    figure(i+size_t_kp);
    hold on;
    grid on;
    for j=1:1:size(t_ki)
        kp = t_kp(i);
        ki = t_ki(j);

        sim('simu3_2.slx');
        txt = ['kp = ',num2str(kp),'  ki = ',num2str(ki)];
        plot(mtim, uchyb, 'LineWidth', 2,'DisplayName',txt);
    end
    legend('show');
    xlabel('t') 
    ylabel('całka kwadratu uchybu'); 
end  

















