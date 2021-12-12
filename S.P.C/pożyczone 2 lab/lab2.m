clear;
close all;


k = 1;
T = 1;
tau = 3;
A = 1;

w0 = 1.38;
w1 = 0.61;


sim('simlab2.slx');

figure;
plot(ans.Re, ans.Im, 'LineWidth', 2);
xlabel("Re[K(jw)]");
ylabel("Im[K(jw)]");

figure;
plot(ans.Re1, ans.Im1, 'LineWidth', 2);
xlabel("Re[K(jw)]");
ylabel("Im[K(jw)]");

figure;
hold on;
plot(ans.t, ans.sin1, 'LineWidth', 2);
plot(ans.t, ans.sind1, 'LineWidth', 2);
ylabel("A");
xlabel("t[s]");
title("w0")

figure;
hold on;
plot(ans.t, ans.sin2, 'LineWidth', 2);
plot(ans.t, ans.sind2, 'LineWidth', 2);
ylabel("A");
xlabel("t[s]");
title("w1")












