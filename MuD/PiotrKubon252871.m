
%Piotr Kuboń 252871
%Grupa: E05-36c 
%Dzień: 14/10/2020
%Numer Ćwiczenia: 1

%%
clear all;       
hold on;    
grid on; 
%%
Qg=1000;
TzewN = -20;
TwewN = 20;
Tp=10;

q=[500:500:2000];
tzew = [-25:5:20];

Kcw = (0.4*Qg)/(TwewN-TzewN);
Kcp = (0.6*Qg)/(Tp-TzewN);
%%
figure(3);
hold on;    
grid on; 
plot(-20,20,'o');
text(-20,10,"punkt nominalny",'VerticalAlignment','top','HorizontalAlignment','left');
for i=1:1:length(q);   
    Twew_2 = (q(i)-Kcp*(Tp-tzew)+Kcw*tzew)/(Kcw); 
    %Tp_2   = (q(i)-Kcw*TwewN+tzew*(Kcw+Kcp))/(Kcp); 
    plot(tzew,Twew_2);
    xlabel("Tzew [C]"); 
    ylabel("Twew [C]"); 
end;
figure(1);
hold on;    
grid on; 
plot(1000,20,'o');
text(1000,20,"punkt nominalny",'VerticalAlignment','top','HorizontalAlignment','left');
for i=1:1:length(q);   
    Twew_2 = (q+tzew(i)*(Kcw+Kcp)-Kcp*Tp)/(Kcw); 
    plot(q,Twew_2);
    xlabel("Q[W]"); 
    ylabel("Twew [C]"); 
end;
figure(2);
hold on;    
grid on; 
plot(1000,10,'o');
text(1000,10,"punkt nominalny",'VerticalAlignment','top','HorizontalAlignment','left');
for i=1:1:length(q);   
    Tp_2   = (q-Kcw*TwewN+tzew(i)*(Kcw+Kcp))/(Kcp); 
    plot(q,Tp_2);
    xlabel("Q[W]"); 
    ylabel("Tp [C]"); 
end;

%%
%x = [-10:1:10]; 
%for a = -2 : .5 : 2;      
%    plot(x, a*x.*x); 
%end
%[x,y]=meshgrid(-2:.2:2,-2:.2:2); 
%z = x.*exp(-x.^2-y.^2); 
%mesh(z)
%%
