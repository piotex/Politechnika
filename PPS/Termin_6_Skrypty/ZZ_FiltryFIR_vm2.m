% -------------------------------------------------------------
% Skrypt pozwala na:
% - wyznaczenie odpow. impulsowej fitru FIR o zadanych parametrach
% - wykreslenie odpow. impulsowej w oknie 1
% - obliczenie i wykreslenie modułu i fazy transmitancji w oknie 2

clear all;
close all;
M = 91;
w = rectwin (M);    % --- okno prostokątne
% w = triang(M);      % --- okno trojkatne
% w = blackman(M);
% w = hamming(M);
% w = kaiser(M,5);
% w = gausswin(M);
% w = blackmanharris(M);

kolor = ['b', 'k', 'r', 'g', 'y','c', 'm', 'w','b', 'k', 'r', 'g', 'y','c', 'm', 'w'];
i=1;
for M2 = 11:40:301
    
    figure (1);
    hold on;
    grid on;
    subplot (211);
    w = rectwin (M2);
    plot (w); 
    xlabel ('czas [pr]');
    ylabel ('okno czasowe');
    
    h = fir1 (M2-1, 0.3, w);   
    subplot (212);
    plot (h,'Color',kolor(i));
    xlabel ('czas [pr]');
    ylabel ('odpowiedz impulsowa');
    set (gcf,'Position',[50 50 600 600]);

    figure (2);
    hold on;
    grid on;
    freqz (h, 1);
    set (gcf,'Position',[700 50 800 600]);
    i=i+1;
end

% h = fir1 (M-1, 0.3, w);   
% subplot (212);
% plot (h);
% xlabel ('czas [pr]');
% ylabel ('odpowiedz impulsowa');
% set (gcf,'Position',[50 50 600 600]);
% 
% figure (2);
% freqz (h, 1);
% set (gcf,'Position',[700 50 800 600]);