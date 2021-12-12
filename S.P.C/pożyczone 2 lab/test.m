clear;
close all;


x = linspace(0,2,20)';             % generate some data
y = sin(x);
plot(x,y,'.-b')
xy = ginput(1);                    % get point
[~,ix] = min(pdist2([x y],xy));    % find closest point
hold on
plot(x(ix),y(ix),'or')             % display closest point
hold off