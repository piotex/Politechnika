% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: 5

clear all;
close all;

t0 = 1;
u0 = 0;
d0 = 1;
Wzm = 1;

e = [2 -2.7 0 0.4 -0.1];
w = [5 5 5 5 5];

x10 = 0;
x20 = 0;

StopTimeW = [15 5 10 10 10];

%%
figure(1);
lista = ['e=2.0 ';'e=-2.7';'e=0.0 ';'e=0.4 ';'e=-0.1';];

for i=1:length(e)
    a = 1;
    b = 2*e(i)*w(i);
    c = w(i)^2;
    
    StopTime = StopTimeW(i);
    subplot(2,5,i);
    
    xlabel('t[s]');
    ylabel('x(t)');
    title('Sygnał');
    hold on;
    grid on;
    sim('Kubon_poprawa_lab5_sim');
    plot(ans.tout,ans.x_out);
    opis2=lista(i,:);
    legend(opis2);
    
    subplot(2,5,i+5);
    lam1 = -e(i)*w(i) + w(i)*sqrt(e(i)^2 - 1);
    lam2 = -e(i)*w(i) - w(i)*sqrt(e(i)^2 - 1);
    lam = [lam1 lam2];
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    plot(real(lam),imag(lam),'o');
end;
%%
StopTime = 10;

%% to samo ksi - e
e = [0.3 0.3 0.3];
w = [1 2 3];

lista = [ 'e=0.3 w=1'; 'e=0.3 w=2'; 'e=0.3 w=3'];
for i=1:length(e)
    figure(2);
    hold on;
    grid on;
    
    Wzm = w(i)^2;   %bo musi być równanie znormalizowane
    a = 1;
    b = 2*e(i)*w(i);
    c = w(i)^2;  
    
    sim('Kubon_poprawa_lab5_sim');
    plot(ans.tout,ans.x_out);
    xlabel('t[s]');
    ylabel('x(t)');
    title('Sygnał');
    opis(i,:)=lista(i,:);
    legend(opis);
    
    figure(3);
    hold on;
    grid on;
    
    lam1 = -e(i)*w(i) + w(i)*sqrt(e(i)^2 - 1);
    lam2 = -e(i)*w(i) - w(i)*sqrt(e(i)^2 - 1);
    lam = [lam1 lam2];
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    axis([-4 4 -4 4]);
    plot(real(lam),imag(lam),'o');
end;

%% to samo omega - w
e = [0.1 0.4 0.7];
w = [3 3 3];

lista = [ 'e=0.1 w=3'; 'e=0.4 w=3'; 'e=0.7 w=3'];
for i=1:length(e)
    figure(4);
    hold on;
    grid on;
    Wzm = w(i)^2;   %bo musi być równanie znormalizowane - wzmocnienie = 1
    a = 1;
    b = 2*e(i)*w(i);
    c = w(i)^2;
    
    sim('Kubon_poprawa_lab5_sim');
    plot(ans.tout,ans.x_out);
    xlabel('t[s]');
    ylabel('x(t)');
    title('Sygnał');
    opis(i,:)=lista(i,:);
    legend(opis);
    
    figure(5);
    hold on;
    grid on;
    lam1 = -e(i)*w(i) + w(i)*sqrt(e(i)^2 - 1);
    lam2 = -e(i)*w(i) - w(i)*sqrt(e(i)^2 - 1);
    lam = [lam1 lam2];
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    axis([-4 4 -4 4]);
    plot(real(lam),imag(lam),'o');
end;
%% taka sama część rzeczywista - re
e = [0.6 0.3 0.2];
w = [1 2 3];

lista = [ 'e=0.6 w=1'; 'e=0.3 w=2'; 'e=0.2 w=3'];
for i=1:length(e)
    figure(6);
    hold on;
    grid on;
    Wzm = w(i)^2;   %bo musi być równanie znormalizowane - wzmocnienie = 1
    a = 1;
    b = 2*e(i)*w(i);
    c = w(i)^2;
    
    sim('Kubon_poprawa_lab5_sim');
    plot(ans.tout,ans.x_out);
    xlabel('t[s]');
    ylabel('x(t)');
    title('Sygnał');
    opis(i,:)=lista(i,:);
    legend(opis);
    
    figure(7);
    hold on;
    grid on;
    
    lam1 = -e(i)*w(i) + w(i)*sqrt(e(i)^2 - 1);
    lam2 = -e(i)*w(i) - w(i)*sqrt(e(i)^2 - 1);
    lam = [lam1 lam2];
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    axis([-4 4 -4 4]);
    plot(real(lam),imag(lam),'o');
end;




