% Kuboń Piotr, nr 252871
% grupa środa 15:15-16:55 (E05-36c)
% nr cwiczenia: 5

clear all;
close all;

t0 = 0;
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

h1 = 0;
h2 = 0;
dfwe1=0.1*fwe1max;
dfwe2 = 0;

figure(1);
for i=1:3
   hold on;
   grid on;
   subplot(2,2,1)
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   sim('Kubon_lab6_sim_test');
   axis([-1 100 -1 10]);
   plot(ans.tout ,ans.h1a);
   xlabel('czas [t]');
   ylabel('wysokosc wody w zbiorniku - h [m]');
   title('wysokosc wody w zbiorniku, pierwszy zbiornik : dfwe1 = 1.1276, dfwe2 = 0');
end
for i=1:3
   hold on;
   grid on;
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   subplot(2,2,2)
   sim('Kubon_lab6_sim_test');
   plot(ans.tout ,ans.h2a)
   xlabel('czas [t]');
   ylabel('wysokosc wody w zbiorniku - h [m]');
   title('wysokosc wody w zbiorniku, drugi zbiornik : dfwe1 = 1.1276, dfwe2 = 0');
end
dfwe2 = 0.1*fwe2max;
for i=1:3
   hold on;
   grid on;
   subplot(2,2,3)
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   sim('Kubon_lab6_sim_test');
   plot(ans.tout ,ans.h1a)
   xlabel('czas [t]');
   ylabel('wysokosc wody w zbiorniku - h [m]');
   title('wysokosc wody w zbiorniku, pierwszy zbiornik : dfwe1 = 1.1276, dfwe2 = 0.9396');
end
for i=1:3
   hold on;
   grid on;
   fwe1 = fwe1w(i);
   fwe2 = fwe2w(i);
   h10=fwe1/a1;
   h20=(fwe1+fwe2)/a2;
   subplot(2,2,4)
   sim('Kubon_lab6_sim_test');
   plot(ans.tout ,ans.h2a)
   xlabel('czas [t]');
   ylabel('wysokosc wody w zbiorniku - h [m]');
   title('wysokosc wody w zbiorniku, drugi zbiornik : dfwe1 = 1.1276, dfwe2 = 0.9396');
end

