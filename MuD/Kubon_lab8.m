% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: 8

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

x0 = [0,0];
A = [-a1/A1 , a1/A1 ; a1/A2 , (-a1-a2)/A2];
B = [1/A1 , 0 ; 0 , 1/A2];
C = eye(2);
D = zeros(2);

figure(1);
lista = [ '0          '; '0.5*fwe1max'; '0.9*fwe1max'];
opis = lista(1,:);

d1=0.1*fwe1max;
d2 = 0;
fwe2 = 0.1*fwe2max;

for i=1:3
   hold on;
   grid on;
   subplot(2,2,1)
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_1_sim');
   plot(ans.tout ,ans.h1_out);
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0.2506, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
for i=1:3
   hold on;
   grid on;
   subplot(2,2,2);
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_1_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0.2506, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
%%
d1= 0; %0.1*fwe1max;
d2 = 0.1*fwe2max;
fwe1 = 0.1*fwe1max;
for i=1:3
   hold on;
   grid on;
   subplot(2,2,3)
   %fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_1_sim');
   plot(ans.tout ,ans.h1_out)
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0, d2 = 0.1834');
   opis(i,:)=lista(i,:);
   legend(opis);
end
for i=1:3
   hold on;
   grid on;
   subplot(2,2,4);
   %fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_1_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0, d2 = 0.1834');
   opis(i,:)=lista(i,:);
   legend(opis);
end
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%transmitancja%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
M1_ = [A1 , a1];
M2_ = [A2 , a1+a2];
L1 = M2_;
L2 = [ a1 ];
L3 = [ a1 ];
L4 = M1_;
M1 = [A1*A2 , A1*a1+A1*a2+A2*a1 , a1*a2];
M2 = M1;
M3 = M2;
M4 = M3;


figure(2);
lista = [ '0          '; '0.5*fwe1max'; '0.9*fwe1max'];
opis = lista(1,:);

d1=0.1*fwe1max;
d2 = 0;
fwe2 = 0.1*fwe2max;

for i=1:3
   hold on;
   grid on;
   subplot(2,2,1)
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_2_sim');
   plot(ans.tout ,ans.h1_out);
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0.2506, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
for i=1:3
   hold on;
   grid on;
   subplot(2,2,2);
   fwe1 = fwe1w(i);
   %fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_2_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0.2506, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
%%
d1= 0; %0.1*fwe1max;
d2 = 0.1*fwe2max;
fwe1 = 0.1*fwe1max;

for i=1:3
   hold on;
   grid on;
   subplot(2,2,3)
   %fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_2_sim');
   plot(ans.tout ,ans.h1_out)
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0, d2 = 0.1834');
   opis(i,:)=lista(i,:);
   legend(opis);
end
for i=1:3
   hold on;
   grid on;
   subplot(2,2,4);
   %fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1+(fwe2+fwe1)/a2;
   h20=(fwe2+fwe1)/a2;
   x0 = [h10,h20];
   
   sim('Kubon_lab8_2_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0, d2 = 0.1834');
   opis(i,:)=lista(i,:);
   legend(opis);
end




























