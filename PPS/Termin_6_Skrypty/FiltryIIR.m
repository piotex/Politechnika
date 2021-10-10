% -------------------------------------------------------------
% Skrypt pozwala na:
% - wyznaczenie wsp�czynnikow a i b opisuj�cych transmitancj� filtru
% - wyznaczenie po�o�enia zer i biegun�w transmitancji
% - wyznaczenie odpow. impulsowej fitru IIR
% - obliczenie i wykreslenie modu�u i fazy transmitancji

clear;
N = 10;
%[b a] = butter (N, 0.4);
%[b a] = cheby1 (N, 2.0, 0.4);
%[b a] = cheby2 (N, 60.0, 0.4);
[b a] = ellip (N, 2.0, 60.0, 0.4);
% --- wyznaczenie po�o�enia zer i biegun�w i ich wykres
zer = roots (b)
pol = roots (a);
figure (1);
zplane (zer, pol);
%set (gcf,'Position',[0 200 600 400]);
% --- wyznaczenie odpowiedzi impulsowej i wykres
K = 701;
h = impz (b,a,K);
figure (2);
plot (h);
xlabel ('czas [pr]');
ylabel ('odpowiedz impulsowa');
set (gcf,'Position',[50 100 500 300]);
% --- wyznaczenie i wykres transmitancji
figure (3);
freqz (b, a);
set (gcf,'Position',[700 50 600 400]);