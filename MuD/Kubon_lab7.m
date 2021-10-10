% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: 7

clear all;
close all;

%%
t0 = 5;
g = 9.81;

H1 = 8;
H2 = 6; %zmienione z 2 na 6 bo wychodziły ujemne wartości
A1 = 4;
A2 = A1;
Aw1 = 0.1*A1;
Aw2 = 0.1*A2;
a1 = Aw1*sqrt(2*g/(H1-H2));
a2 = Aw2*sqrt(2*g/H2);

h10 = 0;
h20 = 0;

fwe1max = a1*(H1-H2);
fwe2max = a2*H2-a1*(H1-H2);

fwe1w=[0,0.5*fwe1max,0.9*fwe1max];
fwe2w=[0,0.5*fwe2max,0.9*fwe2max];


%%
figure(1);
lista = [ '0          '; '0.5*fwe1max'; '0.9*fwe1max'];
opis = lista(1,:);

d1=0.1*fwe1max;
d2 = 0;
fwe2=0.1*fwe2max;

for i=1:3
   hold on;
   grid on;
   subplot(2,2,1)
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   sim('Kubon_lab7_sim');
   plot(ans.tout ,ans.h1_out);
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0.2506, d2 = 0');
%    opis(i,:)=lista(i,:);
%    legend(opis);
end
for i=1:3
   hold on;
   grid on;
   subplot(2,2,2);
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   sim('Kubon_lab7_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0.2506, d2 = 0');
%    opis(i,:)=lista(i,:);
%    legend(opis);
end
%%
d1= 0; %0.1*fwe1max;
d2 = 0.1*fwe2max;
fwe1=0.1*fwe1max;
for i=1:3
   hold on;
   grid on;
   subplot(2,2,3)
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   sim('Kubon_lab7_sim');
   plot(ans.tout ,ans.h1_out)
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0, d2 = 0.1834');
%    opis(i,:)=lista(i,:);
%    legend(opis);
end
for i=1:3
   hold on;
   grid on;
   subplot(2,2,4);
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   sim('Kubon_lab7_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0, d2 = 0.1834');
%    opis(i,:)=lista(i,:);
%    legend(opis);
end
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%dokladny%%%%%%%%%%%%%%%%%%%%%%%%%%%

fwe1max = Aw1*sqrt(2*g*(H1-H2));
fwe2max = Aw2*sqrt(2*g*H2) - Aw1*sqrt(2*g*(H1-H2));

fwe1w=[0,0.5*fwe1max,0.9*fwe1max];
fwe2w=[0,0.5*fwe2max,0.9*fwe2max];

figure(2);

d1=0.1*fwe1max;
d2 = 0;
fwe2=0.1*fwe2max;
%fwe1=0.1*fwe1max;

for i=1:3
   hold on;
   grid on;
   subplot(2,2,1)
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   
   h10=(1/(2*g))*((fwe1/Aw1)^2)     + (1/(2*g))*(((fwe2+fwe1)/Aw2)^2);
   h20=(1/(2*g))*(((fwe2+fwe1)/Aw2)^2);
   
   sim('Kubon_dokladny_lab7_sim');
   plot(ans.tout ,ans.h1_out);
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0.2506, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
% 
% d1=  0;%0.1*fwe1max;
% d2 = 0.1*fwe2max;
% %fwe2=0.1*fwe2max;
% fwe1=0.1*fwe1max;
for i=1:3
   hold on;
   grid on;
   subplot(2,2,2);
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   
   h10=(1/(2*g))*(fwe1/Aw1)^2 + (1/(2*g))*(((fwe2+fwe1)/Aw2)^2);
   h20=1/(2*g)*(((fwe1+fwe2)/Aw2)^2);
   
   sim('Kubon_dokladny_lab7_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
%    title('d1 = 0, d2 = 0.1834');
   title('d1 = 0.2506, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
%%
% d1=  0.1*fwe1max;
% d2 = 0;%0.1*fwe2max;
% fwe2=0.1*fwe2max;
% %fwe1=0.1*fwe1max;

d1=  0;%0.1*fwe1max;
d2 = 0.1*fwe2max;
fwe1=0.1*fwe1max;
%fwe2=0.1*fwe2max;

lista = [ '0          '; '0.5*fwe2max'; '0.9*fwe2max'];
opis = lista(1,:);

for i=1:3
   hold on;
   grid on;
   subplot(2,2,3);
   %fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   
   h10=1/(2*g)*(fwe1/Aw1)^2 + (1/(2*g))*(((fwe2+fwe1)/Aw2)^2);
   h20=1/(2*g)*((fwe1+fwe2)/Aw2)^2;
   
   sim('Kubon_dokladny_lab7_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0, d2 = 0,1834');
   %title('d1 = 0.2506, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
% 
% d1=  0;%0.1*fwe1max;
% d2 = 0.1*fwe2max;
% fwe1=0.1*fwe1max;
% %fwe2=0.1*fwe2max;
for i=1:3
   hold on;
   grid on;
   subplot(2,2,4);
   %fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   
   h10=(1/(2*g))*(fwe1/Aw1)^2 + (1/(2*g))*(((fwe2+fwe1)/Aw2)^2);
   h20=1/(2*g)*(((fwe1+fwe2)/Aw2)^2);
   
   sim('Kubon_dokladny_lab7_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0, d2 = 0,1834');
   opis(i,:)=lista(i,:);
   legend(opis);
end























