%Piotr Kuboń 252871
%Grupa: E05-36c 
%Dzień: 21/10/2020
%Numer Ćwiczenia: 2

%%
clear all;  
close all;
hold on;    
grid on; 
figure(1);
%% 1

t=[1:0.1:10];

xs = 3*exp(-t) -(3/2)*exp(-2*t) ;
xw = (1/2) * ones(1,length(t));
x = xs+xw;
    
plot(t,xs,'.');
plot(t,xw,'.');
plot(t,x,'r');
   
xlabel('t');
ylabel('x');
legend('xs','xw','x')
title('Zadanie 1');
%% 2
figure(2);
hold on;    
grid on; 

xs2 = (-5)*exp(-t) + (3/2)*exp(-2*t) ;
xw2 = (1/2) * ones(1,length(t));
x2 = xs2+xw2;
    
plot(t,xs2,'.');
plot(t,xw2,'.');
plot(t,x2,'r');
   
xlabel('t');
ylabel('x');
legend('xs','xw','x')
title('Zadanie 2');

%% 3a
figure(3);
hold on;    
grid on; 

xs3 = (7/2)*exp(-t) - (7/4)*exp(-2*t) ;
xw3 = (1/4) * ones(1,length(t));
x3 = xs3+xw3;
    
plot(t,xs3,'.');
plot(t,xw3,'.');
plot(t,x3,'r');
   
xlabel('t');
ylabel('x');
legend('xs','xw','x')
title('Zadanie 3a');

%% 3b
figure(4);
hold on;    
grid on; 

xs4 = (-2)*exp(-t) + (1)*exp(-2*t) ;
xw4 = (2) * ones(1,length(t));
x4 = xs4+xw4;

plot(t,xs4,'.');
plot(t,xw4,'.');
plot(t,xs4,'r');
   
xlabel('t');
ylabel('x');
legend('xs','xw','x')
title('Zadanie 3b');


%% 4
figure(5);
hold on;    
grid on; 

xs5 = (-7/2)*exp(-t) + (7/2)*exp(-2*t) ;
    
plot(t,xs5,'r');
   
xlabel('t');
ylabel('x');
legend('xs')
title('Zadanie 4');

%zadanie 3a, 3b, 4 wyliczone na kartce
%3a - 2x''+6x'+4x=1
%4  - pochodna 3a 

