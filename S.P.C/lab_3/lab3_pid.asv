clear all;
close all;

Ttt = 100;

step_ki = 0.01;
step_kp = step_ki;
step_kd = step_ki;

min_kp = 2.2;
min_ki = 0.59;
min_kd = 0.59;

max_kp = 2.5;
max_ki = 0.7;
max_kd = 0.7;

t_kp = min_kp:step_kp:max_kp;
t_ki = min_ki:step_ki:max_ki;
t_kd = min_kd:step_kd:max_kd;

m_uchyb = zeros(length(t_kp),length(t_ki));
%m_uchyb = zeros((max_ki/step_ki),(max_kp/step_kp));

best_c_k_uch = 99999999;
best_kp = 0;
best_ki = 0;
best_kd = 0;

for i=1:1:length(t_kp)
    for j=1:1:length(t_ki)
        for k=1:1:length(t_kd)
            kp = t_kp(i);
            ki = t_ki(j);
            kd = t_kd(j);

            sim('simu3_pid.slx');

            %warunek stabilności obliczony z kryterium Hurwitza  
            if (kd < 8)
                if (ki < ((-kd*kd+7*kd+8)/9))
                    m_uchyb(i,j) = max(c_k_uch);
                    if m_uchyb(i,j) > 100                   %uciecie duzych uchybow
                        m_uchyb(i,j) = 100;
                    end
                    if  m_uchyb(i,j) < best_c_k_uch         %sprawdzenie czy calka z kwadratu uchybu jest mniejsza od ostatniej najlepszej
                        if 1.1 > max(y)        %sprawdzenie czy maksymalne przeregulowanie jest mniejsze od 110% wartosci ustalonej
                            best_c_k_uch = m_uchyb(i,j);
                            best_kp = kp;
                            best_ki = ki;
                            best_kd = kd;
                        end
                    end    
                else
                    m_uchyb(i,j) = -1;
                end
            else
                m_uchyb(i,j) = -1;
            end
        end
    end
    fprintf('%i z %i\n', i, length(t_kp));
end  
%surf(t_ki,t_kp,m_uchyb);
%xlabel('ki'), ylabel('kp'), zlabel('max calka kwadr. uchybu');  

%[x,y] = meshgrid(t_ki,t_kp);
%mesh(x,y,m_uchyb);








