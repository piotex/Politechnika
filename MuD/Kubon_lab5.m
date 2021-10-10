% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: 5

clear all;
close all;
%%
t0=0;
u0=0;
d0=1;
    
x0=0;
x10=0;

%%
ksi = [2;-0.9;0;0.4;-0.1];
w = [ 5.0; 5.0; 5.0; 5.0; 5.0 ];

kolor = ['k', 'r', 'b', 'g', 'm'];
lista= ['ksi=2   ';'ksi=-0.9';'ksi=0   ';'ksi=0.4 ';'ksi=-0.1'];
opis = lista(1,:);
for i=1:length(ksi)
    
    a=1;
    b=2*ksi(i)*w(i);
    c=w(i)*w(i);
    
    opis=lista(i,:);
    
    sim('Kubon_lab5_sim');
    subplot(2,5,i);
    hold on;
    grid on;
    axis([-25 10 -10 10]);
    plot(tout,x,'Color',kolor(i));
    xlabel('t[s]');
    ylabel('x(t)');
    title(strcat('Odpowiedz skokowa, ksi=',num2str(ksi(i))));
    
    %bieguny
    lambda1(i) = -ksi(i)*w(i) + w(i)*sqrt(ksi(i)*ksi(i) - 1);
    lambda2(i) = -ksi(i)*w(i) - w(i)*sqrt(ksi(i)*ksi(i) - 1);
    
    subplot(2,5,i+5);
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    axis([-25 10 -10 10]);
    
    plot(real(lambda1(i)),imag(lambda1(i)),'.', 'Markersize', 20, 'Color', kolor(i));
    plot(real(lambda2(i)),imag(lambda2(i)),'.', 'Markersize', 20, 'Color', kolor(i));
    
    plot([0,real(lambda1(i))],[0,imag(lambda1(i))],'LineStyle', '--', 'Color', [0 0 0]);
    plot([0,real(lambda2(i))],[0,imag(lambda2(i))],'LineStyle', '--', 'Color', [0 0 0]);
    
end
%%%%%%%%%%%%%%%%%%%%%%%%%  to samo ksi  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ksi = [ 0.3; 0.3; 0.3];
w = [2;6;8];
kolor = ['r', 'b', 'm'];
lista = [ 'w=2'; 'w=6'; 'w=8'];
opis = lista(1,:);
for i=1:length(ksi)
    
    a=1;
    b=2*ksi(i)*w(i);
    c=w(i)*w(i);
    
    opis(i,:)=lista(i,:);
    figure(2);
    sim('Kubon_lab5_sim');
    subplot(2,1,1);
    hold on;
    grid on;
    plot(tout,x,'Color',kolor(i));
    xlabel('t[s]');
    ylabel('x(t)');
    title('Taka sama wartosc ksi = 0.3');
    legend(opis);
    
    %bieguny
    lambda1(i) = -ksi(i)*w(i) + w(i)*sqrt(ksi(i)*ksi(i) - 1);
    lambda2(i) = -ksi(i)*w(i) - w(i)*sqrt(ksi(i)*ksi(i) - 1);
    subplot(2,1,2);
    
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    axis([-10 5 -20 20]);
    
    plot(real(lambda1(i)),imag(lambda1(i)),'.', 'Markersize', 25, 'Color', kolor(i));
    plot(real(lambda2(i)),imag(lambda2(i)),'.', 'Markersize', 25, 'Color', kolor(i));
    
    plot([0,real(lambda1(i))],[0,imag(lambda1(i))],'LineStyle', '--', 'Color', [0 0 0]);
    plot([0,real(lambda2(i))],[0,imag(lambda2(i))],'LineStyle', '--', 'Color', [0 0 0]);
end

%%%%%%%%%%%%%%%%%%%%%%%%%  to samo omega  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ksi = [ 0.1; 0.2; 0.5];
w = [ 5; 5; 5];
kolor = ['r', 'b', 'm'];
lista = [ 'ksi=0,1'; 'ksi=0,2'; 'ksi=0,5'];
opis = lista(1,:);
for i=1:length(ksi)
    
    a=1;
    b=2*ksi(i)*w(i);
    c=w(i)*w(i);
    
    opis(i,:)=lista(i,:);
    figure(3);
    sim('Kubon_lab5_sim');
    subplot(2,1,1);
    hold on;
    grid on;
    plot(tout,x,'Color',kolor(i));
    xlabel('t[s]');
    ylabel('x(t)');
    title('Taka sama wartosc omega = 5');
    legend(opis);
    
    %bieguny
    lambda1(i) = -ksi(i)*w(i) + w(i)*sqrt(ksi(i)*ksi(i) - 1);
    lambda2(i) = -ksi(i)*w(i) - w(i)*sqrt(ksi(i)*ksi(i) - 1);
    subplot(2,1,2);
    
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    axis([-10 5 -20 20]);
    
    plot(real(lambda1(i)),imag(lambda1(i)),'.', 'Markersize', 25, 'Color', kolor(i));
    plot(real(lambda2(i)),imag(lambda2(i)),'.', 'Markersize', 25, 'Color', kolor(i));
    
    plot([0,real(lambda1(i))],[0,imag(lambda1(i))],'LineStyle', '--', 'Color', [0 0 0]);
    plot([0,real(lambda2(i))],[0,imag(lambda2(i))],'LineStyle', '--', 'Color', [0 0 0]);
end

%%%%%%%%%%%%%%%%%%%%%%%%%  to samo Re  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ksi = [ 0.9; 0.6; 0.3];
w = [ 1; 1.5; 3];
kolor = ['r', 'b', 'm'];
lista = [ 'ksi=0,9 omega=1  '; 'ksi=0,6 omega=1.5'; 'ksi=0,3 omega=3  '];
opis = lista(1,:);
for i=1:length(ksi)
    
    a=1;
    b=2*ksi(i)*w(i);
    c=w(i)*w(i);
    
    opis(i,:)=lista(i,:);
    figure(4);
    sim('Kubon_lab5_sim');
    subplot(2,1,1);
    hold on;
    grid on;
    plot(tout,x,'Color',kolor(i));
    xlabel('t[s]');
    ylabel('x(t)');
    title('Taka sama wartosc czesci rzeczywistej = -0,9');
    legend(opis);
    
    %bieguny
    lambda1(i) = -ksi(i)*w(i) + w(i)*sqrt(ksi(i)*ksi(i) - 1);
    lambda2(i) = -ksi(i)*w(i) - w(i)*sqrt(ksi(i)*ksi(i) - 1);
    subplot(2,1,2);
    
    hold on;
    grid on;
    xlabel('Re');
    ylabel('Im');
    title('Bieguny');
    axis([-5 5 -5 5]);
    
    plot(real(lambda1(i)),imag(lambda1(i)),'.', 'Markersize', 25, 'Color', kolor(i));
    plot(real(lambda2(i)),imag(lambda2(i)),'.', 'Markersize', 25, 'Color', kolor(i));
    
    plot([0,real(lambda1(i))],[0,imag(lambda1(i))],'LineStyle', '--', 'Color', [0 0 0]);
    plot([0,real(lambda2(i))],[0,imag(lambda2(i))],'LineStyle', '--', 'Color', [0 0 0]);
end









