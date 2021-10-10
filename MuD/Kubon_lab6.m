% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: 6

clear all;
close all;

%%
t0 = 5;
g = 9.81;

H1 = 8;
H2 = 2;
A1 = 1;
A2 = 7;
Aw1 = 0.1*A1;
Aw2 = 0.1*A2;
a1 = Aw1*sqrt(2*g/H1);
a2 = Aw2*sqrt(2*g/H2);

h10 = 0;
h20 = 0;

fwe1max = H1*a1;
fwe2max = H2*a2-H1*a1;

fwe1w=[0,0.5*fwe1max,0.9*fwe1max];
fwe2w=[0,0.5*fwe2max,0.9*fwe2max];


%%
figure(1);

lista = [ '0          '; '0.5*fwe1max'; '0.9*fwe1max'];
opis = lista(1,:);


d1=0.1*fwe1max;
d2 = 0;
for i=1:3
   hold on;
   grid on;
   subplot(2,2,1)
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   sim('Kubon_lab6_sim');
   plot(ans.tout ,ans.h1_out);
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0.1253, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
lista = [ '0          '; '0.5*fwe1max'; '0.9*fwe1max'];
opis = lista(1,:);
for i=1:3
   hold on;
   grid on;
   subplot(2,2,2);
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   sim('Kubon_lab6_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0.1253, d2 = 0');
   opis(i,:)=lista(i,:);
   legend(opis);
end
%%
d1=0.1*fwe1max;
d2 = 0.1*fwe2max;
lista = [ '0          '; '0.5*fwe1max'; '0.9*fwe1max'];
opis = lista(1,:);
for i=1:3
   hold on;
   grid on;
   subplot(2,2,3)
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   sim('Kubon_lab6_sim');
   plot(ans.tout ,ans.h1_out)
   xlabel('czas [t]');
   ylabel('h1 [m]');
   title('d1 = 0.1253, d2 = 0.3132');
   opis(i,:)=lista(i,:);
   legend(opis);
end
lista = [ '0          '; '0.5*fwe1max'; '0.9*fwe1max'];
opis = lista(1,:);
for i=1:3
   hold on;
   grid on;
   subplot(2,2,4);
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   sim('Kubon_lab6_sim');
   plot(ans.tout ,ans.h2_out)
   xlabel('czas [t]');
   ylabel('h2 [m]');
   title('d1 = 0.1253, d2 = 0.3132');
   opis(i,:)=lista(i,:);
   legend(opis);
end

