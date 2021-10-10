% -------------------------------------------------------------
% Skrypt pozwala na:
% - zadanie po�o�enia zer lub/i biegun�w
% - wykre�lenie ich po�o�enia
% - obliczenie i wykre�lenie odpowiedzi impulsowej
% - obliczenie i wykreslenie modu�u i fazy transmitancji

clear;
fp = 1;
N = 4096;
t = 0:1:N-1;
x = chirp (t, 0.03, N, 0.47);
subplot (321);
plot (t, x);
xlabel ('czas [pr]');
ylabel ('sygnal wejsciowy');

wx = abs(fft(x, N));
N21 = N/2+1;
f = linspace (0, fp/2, N21);
subplot (322);
plot (f, wx(1:N21));
xlabel ('unormowana czestotl.');
ylabel ('modul widma');

% --------- odpowied� impulsowa filtra
M = 301;
h = fir1 (M-1, [0.2 0.4]);
subplot (323);
plot (h);

% ----------  modu� transmitancji
wh = abs(fft(h, N));
subplot (324);
plot (f, wh(1:N21));
xlabel ('unormowana czestotl.');
ylabel ('modul transmitancji');

% -------   filtracja
y = filter (h, 1, x);
subplot (325);
plot (y);
xlabel ('czas [pr]');
ylabel ('sygnal po filtracji');

% -------   modul widma po filtracji
wy = abs(fft(y, N));
subplot (326);
plot (f, wy(1:N21));
xlabel ('unormowana czestotl.');
ylabel ('modul widma');

set (gcf,'Position',[50 50 1000 700]);