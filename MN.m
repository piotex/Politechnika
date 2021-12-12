clear all;
close all;

A=[
    100 1 1 1 1 1 1 1 1 1 1; 
    1 100 1 1 1 1 1 1 1 1 1; 
    1 1 100 1 1 1 1 1 1 1 1; 
    1 1 1 100 1 1 1 1 1 1 1; 
    1 1 1 1 100 1 1 1 1 1 1; 
    1 1 1 1 1 100 1 1 1 1 1; 
    1 1 1 1 1 1 100 1 1 1 1; 
    1 1 1 1 1 1 1 100 1 1 1; 
    1 1 1 1 1 1 1 1 100 1 1; 
    1 1 1 1 1 1 1 1 1 100 1; 
    1 1 1 1 1 1 1 1 1 1 100; 
    ];
b=[1 2 3 4 5 6 7 8 9 10 11];

x=zeros(11,1);
n=size(x,1);
blad=Inf;
prog=0.00001;

while blad>prog
    x_old = x;
    for i=1:n
        tmp=0;
        for j=1:i-1
           tmp=tmp+A(i,j)*x(j); 
        end
        for j=i+1:n
            tmp=tmp+A(i,j)*x_old(j); 
        end

        x(i)=(b(i)-tmp)/(A(i,i)); 
    end
    
    blad=norm(x-x_old)/norm(x);
    
end
fprintf('------------------------\n');
fprintf('%f\n%f\n%f\n%f\n',x);









