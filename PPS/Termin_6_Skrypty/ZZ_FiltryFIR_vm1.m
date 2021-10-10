% -------------------------------------------------------------
% Skrypt pozwala na:
% - wyznaczenie odpow. impulsowej fitru FIR o zadanych parametrach
% - wykreslenie odpow. impulsowej w oknie 1
% - obliczenie i wykreslenie modułu i fazy transmitancji w oknie 2

clear all;
close all;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
M = 51;
% w = rectwin (M);    % --- okno prostokątne
% w = triang(M);      % --- okno trojkatne
%w = blackman(M);
%w = hamming(M);
%w = kaiser(M,5);
%w = gausswin(M);
w = blackmanharris(M);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure (1);
subplot (211);
plot (w);
xlabel ('czas [pr]');
ylabel ('okno czasowe');
title(strcat('Rząd Filtru =  ',num2str(M-1)));

h = fir1 (M-1, 0.3, w);   
subplot (212);
plot (h);
xlabel ('czas [pr]');
ylabel ('odpowiedz impulsowa');
set (gcf,'Position',[50 50 600 600]);

figure (2);
freqz (h, 1);
set (gcf,'Position',[700 50 800 600]);
title(strcat('Rząd Filtru =  ',num2str(M-1)));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
M = 91;
% w = rectwin (M);    % --- okno prostokątne
% w = triang(M);      % --- okno trojkatne
%w = blackman(M);
%w = hamming(M);
%w = kaiser(M,5);
%w = gausswin(M);
 w = blackmanharris(M);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure (3);
subplot (211);
plot (w);
xlabel ('czas [pr]');
ylabel ('okno czasowe');
title(strcat('Rząd Filtru =  ',num2str(M-1)));

h = fir1 (M-1, 0.3, w);   
subplot (212);
plot (h);
xlabel ('czas [pr]');
ylabel ('odpowiedz impulsowa');
set (gcf,'Position',[50 50 600 600]);

figure (4);
freqz (h, 1);
set (gcf,'Position',[700 50 800 600]);
title(strcat('Rząd Filtru =  ',num2str(M-1)));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
M = 301;
% w = rectwin (M);    % --- okno prostokątne
% w = triang(M);      % --- okno trojkatne
%w = blackman(M);
%w = hamming(M);
%w = kaiser(M,5);
%w = gausswin(M);
 w = blackmanharris(M);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure (5);
subplot (211);
plot (w);
xlabel ('czas [pr]');
ylabel ('okno czasowe');
title(strcat('Rząd Filtru =  ',num2str(M-1)));

h = fir1 (M-1, 0.3, w);   
subplot (212);
plot (h);
xlabel ('czas [pr]');
ylabel ('odpowiedz impulsowa');
set (gcf,'Position',[50 50 600 600]);

figure (6);
freqz (h, 1);
set (gcf,'Position',[700 50 800 600]);
title(strcat('Rząd Filtru =  ',num2str(M-1)));




















