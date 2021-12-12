clear all;
close all;

%a = [1; 2; 3; 4; 5];
%b = [1; 2; 3; 4; 5];
%c = b + a;


%[x,y] = meshgrid(a,b);
%z = c;
%mesh(x,y,z);

z = zeros(11,11);
x = 0:1:10;
y = 0:1:10;
surf(x,y,z);

%[X,Y]= meshgrid(-10:10);
%Z = X.^2 + Y.^2;
surf(X,Y,Z);