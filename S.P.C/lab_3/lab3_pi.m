clear all;
close all;

Ttt = 100;

step_ki = 0.01;
step_kp = step_ki;

min_kp = 2;
min_ki = 0.0;

max_kp = 3;
max_ki = 0.5;

t_kp = min_kp:step_kp:max_kp;
t_ki = min_ki:step_ki:max_ki;

m_uchyb = zeros(length(t_kp),length(t_ki));
%m_uchyb = zeros((max_ki/step_ki),(max_kp/step_kp));

best_c_k_uch = 99999999;
best_kp = 0;
best_ki = 0;

for i=1:1:length(t_kp)
    for j=1:1:length(t_ki)
        kp = t_kp(i);
        ki = t_ki(j);

        sim('simu3_pi.slx');
        
        %warunek stabilności obliczony z kryterium Hurwitza  
        if (kp < 8)
            if (ki < ((-kp*kp+7*kp+8)/7))
                m_uchyb(i,j) = max(c_k_uch);
                if m_uchyb(i,j) > 100                   %uciecie duzych uchybow
                    m_uchyb(i,j) = 100;
                end
                if  m_uchyb(i,j) < best_c_k_uch         %sprawdzenie czy calka z kwadratu uchybu jest mniejsza od ostatniej najlepszej
                    if 1.1 > max(y)        %sprawdzenie czy maksymalne przeregulowanie jest mniejsze od 110% wartosci ustalonej
                        best_c_k_uch = m_uchyb(i,j);
                        best_kp = kp;
                        best_ki = ki;
                        best_copy_y = y;
                    end
                end    
            else
                m_uchyb(i,j) = -1;
            end
        else
            m_uchyb(i,j) = -1;
        end
        

    end
    fprintf('%i z %i\n', i, length(t_kp));
end  
surf(t_ki,t_kp,m_uchyb);

%[x,y] = meshgrid(t_ki,t_kp);
%mesh(x,y,m_uchyb);

xlabel('ki'), ylabel('kp'), zlabel('max calka kwadr. uchybu');  %to ma byc na odwrot!







