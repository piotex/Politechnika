% Kuboń Piotr, nr 25287
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: 4

clear all;
close all;
%%
t0=0;
a1=1;
a0=7;
b=8;
u0=2;
du= u0 * b;
t = [0:0.1:10];
x00 = [16/7,10/7,0,63/7];

A1 = [0,-6/7,-16/7,47/7];
      
t0=0; % od tej wartosci czasu nastepije skok
du=0; %wielkosc skoku


for i=1:1:length(A1);  
    figure(i);
    hold on; 
    grid on; 
    
    x0 = x00(i);
    sim('Kubon_lab4_sim');
    plot(ans.tout, ans.x,'o');
    xlabel("t"); 
    ylabel("x"); 
    title(strcat('Dla A1 = ',num2str(A1(i))));
end;

for i=1:1:length(A1); 
    figure(i);
    hold on; 
    grid on; 
    x1 = A1(i) * exp(-a0*t/a1);
    x2 =  b*u0/a0  * ones(1,length(t));
    x =  x1 + x2;
    plot(t,x1,'--');
    plot(t,x2,'--');
    plot(t,x,'-');
    xlabel("t"); 
    ylabel("x"); 
    title(strcat('Dla A1 = ',num2str(A1(i))));
    legend('Składowa Swobodna','Składowa Wymuszona','x')
end;

%Wymuszenie skokiem 1
u0=0;
t0=5;
du=1;
x0=0;
sim('Kubon_lab4_sim');
figure(5)
plot(ans.tout,ans.x);
grid on;
xlabel('t [s]')
ylabel('x(t)')
title('rozwiazanie symulacyjne dla u0=0, t0=5, du=1')


%Wymuszenie skokiem 2
u0=3;
t0=5;
du=2;
x0=0;
sim('Kubon_lab4_sim');
figure(6)
plot(ans.tout,ans.x);
grid on;
xlabel('t [s]')
ylabel('x(t)')
title('rozwiazanie symulacyjne dla u0=3, t0=5 i du=2')

